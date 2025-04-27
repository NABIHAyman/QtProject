#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDate>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialisation de la base de données
    initDatabase();

    // Configuration des modèles
    setupModels();

    // Masquer la colonne ID_Professeur
    ui->sujetsTableView->hideColumn(5);

    // Connexion pour le bouton Valider
    connect(ui->sujetsTableView->selectionModel(), &QItemSelectionModel::selectionChanged,
            this, &MainWindow::updateValiderButtonState);
}

void MainWindow::initDatabase()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("projet");
    db.setUserName("root");
    db.setPassword("");

    if(!db.open()) {
        QMessageBox::critical(this, "Erreur", "Connexion à la base de données échouée: " + db.lastError().text());
    }
}

void MainWindow::setupModels()
{
    // Modèle Étudiants
    etudiantsModel = new QSqlTableModel(this, db);
    etudiantsModel->setTable("etudiant");
    etudiantsModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    etudiantsModel->setHeaderData(1, Qt::Horizontal, tr("Nom"));
    ui->etudiantsTableView->setModel(etudiantsModel);

    // Modèle Sujets
    sujetsModel = new QSqlTableModel(this, db);
    sujetsModel->setTable("sujet");
    sujetsModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    sujetsModel->setHeaderData(1, Qt::Horizontal, tr("Titre"));
    sujetsModel->setHeaderData(4, Qt::Horizontal, tr("Validation"));
    ui->sujetsTableView->setModel(sujetsModel);

    // Modèle Groupes
    groupesModel = new QSqlRelationalTableModel(this, db);
    groupesModel->setTable("groupe");
    groupesModel->setRelation(1, QSqlRelation("sujet", "ID_Sujet", "Titre"));
    groupesModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->groupesTableView->setModel(groupesModel);
    ui->groupesTableView->setItemDelegate(new QSqlRelationalDelegate(ui->groupesTableView));

    // Masquer les colonnes ID
    ui->etudiantsTableView->hideColumn(0);
    ui->sujetsTableView->hideColumn(0);
    ui->groupesTableView->hideColumn(0);
}

void MainWindow::showPage(QWidget *page) {
    ui->stackedWidget->setCurrentWidget(page);
}

void MainWindow::on_loginButton_clicked()
{
    QString email = ui->emailInput->text().trimmed();
    QString password = ui->passwordInput->text();

    if(email.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT Nom FROM professeur WHERE Email = ? AND password = ?");
    query.addBindValue(email);
    query.addBindValue(password);

    if(!query.exec() || !query.next()) {
        QMessageBox::warning(this, "Erreur", "Email ou mot de passe incorrect");
        return;
    }

    ui->welcomeLabel->setText("Bienvenue, " + query.value(0).toString());
    showPage(ui->mainMenuPage);
}

void MainWindow::on_logoutButton_clicked()
{
    ui->emailInput->clear();
    ui->passwordInput->clear();
    showPage(ui->loginPage);
}

// Gestion des étudiants
void MainWindow::on_etudiantsButton_clicked()
{
    refreshEtudiantsTable();
    showPage(ui->etudiantsPage);
}

void MainWindow::refreshEtudiantsTable()
{
    if(!etudiantsModel->select()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors du chargement: " + etudiantsModel->lastError().text());
    }
}

void MainWindow::on_addEtudiantButton_clicked()
{
    int row = etudiantsModel->rowCount();
    etudiantsModel->insertRow(row);
    QModelIndex index = etudiantsModel->index(row, 1);
    ui->etudiantsTableView->setCurrentIndex(index);
    ui->etudiantsTableView->edit(index);
}

void MainWindow::on_editEtudiantButton_clicked()
{
    QModelIndex index = ui->etudiantsTableView->currentIndex();
    if(!index.isValid()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un étudiant");
        return;
    }
    ui->etudiantsTableView->edit(index);
}

void MainWindow::on_deleteEtudiantButton_clicked()
{
    QModelIndex index = ui->etudiantsTableView->currentIndex();
    if(!index.isValid()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un étudiant");
        return;
    }

    if(QMessageBox::question(this, "Confirmation", "Supprimer cet étudiant ?") == QMessageBox::Yes) {
        etudiantsModel->removeRow(index.row());
        if(!etudiantsModel->submitAll()) {
            QMessageBox::critical(this, "Erreur", "Erreur lors de la suppression: " + etudiantsModel->lastError().text());
        }
    }
}

void MainWindow::on_backEtudiantButton_clicked()
{
    if(etudiantsModel->isDirty()) {
        if(!etudiantsModel->submitAll()) {
            QMessageBox::critical(this, "Erreur", "Erreur lors de l'enregistrement: " + etudiantsModel->lastError().text());
        }
    }
    showPage(ui->mainMenuPage);
}

// Gestion des sujets
void MainWindow::on_sujetsButton_clicked()
{
    refreshSujetsTable();
    showPage(ui->sujetsPage);
}

void MainWindow::refreshSujetsTable()
{
    if(!sujetsModel->select()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors du chargement: " + sujetsModel->lastError().text());
        return;
    }

    // Formater la colonne Est_Valide
    for(int i = 0; i < sujetsModel->rowCount(); ++i) {
        QModelIndex index = sujetsModel->index(i, 4);
        bool valide = sujetsModel->data(index).toBool();
        sujetsModel->setData(index, valide ? "Validé" : "Non validé", Qt::DisplayRole);
    }
}

void MainWindow::updateValiderButtonState()
{
    QModelIndexList selected = ui->sujetsTableView->selectionModel()->selectedRows();
    if(selected.isEmpty()) {
        ui->validerSujetButton->setEnabled(false);
        return;
    }

    int row = selected.first().row();
    bool dejaValide = sujetsModel->data(sujetsModel->index(row, 4)).toBool();
    ui->validerSujetButton->setEnabled(!dejaValide);
}

void MainWindow::on_addSujetButton_clicked()
{
    if(ui->emailInput->text().isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Connectez-vous d'abord");
        return;
    }

    // Récupérer l'ID du professeur
    QSqlQuery query;
    query.prepare("SELECT ID_Professeur FROM professeur WHERE Email = ?");
    query.addBindValue(ui->emailInput->text());

    if(!query.exec() || !query.next()) {
        QMessageBox::critical(this, "Erreur", "Professeur non trouvé");
        return;
    }

    int idProf = query.value(0).toInt();

    // Ajouter une nouvelle ligne
    int row = sujetsModel->rowCount();
    if(!sujetsModel->insertRow(row)) {
        QMessageBox::critical(this, "Erreur", "Impossible d'ajouter un sujet");
        return;
    }

    // Remplir les valeurs par défaut
    sujetsModel->setData(sujetsModel->index(row, 2), QDate::currentDate()); // Date
    sujetsModel->setData(sujetsModel->index(row, 3), 0); // Est_Personnalise
    sujetsModel->setData(sujetsModel->index(row, 4), 0); // Est_Valide
    sujetsModel->setData(sujetsModel->index(row, 5), idProf); // ID_Professeur

    // Positionner le curseur sur le titre pour édition
    QModelIndex index = sujetsModel->index(row, 1);
    ui->sujetsTableView->setCurrentIndex(index);
    ui->sujetsTableView->edit(index);
}

void MainWindow::on_validerSujetButton_clicked()
{
    QModelIndexList selected = ui->sujetsTableView->selectionModel()->selectedRows();
    if(selected.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Sélectionnez un sujet");
        return;
    }

    int row = selected.first().row();
    sujetsModel->setData(sujetsModel->index(row, 4), 1); // Est_Valide = true

    if(!sujetsModel->submitAll()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la validation: " + sujetsModel->lastError().text());
        return;
    }

    refreshSujetsTable();
}

void MainWindow::on_deleteSujetButton_clicked()
{
    QModelIndexList selected = ui->sujetsTableView->selectionModel()->selectedRows();
    if(selected.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Sélectionnez un sujet");
        return;
    }

    int row = selected.first().row();
    int idSujet = sujetsModel->data(sujetsModel->index(row, 0)).toInt();

    // Vérifier si le sujet est utilisé
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM groupe WHERE ID_Sujet = ?");
    checkQuery.addBindValue(idSujet);

    if(!checkQuery.exec() || !checkQuery.next()) {
        QMessageBox::critical(this, "Erreur", "Vérification impossible");
        return;
    }

    if(checkQuery.value(0).toInt() > 0) {
        QMessageBox::warning(this, "Erreur", "Ce sujet est utilisé par des groupes");
        return;
    }

    if(QMessageBox::question(this, "Confirmer", "Supprimer définitivement ce sujet ?") != QMessageBox::Yes) {
        return;
    }

    sujetsModel->removeRow(row);
    if(!sujetsModel->submitAll()) {
        QMessageBox::critical(this, "Erreur", "Échec de suppression: " + sujetsModel->lastError().text());
        return;
    }
}

void MainWindow::on_backSujetButton_clicked()
{
    if(sujetsModel->isDirty()) {
        if(!sujetsModel->submitAll()) {
            QMessageBox::critical(this, "Erreur", "Erreur lors de l'enregistrement: " + sujetsModel->lastError().text());
        }
    }
    showPage(ui->mainMenuPage);
}

// Gestion des groupes
void MainWindow::on_groupesButton_clicked()
{
    refreshGroupesTable();
    showPage(ui->groupesPage);
}

void MainWindow::refreshGroupesTable()
{
    if(!groupesModel->select()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors du chargement: " + groupesModel->lastError().text());
    }
}

void MainWindow::on_addGroupeButton_clicked()
{
    int row = groupesModel->rowCount();
    groupesModel->insertRow(row);
    QModelIndex index = groupesModel->index(row, 1);
    ui->groupesTableView->setCurrentIndex(index);
    ui->groupesTableView->edit(index);
}

void MainWindow::on_editGroupeButton_clicked()
{
    QModelIndex index = ui->groupesTableView->currentIndex();
    if(!index.isValid()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un groupe");
        return;
    }
    ui->groupesTableView->edit(index);
}

void MainWindow::on_deleteGroupeButton_clicked()
{
    QModelIndex index = ui->groupesTableView->currentIndex();
    if(!index.isValid()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un groupe");
        return;
    }

    int idGroupe = groupesModel->data(groupesModel->index(index.row(), 0)).toInt();
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM etudiant WHERE ID_Groupe = ?");
    query.addBindValue(idGroupe);

    if(!query.exec() || !query.next()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la vérification");
        return;
    }

    if(query.value(0).toInt() > 0) {
        QMessageBox::warning(this, "Erreur", "Ce groupe contient des étudiants");
        return;
    }

    if(QMessageBox::question(this, "Confirmation", "Supprimer ce groupe ?") == QMessageBox::Yes) {
        groupesModel->removeRow(index.row());
        if(!groupesModel->submitAll()) {
            QMessageBox::critical(this, "Erreur", "Erreur lors de la suppression: " + groupesModel->lastError().text());
        }
    }
}

void MainWindow::on_backGroupeButton_clicked()
{
    if(groupesModel->isDirty()) {
        if(!groupesModel->submitAll()) {
            QMessageBox::critical(this, "Erreur", "Erreur lors de l'enregistrement: " + groupesModel->lastError().text());
        }
    }
    showPage(ui->mainMenuPage);
}

MainWindow::~MainWindow()
{
    db.close();
    delete ui;
}

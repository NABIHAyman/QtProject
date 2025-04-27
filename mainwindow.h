#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRelation>
#include <QSqlRelationalDelegate>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Connexion
    void on_loginButton_clicked();
    void on_logoutButton_clicked();

    // Navigation
    void on_etudiantsButton_clicked();
    void on_sujetsButton_clicked();
    void on_groupesButton_clicked();
    void on_backEtudiantButton_clicked();
    void on_backSujetButton_clicked();
    void on_backGroupeButton_clicked();

    // Gestion Étudiants
    void on_addEtudiantButton_clicked();
    void on_editEtudiantButton_clicked();
    void on_deleteEtudiantButton_clicked();

    // Gestion Sujets
    void on_addSujetButton_clicked();
    void on_validerSujetButton_clicked();
    void on_deleteSujetButton_clicked();

    // Gestion Groupes
    void on_addGroupeButton_clicked();
    void on_editGroupeButton_clicked();
    void on_deleteGroupeButton_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;

    // Modèles de données
    QSqlTableModel *etudiantsModel;
    QSqlTableModel *sujetsModel;
    QSqlRelationalTableModel *groupesModel;

    // Méthodes utilitaires
    void initDatabase();
    void setupModels();
    void showPage(QWidget *page);
    bool isCurrentUserAdmin();

    // Rafraîchissement des données
    void refreshEtudiantsTable();
    void refreshSujetsTable();
    void refreshGroupesTable();
    void updateValiderButtonState();
};

#endif // MAINWINDOW_H

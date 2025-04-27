/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *loginPage;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelTitle;
    QSpacerItem *verticalSpacer;
    QFormLayout *formLayout;
    QLabel *labelEmail;
    QLineEdit *emailInput;
    QLabel *labelPassword;
    QLineEdit *passwordInput;
    QPushButton *loginButton;
    QSpacerItem *verticalSpacer_2;
    QWidget *mainMenuPage;
    QVBoxLayout *verticalLayout_3;
    QLabel *welcomeLabel;
    QSpacerItem *verticalSpacer_3;
    QPushButton *etudiantsButton;
    QPushButton *sujetsButton;
    QPushButton *groupesButton;
    QSpacerItem *verticalSpacer_4;
    QPushButton *logoutButton;
    QWidget *etudiantsPage;
    QVBoxLayout *verticalLayout_4;
    QLabel *labelEtudiants;
    QTableView *etudiantsTableView;
    QHBoxLayout *horizontalLayout;
    QPushButton *addEtudiantButton;
    QPushButton *editEtudiantButton;
    QPushButton *deleteEtudiantButton;
    QPushButton *backEtudiantButton;
    QWidget *sujetsPage;
    QVBoxLayout *verticalLayout_5;
    QLabel *labelSujets;
    QTableView *sujetsTableView;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *addSujetButton;
    QPushButton *editSujetButton;
    QPushButton *validerSujetButton;
    QPushButton *deleteSujetButton;
    QPushButton *backSujetButton;
    QWidget *groupesPage;
    QVBoxLayout *verticalLayout_6;
    QLabel *labelGroupes;
    QTableView *groupesTableView;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *addGroupeButton;
    QPushButton *editGroupeButton;
    QPushButton *deleteGroupeButton;
    QPushButton *backGroupeButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        loginPage = new QWidget();
        loginPage->setObjectName("loginPage");
        verticalLayout_2 = new QVBoxLayout(loginPage);
        verticalLayout_2->setObjectName("verticalLayout_2");
        labelTitle = new QLabel(loginPage);
        labelTitle->setObjectName("labelTitle");
        labelTitle->setStyleSheet(QString::fromUtf8("font-size: 18px; font-weight: bold;"));
        labelTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(labelTitle);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        labelEmail = new QLabel(loginPage);
        labelEmail->setObjectName("labelEmail");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, labelEmail);

        emailInput = new QLineEdit(loginPage);
        emailInput->setObjectName("emailInput");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, emailInput);

        labelPassword = new QLabel(loginPage);
        labelPassword->setObjectName("labelPassword");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, labelPassword);

        passwordInput = new QLineEdit(loginPage);
        passwordInput->setObjectName("passwordInput");
        passwordInput->setEchoMode(QLineEdit::EchoMode::Password);

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, passwordInput);


        verticalLayout_2->addLayout(formLayout);

        loginButton = new QPushButton(loginPage);
        loginButton->setObjectName("loginButton");
        loginButton->setStyleSheet(QString::fromUtf8("padding: 8px; font-weight: bold;"));

        verticalLayout_2->addWidget(loginButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        stackedWidget->addWidget(loginPage);
        mainMenuPage = new QWidget();
        mainMenuPage->setObjectName("mainMenuPage");
        verticalLayout_3 = new QVBoxLayout(mainMenuPage);
        verticalLayout_3->setObjectName("verticalLayout_3");
        welcomeLabel = new QLabel(mainMenuPage);
        welcomeLabel->setObjectName("welcomeLabel");
        welcomeLabel->setStyleSheet(QString::fromUtf8("font-size: 16px;"));
        welcomeLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_3->addWidget(welcomeLabel);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        etudiantsButton = new QPushButton(mainMenuPage);
        etudiantsButton->setObjectName("etudiantsButton");
        etudiantsButton->setMinimumSize(QSize(0, 40));
        etudiantsButton->setStyleSheet(QString::fromUtf8("font-size: 14px;"));

        verticalLayout_3->addWidget(etudiantsButton);

        sujetsButton = new QPushButton(mainMenuPage);
        sujetsButton->setObjectName("sujetsButton");
        sujetsButton->setMinimumSize(QSize(0, 40));
        sujetsButton->setStyleSheet(QString::fromUtf8("font-size: 14px;"));

        verticalLayout_3->addWidget(sujetsButton);

        groupesButton = new QPushButton(mainMenuPage);
        groupesButton->setObjectName("groupesButton");
        groupesButton->setMinimumSize(QSize(0, 40));
        groupesButton->setStyleSheet(QString::fromUtf8("font-size: 14px;"));

        verticalLayout_3->addWidget(groupesButton);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_4);

        logoutButton = new QPushButton(mainMenuPage);
        logoutButton->setObjectName("logoutButton");

        verticalLayout_3->addWidget(logoutButton);

        stackedWidget->addWidget(mainMenuPage);
        etudiantsPage = new QWidget();
        etudiantsPage->setObjectName("etudiantsPage");
        verticalLayout_4 = new QVBoxLayout(etudiantsPage);
        verticalLayout_4->setObjectName("verticalLayout_4");
        labelEtudiants = new QLabel(etudiantsPage);
        labelEtudiants->setObjectName("labelEtudiants");
        labelEtudiants->setStyleSheet(QString::fromUtf8("font-size: 16px; font-weight: bold;"));
        labelEtudiants->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_4->addWidget(labelEtudiants);

        etudiantsTableView = new QTableView(etudiantsPage);
        etudiantsTableView->setObjectName("etudiantsTableView");
        etudiantsTableView->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        etudiantsTableView->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);

        verticalLayout_4->addWidget(etudiantsTableView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        addEtudiantButton = new QPushButton(etudiantsPage);
        addEtudiantButton->setObjectName("addEtudiantButton");

        horizontalLayout->addWidget(addEtudiantButton);

        editEtudiantButton = new QPushButton(etudiantsPage);
        editEtudiantButton->setObjectName("editEtudiantButton");

        horizontalLayout->addWidget(editEtudiantButton);

        deleteEtudiantButton = new QPushButton(etudiantsPage);
        deleteEtudiantButton->setObjectName("deleteEtudiantButton");
        deleteEtudiantButton->setStyleSheet(QString::fromUtf8("color: white; background-color: #f44336;"));

        horizontalLayout->addWidget(deleteEtudiantButton);

        backEtudiantButton = new QPushButton(etudiantsPage);
        backEtudiantButton->setObjectName("backEtudiantButton");

        horizontalLayout->addWidget(backEtudiantButton);


        verticalLayout_4->addLayout(horizontalLayout);

        stackedWidget->addWidget(etudiantsPage);
        sujetsPage = new QWidget();
        sujetsPage->setObjectName("sujetsPage");
        verticalLayout_5 = new QVBoxLayout(sujetsPage);
        verticalLayout_5->setObjectName("verticalLayout_5");
        labelSujets = new QLabel(sujetsPage);
        labelSujets->setObjectName("labelSujets");
        labelSujets->setStyleSheet(QString::fromUtf8("font-size: 16px; font-weight: bold;"));
        labelSujets->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_5->addWidget(labelSujets);

        sujetsTableView = new QTableView(sujetsPage);
        sujetsTableView->setObjectName("sujetsTableView");
        sujetsTableView->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        sujetsTableView->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);

        verticalLayout_5->addWidget(sujetsTableView);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        addSujetButton = new QPushButton(sujetsPage);
        addSujetButton->setObjectName("addSujetButton");

        horizontalLayout_2->addWidget(addSujetButton);

        editSujetButton = new QPushButton(sujetsPage);
        editSujetButton->setObjectName("editSujetButton");

        horizontalLayout_2->addWidget(editSujetButton);

        validerSujetButton = new QPushButton(sujetsPage);
        validerSujetButton->setObjectName("validerSujetButton");
        validerSujetButton->setStyleSheet(QString::fromUtf8("background-color: #4CAF50; color: white; font-weight: bold;"));

        horizontalLayout_2->addWidget(validerSujetButton);

        deleteSujetButton = new QPushButton(sujetsPage);
        deleteSujetButton->setObjectName("deleteSujetButton");
        deleteSujetButton->setStyleSheet(QString::fromUtf8("color: white; background-color: #f44336;"));

        horizontalLayout_2->addWidget(deleteSujetButton);

        backSujetButton = new QPushButton(sujetsPage);
        backSujetButton->setObjectName("backSujetButton");

        horizontalLayout_2->addWidget(backSujetButton);


        verticalLayout_5->addLayout(horizontalLayout_2);

        stackedWidget->addWidget(sujetsPage);
        groupesPage = new QWidget();
        groupesPage->setObjectName("groupesPage");
        verticalLayout_6 = new QVBoxLayout(groupesPage);
        verticalLayout_6->setObjectName("verticalLayout_6");
        labelGroupes = new QLabel(groupesPage);
        labelGroupes->setObjectName("labelGroupes");
        labelGroupes->setStyleSheet(QString::fromUtf8("font-size: 16px; font-weight: bold;"));
        labelGroupes->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_6->addWidget(labelGroupes);

        groupesTableView = new QTableView(groupesPage);
        groupesTableView->setObjectName("groupesTableView");
        groupesTableView->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        groupesTableView->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);

        verticalLayout_6->addWidget(groupesTableView);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        addGroupeButton = new QPushButton(groupesPage);
        addGroupeButton->setObjectName("addGroupeButton");

        horizontalLayout_3->addWidget(addGroupeButton);

        editGroupeButton = new QPushButton(groupesPage);
        editGroupeButton->setObjectName("editGroupeButton");

        horizontalLayout_3->addWidget(editGroupeButton);

        deleteGroupeButton = new QPushButton(groupesPage);
        deleteGroupeButton->setObjectName("deleteGroupeButton");
        deleteGroupeButton->setStyleSheet(QString::fromUtf8("color: white; background-color: #f44336;"));

        horizontalLayout_3->addWidget(deleteGroupeButton);

        backGroupeButton = new QPushButton(groupesPage);
        backGroupeButton->setObjectName("backGroupeButton");

        horizontalLayout_3->addWidget(backGroupeButton);


        verticalLayout_6->addLayout(horizontalLayout_3);

        stackedWidget->addWidget(groupesPage);

        verticalLayout->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gestion de Projets Acad\303\251miques", nullptr));
        labelTitle->setText(QCoreApplication::translate("MainWindow", "Connexion Professeur", nullptr));
        labelEmail->setText(QCoreApplication::translate("MainWindow", "Email :", nullptr));
        emailInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez votre email", nullptr));
        labelPassword->setText(QCoreApplication::translate("MainWindow", "Mot de passe :", nullptr));
        passwordInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez votre mot de passe", nullptr));
        loginButton->setText(QCoreApplication::translate("MainWindow", "Se connecter", nullptr));
        welcomeLabel->setText(QCoreApplication::translate("MainWindow", "Bienvenue, [Nom]", nullptr));
        etudiantsButton->setText(QCoreApplication::translate("MainWindow", "G\303\251rer les \303\251tudiants", nullptr));
        sujetsButton->setText(QCoreApplication::translate("MainWindow", "G\303\251rer les sujets", nullptr));
        groupesButton->setText(QCoreApplication::translate("MainWindow", "G\303\251rer les groupes", nullptr));
        logoutButton->setText(QCoreApplication::translate("MainWindow", "D\303\251connexion", nullptr));
        labelEtudiants->setText(QCoreApplication::translate("MainWindow", "Gestion des \303\211tudiants", nullptr));
        addEtudiantButton->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        editEtudiantButton->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        deleteEtudiantButton->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        backEtudiantButton->setText(QCoreApplication::translate("MainWindow", "Retour", nullptr));
        labelSujets->setText(QCoreApplication::translate("MainWindow", "Gestion des Sujets", nullptr));
        addSujetButton->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        editSujetButton->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        validerSujetButton->setText(QCoreApplication::translate("MainWindow", "Valider", nullptr));
        deleteSujetButton->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        backSujetButton->setText(QCoreApplication::translate("MainWindow", "Retour", nullptr));
        labelGroupes->setText(QCoreApplication::translate("MainWindow", "Gestion des Groupes", nullptr));
        addGroupeButton->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        editGroupeButton->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        deleteGroupeButton->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        backGroupeButton->setText(QCoreApplication::translate("MainWindow", "Retour", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

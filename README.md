# Gestion de projets de fin d'études — application Qt

Application de bureau en C++/Qt pour gérer les étudiants, les sujets de projet et
les groupes d'un établissement, avec une base MySQL.

---

## Aperçu

L'application couvre trois entités liées — **étudiants**, **sujets**, **groupes** —
et les opérations de gestion associées : création, modification, suppression, et
validation d'un sujet.

L'accès est protégé par un écran de connexion, et certaines actions (la
validation d'un sujet notamment) sont réservées aux administrateurs.

L'affichage repose sur les modèles SQL de Qt : `QSqlTableModel` pour les tables
simples, et `QSqlRelationalTableModel` pour les groupes, dont les colonnes de
clé étrangère sont résolues automatiquement vers des libellés lisibles.

---

## Stack technique

![C++](https://img.shields.io/badge/C%2B%2B-17-00599C?style=flat-square&logo=cplusplus&logoColor=white)
![Qt](https://img.shields.io/badge/Qt-6.9-41CD52?style=flat-square&logo=qt&logoColor=white)
![MySQL](https://img.shields.io/badge/MySQL-4479A1?style=flat-square&logo=mysql&logoColor=white)

| Composant | Détail |
|---|---|
| Langage | C++17 |
| Framework | Qt 6.9 — modules `core`, `gui`, `widgets`, `sql` |
| Base de données | MySQL, via le pilote `QMYSQL` |
| Build | qmake (`ProjetQt.pro`) |
| Interface | Qt Designer (`mainwindow.ui`) |

---

## Fonctionnalités

- Connexion / déconnexion, avec distinction du rôle administrateur
- Navigation par pages entre les trois sections
- **Étudiants** — ajout, modification, suppression
- **Sujets** — ajout, suppression, validation réservée à l'administrateur
- **Groupes** — ajout, modification, suppression, avec résolution des clés
  étrangères via `QSqlRelationalTableModel`
- Rafraîchissement des tables après chaque opération

---

## Prérequis

| Outil | Version |
|---|---|
| Qt | 6.9 avec le module Qt SQL et le pilote MySQL |
| Compilateur | Compatible C++17 (GCC 11+, MSVC 2019+, Clang 13+) |
| MySQL | 8.0 |
| Qt Creator | recommandé, ou qmake + make en ligne de commande |

> Le pilote `QMYSQL` n'est pas toujours fourni compilé avec Qt. S'il manque,
> `db.open()` échoue avec « Driver not loaded » : il faut alors le construire
> depuis les sources de Qt.

---

## Installation et lancement

```bash
git clone https://github.com/NABIHAyman/QtProject.git
cd QtProject
```

Créer la base de données :

```sql
CREATE DATABASE projet CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;
```

Les tables attendues sont `etudiant`, `sujet` et `groupe`.
**Aucun script SQL n'est fourni dans le dépôt** : le schéma doit être recréé à la
main à partir des modèles définis dans `setupModels()`.

Configurer la connexion dans `mainwindow.cpp`, fonction `initDatabase()` :

```cpp
db.setHostName("127.0.0.1");
db.setDatabaseName("projet");
db.setUserName("<utilisateur>");
db.setPassword("<mot de passe>");
```

Compiler et lancer :

```bash
qmake ProjetQt.pro
make
./ProjetQt
```

Sous Qt Creator, ouvrir `ProjetQt.pro` et lancer avec `Ctrl+R`.

---

## Structure du projet

```
QtProject/
├── ProjetQt.pro        # Configuration qmake (modules, sources, formulaires)
├── main.cpp            # Point d'entrée, instanciation de QApplication
├── mainwindow.h        # Déclaration de MainWindow, slots et modèles SQL
├── mainwindow.cpp      # Connexion BD, modèles, logique des trois sections
├── mainwindow.ui       # Interface conçue sous Qt Designer
└── build/              # Artefacts de compilation (à retirer du suivi Git)
```

---

## Captures d'écran

> *À compléter.* Emplacements prévus : écran de connexion, liste des étudiants,
> liste des sujets avec bouton de validation, gestion des groupes.

```
docs/screenshots/
├── connexion.png
├── etudiants.png
├── sujets.png
└── groupes.png
```

---

## Statut

**Projet académique**, réalisé en 2025 dans le cadre d'un module de programmation
C++/Qt. Il n'a jamais été déployé et ne comporte ni tests automatisés ni script
de création de schéma.

Deux limites connues, assumées pour un travail de TP :

- les identifiants de connexion MySQL sont écrits en dur dans `mainwindow.cpp` ;
- le dossier `build/` contient des binaires compilés qui n'ont pas leur place
  dans le suivi de version.

---

## Licence

Distribué sous licence [MIT](LICENSE) — © 2026 Ayman NABIH.

---

## Auteur

**Ayman NABIH**
[github.com/NABIHAyman](https://github.com/NABIHAyman) ·
[linkedin.com/in/nabihayman](https://linkedin.com/in/nabihayman)

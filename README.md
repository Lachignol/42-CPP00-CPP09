# Exercices C++ - École 42

Bienvenue dans ce dépôt qui regroupe tous mes exercices en C++ réalisés dans le cadre de la formation à l'école 42.

## Contenu du dépôt

Ce dépôt contient des exercices pratiques couvrant différents aspects de la programmation en C++ :

- Gestion des bases du langage (syntaxe, variables, fonctions, boucles, conditions)
- Programmation orientée objet (classes, héritage, polymorphisme, encapsulation)
- Gestion de la mémoire dynamique
- Manipulation des fichiers
- Utilisation des templates et de la STL
- Gestion des exceptions et bonnes pratiques de conception

Chaque module `CPP-XX` correspond à une étape d’apprentissage avec des exercices progressifs.

---

## Notions par module

### **CPP-00** – Introduction au C++
- Manipulation des arguments de la ligne de commande
- Bases de l’IO stream (`std::cout`, `std::cin`)
- Organisation du code en fichiers
- Introduction au `Makefile`

### **CPP-01** – Mémoires, pointeurs et références
- Allocation dynamique (`new` / `delete`)
- Différences entre pile et tas
- Références et pointeurs
- Portée et durée de vie des objets
- Premier contact avec les classes et destructeurs
- Gestion de l'inclusion avec fichiers `.hpp`

### **CPP-02** – Orthodox Canonical Form & opérateurs
- Forme canonique d’une classe C++ (constructeur par défaut, de copie, opérateur d'affectation, destructeur)
- Surcharge d’opérateurs (`operator=`, `operator<<`, etc.)
- Types `const`
- Classes utilitaires simples

### **CPP-03** – Hérédité simple
- Héritage de classes
- Appel de constructeurs parents
- Redéfinition de méthodes (`override`)
- Composition vs héritage
- Portée `public`, `protected`, `private`

### **CPP-04** – Polymorphisme et classes abstraites
- Fonctions virtuelles
- Classes abstraites et méthodes pures
- Polymorphisme dynamique (`virtual`)
- Destructeurs virtuels
- Deep copy et gestion de ressources

### **CPP-05** – Exceptions & contrôle des flux d’exécution
- Gestion des exceptions (`try`, `catch`, `throw`)
- Chaînage d’objets entre classes
- Vérification des préconditions
- Programmation défensive
- Formulaires orientés bureaucratie (concept d’autorisation et signature)

### **CPP-06** – Conversion de types et casts
- Conversions implicites et explicites
- `static_cast`, `dynamic_cast`, `reinterpret_cast`, `const_cast`
- Sérialisation d’objets en données brutes
- Reconnaissance de type à l’exécution (`RTTI`)

### **CPP-07** – Templates
- Fonctions templates
- Classes templates
- Spécialisation
- Manipulation générique de types

### **CPP-08** – Conteneurs & algorithmes STL
- Introduction aux containers (`vector`, `list`, `deque`)
- Fonctions algorithmiques (`find`, `sort`, etc.)
- Concepts d’itérateurs
- Création de structures de données personnalisées

### **CPP-09** – Algorithmes avancés & parsing
- Lecture et parsing de fichiers
- Gestion et traitement de données (par exemple CSV)
- Algorithmes de tri hybrides
- Algorithmes sur piles (RPN – Reverse Polish Notation)
- Optimisation de la complexité

---

## Comment utiliser ce dépôt

1. Cloner le dépôt :

git clone <URL_DE_VOTRE_REPO>

2. Pour tester un exercice :

- Se rendre dans le dossier de l'exercice souhaité :
  ```
  cd nom_du_dossier_exercice
  ```
- Compiler et exécuter l'exercice avec `make` :
  ```
  make
  ```
- L’exécutable sera alors généré. Vous pouvez le lancer avec :
  ```
  ./nom_de_l_executable
  ```

3. Pour nettoyer les fichiers générés (optionnel) :

```
make clean
```

> **Remarque :** Assurez-vous d’avoir `make` et un compilateur C++ installés sur votre machine.

## Prérequis

- Un compilateur C++ (g++, clang++, etc.)
- Système d’exploitation compatible (Linux, macOS, Windows avec environnement adapté comme WSL ou MinGW)

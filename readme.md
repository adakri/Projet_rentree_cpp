# Kit de démarrage
Min découverte par l'exemple:

- une fonction toute simple, avec trois paramètres passés par valeur, par référence, et une adresse comme au bon vieux C.
- une classe toute simple.
- un main

Rapport d'étonnement?


# Compilation et exécution à la mimine, sous Linux.
Depuis le répertoire principal:

    mkdir build
    cd build
    cmake ..
    make
    ./example

# Sous VS Code
Un exemple ici avec l'IDE [Visual Studio Code](https://code.visualstudio.com/). Il est installé sous les Linux de l'écode (commande `code`), mais est aussi disponible sous Windows ou macOS.

Un tutorial est disponible ici: [Get started with CMake Tools on Linux](https://code.visualstudio.com/docs/cpp/cmake-linux), avec des équivalents pour les autres plateformes. En gros:

    Command Palette (Ctrl+Shift+P) -> Select a kit -> GCC 9.3.0
    Command Palette (Ctrl+Shift+P) -> Select a Variant -> Debug
    Command Palette (Ctrl+Shift+P) -> CMake: Configure
    Command Palette (Ctrl+Shift+P) -> CMake: Build
    Command Palette (Ctrl+Shift+P) -> CMake: Run Without Debugging (Shift + F5)
    Command Palette (Ctrl+Shift+P) -> CMake: Debug (Ctrl + F5)

Bien sûr, adapter le kit à votre système d'exploitation. Et il faudra dans tous les cas installer un compilateur au préalable, et un déboguer si besoin (vous avez un doute? Evidemment qu'un déboguer est indispensable!)

Lorsque votre projet est modifié, par exemple en ajoutant de nouveaux fichiers, il est nécessaire de relancer l'étape de configuration avant de compiler.

# Autres IDE, systèmes d'exploitations
Je ne sais pas, débrouillez-vous. Mais ça marchera.

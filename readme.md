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


# Projets Boids 

Installer une version pré-compilé de **SFML-2.5.1** dans [le lien suivant](https://www.sfml-dev.org/download.php). Sinon, utiliser le fichier **CMakeLists1.txt** (donc en le renommant CMakeLists.txt) pour compiler avec une version de SFML installée comme package.

Règles et méthodes inspirées des notes [suivantes](https://github.com/florimondmanca/pyboids/blob/master/NOTES.md) et du [site de Conrad Parker](http://www.vergenet.net/~conrad/boids/index.html).

# Quelques images et une animation gif

Une animation gif :

<img src="https://github.com/adakri/Projet_rentree_cpp/blob/master/images/boids1.gif?raw=true" width="640" height="480">


Quelques images plus illustrantes:

<img src="https://github.com/adakri/Projet_rentree_cpp/blob/master/images/boids1.png?raw=true" width="350" height="250">

<img src="https://github.com/adakri/Projet_rentree_cpp/blob/master/images/boids2.png?raw=true" width="350" height="250">

En jouant un petit peu avec les règles et les paramètres (et la direction) de séparation et de cohésien:

<img src="https://github.com/adakri/Projet_rentree_cpp/blob/master/images/boids3.png?raw=true" width="350" height="250">

<img src="https://github.com/adakri/Projet_rentree_cpp/blob/master/images/boids4.png?raw=true" width="350" height="250">



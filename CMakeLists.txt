# un exemple de CMakeLists.txt
# un peu vieux jeu, la bonne pratique desormais est d'utiliser des "target"
# quelqu'un.e nous fait un recherche et un petit topo la-dessus?

cmake_minimum_required(VERSION 3.0.0)

project(example)

# options de compilation
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# chemin vers les header files
include_directories(include)

# les fichiers source peuvent etre ajoutes un a un (penilbe, mais toujours fiable)
#   set(SOURCES src/main.cpp src/une_fonction.cpp src/une_classe.cpp
# - OU -
# ajout globally (simple, pas toujours recommande; cf. manuel)
file(GLOB_RECURSE sources CONFIGURE_DEPENDS src/*.cpp)

add_executable(${PROJECT_NAME} ${sources})
# bin location: (. by default)
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)  # or in bin

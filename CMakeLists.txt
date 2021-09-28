# un exemple de CMakeLists.txt
# un peu vieux jeu, la bonne pratique desormais est d'utiliser des "target"
# quelqu'un.e nous fait un recherche et un petit topo la-dessus?

cmake_minimum_required(VERSION 3.0.2)

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

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)


target_link_libraries(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.52)


#if(SFML_FOUND)
#  include_directories(${SFML_INCLUDE_DIR})
#  target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)
#endif()


cmake_minimum_required(VERSION 3.10)

project(boids)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE
  src/main.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE
  SFML-2.5.1/include include/)

target_link_directories(${PROJECT_NAME} PRIVATE
  SFML-2.5.1/lib include/)
target_link_libraries(${PROJECT_NAME} PRIVATE
  sfml-graphics
  sfml-window
  sfml-system)

cmake_minimum_required(VERSION 3.10)

project(boids)


# chemin vers les header files
include_directories(include)

set(SOURCES src/*.cpp )


add_executable(${PROJECT_NAME})


target_sources(${PROJECT_NAME} PRIVATE src/main.cpp src/boid.cpp src/env.cpp src/expr.cpp src/Fraction.cpp src/simulation.cpp src/une_classe.cpp src/une_fonction.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE
  SFML-2.5.1/include)

target_link_directories(${PROJECT_NAME} PRIVATE
  SFML-2.5.1/lib)

target_link_libraries(${PROJECT_NAME}  PRIVATE 
  sfml-graphics
  sfml-window
  sfml-system)


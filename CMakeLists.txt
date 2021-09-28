cmake_minimum_required(VERSION 3.10)

project(boids)


# chemin vers les header files
include_directories(include)

add_executable(${PROJECT_NAME})


target_sources(${PROJECT_NAME} PRIVATE src/main.cpp src/boid.cpp src/env.cpp src/expr.cpp src/Fraction.cpp src/simulation.cpp src/une_classe.cpp src/une_fonction.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE
  SFML-2.5.1/include)

#target_link_libraries(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.52)

#target_link_libraries(${PROJECT_NAME}  PRIVATE 
#  sfml-graphics
#  sfml-window
#  sfml-system)

#if(SFML_FOUND)
#  include_directories(${SFML_INCLUDE_DIR})
#  target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)
#endif()


cmake_minimum_required(VERSION 3.10)

project(boids)

#add_executable(${PROJECT_NAME})

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

cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(game)

include_directories(include)

file(GLOB SRC CONFIGURE_DEPENDS "src/*.cpp")
message(STATUS ${SRC})

add_executable(${CMAKE_PROJECT_NAME} 
  ${SRC})

target_link_libraries(${CMAKE_PROJECT_NAME} sfml-graphics sfml-window sfml-system)


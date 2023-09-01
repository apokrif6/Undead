cmake_minimum_required(VERSION 3.26)
project(Undead)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES "src/*.cpp" "src/**/*.cpp")

add_executable(Undead main.cpp ${SOURCES}
        src/Managers/InputManager/InputManager.cpp
        src/Managers/InputManager/InputManager.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio REQUIRED)

include_directories(C:/SFML/include)
target_link_libraries(Undead sfml-system sfml-window sfml-graphics sfml-audio)
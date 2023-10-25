cmake_minimum_required(VERSION 3.26)
project(Undead)

set(CMAKE_CXX_STANDARD 17)

add_executable(Undead main.cpp
        src/Animator/Animator.cpp
        src/Game/Game.cpp
        src/Managers/AssetManager/AssetManager.cpp
        src/Managers/InputManager/InputManager.cpp
        src/Managers/SoundManager/SoundManager.cpp
        src/Player/Player.cpp
        src/Weapon/Weapon.cpp
        src/config.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS graphics window audio system REQUIRED)

include_directories(C:/SFML/include)
target_link_libraries(Undead sfml-graphics sfml-window sfml-audio sfml-system)
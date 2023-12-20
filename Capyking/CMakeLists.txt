# Specify the source files
set(SOURCE_FILES sfml.cpp
        Game/Game.h
        Game/Game.cpp
        Object/Object.cpp
        Object/Object.h
        Player/Player.cpp
        Player/Player.h
        Capybara/Capybara.cpp
        Capybara/Capybara.h
        Bullet/Bullet.cpp
        Bullet/Bullet.h
        Score/Score.cpp
        Score/Score.h
        Background/Background.cpp
        Background/Background.h
        Character/Character.cpp
        Character/Character.h
        CapyBoss/CapyBoss.cpp
        CapyBoss/CapyBoss.h
        Enemy/Enemy.cpp
        Enemy/Enemy.h
        MenuState/MenuState.cpp
        MenuState/MenuState.h
        State/State.cpp
        State/State.h
        EndState/EndState.cpp
        EndState/EndState.h
)

# Set the SFML directory
set(SFML_DIR "/usr/lib/x86_64-linux-gnu/cmake/SFML")

cmake_minimum_required(VERSION 3.22)
project(tdp005)


# Existing content regarding the school's Linux system setup
if (DEFINED ENV{LOADEDMODULES} AND ("$ENV{LOADEDMODULES}" MATCHES ".*prog/gcc/6.1.0.*"))
    set(CMAKE_CXX_COMPILER /sw/gcc-6.1.0/bin/g++)
    if (DEFINED ENV{SFML_ROOT})
        list(APPEND CMAKE_MODULE_PATH "$ENV{SFML_ROOT}/share/SFML/cmake/Modules")
    endif()
endif()

# Välj vilka moduler i SFML som ska användas.
set(SFML_MODULES network graphics window system)

# Försök att hitta SFML genom att anropa 'FindSFML.cmake' (om det finns).
find_package(SFML 2 COMPONENTS ${SFML_MODULES})
include_directories(${SFML_INCLUDE_DIR})

# Om det inte finns hoppas vi på att SFML finns installerat ändå.
if (NOT (${SFML_FOUND} STREQUAL "TRUE"))
    set(SFML_LIBRARIES "")
    foreach (i ${SFML_MODULES})
        list(APPEND SFML_LIBRARIES "sfml-${i}")
    endforeach(i)
endif()

# Replace EXECUTABLE with your desired executable name
add_executable(EXECUTABLE ${SOURCE_FILES})
target_link_libraries(EXECUTABLE ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})

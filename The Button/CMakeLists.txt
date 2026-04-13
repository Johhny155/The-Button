cmake_minimum_required(VERSION 3.20)
project(The_Button)

set(CMAKE_CXX_STANDARD 17)

set(SFML_DIR "/opt/homebrew/opt/sfml@2/lib/cmake/SFML")

find_package(SFML COMPONENTS graphics window system REQUIRED)

add_executable(The_Button
        main.cpp
        ButtonUtils.cpp)

target_link_libraries(The_Button sfml-graphics sfml-window sfml-system sfml-audio)

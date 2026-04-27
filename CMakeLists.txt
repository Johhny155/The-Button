cmake_minimum_required(VERSION 3.20)
project(The_Button)


set(CMAKE_CXX_STANDARD 17)

set(SFML_DIR ${CMAKE_SOURCE_DIR}/lib/cmake/SFML)

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH}/bin)

add_executable(The_Button "main.cpp" "ButtonUtils.cpp")

target_link_libraries(The_Button sfml-graphics sfml-window sfml-system sfml-audio)


find_package(SFML COMPONENTS graphics window system REQUIRED)

include_directories(The_Button ${CMAKE_SOURCE_DIR}/include)

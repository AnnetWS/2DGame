cmake_minimum_required(VERSION 3.22.1)

project(kur)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_PREFIX_PATH "/home/anna/Загрузки/SFML-2.6.1/include/SFML")

add_executable(sfmlapp main.cpp GameMenu.cpp GameMenu.hpp view.hpp Players.cpp Players.hpp map1.hpp Engine.hpp Engine.cpp)

target_link_libraries(sfmlapp -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system)


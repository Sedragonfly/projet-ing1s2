cmake_minimum_required(VERSION 3.29)
project(deplaceme C)

set(CMAKE_C_STANDARD 23)

add_executable(deplaceme main.c
        "font .c"
        generale.h
        personnage.c
        animation-personage.c
)
target_link_libraries(deplaceme -lmingw32 -lalleg44)
cmake_minimum_required(VERSION 3.15)
project(adt_films C)

set(CMAKE_C_STANDARD 99)

add_executable(adt_films main.c list.h list.c queue.h queue.c tree.h)
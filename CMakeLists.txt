cmake_minimum_required(VERSION 3.10)

project(smoltens)

set(CMAKE_C_STANDARD 99)

add_executable(smoltens main.c tensor.c)

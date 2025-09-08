cmake_minimum_required(VERSION 3.10)

# Establecer el nombre del proyecto
project(CompresorHuffman)

# Especificar el estándar de C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Incluir directorios
include_directories(include)

# Agregar el ejecutable
add_executable(CompresorHuffman 
    src/main.cpp
    src/funciones.cpp
)
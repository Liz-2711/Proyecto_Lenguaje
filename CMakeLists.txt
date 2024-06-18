cmake_minimum_required(VERSION 3.10)
project(ProyectoLenguaje)

set(CMAKE_CXX_STANDARD 14)

# Establecer la opción de tiempo de ejecución para todas las configuraciones
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")

# Incluir directorios de encabezados
include_directories(include)

# Agregar GoogleTest
add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)

# Archivos fuente del proyecto
file(GLOB SRC_FILES
    "src/*.cpp"
)

# Archivos fuente de pruebas
file(GLOB TEST_FILES
    "test/*.cpp"
)

# Agregar el ejecutable principal
add_executable(main ${SRC_FILES} main.cpp)

# Agregar el ejecutable de pruebas y vincular GoogleTest
add_executable(runTests ${TEST_FILES} ${SRC_FILES})
target_link_libraries(runTests gtest gtest_main)

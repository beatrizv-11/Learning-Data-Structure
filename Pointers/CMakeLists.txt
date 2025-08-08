cmake_minimum_required(VERSION 3.5)
project(LinkedList)
 
# Define o padrão C++
set(CMAKE_CXX_STANDARD 17)
add_executable(MAIN main.cpp)

# Adiciona o diretório 'utils' ao caminho de includes
# target_include_directories(MAIN PRIVATE ${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/utils)cd ..

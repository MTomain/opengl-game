# Versão mínima do CMake
cmake_minimum_required(VERSION 3.5)

# Nome do projeto e linguagem
project(ProjetoOpenGL C)

# Define o padrão do C a ser utilizado
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Encontra os pacotes OpenGL, GLUT e a biblioteca matemática
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

# Define uma variável com todos os seus arquivos-fonte.
# Isso torna mais fácil adicionar novos arquivos no futuro.
set(SOURCES
    src/main.c
)

# Adiciona o diretório "include" para que você possa usar #include "house.h"
# em vez de #include "../include/house.h"
include_directories(include)

#Temporariamente para achar erros
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0 -fno-omit-frame-pointer -fsanitize=address,undefined")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address,undefined")

# Cria o executável a partir dos seus arquivos-fonte
add_executable(sludge ${SOURCES})

# Linka as bibliotecas necessárias com o nosso executável.
# A mágica acontece aqui: adicionamos "m" para a biblioteca matemática.
target_link_libraries(sludge PRIVATE
    ${OPENGL_LIBRARIES}
    ${GLUT_LIBRARIES}
    m # <-- ESSA É A LINHA QUE FALTAVA
)
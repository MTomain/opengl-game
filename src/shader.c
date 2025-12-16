#include "../include/glad.h" // Ou <GL/glew.h>, dependendo do que estiver usando no commons.h
#include "../include/shader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função auxiliar para ler o arquivo de texto
char* readFile(const char* filePath) {
    FILE* file = fopen(filePath, "r");
    if (!file) {
        printf("ERRO: Nao foi possivel abrir o arquivo %s\n", filePath);
        return NULL;
    }
    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    char* content = (char*)malloc(length + 1);
    fread(content, 1, length, file);
    content[length] = '\0';
    fclose(file);
    return content;
}

// Função auxiliar para compilar
unsigned int compileShader(unsigned int type, const char* source) {
    unsigned int id = glCreateShader(type);
    glShaderSource(id, 1, &source, NULL);
    glCompileShader(id);

    // Checagem de erro
    int success;
    char infoLog[512];
    glGetShaderiv(id, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(id, 512, NULL, infoLog);
        printf("ERRO DE COMPILACAO SHADER (%d): %s\n", type, infoLog);
    }
    return id;
}

// Função Principal que você chamará na Main
unsigned int LoadShaders(const char* vertexPath, const char* fragmentPath) {
    char* vertexCode = readFile(vertexPath);
    char* fragmentCode = readFile(fragmentPath);

    if (!vertexCode || !fragmentCode) return 0;

    unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexCode);
    unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentCode);

    unsigned int programID = glCreateProgram();
    glAttachShader(programID, vs);
    glAttachShader(programID, fs);
    glLinkProgram(programID);

    // Checar erro de linkagem
    int success;
    char infoLog[512];
    glGetProgramiv(programID, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(programID, 512, NULL, infoLog);
        printf("ERRO DE LINKAGEM DO PROGRAMA: %s\n", infoLog);
    }

    // Limpeza (já estão no programa, não precisamos mais dos individuais)
    glDeleteShader(vs);
    glDeleteShader(fs);
    free(vertexCode);
    free(fragmentCode);

    return programID;
}
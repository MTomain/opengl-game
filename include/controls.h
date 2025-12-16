#ifndef CONTROLS_H
#define CONTROLS_H

#include "../include/commons.h"

//Declaração de Variáveis Globis
extern int projecao; //Variável Lógica para Definir o Tipo de Projeção (Perspectiva ou Ortogonal)
extern float posx;
extern float posy;
extern float posz; //Variáveis que definem a posição da câmera
extern float oy;
extern float ox;
extern float oz;         //Variáveis que definem para onde a câmera olha
extern int lx;
extern int ly;
extern int lz;     //Variáveis que definem o eixo da câmera

extern GLfloat angulox;
extern GLfloat anguloy;

#endif
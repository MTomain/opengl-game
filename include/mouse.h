#ifndef MOUSE_H
#define MOUSE_H

#include "../include/commons.h"

#define x_temp -1 // Armazena posição X do ponteiro do mouse
#define y_temp -1 // Armazena posição Y do ponteiro do mouse
#define SCREEN_CENTER_X 400 
#define SCREEN_CENTER_Y 300 
#define SENSITIVITY 0.05  // Ajuste este valor para controlar a velocidade da câmera
extern int rotacao; // Controla eixo de rotação do mouse

void MOUSE(int x, int y);


#endif
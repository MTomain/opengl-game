#include "../include/controls.h"

//Declaração de Variáveis Globis
int projecao=0; //Variável Lógica para Definir o Tipo de Projeção (Perspectiva ou Ortogonal)
float posx=0, posy=25, posz=0; //Variáveis que definem a posição da câmera
float oy=100,ox=0,oz=0;         //Variáveis que definem para onde a câmera olha
int lx=0, ly=1,  lz=0;     //Variáveis que definem o eixo da câmera 

GLfloat angulox=0.0;
GLfloat anguloy=0.0;
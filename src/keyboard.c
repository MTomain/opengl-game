#include "../include/keyboard.h"
#include "../include/controls.h"

//controle de moovimento
unsigned char keys[2]; // [0] -> movimento horizontal [1] -> movimento vertical
float acc = 2;


void pressed_keys(unsigned char tecla, int x, int y)
{
   if (tecla == 'a' || tecla == 'd'){
    keys[0]= tecla;
   }else if (tecla == 'w' || tecla == 's'){
    keys[1] = tecla;
   }
}

void released_keys(unsigned char tecla, int x, int y)
{
   if (tecla == 'a' || tecla == 'd'){
    keys[0]= '\0';
   }else if (tecla == 'w' || tecla == 's'){
    keys[1] = '\0';
   }
}

void update_moviment(){
    // correct acc
    if(keys[0] !='\0' && keys[1] !='\0') acc= 2.24;

    switch(keys[0]){
    case 'd':
        posx=posx+(acc*sin((anguloy+90)/57.32));
        posz=posz-(acc*cos((anguloy+90)/57.32));
        ox=ox+(acc*sin((anguloy+90)/57.32));
        oz=oz-(acc*cos((anguloy+90)/57.32));
        glutPostRedisplay();
        break;

    case 'a':
        posx=posx-(acc*sin((anguloy+90)/57.32));
        posz=posz+(acc*cos((anguloy+90)/57.32));
        ox=ox-(acc*sin((anguloy+90)/57.32));
        oz=oz+(acc*cos((anguloy+90)/57.32));
        glutPostRedisplay();
        break;
    default:
        break;
    }

    switch(keys[1]){
    case 's':
        posx=posx+(acc*cos((anguloy+90)/57.32));
        posz=posz+(acc*sin((anguloy+90)/57.32));
        ox=ox+(acc*cos((anguloy+90)/57.32));
        oz=oz+(acc*sin((anguloy+90)/57.32));
        glutPostRedisplay();
        break;

    case 'w':
        posx=posx-(acc*cos((anguloy+90)/57.32));
        posz=posz-(acc*sin((anguloy+90)/57.32));
        ox=ox-(acc*cos((anguloy+90)/57.32));
        oz=oz-(acc*sin((anguloy+90)/57.32));
        glutPostRedisplay();
        break;

    default:
        break;
    }
}

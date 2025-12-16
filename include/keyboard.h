#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "../include/commons.h"

//controle de moovimento
extern unsigned char keys[2]; // [0] -> movimento horizontal [1] -> movimento vertical
extern float acc;

void pressed_keys(unsigned char tecla, int x, int y);
void released_keys(unsigned char tecla, int x, int y);
void TeclasEspeciaisUp(int key, int x, int y);
void TeclasEspeciais(int key, int x, int y);
void update_moviment();

#endif
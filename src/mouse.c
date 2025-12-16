#include "../include/mouse.h"
#include "../include/controls.h"

void MOUSE(int x, int y)
{
    // 1. Calcula o deslocamento (delta) a partir do centro da tela
    int delta_x = x - SCREEN_CENTER_X;
    int delta_y = y - SCREEN_CENTER_Y;

    // Se não houve movimento, não faça nada
    if (delta_x == 0 && delta_y == 0)
        return;

    // 2. Atualiza os ângulos com base no delta e na sensibilidade
    //    Multiplicamos delta_y por -1 se você quiser que mover o mouse para cima olhe para cima (inversão)
    anguloy += (float)delta_x * SENSITIVITY;
    angulox += (float)delta_y * SENSITIVITY;

    // 3. Normaliza o ângulo Y (rotação horizontal) para ficar entre 0 e 360
    if (anguloy >= 360.0f)
    {
        anguloy -= 360.0f;
    }
    if (anguloy < 0.0f)
    {
        anguloy += 360.0f;
    }

    // 4. (Opcional) Limita o ângulo X (rotação vertical) para evitar que a câmera vire de cabeça para baixo
    //    Um limite comum é entre -89 e 89 graus.
    if (angulox > 89.0f)
    {
        angulox = 89.0f;
    }
    if (angulox < -89.0f)
    {
        angulox = -89.0f;
    }

    // 5. Reseta o cursor para o centro da tela para permitir rotação "infinita"
    glutWarpPointer(SCREEN_CENTER_X, SCREEN_CENTER_Y);

    // 6. Solicita que a tela seja redesenhada com a nova perspectiva
    glutPostRedisplay();
}
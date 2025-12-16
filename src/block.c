#include "../include/block.h"

void block(float dimX, float dimY, float dimZ){
    float x = dimX / 2.0f;
    float y = dimY / 2.0f;
    float z = dimZ / 2.0f;

    glPushMatrix();
    orange;
    glTranslatef(0,0,0); // centraliza TUDO na origem
    glTranslatef(0,y,0); // fica acima do nivel do chão
    glBegin(GL_QUADS);
        // Face Frontal (+Z)
        glNormal3f(0.0f, 0.0f, 1.0f); // Normal aponta para frente
        glVertex3f(-x, -y,  z);
        glVertex3f( x, -y,  z);
        glVertex3f( x,  y,  z);
        glVertex3f(-x,  y,  z);

        // Face Traseira (-Z)
        glNormal3f(0.0f, 0.0f, -1.0f);
        glVertex3f(-x, -y, -z);
        glVertex3f(-x,  y, -z);
        glVertex3f( x,  y, -z);
        glVertex3f( x, -y, -z);

        // Face Superior (+Y)
        glNormal3f(0.0f, 1.0f, 0.0f);
        glVertex3f(-x,  y, -z);
        glVertex3f(-x,  y,  z);
        glVertex3f( x,  y,  z);
        glVertex3f( x,  y, -z);

        // Face Inferior (-Y)
        glNormal3f(0.0f, -1.0f, 0.0f);
        glVertex3f(-x, -y, -z);
        glVertex3f( x, -y, -z);
        glVertex3f( x, -y,  z);
        glVertex3f(-x, -y,  z);

        // Face Direita (+X)
        glNormal3f(1.0f, 0.0f, 0.0f);
        glVertex3f( x, -y, -z);
        glVertex3f( x,  y, -z);
        glVertex3f( x,  y,  z);
        glVertex3f( x, -y,  z);

        // Face Esquerda (-X)
        glNormal3f(-1.0f, 0.0f, 0.0f);
        glVertex3f(-x, -y, -z);
        glVertex3f(-x, -y,  z);
        glVertex3f(-x,  y,  z);
        glVertex3f(-x,  y, -z);

    glEnd();

    glPopMatrix();
}

void drawNormals(float dimX, float dimY, float dimZ){  
    float x = dimX / 2.0f;
    float y = dimY;
    float z = dimZ / 2.0f;  
    glColor3f(1.0f, 0.0f, 1.0f); 
    // Linhas um pouco mais grossas
    glLineWidth(2.0f);
    glBegin(GL_LINES);
        // Face Frontal (+Z)
        // Centro está em (0, 0, z), Normal é (0,0,1)
        glVertex3f(0.0f, y/2, z);              // Início da linha
        glVertex3f(0.0f, y/2, z + normal_len); // Fim da linha (z + comprimento)

        // Face Traseira (-Z)
        // Centro está em (0, 0, -z), Normal é (0,0,-1)
        glVertex3f(0.0f, y/2, -z);
        glVertex3f(0.0f, y/2, -z - normal_len);

        // Face Superior (+Y)
        // Centro está em (0, y, 0), Normal é (0,1,0)
        glVertex3f(0.0f, y, 0.0f);
        glVertex3f(0.0f, y + normal_len, 0.0f);

        // Face Inferior (-Y)
        // Centro está em (0, -y, 0), Normal é (0,-1,0)
        glVertex3f(0.0f, -y, 0.0f);
        glVertex3f(0.0f, -y - normal_len, 0.0f);

        // Face Direita (+X)
        // Centro está em (x, 0, 0), Normal é (1,0,0)
        glVertex3f(x, y/2, 0.0f);
        glVertex3f(x + normal_len, y/2, 0.0f);

        // Face Esquerda (-X)
        // Centro está em (-x, 0, 0), Normal é (-1,0,0)
        glVertex3f(-x, y/2, 0.0f);
        glVertex3f(-x - normal_len, y/2, 0.0f);
    glEnd();
}

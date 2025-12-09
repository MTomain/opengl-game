#include <GL/glut.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

void DesenharCena();
int angulo =0;
int portaAbrindo = 0;

void atualizaPorta() {
    if (portaAbrindo == 1 && angulo < 90) {
        angulo += 1.0f;
    } else if (portaAbrindo == -1 && angulo > 0) {
        angulo -= 1.0f;
    }
    glutPostRedisplay();
}

//Declaração de Variáveis Globis
int projecao=0; //Variável Lógica para Definir o Tipo de Projeção (Perspectiva ou Ortogonal)
float posx=0, posy=30, posz=200; //Variáveis que definem a posição da câmera
float oy=30,ox=0,oz=0;         //Variáveis que definem para onde a câmera olha
int lx=0, ly=1,  lz=0;     //Variáveis que definem o eixo da câmera


GLfloat angulox=0.0;
GLfloat anguloy=0.0;

int x_temp=-1; //Armazena posição X do ponteiro do mouse
int y_temp=-1; //Armazena posição Y do ponteiro do mouse
int rotacao = 0; //Controla eixo de rotação do mouse
int i;//controle do for


void stroke_output(GLfloat x, GLfloat y, char *format,...)//função para escrever em 3d
{
    va_list args;
    char buffer[200], *p;
    va_start(args, format);
    vsprintf(buffer, format, args);
    va_end(args);
    glPushMatrix();
    glScalef(0.05, 0.05, 0.05);
    for (p = buffer; *p; p++)
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
    glPopMatrix();
}

void parede(){
	//Define uma casinha composta por um quadrado e um triângulo.
   glColor3f(0,0,1); //Define cor como azul
   glBegin(GL_QUADS); //quadrado
      glVertex2f(0,0);
      glVertex2f(0, 50);
      glVertex2f( 50, 50);
      glVertex2f( 50,0);
   glEnd();
}

void telhado(){
   glColor3f(0,1,0); 
   glBegin(GL_TRIANGLES); //define as linhas da janela
      glVertex3f(0, 50,0);
      glVertex3f(50, 50,0);
      glVertex3f(25, 75,-25);
   glEnd();
}

void door(){
    glPushMatrix();
    glRotatef(angulo,0,1,0);
    glTranslatef(0,0,0);
    	//Define uma casinha composta por um quadrado e um triângulo.
   glColor3f(1,0,0); //Define cor como azul
   glBegin(GL_QUADS);
      glVertex2f(0,0);
      glVertex2f(0,40);
      glVertex2f(15,40);
      glVertex2f(15,0);
   glEnd();
}


void parede_with_door(){
	//Define uma casinha composta por um quadrado e um triângulo.
   glColor3f(0,0,1); //Define cor como azul
   glBegin(GL_QUADS); //quadrado
      glVertex2f(0,0);
      glVertex2f(0, 50); 
      glVertex2f(20,50);
      glVertex2f(20,0);

   glEnd();
   
   glBegin(GL_QUADS);
      glVertex2f(20,40);
      glVertex2f(20,50);
      glVertex2f(35,50);
      glVertex2f(35,40);
   glEnd();

   glBegin(GL_QUADS);
      glVertex2f(35,0);
      glVertex2f(35, 50);
      glVertex2f( 50, 50);
      glVertex2f( 50,0);
   glEnd();
}

void house(){
    parede();
    glTranslatef(0,0,50);
    parede();
    glPopMatrix();
    glRotatef(90,0,1,0);
    parede_with_door();
    glPopMatrix();
    glTranslatef(0,0,50);
    parede();
    glPopMatrix();
    telhado();
    glPopMatrix();
    glRotatef(90,0,1,0);
    glTranslatef(0,0,50);
    telhado();
    glPopMatrix();
    glRotatef(180,0,1,0);
    glTranslatef(-50,0,50);
    telhado();
    glPopMatrix();
    glRotatef(270,0,1,0);
    glTranslatef(-50,0,0);    
    telhado();
    glPopMatrix();
    glTranslatef(-5,0,0); 
    glTranslatef(20,0,0);
    door();
    glPopMatrix();
}

// Inicializa parâmetros de rendering
void Inicializa(void)
{
    // Define a cor de fundo da janela de visualização como preta
    glClearColor(0, 255, 255, 0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glutWarpPointer(400,300);
    glutSetCursor(GLUT_CURSOR_NONE);
}

void DISPLAY(void)
{
    glMatrixMode(GL_PROJECTION);/*glMatrixMode()- define qual matriz será alterada. SEMPRE defina o tipo de apresentação
                              (Ortogonal ou Perspectiva) na matriz PROJECTION.*/
    glLoadIdentity();//"Limpa" ou "transforma" a matriz em identidade, reduzindo possíveis erros.
    if (projecao==1)
    {
        glOrtho(-200, 200, -200, 200, -200, 200);  //Define a projeção como ortogonal
        if (rotacao=1)
            glRotatef(angulox,1.0,0.0,0.0);
        if (rotacao=2)
            glRotatef(anguloy,0.0,1.0,0.0);
    }
    if (projecao == 0)
    {
        gluPerspective(90,1,1,500); //Define a projeção como perspectiva
        if (rotacao=1)
            glRotatef(angulox,1.0,0.0,0.0);
        if (rotacao=2)
            glRotatef(anguloy,0.0,1.0,0.0);
    }

    glMatrixMode(GL_MODELVIEW);/*glMatrixMode()- define qual matriz será alterada. SEMPRE defina a câmera
                              (Ortogonal ou Perspectiva) na matriz MODELVIEW (onde o desenho ocorrerá).*/
    glLoadIdentity(); ////"Limpa" ou "transforma" a matriz em identidade, reduzindo possíveis erros.

    gluLookAt(posx,posy,posz,ox,oy,oz,lx,ly,lz); //Define a pos da câmera, para onde olha e qual eixo está na vertical.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); /* "limpa" um buffer particular ou combinações de buffers,
                                                         onde buffer é uma área de armazenamento para informações da imagem.
                                                        Nesse caso, está "limpando os buffers para suportarem animações */
    DesenharCena();
    glutSwapBuffers();
    glutPostRedisplay();
}

void DesenharCena ()
{
    /*Crosta Terrestre*/
    glColor3ub(100,200,0);
    glPushMatrix();
    glTranslatef(0,0,0);
    glScalef(60,0.01,60);
    glutSolidCube(20);
    glPopMatrix();
    /******/
    house();
}

void MOUSE_Button(int botao, int estado, int x, int y)
{
    //botão - recebe o código do botão pressionado
    //estado - recebe se está pressionado ou não
    //x, y - recebem respectivamente as posições do cursor do mouse
    switch (botao)
    {
    case GLUT_LEFT_BUTTON:
        if (estado == GLUT_DOWN)
        {
            projecao=1;
            posx=0;
            posy=0;
            posz=20;
            ox=0,oy=0,oz=0;
            lx=0, ly=1,lz=0;
            glutPostRedisplay();
        }
        break;

    case GLUT_RIGHT_BUTTON:
        if(estado == GLUT_DOWN)
        {
            projecao=0;
            posx=0;
            posy=30;
            posz=200;
            oy=30;
            ox=0;
            oz=0;
            lx=0, ly=1, lz=0;
            glutPostRedisplay();
        }
        break;
    }
}

void MOUSE(int x, int y)
{
    if (x > x_temp)
    {
        anguloy=anguloy+(x/100);
        if(anguloy > 360.0)
            anguloy = anguloy-360;
        rotacao = 2;
        glutPostRedisplay();
    }
    if (x < x_temp)
    {
        anguloy=anguloy-(x/100);
        if(anguloy > 360.0)
            anguloy = anguloy-360;
        rotacao = 2;
        glutPostRedisplay();
    }
    x_temp=x;
    if (y>y_temp)
    {
        angulox=angulox+(y/100);
        if(angulox > 360.0)
            angulox = angulox-360;
        rotacao = 1;
       glutPostRedisplay();
    }
    if (y<y_temp)
    {
        angulox=angulox-(y/100);
        if(angulox > 360.0)
            angulox = angulox-360;
        rotacao = 1;
        glutPostRedisplay();
    }
    y_temp = y;
    if(x>=500 || x<=300 || y>=400 || y<=200) //delimitar uma area de acesso ao mouse de 600x450
    {
        glutWarpPointer(400,300);
        glutPostRedisplay();
    }
    
}

void keyboard(unsigned char tecla, int x, int y)
{
    switch(tecla)
    {
    case 's':
        posx=posx+(5*cos((anguloy+90)/57.32));
        posz=posz+(5*sin((anguloy+90)/57.32));
        ox=ox+(5*cos((anguloy+90)/57.32));
        oz=oz+(5*sin((anguloy+90)/57.32));
        glutPostRedisplay();
        break;

    case 'w':
        posx=posx-(5*cos((anguloy+90)/57.32));
        posz=posz-(5*sin((anguloy+90)/57.32));
        ox=ox-(5*cos((anguloy+90)/57.32));
        oz=oz-(5*sin((anguloy+90)/57.32));
        glutPostRedisplay();
        break;

    case 'd':
        posx=posx+(5*sin((anguloy+90)/57.32));
        posz=posz-(5*cos((anguloy+90)/57.32));
        ox=ox+(5*sin((anguloy+90)/57.32));
        oz=oz-(5*cos((anguloy+90)/57.32));
        glutPostRedisplay();
        break;

    case 'a':
        posx=posx-(5*sin((anguloy+90)/57.32));
        posz=posz+(5*cos((anguloy+90)/57.32));
        ox=ox-(5*sin((anguloy+90)/57.32));
        oz=oz+(5*cos((anguloy+90)/57.32));
        glutPostRedisplay();
        break;
    case 'e':
        if (angulo == 0) portaAbrindo = 1;   // começa abrir
        else if (angulo == 90) portaAbrindo = -1; // começa fechar
    break;
    case 27:
        exit(0);
        break;
    default:
        break;
    }
}

void TeclasEspeciais (int key, int x, int y)
{
    //Key - recebe o código ASCII da tecla
//x, y - recebem respectivamente as posições do cursor do mouse (permite tratar os dois dispositivos)
    if (key==GLUT_KEY_PAGE_UP)
    {
        posy+=5;
        oy+=5;
    }
    else if (key==GLUT_KEY_PAGE_DOWN)
    {
        posy-=5;
        oy-=5;
    }
    glutPostRedisplay();
}

int main(int argc, char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_STENCIL); /*Define as características do espaço vetorial.
                                                                        //  Nesse caso, permite animações (sem cintilações), cores compostas por Verm. Verde e Azul,
                                                                //  Buffer que permite trablhar com profundidade e elimina faces escondidas.*/
    glutInitWindowSize(800,600);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("Aula 07");
    Inicializa();
    glutDisplayFunc(DISPLAY);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(MOUSE_Button);
    glutPassiveMotionFunc(MOUSE);
    glutSpecialFunc(TeclasEspeciais);
    glutIdleFunc(atualizaPorta);
    glutMainLoop();
    return 0;
}
#include <windows.h>
#include <GL/glut.h>
#include <cmath>

int init(void){
    glClearColor(1.0,1.0,1.0,1.0); // Cor de fundo preta

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10.0,10.0,-10.0,12.0);
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);


    // Desenha a faixa verde à esquerda
    glColor3f(0.0, 0.5, 0.0);  // Verde
    glBegin(GL_POLYGON);
        glVertex2f(-1.0, 1.0);
        glVertex2f(0.0, 1.0);
        glVertex2f(0.0, -1.0);
        glVertex2f(-1.0, -1.0);
    glEnd();

    // Desenha a faixa amarela no meio
    glColor3f(1.0, 1.0, 0.0);  // Amarelo
    glBegin(GL_POLYGON);
        glVertex2f(0.0, 1.0);
        glVertex2f(1.0, 1.0);
        glVertex2f(1.0, -1.0);
        glVertex2f(0.0, -1.0);
    glEnd();

    // Desenha a faixa vermelha à direita
    glColor3f(1.0, 0.0, 0.0);  // Vermelho
    glBegin(GL_POLYGON);
        glVertex2f(0.0, 1.0);
        glVertex2f(1.0, 1.0);
        glVertex2f(1.0, -1.0);
        glVertex2f(0.0, -1.0);
    glEnd();


    glutSwapBuffers();
}

int main(int argc, char**  argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(400,300);
    glutCreateWindow("Bandeira: Senegal");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

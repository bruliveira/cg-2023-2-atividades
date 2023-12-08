#include <windows.h>
#include <GL/glut.h>

int init(void){
    glClearColor(0.0,0.0,0.0,0.0); // Cor de fundo preta

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10.0,10.0,-10.0,12.0);
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BITS);

    glBegin(GL_TRIANGLES);
        glColor3f(0.0,1.0,0.0); //Verde
        glVertex3f(-6, -6, 0.0);

        glColor3f(0.0,0.0,1.0); //Azul
        glVertex3f(0, 10, 0.0);

        glColor3f(1.0,0.0,0.0); //Red
        glVertex3f(6, -6, 0.0);
    glEnd();
    glutSwapBuffers();
}

int main(int argc, char**  argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(400,300);
    glutCreateWindow("Questão 01 - Triângulo");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

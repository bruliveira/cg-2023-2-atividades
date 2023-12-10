#include <windows.h>
#include <GL/glut.h>

int init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-2.0,2.0,-2.0,2.0);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 0.0); // Amarelo
    glBegin(GL_QUADS);
        glVertex2f(-1.0, 0.33);
        glVertex2f(1.0, 0.33);
        glVertex2f(1.0, 1.0);
        glVertex2f(-1.0, 1.0);
    glEnd();

    glColor3f(0.0, 0.0, 1.0); // Azul
    glBegin(GL_QUADS);
        glVertex2f(-1.0, -0.33);
        glVertex2f(1.0, -0.33);
        glVertex2f(1.0, 0.33);
        glVertex2f(-1.0, 0.33);
    glEnd();

    glColor3f(1.0, 0.0, 0.0); // Vermelho
    glBegin(GL_QUADS);
        glVertex2f(-1.0, -1.0);
        glVertex2f(1.0, -1.0);
        glVertex2f(1.0, -0.33);
        glVertex2f(-1.0, -0.33);
    glEnd();

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400,300);
    glutInitWindowPosition(50, 0);
    glutCreateWindow("Bandeira: México");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

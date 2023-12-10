#include <windows.h>
#include <GL/glut.h>

int init(void){
    glClearColor(1.0,1.0,1.0,0.0); // Cor de fundo branca
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2.0,2.0,-2.0,2.0);
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 0.0); // Preto - Topo
    glBegin(GL_QUADS);
        glVertex2f(-1.0, 0.33);
        glVertex2f(1.0, 0.33);
        glVertex2f(1.0, 1.0);
        glVertex2f(-1.0, 1.0);
    glEnd();

    glColor3f(1.0, 0.0, 0.0); // Meio - Vermelho
    glBegin(GL_QUADS);
        glVertex2f(-1.0, -0.33);
        glVertex2f(1.0, -0.33);
        glVertex2f(1.0, 0.33);
        glVertex2f(-1.0, 0.33);
    glEnd();

    glColor3f(1.0, 1.0, 0.0); // Amarelo - inferior
    glBegin(GL_QUADS);
        glVertex2f(-1.0, -1.0);
        glVertex2f(1.0, -1.0);
        glVertex2f(1.0, -0.33);
        glVertex2f(-1.0, -0.33);
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char**  argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(400,300);
    glutCreateWindow("Bandeira: Alemanha");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

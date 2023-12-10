#include <windows.h>
#include <GL/glut.h>

int init(void){
    glClearColor(1.0,1.0,1.0,0.0); // Cor de fundo branca

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10.0,10.0,-10.0,10.0);
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0); // red

    glBegin(GL_QUADS); // Cabeça
        glVertex2f(-1, 6);
        glVertex2f(1, 6);
        glVertex2f(1, 8);
        glVertex2f(-1, 8);
    glEnd();

    glLineWidth(4.0); // Deixar as linhas mais grossas
    glBegin(GL_LINES); // Corpo
        glVertex2f(0.0, 6);
        glVertex2f(0, 2);
    glEnd();

    glBegin(GL_LINES); // Pernas
        glVertex2f(0.0, 2.0);
        glVertex2f(-2.0, -1.0);
    glEnd();
    glBegin(GL_LINES); // Pernas
        glVertex2f(0.0, 2.0);
        glVertex2f(2.0, -1.0);
    glEnd();

    glBegin(GL_LINES); // Braços
        glVertex2f(0.0, 5.0);
        glVertex2f(-2.5, 4.0);
    glEnd();
    glBegin(GL_LINES); // Braços
        glVertex2f(0.0, 5.0);
        glVertex2f(2.5, 4.0);
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char**  argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(400,300);
    glutCreateWindow("Boneco - palito");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

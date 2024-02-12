#include <windows.h>
#include <stdio.h>
#include <GL/glut.h>

int valorX = 0;
int valorY = 0;

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // Define a cor de fundo

    glMatrixMode(GL_PROJECTION); // Carrega a matriz de projeção
    glLoadIdentity(); // Matriz identidade
    gluOrtho2D(-100.0, 100.0, -100.0, 100.0); // Define a janela de recorte
}

void desenhaObjeto() {
    glBegin(GL_TRIANGLES);
    glVertex2i(50, -50);
    glVertex2i(0, 50);
    glVertex2i(-50, -50);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2i(-99, -99);
    glVertex2i(99, -99);
    glVertex2i(99, 99);
    glVertex2i(-99, 99);
    glEnd();
}

void desenhaPonto(int x, int y) {
    glColor3f(0.0f, 0.0f, 1.0f);
    glPointSize(5.0f);
    glBegin(GL_POINTS);
        glVertex2i(x, y);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Primeira viewport
    glViewport(20, 20, 200, 200);
    glColor3f(1.0f, 0.0f, 0.0f);
    desenhaObjeto();
    desenhaPonto(valorX, valorY);

    // Segunda viewport
    glViewport(250, 20, 100, 100);
    glColor3f(0.0f, 1.0f, 0.0f);
    glRotatef(90, 0, 0, 1);
    desenhaObjeto();
    desenhaPonto(valorX, valorY);

    // Extras - verificar
    printf("\nValores de X e Y: (%d, %d)\n", valorX, valorY);
    printf("Viewport 1 (vermelha): (%d, %d, %d, %d)\n", 20, 20, 200, 200);
    printf("Viewport 2 (verde): (%d, %d, %d, %d)\n", 250, 20, 100, 100);

    glFlush();
}

void mouseCallback(int button, int state, int x_screen, int y_screen) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        int viewport[4];
        glGetIntegerv(GL_VIEWPORT, viewport);
        valorX = x_screen - viewport[0] + 130;
        valorY = viewport[3] - y_screen + viewport[1] + 60;
        glutPostRedisplay();
    }
}

int main(int argc, char **argv) {
    glutInit(&argc, argv); // Inicializa o glut
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Modo de display
    glutInitWindowPosition(200, 0);
    glutInitWindowSize(400, 300); // Largura e altura da janela de exibição
    glutCreateWindow("Atividade - ViewPort"); // Criação da janela de exibição

    init();
    glutMouseFunc(mouseCallback);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

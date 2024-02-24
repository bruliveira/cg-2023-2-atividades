#include <windows.h>
#include <gl/gl.h>
#include <GL/freeglut.h>

int init(){
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //Define a cor de fundo
    glEnable(GL_DEPTH_TEST); //Habilita o teste de profundidade

    glMatrixMode(GL_MODELVIEW); //Define que a matrix � a model view
    glLoadIdentity(); //Carrega a matrix de identidade
    gluLookAt(0.8, 0.25, 0.4,  //Posi��o da camera
              0.0, 0.0, 0.0,  //Onde a camera aponta
              0.0, 1.0, 0.0); //Vetor view-up

    glMatrixMode(GL_PROJECTION); //Define que a matrix � a de proje��o
    glLoadIdentity(); //Carrega a matrix de identidade

    gluPerspective(60.0, 1.0, 0.1, 10.0); // Define uma proje��o perspectiva

    //glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0); //Define a proje��o ortogonal

}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Limpa o buffer
    glMatrixMode(GL_MODELVIEW); //Define que a matrix � a de modelo
    //Desenha um cubo
    glColor3f(1.0f, 0.0f, 0.0f);
    glutWireCube(0.3f);

    glFlush(); //For�a o desenha das primitivas
}

int main(int argc, char** argv){
    glutInit(&argc, argv); //Inicializa o GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); //COnfigura o modo de display
    glutInitWindowPosition(200, 0); //Seta a posi��o inicial da janela
    glutInitWindowSize(500, 500); // Largura e altura da janela de exibi��o
    glutCreateWindow("Proje��o perspectiva sim�trica"); // Cria a janela de exibi��o

    init(); //Executa fun�a� de inicializa��o
    glutDisplayFunc(display);
    glutMainLoop(); //Mostra tudo e espera
    return 0;
}


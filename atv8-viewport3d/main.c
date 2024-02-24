#include <windows.h>
#include <gl/gl.h>
#include <GL/freeglut.h>

int init(){
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //Define a cor de fundo
    glEnable(GL_DEPTH_TEST); //Habilita o teste de profundidade

    glMatrixMode(GL_MODELVIEW); //Define que a matrix é a model view
    glLoadIdentity(); //Carrega a matrix de identidade
    gluLookAt(0.8, 0.25, 0.4,  //Posição da camera
              0.0, 0.0, 0.0,  //Onde a camera aponta
              0.0, 1.0, 0.0); //Vetor view-up

    glMatrixMode(GL_PROJECTION); //Define que a matrix é a de projeção
    glLoadIdentity(); //Carrega a matrix de identidade

    gluPerspective(60.0, 1.0, 0.1, 10.0); // Define uma projeção perspectiva

    //glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0); //Define a projeção ortogonal

}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Limpa o buffer
    glMatrixMode(GL_MODELVIEW); //Define que a matrix é a de modelo
    //Desenha um cubo
    glColor3f(1.0f, 0.0f, 0.0f);
    glutWireCube(0.3f);

    glFlush(); //Força o desenha das primitivas
}

int main(int argc, char** argv){
    glutInit(&argc, argv); //Inicializa o GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); //COnfigura o modo de display
    glutInitWindowPosition(200, 0); //Seta a posição inicial da janela
    glutInitWindowSize(500, 500); // Largura e altura da janela de exibição
    glutCreateWindow("Projeção perspectiva simétrica"); // Cria a janela de exibição

    init(); //Executa funçaõ de inicialização
    glutDisplayFunc(display);
    glutMainLoop(); //Mostra tudo e espera
    return 0;
}


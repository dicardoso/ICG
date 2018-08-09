#include <GL/gl.h>
#include <GL/glut.h>
#define op 5
void ponto(int a[]){//OP = 1
    glBegin(GL_POINTS);
        glColor3f(1,0,0);
        glVertex2d(100,150);
    glEnd();

    glBegin(GL_POINTS);
        glColor3f(1,0,0);
    glEnd();
}

void linha(int a[],int b[]){//OP = 2
    glBegin(GL_LINES);
        glColor3f(0,0,1);
        glVertex2d(a[0],a[1]);
        glVertex2d(b[0],b[1]);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(1,0,0);
        glVertex2d(a[0],a[1]);
        glVertex2d(b[0],b[1]);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0,1,0);
        glVertex2d(a[0],a[1]);
        glVertex2d(b[0],b[1]);
    glEnd();
}

void triComplicado (int a[], int b[], int c[]){//OP 3
    glBegin(GL_LINES);
        glColor3f(1,0,0);
        glVertex2d(a[0],a[1]);
        glVertex2d(b[0],b[1]);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(1,0,0);
        glVertex2d(a[0],a[1]);
        glVertex2d(c[0],c[1]);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(1,0,0);
        glVertex2d(c[0],c[1]);
        glVertex2d(b[0],b[1]);
    glEnd();
}

void triSimples(int a[], int b[], int c[]){//OP = 4
    glBegin(GL_LINE_LOOP);
        glColor3f(1,0,0);
        glVertex2d(a[0],a[1]);
        glVertex2d(b[0],b[1]);
        glVertex2d(c[0],c[1]);
    glEnd();
}

void triPreenchido(int a[], int b[], int c[]){//OP = 5
    glBegin(GL_TRIANGLES);                                   // início triângulo
        glColor3f(1,0,0);
        glVertex3f(a[0],a[1],0.0f);                          // Topo
        glVertex3f(b[0],b[1],0.0f);                          // Esquerda embaixo
        glVertex3f(c[0],c[1],0.0f);                          // Direita embaixo
    glEnd();                                                 // fim triângulo
}
void draw (){
    glClear(GL_COLOR_BUFFER_BIT); //limpar o buffer

    glMatrixMode(GL_PROJECTION);//faz uma projeção
    glLoadIdentity();//carrega a projeção

    gluOrtho2D(-7,7,-7,7);//limita o plano
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    int centro[2] = {0,0};//baricentro
    int a[2],b[2],c[2];

    int d = 2;//distancia do centro ao ponto

    a[0] = 2;//centro[0]+d;
    a[1] = 2;//centro[1];

    b[0] = centro[0];
    b[1] = centro[1];

    c[0] = centro[0];
    c[1] = centro[1]+d;


    /*OPÇÕES PARA APRESENTAR
    1 - Ponto
    2 - Linha
    3 - Triângulo mais complicado
    4 - Triângulo simples
    5 - Triângulo preenchido
    */
    switch (op){
    case 1:
        ponto(a);
        break;
    case 2:
        linha(a,b);
        break;
    case 3:
        triComplicado(a,b,c);
        break;
    case 4:
        triSimples(a,b,c);
        break;
    case 5:
        triPreenchido(a,b,c);
        break;
    }
    glFlush();
}

int main (){
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(512,512);
    /*
    Calcular o centro da tela

    Resolução da tela (X pixels, Y pixels)
    Tamanho da janela (a,b)

    Centro ((X-a)/2, (y-b)/2)
    */
    glutInitWindowPosition(268,84);

    glutCreateWindow("Aplicação OpenGL");
    glutDisplayFunc(draw);
    glClearColor(0,0,0,0); //cor de fundo
    glutMainLoop();
    return 0;
}

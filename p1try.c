#include <stdio.h>
#include <GL/glut.h>

int X1, Y1, X2, Y2;

void LineBres() {
    int dx = abs(X2 - X1), dy = abs(Y2 - Y1);
    int p = 2 * dy - dx, x = X1, y = Y1;
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    while (x < X2) {
        x++;
        p += (p < 0) ? 2 * dy : 2 * (dy - dx) + (y++, 0);
        glVertex2i(x, y);
    }
    glEnd();
    glFlush();
}

void Init() {
    gluOrtho2D(0, 50, 0, 50);
}

int main(int argc, char **argv) {
    scanf("%d%d%d%d", &X1, &Y1, &X2, &Y2);
    glutInit(&argc, argv);
    glutCreateWindow("Line Bresenham");
    Init();
    glutDisplayFunc(LineBres);
    glutMainLoop();
    return 0;
}

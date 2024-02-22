#include <GL/glut.h>///第18行

void display()
{
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}

int main(int argc, char *argv[])///第134行
{
    glutInit(&argc, argv);///第140行
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///第143行
    glutCreateWindow("GLUT Shapes");///第145行
    glutDisplayFunc(display);///第148行

    glutMainLoop();///第174行
}

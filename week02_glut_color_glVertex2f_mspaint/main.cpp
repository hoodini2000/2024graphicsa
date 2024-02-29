#include <GL/glut.h>
void display()
{
    glBegin(GL_POLYGON);
        glVertex2d((34-200)/200.0,-(76-200)/200.0);
        glVertex2d((48-200)/200.0,-(131-200)/200.0);
        glVertex2d((85-200)/200.0,-(59-200)/200.0);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2d((383-200)/200.0,-(79-200)/200.0);
        glVertex2d((348-200)/200.0,-(146-200)/200.0);
        glVertex2d((312-200)/200.0,-(55-200)/200.0);

    glEnd();
    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week02_glut_color_triangle");
    glutDisplayFunc(display);

    glutMainLoop();
}

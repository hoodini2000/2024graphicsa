#include <GL/glut.h> ///��18��d�U��,�ϥ�GLUT�~��
void display()
{
    glColor3f(247/255.0,180/255.0,171/255.0);
    glutSolidTeapot( 0.3 );

    glColor3f(251/255.0,233/255.0,219/255.0);
    glutSolidTeapot( 0.2 );

    glutSwapBuffers();
}

int main(int argc, char *argv[])///��138��,main()�禡
{
    glutInit(&argc, argv);///��140��,�}��GLUT�\��
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///��143��
    glutCreateWindow("2024�q���Ͼǲ�01�g");///��145��,�}�@��GLUT����
    glutDisplayFunc(display);///148��, �n��display()�禡�ӵe��

       glutMainLoop();///174��,�D�n���j��,�b�o�̤@���B�@,������
}

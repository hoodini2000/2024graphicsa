#include <GL/glut.h> ///第18行留下來,使用GLUT外掛
void display()
{
    glColor3f(247/255.0,180/255.0,171/255.0);
    glutSolidTeapot( 0.3 );

    glColor3f(251/255.0,233/255.0,219/255.0);
    glutSolidTeapot( 0.2 );

    glutSwapBuffers();
}

int main(int argc, char *argv[])///第138行,main()函式
{
    glutInit(&argc, argv);///第140行,開啟GLUT功能
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///第143行
    glutCreateWindow("2024電腦圖學第01週");///第145行,開一個GLUT視窗
    glutDisplayFunc(display);///148行, 要用display()函式來畫圖

       glutMainLoop();///174行,主要的迴圈,在這裡一直運作,不結束
}

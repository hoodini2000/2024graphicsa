#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
 #include <GL/glut.h>
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
#include <GL/glut.h>
#include "glm.h"
GLMmodel * pmodel = NULL;
GLMmodel * handA = NULL;
GLMmodel * handB = NULL;
GLMmodel * upperA = NULL;
GLMmodel * lowerA = NULL;
GLMmodel * upperB = NULL;
GLMmodel * lowerB = NULL;
GLMmodel * body = NULL;
GLMmodel * head = NULL;
GLMmodel * footA = NULL;
GLMmodel * footB = NULL;

void drawhead(void)
{
    if (!head) {
	head  = glmReadOBJ("data/head.obj");
	if (!head) exit(0);
	glmUnitize(head);
	glmFacetNormals(head);
	glmVertexNormals(head, 90.0);
    }
    glPushMatrix();
        glScalef(1.2,1.2,1.2);
        glmDraw(head, GLM_SMOOTH );
    glPopMatrix();
}
void drawBody(void)
{
    if (!body) {
	body  = glmReadOBJ("data/body.obj");
	if (!body) exit(0);
	glmUnitize(body);
	glmFacetNormals(body);
	glmVertexNormals(body, 90.0);
    }

    glmDraw(body, GLM_SMOOTH );
}
void drawUpperA(void)
{
    if (!upperA) {
	upperA  = glmReadOBJ("data/upperA.obj");
	if (!upperA) exit(0);
	glmUnitize(upperA);
	glmFacetNormals(upperA);
	glmVertexNormals(upperA, 90.0);
    }

    glmDraw(upperA, GLM_SMOOTH  );
}
void drawUpperB(void)
{
    if (!upperB) {
	upperB  = glmReadOBJ("data/upperB.obj");
	if (!upperB) exit(0);
	glmUnitize(upperB);
	glmFacetNormals(upperB);
	glmVertexNormals(upperB, 90.0);
    }

    glmDraw(upperB, GLM_SMOOTH  );
}
void drawLowerA(void)
{
    if (!lowerA) {
	lowerA= glmReadOBJ("data/lowerA.obj");
	if (!lowerA) exit(0);
	glmUnitize(lowerA);
	glmFacetNormals(lowerA);
	glmVertexNormals(lowerA, 90.0);
    }

    glmDraw(lowerA, GLM_SMOOTH );
}
void drawLowerB(void)
{
    if (!lowerB) {
	lowerB= glmReadOBJ("data/lowerB.obj");
	if (!lowerB) exit(0);
	glmUnitize(lowerB);
	glmFacetNormals(lowerB);
	glmVertexNormals(lowerB, 90.0);
    }

    glmDraw(lowerB, GLM_SMOOTH );
}
void drawhandA(void)
{
    if (!handA) {
	handA= glmReadOBJ("data/handA.obj");
	if (!handA) exit(0);
	glmUnitize(handA);
	glmFacetNormals(handA);
	glmVertexNormals(handA, 90.0);
    }

    glmDraw(handA, GLM_SMOOTH );
}
void drawhandB(void)
{
    if (!handB) {
	handB= glmReadOBJ("data/handB.obj");
	if (!handB) exit(0);
	glmUnitize(handB);
	glmFacetNormals(handB);
	glmVertexNormals(handB, 90.0);
    }

    glmDraw(handB, GLM_SMOOTH );
}
void drawfootA(void)
{
    if (!footA) {
	footA  = glmReadOBJ("data/footA.obj");
	if (!footA) exit(0);
	glmUnitize(footA);
	glmFacetNormals(footA);
	glmVertexNormals(footA, 90.0);
    }
    glPushMatrix();
            glScalef(0.35,0.35,0.35);
            glmDraw(footA, GLM_SMOOTH );
        glPopMatrix();
    }

void drawfootB(void)
{
    if (!footB) {
	footB  = glmReadOBJ("data/footB.obj");
	if (!footB) exit(0);
	glmUnitize(footB);
	glmFacetNormals(footB);
	glmVertexNormals(footB, 90.0);
    }
    glPushMatrix();
            glScalef(0.35,0.35,0.35);
            glmDraw(footB, GLM_SMOOTH );
        glPopMatrix();
}
void myBody()
{
    glPushMatrix();
        glColor3f(1,0,0);
        glutSolidCube(0.6);///myBody()
	glPopMatrix();
}
///float angle = 0,da=1; ///加這行, 讓它轉動
float angle[20]={};
int angleID=0;
int oldX=0,oldY=0;
#include <stdio.h>
FILE * fin = NULL;
FILE * fout = NULL;
void motion(int x, int y){
    angle[angleID]+=y-oldY;
    oldX=x;
    oldY=y;
    glutPostRedisplay();
    /*
    if(fout==NULL) fout = fopen("angle.txt", "w+");
    for(int i=0; i<20; i++){
        printf("%.1f", angle[i]);
        fprintf(fout, "%.1f ", angle[i]);
    }
    printf("\n");
    fprintf(fout, "\n");
    */
}
void mouse(int button,int state,int x, int y){
    oldX=x;
    oldY=y;
}

void keyboard(unsigned char key,int x,int y){
    if(key=='r'){
        if(fin==NULL) fin = fopen("angle.txt", "r");
        for(int i=0; i<20; i++){
            fscanf(fin,"%f", &angle[i]);
        }
        glutPostRedisplay();
    }
    if(key=='0')angleID=0;
    if(key=='1')angleID=1;
    if(key=='2')angleID=2;
    if(key=='3')angleID=3;
    if(key=='4')angleID=4;
    if(key=='5')angleID=5;
    if(key=='6')angleID=6;
    if(key=='7')angleID=7;
    if(key=='8')angleID=8;
    if(key=='9')angleID=9;
}
void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // 设置背景颜色为白色
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // 清除颜色缓冲区和深度缓冲区

    ///angle+=da;
    ///if(angle>90)da=-1;
    ///if(angle<0)da=+1;
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glDisable(GL_TEXTURE_2D);
    ///glutSolidSphere(0.1,30,30);
    glEnable(GL_TEXTURE_2D);
    glColor3f(1 ,1 ,1 );

    glPushMatrix();
        glTranslatef(0,0.35,0);
        glRotatef(angle[0],0,1,0);
        glRotatef(angle[3],0,1,0);
        glTranslatef(0,0,0.025);
        drawhead();
    glPopMatrix();

    glPushMatrix();
        glRotatef(angle[0],0,1,0);
        drawBody();
        glColor3f(1,1,1);

    glPushMatrix();
        ///glColor3f(1,0,0);
        glTranslatef(-0.16,0.18,0);
        glRotatef(angle[1],0,0,1);
        glTranslatef(-0.12,0,0.025);
        drawUpperA();
        glPushMatrix(); ///加這行, 讓它轉動
            glTranslatef(-0.1,0.03,0);
            glRotatef(angle[1],0,0,1);
            glRotatef(angle[2],0,1,0);
            glTranslatef(-0.1,-0.03,0);
            drawLowerA();
                glPushMatrix();
                    glTranslatef(-0.1,0,0);
                    glRotatef(angle[1],0,0,1);
                    glRotatef(angle[4],0,0,1);
                    glTranslatef(-0.07,0,0);
                    drawhandA();
            glPopMatrix();
        glPopMatrix(); ///加這行, 讓它轉動
        glPopMatrix();

     glPushMatrix();
        ///glColor3f(1,0,0);
        glTranslatef(0.16,0.18,0);
        glRotatef(angle[5],0,0,1);
        glTranslatef(0.12,0,0.025);
        drawUpperB();
        glPushMatrix(); ///加這行, 讓它轉動
            glTranslatef(0.1,0.03,0);
            glRotatef(angle[5],0,0,1);
            glRotatef(angle[6],0,1,0);
            glTranslatef(0.1,-0.03,0);
            drawLowerB();
                glPushMatrix();
                    glTranslatef(0.1,0,0);
                    glRotatef(angle[5],0,0,1);
                    glRotatef(angle[7],0,0,1);
                    glTranslatef(0.07,0,0);
                    drawhandB();
            glPopMatrix();
        glPopMatrix(); ///加這行, 讓它轉動
     glPopMatrix();

            glPushMatrix();
                glTranslatef(-0.05,-0.23,0.08);
                glRotatef(angle[8],1,0,0);
                glTranslatef(0,-0.3,0);
                drawfootA();
            glPopMatrix();
            glPushMatrix();
                glTranslatef(0.05,-0.23,0.08);
                glRotatef(angle[9],1,0,0);
                glTranslatef(0,-0.3,0);
                drawfootB();
            glPopMatrix();

glPopMatrix();
    glutSwapBuffers();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };///加這行, 讓它轉動

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

int main(int argc, char*argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week13");
    glutDisplayFunc(display);
    glutIdleFunc(display); ///加這行, 讓它轉動
    glutMotionFunc(motion);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);

    myTexture("data/Diffuse.jpg");

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();
}

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include<stdlib.h>
#define STARS_NUM 400
using namespace std;

typedef struct Star{
    float x;
    float y;
}STAR;
STAR st[STARS_NUM];
STAR sT[STARS_NUM];
STAR St[STARS_NUM];

//float iposition = 0.0;
//int state =1;
float RandomNumber(float Min, float Max);

float colR;
float colG;
float colB;

float speedYst = 0.0004;
float speedYsT = 0.0008;
float speedYSt = 0.002;

float positionbu = 0.0;
float positionxy = 0.0;
float positionXY = 0.0;

float movex = 0.0;
float movey = 0.0;

void update(int value) {
    positionbu += 0.01;
	glutPostRedisplay();
	glutTimerFunc(20, update, 0);
}


void SpecialInput(int key, int x, int y){
    switch(key){
        case GLUT_KEY_UP:
            if(positionXY > 1.6)
                positionXY = 1.65;
            else
                positionXY += 0.05f;
            break;
        case GLUT_KEY_DOWN:
            if(positionXY < -1.65)
                positionXY = -1.7;
        else
                positionXY += -0.05f;
            break;
        case GLUT_KEY_LEFT:
            if(positionxy < -1.75)
                positionxy = -1.8;
            else
                positionxy += -0.05f;
            break;
        case GLUT_KEY_RIGHT:
            if(positionxy > 1.75)
                positionxy = 1.8;
            else
                positionxy += 0.05f;
            break;
    }
    glutPostRedisplay();
}
void moveY(){
    for (int i=0;i<STARS_NUM;i++){
        if (st[i].y<=-1){
            st[i].y=1;
        }
        if (sT[i].y<=-1){
            sT[i].y=1;
        }
        if (St[i].y<=-1){
            St[i].y=1;
        }

        st[i].y-=speedYst;
        sT[i].y-=speedYsT;
        St[i].y-=speedYSt;

    }
}



void display(){

    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glPointSize(1);
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f);
    for(int i=0;i<STARS_NUM;i++){
        glVertex2f(st[i].x,st[i].y);
    }
    moveY();
    glEnd();

    glPointSize(2);
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f);
    for(int i=0;i<STARS_NUM;i++){
        glVertex2f(sT[i].x,sT[i].y);
    }
    moveY();
    glEnd();

    glPointSize(2);
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f);
    for(int i=0;i<STARS_NUM;i++){
        glVertex2f(St[i].x,St[i].y);
    }
    //moveY();
    glEnd();

    glPushMatrix();

    //glTranslatef(positionxy, positionXY, 0.0);

    //glBegin(GL_POINTS);
        //while(true){
            //glColor3f(0.5, 0.5, 1.0);
            //glVertex3f(0.0, positionbu, 0.0);
        //}
    //glEnd();

    glScalef(0.5,0.5,0.0);
    glTranslatef(positionxy, positionXY, 0.0);

    glBegin(GL_POLYGON);
        glColor3f(0.5, 0.5, 0.5);

        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, 0.37, 0.0);
        glVertex3f(0.02, 0.325, 0.0);
        glVertex3f(0.02, 0.2, 0.0);
        glVertex3f(0.04, 0.175, 0.0);
        glVertex3f(0.06, 0.2, 0.0);
        glVertex3f(0.06, 0.075, 0.0);
        glVertex3f(0.08, 0.025, 0.0);
        glVertex3f(0.2, -0.05, 0.0);
        glVertex3f(0.2, -0.125, 0.0);
        glVertex3f(0.08, -0.15, 0.0);
        glVertex3f(0.09, -0.175, 0.0);
        glVertex3f(0.14, -0.25, 0.0);
        glVertex3f(0.14, -0.275, 0.0);
        glVertex3f(0.03, -0.3, 0.0);
        glVertex3f(0.03, -0.25, 0.0);
        glVertex3f(0.02, -0.275, 0.0);
        glVertex3f(-0.00, -0.275, 0.0);

        glVertex3f(-0.00, -0.275, 0.0);
        glVertex3f(-0.02, -0.275, 0.0);
        glVertex3f(-0.03, -0.25, 0.0);
        glVertex3f(-0.03, -0.3, 0.0);
        glVertex3f(-0.14, -0.275, 0.0);
        glVertex3f(-0.14, -0.25, 0.0);
        glVertex3f(-0.09, -0.175, 0.0);
        glVertex3f(-0.08, -0.15, 0.0);
        glVertex3f(-0.2, -0.125, 0.0);
        glVertex3f(-0.2, -0.05, 0.0);
        glVertex3f(-0.08, 0.025, 0.0);
        glVertex3f(-0.06, 0.075, 0.0);
        glVertex3f(-0.06, 0.2, 0.0);
        glVertex3f(-0.04, 0.175, 0.0);
        glVertex3f(-0.02, 0.2, 0.0);
        glVertex3f(-0.02, 0.325, 0.0);
        glVertex3f(-0.0, 0.37, 0.0);

   glEnd();





glPopMatrix();


    glutSwapBuffers();
    //glFlush();
}

float RandomNumber(float Min, float Max){
    return((float(rand()))/(float(RAND_MAX))*(Max-Min))+Min;
}

void init_Pos_Stars(){
    for (int i=0;i<STARS_NUM;i++){
        st[i].x=RandomNumber(-1,1);
        st[i].y=RandomNumber(-1,1);
        sT[i].x=RandomNumber(-1,1);
        sT[i].y=RandomNumber(-1,1);
        St[i].x=RandomNumber(-1,1);
        St[i].y=RandomNumber(-1,1);

    }
}





void reshape(int w,int h){
    glViewport(0.0,0.0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0,1.0,-1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
}
//void timer(int);

void init(){
    glClearColor(1.0,0.0,0.0,1.0);
    glColor3f(1.0,1.0,1.0);
}
void initGL(){
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

int main (int argc,char**argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    //glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(600,100);
    glutInitWindowSize(700,700);
    glutCreateWindow("JoJo");

    //init_Pos_Stars();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(SpecialInput);
    glutTimerFunc(0,update,0);
    init();
    initGL();
    glutMainLoop();
}



/*
void timer(int){
    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,0);

    switch(state){
    case 1:
        if(iposition<0.8)
            iposition+=0.01;
        else
            state=-1;
        break;
    case -1:
        if(iposition>-1)
            iposition-=0.01;
        else
            state=1;
        break;
    }
}
*/


#include <Windows.h>
#include<math.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#include<stdlib.h>
#include<mmsystem.h>

using namespace std;

float dn1a = 0.12734375;
float dn1b = 0.7046878;
float dn1c = 0.99765625;
float dn2a = 1.0;
float dn2b = 1.0;
float dn2c = 1.0;



float _run = 0.0;
float _run1 = 0.0;
float _run2 = 0.0;
float _run3 = 0.0;
float _rain = 0.0;
float _nt = 0.0;
float _ang_tri = 0.0;
char text[] = "saif";


bool onOff;
bool frd = false;
bool bck = false;

bool rainday = false;
bool night = false;


//float _angle = 0.0;
//float _cameraAngle = 0.0;
//float _run = 0.0;

void Sprint(float x, float y, char* st)
{
	int l, i;


	l = strlen(st); // see how many characters are in text string.
	glColor3f(1.0, 0.0, 0.0);
	//glDisable(GL_LIGHTING);
	glRasterPos2f(x, y); // location to start printing text
	for (i = 0; i < l; i++) // loop until i is greater then l
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, st[i]);

	}
}



void init() {

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1280.0, 0.0, 960.0);

}


void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3ub(120, 105, 78);
	glPointSize(5.0);
	//sky
	if (night == false)


	{	//sky
		glColor3f(dn2a, dn2b, dn2c);
		glBegin(GL_POLYGON);
		glVertex2f(0, 650);
		glColor3f(dn1a, dn1b, dn1c);
		glVertex2f(0, 1000);
		glColor3f(dn1a, dn1b, dn1c);
		glVertex2f(1400, 1000);
		glColor3f(dn2a, dn2b, dn2c);
		glVertex2f(1400, 650);
		glEnd();

		///sun
		glPushMatrix();

		glTranslatef(1000, 600, 0);
		glScalef(1, 1, 0);


		glBegin(GL_POLYGON);
		glColor3ub(0, 0, 0);
		for (GLfloat i = 0; i < 360; i += 5)
		{
			glVertex2f(50 * sin(i * 3.1416 / 180), 50 * cos(i * 3.1416 / 180));
		}
		glEnd();
		glPopMatrix();

	}




	glColor3ub(120, 105, 78);
	glPointSize(5.0);
	glBegin(GL_QUADS);

	//hills
	//hill 1

	glColor3ub(85, 107, 17);
	glVertex2i(0, 650);
	glVertex2i(80, 650);
	glVertex2i(0, 800);
	glVertex2i(3, 700);


	//hill3
	glVertex2i(100, 650);
	glVertex2i(700, 650);
	glVertex2i(320, 820);
	glVertex2i(200, 750);
	//hill 2
	glVertex2i(60, 650);
	glVertex2i(120, 650);
	glVertex2i(100, 700);
	glVertex2i(69, 680);
	//hill4
	glVertex2i(600, 650);
	glVertex2i(1400, 650);
	glVertex2i(1020, 720);
	glVertex2i(800, 750);


	//field
	glBegin(GL_QUADS);

	if (night == true) { glColor3ub(0, 100, 0); }
	else
	{
		glColor3ub(0, 255, 0);
	}
	glVertex2i(0, 0);
	glVertex2i(1300, 0);
	glVertex2i(1300, 650);
	glVertex2i(0, 650);

	//tree14(upper)
	//body
	glBegin(GL_QUADS);
	glColor3ub(118, 92, 72);
	glVertex2i(804, 540);
	glVertex2i(812, 540);
	glVertex2i(812, 570);
	glVertex2i(804, 570);

	//head1
	glBegin(GL_TRIANGLES);
	glColor3ub(11, 83, 69);
	glVertex2i(780, 570);
	glVertex2i(840, 570);
	glVertex2i(807, 600);
	glVertex2i(806, 600);
	//head2
	glVertex2i(780, 580);
	glVertex2i(840, 580);
	glVertex2i(807, 620);
	glVertex2i(806, 620);
	//head3
	glVertex2i(780, 600);
	glVertex2i(840, 600);
	glVertex2i(807, 660);
	glVertex2i(806, 660);
	//head4
	glVertex2i(780, 620);
	glVertex2i(840, 620);
	glVertex2i(807, 680);
	glVertex2i(806, 680);

	//tree10(upper)
	//body
	glBegin(GL_QUADS);
	glColor3ub(118, 92, 72);
	glVertex2i(564, 540);
	glVertex2i(572, 540);
	glVertex2i(572, 570);
	glVertex2i(564, 570);

	//head1
	glBegin(GL_TRIANGLES);
	glColor3ub(11, 83, 69);
	glVertex2i(540, 570);
	glVertex2i(600, 570);
	glVertex2i(567, 600);
	glVertex2i(566, 600);
	//head2
	glVertex2i(540, 580);
	glVertex2i(600, 580);
	glVertex2i(567, 620);
	glVertex2i(566, 620);
	//head3
	glVertex2i(540, 600);
	glVertex2i(600, 600);
	glVertex2i(567, 660);
	glVertex2i(566, 660);
	//head4
	glVertex2i(540, 620);
	glVertex2i(600, 620);
	glVertex2i(567, 680);
	glVertex2i(566, 680);



	//tree6(upper)
	//body
	glBegin(GL_QUADS);
	glColor3ub(118, 92, 72);
	glVertex2i(324, 540);
	glVertex2i(332, 540);
	glVertex2i(332, 570);
	glVertex2i(324, 570);

	//head1
	glBegin(GL_TRIANGLES);
	glColor3ub(11, 83, 69);
	glVertex2i(300, 570);
	glVertex2i(360, 570);
	glVertex2i(327, 600);
	glVertex2i(326, 600);
	//head2
	glVertex2i(300, 580);
	glVertex2i(360, 580);
	glVertex2i(327, 620);
	glVertex2i(326, 620);
	//head3
	glVertex2i(300, 600);
	glVertex2i(360, 600);
	glVertex2i(327, 660);
	glVertex2i(326, 660);
	//head4
	glVertex2i(300, 620);
	glVertex2i(360, 620);
	glVertex2i(327, 680);
	glVertex2i(326, 680);

	//station
	glPushMatrix();
	glTranslatef(0, 50, 0);

	glColor3ub(210, 105, 30);   //BODY
	glBegin(GL_QUADS);
	glVertex2i(575, 450);
	glVertex2i(575, 525);
	glVertex2i(825, 525);
	glVertex2i(825, 450);
	glEnd();

	glColor3ub(77, 77, 219);   //ROOF
	glBegin(GL_QUADS);
	glVertex2i(550, 525);
	glVertex2i(600, 560);
	glVertex2i(800, 560);
	glVertex2i(850, 525);
	glEnd();

	glColor3ub(139, 137, 143);    //STAIR
	glBegin(GL_QUADS);
	glVertex2i(565, 440);
	glVertex2i(565, 450);
	glVertex2i(835, 450);
	glVertex2i(835, 440);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);   //DOOR
	glBegin(GL_QUADS);
	glVertex2i(690, 450);
	glVertex2i(690, 500);
	glVertex2i(710, 500);
	glVertex2i(710, 450);
	glEnd();

	if (night == true) { glColor3ub(255, 255, 0); }
	else {
		glColor3f(0.38, 0.21, 0.26);
	}  //Left Windows
	glBegin(GL_QUADS);
	glVertex2i(595, 475);
	glVertex2i(595, 500);
	glVertex2i(615, 500);
	glVertex2i(615, 475);
	glEnd();

	if (night == true) { glColor3ub(255, 255, 0); }
	else {
		glColor3f(0.38, 0.21, 0.26);
	}
	glBegin(GL_QUADS);
	glVertex2i(635, 475);
	glVertex2i(635, 500);
	glVertex2i(655, 500);
	glVertex2i(655, 475);
	glEnd();

	if (night == true) { glColor3ub(255, 255, 0); }
	else {
		glColor3f(0.38, 0.21, 0.26);
	}  //Right Windows
	glBegin(GL_QUADS);
	glVertex2i(805, 475);
	glVertex2i(805, 500);
	glVertex2i(785, 500);
	glVertex2i(785, 475);
	glEnd();

	if (night == true) { glColor3ub(255, 255, 0); }
	else {
		glColor3f(0.38, 0.21, 0.26);
	}
	glBegin(GL_QUADS);
	glVertex2i(765, 500);
	glVertex2i(745, 500);
	glVertex2i(745, 475);
	glVertex2i(765, 475);
	glEnd();

	glPopMatrix();



	//text school
	glColor3f(1.0, 1.0, 1.0);    //QUAD
	glBegin(GL_QUADS);
	glVertex2i(675, 520);
	glVertex2i(735, 520);
	glVertex2i(735, 500);
	glVertex2i(675, 500);
	glEnd();


	glPushMatrix();
	glTranslatef(680, 505, 0);
	Sprint(1.0, 0, text);
	glPopMatrix();
	// end of text

	///rail line
	glColor3ub(150, 150, 144);
	glBegin(GL_QUADS);
	glVertex2i(0, 380);
	glVertex2i(0, 405);
	glVertex2i(1280, 405);
	glVertex2i(1280, 380);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(0, 402);
	glVertex2i(1280, 402);
	glVertex2i(1280, 405);
	glVertex2i(0, 405);

	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(0, 380);
	glVertex2i(1280, 380);
	glVertex2i(1280, 384);
	glVertex2i(0, 384);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_LINES);
	float j;
	for (j = 0; j <= 1280; j += 20) //rail line
	{
		glVertex2i(10 + j, 380);
		glVertex2i(15 + j, 405);

	}
	glEnd();








	glPopMatrix();


	///Making of Rail Body

	glPushMatrix();
	glTranslatef(_ang_tri, 0.0, 0.0);

	glColor3ub(0, 0, 255);
	glBegin(GL_QUADS);
	glVertex2i(100, 400);
	glVertex2i(170, 400);
	glVertex2i(170, 450);
	glVertex2i(100, 450);
	glEnd();

	if (night == true) { glColor3ub(255, 255, 0); }
	else {
		glColor3f(1.0, 1.0, 1.0);
	}
	glBegin(GL_QUADS);
	glVertex2i(110, 425);
	glVertex2i(120, 425);
	glVertex2i(120, 440);
	glVertex2i(110, 440);
	glEnd();

	if(night == true) { glColor3ub(255, 255, 0); }
	else {
	glColor3f(1.0, 1.0, 1.0);
	}
	glBegin(GL_QUADS);
	glVertex2i(130, 425);
	glVertex2i(140, 425);
	glVertex2i(140, 440);
	glVertex2i(130, 440);
	glEnd();

	if (night == true) { glColor3ub(255, 255, 0); }
	else {
		glColor3f(1.0, 1.0, 1.0);
	}
	glBegin(GL_QUADS);
	glVertex2i(150, 425);
	glVertex2i(160, 425);
	glVertex2i(160, 440);
	glVertex2i(150, 440);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2i(100, 410);
	glVertex2i(170, 410);
	glVertex2i(170, 415);
	glVertex2i(100, 415);
	glEnd();

	glColor3ub(0, 0, 255);
	glBegin(GL_QUADS);
	glVertex2i(170, 400);
	glVertex2i(176, 410);
	glVertex2i(176, 460);
	glVertex2i(170, 450);
	glEnd();


	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2i(101, 450);
	glVertex2i(170, 450);
	glVertex2i(176, 460);
	glVertex2i(105, 460);
	glEnd();

	glPushMatrix();
	glTranslatef(115, 392, 0.0);
	glBegin(GL_POLYGON);
	glColor3ub(0, 0, 0);
	for (int i = 0; i < 200; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 200;
		float r = 10;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(155, 392, 0.0);
	glBegin(GL_POLYGON);
	glColor3ub(0, 0, 0);
	for (int i = 0; i < 200; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 200;
		float r = 10;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(75, 0, 0);

	glColor3ub(0, 0, 255);
	glBegin(GL_QUADS);
	glVertex2i(100, 400);
	glVertex2i(170, 400);
	glVertex2i(170, 450);
	glVertex2i(100, 450);
	glEnd();

	if (night == true) { glColor3ub(255, 255, 0); }
	else {
		glColor3f(1.0, 1.0, 1.0);
	}
	glBegin(GL_QUADS);
	glVertex2i(110, 425);
	glVertex2i(120, 425);
	glVertex2i(120, 440);
	glVertex2i(110, 440);
	glEnd();

	if (night == true) { glColor3ub(255, 255, 0); }
	else {
		glColor3f(1.0, 1.0, 1.0);
	}
	glBegin(GL_QUADS);
	glVertex2i(130, 425);
	glVertex2i(140, 425);
	glVertex2i(140, 440);
	glVertex2i(130, 440);
	glEnd();

	if (night == true) { glColor3ub(255, 255, 0); }
	else {
		glColor3f(1.0, 1.0, 1.0);
	}
	glBegin(GL_QUADS);
	glVertex2i(150, 425);
	glVertex2i(160, 425);
	glVertex2i(160, 440);
	glVertex2i(150, 440);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2i(100, 410);
	glVertex2i(170, 410);
	glVertex2i(170, 415);
	glVertex2i(100, 415);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2i(170, 400);
	glVertex2i(176, 410);
	glVertex2i(176, 460);
	glVertex2i(170, 450);
	glEnd();


	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2i(101, 450);
	glVertex2i(170, 450);
	glVertex2i(176, 460);
	glVertex2i(105, 460);
	glEnd();

	glPushMatrix();
	glTranslatef(115, 392, 0.0);
	glBegin(GL_POLYGON);
	glColor3ub(0, 0, 0);
	for (int i = 0; i < 200; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 200;
		float r = 10;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(155, 392, 0.0);
	glBegin(GL_POLYGON);
	glColor3ub(0, 0, 0);
	for (int i = 0; i < 200; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 200;
		float r = 10;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();
	glPopMatrix();

	glPopMatrix();



	glPushMatrix();
	glTranslatef(-75, 0, 0);

	glColor3ub(0, 0, 255);
	glBegin(GL_QUADS);
	glVertex2i(100, 400);
	glVertex2i(170, 400);
	glVertex2i(170, 450);
	glVertex2i(100, 450);
	glEnd();

	if (night == true) { glColor3ub(255, 255, 0); }
	else {
		glColor3f(1.0, 1.0, 1.0);
	}
	glBegin(GL_QUADS);
	glVertex2i(110, 425);
	glVertex2i(120, 425);
	glVertex2i(120, 440);
	glVertex2i(110, 440);
	glEnd();

	if (night == true) { glColor3ub(255, 255, 0); }
	else {
		glColor3f(1.0, 1.0, 1.0);
	}
	glBegin(GL_QUADS);
	glVertex2i(130, 425);
	glVertex2i(140, 425);
	glVertex2i(140, 440);
	glVertex2i(130, 440);
	glEnd();

	if (night == true) { glColor3ub(255, 255, 0); }
	else {
		glColor3f(1.0, 1.0, 1.0);
	}
	glBegin(GL_QUADS);
	glVertex2i(150, 425);
	glVertex2i(160, 425);
	glVertex2i(160, 440);
	glVertex2i(150, 440);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2i(100, 410);
	glVertex2i(170, 410);
	glVertex2i(170, 415);
	glVertex2i(100, 415);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2i(170, 400);
	glVertex2i(176, 410);
	glVertex2i(176, 460);
	glVertex2i(170, 450);
	glEnd();


	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2i(101, 450);
	glVertex2i(170, 450);
	glVertex2i(176, 460);
	glVertex2i(105, 460);
	glEnd();

	glPushMatrix();
	glTranslatef(115, 392, 0.0);
	glBegin(GL_POLYGON);
	glColor3ub(0, 0, 0);
	for (int i = 0; i < 200; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 200;
		float r = 10;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(155, 392, 0.0);
	glBegin(GL_POLYGON);
	glColor3ub(0, 0, 0);
	for (int i = 0; i < 200; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 200;
		float r = 10;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	glTranslatef(150, 0, 0);

	glColor3ub(0, 0, 255);
	glBegin(GL_QUADS);
	glVertex2i(100, 400);
	glVertex2i(170, 400);
	glVertex2i(170, 450);
	glVertex2i(100, 450);
	glEnd();

	if (night == true) { glColor3ub(255, 255, 0); }
	else {
		glColor3f(1.0, 1.0, 1.0);
	}
	glBegin(GL_QUADS);
	glVertex2i(110, 425);
	glVertex2i(120, 425);
	glVertex2i(120, 440);
	glVertex2i(110, 440);
	glEnd();

	if (night == true) { glColor3ub(255, 255, 0); }
	else {
		glColor3f(1.0, 1.0, 1.0);
	}
	glBegin(GL_QUADS);
	glVertex2i(130, 425);
	glVertex2i(140, 425);
	glVertex2i(140, 440);
	glVertex2i(130, 440);
	glEnd();

	if (night == true) { glColor3ub(255, 255, 0); }
	else {
		glColor3f(1.0, 1.0, 1.0);
	}
	glBegin(GL_QUADS);
	glVertex2i(150, 425);
	glVertex2i(160, 425);
	glVertex2i(160, 440);
	glVertex2i(150, 440);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2i(100, 410);
	glVertex2i(170, 410);
	glVertex2i(170, 415);
	glVertex2i(100, 415);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2i(170, 400);
	glVertex2i(176, 410);
	glVertex2i(176, 460);
	glVertex2i(170, 450);
	glEnd();


	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2i(101, 450);
	glVertex2i(170, 450);
	glVertex2i(176, 460);
	glVertex2i(105, 460);
	glEnd();

	glPushMatrix();
	glTranslatef(115, 392, 0.0);
	glBegin(GL_POLYGON);
	glColor3ub(0, 0, 0);
	for (int i = 0; i < 200; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 200;
		float r = 10;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(155, 392, 0.0);
	glBegin(GL_POLYGON);
	glColor3ub(0, 0, 0);
	for (int i = 0; i < 200; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 200;
		float r = 10;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();
	glPopMatrix();

	glPopMatrix();

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2i(322, 445);
	glVertex2i(330, 445);
	glVertex2i(330, 432);
	glVertex2i(322, 432);
	glEnd();

	glColor3f(0.325, 0.101, 0.619);
	glBegin(GL_QUADS);
	glVertex2i(310, 453);
	glVertex2i(300, 453);
	glVertex2i(300, 458);
	glVertex2i(310, 458);
	glEnd();

	glPushMatrix();
	glTranslatef(303, 467, 0.0);
	glBegin(GL_POLYGON);
	glColor3f(0.709, 0.701, 0.717);
	for (int i = 0; i < 200; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 200;
		float r = 3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(293, 470, 0.0);
	glBegin(GL_POLYGON);
	glColor3f(0.709, 0.701, 0.717);
	for (int i = 0; i < 200; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 200;
		float r = 4;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(283, 472, 0.0);
	glBegin(GL_POLYGON);
	glColor3f(0.709, 0.701, 0.717);
	for (int i = 0; i < 200; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 200;
		float r = 5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();
	glPopMatrix();

	glPopMatrix();

	///End of Making of Rail Body



	glPopMatrix();
	glPopMatrix();

	glPopMatrix();

	///sun
	glPushMatrix();

	glTranslatef(1100, 850, 0);
	glScalef(1, 1, 0);


	glBegin(GL_POLYGON);
	if(night == true){
		glColor3ub(255, 255, 255);
	}
	else {
		glColor3ub(255, 255, 0);
	}
	for (GLfloat i = 0; i < 360; i += 5)
	{
		glVertex2f(50 * sin(i * 3.1416 / 180), 50 * cos(i * 3.1416 / 180));
	}
	glEnd();
	glPopMatrix();


	///Cloud

	glPushMatrix();
	glTranslatef(_run3, 0.0, 0.0);

	glPushMatrix();
	glTranslatef(200, 800, 0);

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	for (int i = 0; i < 200; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 200;
		float r = 40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(180, 750, 0);

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	for (int i = 0; i < 200; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 200;
		float r = 50;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(250, 800, 0);

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	for (int i = 0; i < 200; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 200;
		float r = 40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(230, 750, 0);

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	for (int i = 0; i < 200; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 200;
		float r = 50;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();
	glPopMatrix();

	//cloud 2
	glPushMatrix();
	glTranslatef(350, 100, 0);
	glPushMatrix();
	glTranslatef(200, 800, 0);

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	for (int i = 0; i < 200; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 200;
		float r = 40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(180, 750, 0);

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	for (int i = 0; i < 200; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 200;
		float r = 50;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(250, 800, 0);

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	for (int i = 0; i < 200; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 200;
		float r = 50;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(230, 750, 0);

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	for (int i = 0; i < 200; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 200;
		float r = 50;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(300, 800, 0);

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	for (int i = 0; i < 200; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 200;
		float r = 40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(290, 760, 0);

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	for (int i = 0; i < 200; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 200;
		float r = 40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();
	//end of cloud
	//tree18(upper)
	//body
	glBegin(GL_QUADS);
	glColor3ub(118, 92, 72);
	glVertex2i(1044, 540);
	glVertex2i(1052, 540);
	glVertex2i(1052, 570);
	glVertex2i(1044, 570);

	//head1
	glBegin(GL_TRIANGLES);
	glColor3ub(11, 83, 69);
	glVertex2i(1020, 570);
	glVertex2i(1080, 570);
	glVertex2i(1047, 600);
	glVertex2i(1046, 600);
	//head2
	glVertex2i(1020, 580);
	glVertex2i(1080, 580);
	glVertex2i(1047, 620);
	glVertex2i(1046, 620);
	//head3
	glVertex2i(1020, 600);
	glVertex2i(1080, 600);
	glVertex2i(1047, 660);
	glVertex2i(1046, 660);
	//head4
	glVertex2i(1020, 620);
	glVertex2i(1080, 620);
	glVertex2i(1047, 680);
	glVertex2i(1046, 680);



	//tree18
	//body
	glBegin(GL_QUADS);
	glColor3ub(118, 92, 72);
	glVertex2i(1044, 340);
	glVertex2i(1052, 340);
	glVertex2i(1052, 370);
	glVertex2i(1044, 370);

	//head1
	glBegin(GL_TRIANGLES);
	glColor3ub(11, 83, 69);
	glVertex2i(1020, 370);
	glVertex2i(1080, 370);
	glVertex2i(1047, 400);
	glVertex2i(1046, 400);
	//head2
	glVertex2i(1020, 380);
	glVertex2i(1080, 380);
	glVertex2i(1047, 420);
	glVertex2i(1046, 420);
	//head3
	glVertex2i(1020, 400);
	glVertex2i(1080, 400);
	glVertex2i(1047, 460);
	glVertex2i(1046, 460);
	//head4
	glVertex2i(1020, 420);
	glVertex2i(1080, 420);
	glVertex2i(1047, 480);
	glVertex2i(1046, 480);


	//tree14
	//body
	glBegin(GL_QUADS);
	glColor3ub(118, 92, 72);
	glVertex2i(804, 340);
	glVertex2i(812, 340);
	glVertex2i(812, 370);
	glVertex2i(804, 370);

	//head1
	glBegin(GL_TRIANGLES);
	glColor3ub(11, 83, 69);
	glVertex2i(780, 370);
	glVertex2i(840, 370);
	glVertex2i(807, 400);
	glVertex2i(806, 400);
	//head2
	glVertex2i(780, 380);
	glVertex2i(840, 380);
	glVertex2i(807, 420);
	glVertex2i(806, 420);
	//head3
	glVertex2i(780, 400);
	glVertex2i(840, 400);
	glVertex2i(807, 460);
	glVertex2i(806, 460);
	//head4
	glVertex2i(780, 420);
	glVertex2i(840, 420);
	glVertex2i(807, 480);
	glVertex2i(806, 480);

	//tree10
	//body
	glBegin(GL_QUADS);
	glColor3ub(118, 92, 72);
	glVertex2i(564, 340);
	glVertex2i(572, 340);
	glVertex2i(572, 370);
	glVertex2i(564, 370);

	//head1
	glBegin(GL_TRIANGLES);
	glColor3ub(11, 83, 69);
	glVertex2i(540, 370);
	glVertex2i(600, 370);
	glVertex2i(567, 400);
	glVertex2i(566, 400);
	//head2
	glVertex2i(540, 380);
	glVertex2i(600, 380);
	glVertex2i(567, 420);
	glVertex2i(566, 420);
	//head3
	glVertex2i(540, 400);
	glVertex2i(600, 400);
	glVertex2i(567, 460);
	glVertex2i(566, 460);
	//head4
	glVertex2i(540, 420);
	glVertex2i(600, 420);
	glVertex2i(567, 480);
	glVertex2i(566, 480);

	//tree6
	//body
	glBegin(GL_QUADS);
	glColor3ub(118, 92, 72);
	glVertex2i(324, 340);
	glVertex2i(332, 340);
	glVertex2i(332, 370);
	glVertex2i(324, 370);

	//head1
	glBegin(GL_TRIANGLES);
	glColor3ub(11, 83, 69);
	glVertex2i(300, 370);
	glVertex2i(360, 370);
	glVertex2i(327, 400);
	glVertex2i(326, 400);
	//head2
	glVertex2i(300, 380);
	glVertex2i(360, 380);
	glVertex2i(327, 420);
	glVertex2i(326, 420);
	//head3
	glVertex2i(300, 400);
	glVertex2i(360, 400);
	glVertex2i(327, 460);
	glVertex2i(326, 460);
	//head4
	glVertex2i(300, 420);
	glVertex2i(360, 420);
	glVertex2i(327, 480);
	glVertex2i(326, 480);

	//tree2
	//body
	glBegin(GL_QUADS);
	glColor3ub(118, 92, 72);
	glVertex2i(84, 340);
	glVertex2i(92, 340);
	glVertex2i(92, 370);
	glVertex2i(84, 370);
	//head1
	glBegin(GL_TRIANGLES);
	glColor3ub(11, 83, 69);
	glVertex2i(60, 370);
	glVertex2i(120, 370);
	glVertex2i(87, 400);
	glVertex2i(86, 400);
	//head2
	glVertex2i(60, 380);
	glVertex2i(120, 380);
	glVertex2i(87, 420);
	glVertex2i(86, 420);
	//head3
	glVertex2i(60, 400);
	glVertex2i(120, 400);
	glVertex2i(87, 460);
	glVertex2i(86, 460);
	//head4
	glVertex2i(60, 420);
	glVertex2i(120, 420);
	glVertex2i(87, 480);
	glVertex2i(86, 480);
	glEnd();

	///river



	glPushMatrix();

	glColor3ub(152, 222, 245);
	glBegin(GL_QUADS);
	glVertex2i(0, 0);
	glVertex2i(1280, 0);
	glVertex2i(1280, 150);
	glVertex2i(0, 150);
	glEnd();

	glPopMatrix();


	//riverbank


	glPushMatrix();

	glColor3ub(194, 178, 128);
	glBegin(GL_QUADS);
	glVertex2i(0, 150);
	glVertex2i(1280, 150);
	glVertex2i(1100, 130);
	glVertex2i(10, 130);
	glEnd();

	glPopMatrix();

	///house
	glBegin(GL_POLYGON);
	glColor3f(.990, 0.0, 0.0);
	glVertex2i(285, 305);
	glVertex2i(285, 330);
	glVertex2i(380, 315);
	glVertex2i(380, 305);

	glEnd();

	///House_Roof_Shadow
	glBegin(GL_POLYGON);
	glColor3f(.890, 0.0, 0.0);
	glVertex2i(285, 305);
	glVertex2i(285, 320);
	glVertex2i(380, 305);
	glVertex2i(380, 305);

	glEnd();

	///House_Fence
	glBegin(GL_POLYGON);
	glColor3f(.555, 1.0, 1.0);
	glVertex2i(290, 270);
	glVertex2i(290, 304);
	glVertex2i(375, 304);
	glVertex2i(375, 270);

	glEnd();

	///House_Fence_Shadow
	glBegin(GL_POLYGON);
	glColor3f(.555, 0.924, 0.930);
	glVertex2i(310, 270);
	glVertex2i(350, 304);
	glVertex2i(375, 304);
	glVertex2i(375, 270);

	glEnd();

	///House_Door
	glBegin(GL_POLYGON);
	glColor3f(0.38, 0.41, 0.36);
	glVertex2i(330, 270);
	glVertex2i(330, 300);
	glVertex2i(350, 300);
	glVertex2i(350, 270);

	glEnd();

	///House_Window1
	glBegin(GL_POLYGON);
	if (night == true) { glColor3ub(255, 255, 0); }
	else {
		glColor3f(0.38, 0.21, 0.26);
	}
	glVertex2i(295, 275);
	glVertex2i(295, 290);
	glVertex2i(310, 290);
	glVertex2i(310, 275);

	glEnd();

	///House_Window2
	glBegin(GL_POLYGON);
	if (night == true) { glColor3ub(255, 255, 0); }
	else {
		glColor3f(0.38, 0.21, 0.26);
	}
	glVertex2i(312, 275);
	glVertex2i(312, 290);
	glVertex2i(327, 290);
	glVertex2i(327, 275);

	glEnd();

	///House_Window3
	glBegin(GL_POLYGON);
	if (night == true) { glColor3ub(255, 255, 0); }
	else {
		glColor3f(0.38, 0.21, 0.26);
	}
	glVertex2i(355, 275);
	glVertex2i(355, 290);
	glVertex2i(370, 290);
	glVertex2i(370, 275);

	glEnd();

	///House_Small_Roof
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(250, 290);
	glVertex2i(257, 304);
	glVertex2i(290, 304);
	glVertex2i(290, 290);

	glEnd();

	///House_Small_Fence
	glBegin(GL_POLYGON);
	glColor3f(.555, .724, .930);
	glVertex2i(255, 270);
	glVertex2i(255, 290);
	glVertex2i(290, 290);
	glVertex2i(290, 270);

	glEnd();

	///House_Small_Door
	glBegin(GL_POLYGON);
	glColor3f(0.11, 0.23, 0.36);
	glVertex2i(260, 270);
	glVertex2i(260, 280);
	glVertex2i(285, 280);
	glVertex2i(285, 270);

	glEnd();

	//house2
	///house
	glBegin(GL_POLYGON);
	glColor3f(.990, 0.0, 0.0);
	glVertex2i(585, 305);
	glVertex2i(585, 330);
	glVertex2i(680, 315);
	glVertex2i(680, 305);

	glEnd();

	///House_Roof_Shadow
	glBegin(GL_POLYGON);
	glColor3f(.890, 0.0, 0.0);
	glVertex2i(585, 305);
	glVertex2i(585, 320);
	glVertex2i(680, 305);
	glVertex2i(680, 305);

	glEnd();

	///House_Fence
	glBegin(GL_POLYGON);
	glColor3f(.555, 1.0, 1.0);
	glVertex2i(590, 270);
	glVertex2i(590, 304);
	glVertex2i(675, 304);
	glVertex2i(675, 270);

	glEnd();

	///House_Fence_Shadow
	glBegin(GL_POLYGON);
	glColor3f(.555, 0.924, 0.930);
	glVertex2i(610, 270);
	glVertex2i(650, 304);
	glVertex2i(675, 304);
	glVertex2i(675, 270);

	glEnd();

	///House_Door
	glBegin(GL_POLYGON);
	glColor3f(0.38, 0.41, 0.36);
	glVertex2i(630, 270);
	glVertex2i(630, 300);
	glVertex2i(650, 300);
	glVertex2i(650, 270);

	glEnd();

	///House_Window1
	glBegin(GL_POLYGON);
	if (night == true) { glColor3ub(255, 255, 0); }
	else {
		glColor3f(0.38, 0.21, 0.26);
	}
	glVertex2i(595, 275);
	glVertex2i(595, 290);
	glVertex2i(610, 290);
	glVertex2i(610, 275);

	glEnd();

	///House_Window2
	glBegin(GL_POLYGON);
	if (night == true) { glColor3ub(255, 255, 0); }
	else {
		glColor3f(0.38, 0.21, 0.26);
	}
	glVertex2i(612, 275);
	glVertex2i(612, 290);
	glVertex2i(627, 290);
	glVertex2i(627, 275);

	glEnd();

	///House_Window3
	glBegin(GL_POLYGON);
	if (night == true) { glColor3ub(255, 255, 0); }
	else {
		glColor3f(0.38, 0.21, 0.26);
	}
	glVertex2i(655, 275);
	glVertex2i(655, 290);
	glVertex2i(670, 290);
	glVertex2i(670, 275);

	glEnd();

	///House_Small_Roof
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(550, 290);
	glVertex2i(557, 304);
	glVertex2i(590, 304);
	glVertex2i(590, 290);

	glEnd();

	///House_Small_Fence
	glBegin(GL_POLYGON);
	glColor3f(.555, .724, .930);
	glVertex2i(555, 270);
	glVertex2i(555, 290);
	glVertex2i(590, 290);
	glVertex2i(590, 270);

	glEnd();

	///House_Small_Door
	glBegin(GL_POLYGON);
	glColor3f(0.11, 0.23, 0.36);
	glVertex2i(560, 270);
	glVertex2i(560, 280);
	glVertex2i(585, 280);
	glVertex2i(585, 270);

	glEnd();

	//house3
	///house
	glBegin(GL_POLYGON);
	glColor3f(.990, 0.0, 0.0);
	glVertex2i(885, 305);
	glVertex2i(885, 330);
	glVertex2i(980, 315);
	glVertex2i(980, 305);

	glEnd();

	///House_Roof_Shadow
	glBegin(GL_POLYGON);
	glColor3f(.890, 0.0, 0.0);
	glVertex2i(885, 305);
	glVertex2i(885, 320);
	glVertex2i(980, 305);
	glVertex2i(980, 305);

	glEnd();

	///House_Fence
	glBegin(GL_POLYGON);
	glColor3f(.555, 1.0, 1.0);
	glVertex2i(890, 270);
	glVertex2i(890, 304);
	glVertex2i(975, 304);
	glVertex2i(975, 270);

	glEnd();

	///House_Fence_Shadow
	glBegin(GL_POLYGON);
	glColor3f(.555, 0.924, 0.930);
	glVertex2i(910, 270);
	glVertex2i(950, 304);
	glVertex2i(975, 304);
	glVertex2i(975, 270);

	glEnd();

	///House_Door
	glBegin(GL_POLYGON);
	glColor3f(0.38, 0.41, 0.36);
	glVertex2i(930, 270);
	glVertex2i(930, 300);
	glVertex2i(950, 300);
	glVertex2i(950, 270);

	glEnd();

	///House_Window1
	glBegin(GL_POLYGON);
	if (night == true) { glColor3ub(255, 255, 0); }
	else {
		glColor3f(0.38, 0.21, 0.26);
	}
	glVertex2i(895, 275);
	glVertex2i(895, 290);
	glVertex2i(910, 290);
	glVertex2i(910, 275);

	glEnd();

	///House_Window2
	glBegin(GL_POLYGON);
	if (night == true) { glColor3ub(255, 255, 0); }
	else {
		glColor3f(0.38, 0.21, 0.26);
	}
	glVertex2i(912, 275);
	glVertex2i(912, 290);
	glVertex2i(927, 290);
	glVertex2i(927, 275);

	glEnd();

	///House_Window3
	glBegin(GL_POLYGON);
	if (night == true) { glColor3ub(255, 255, 0); }
	else {
		glColor3f(0.38, 0.21, 0.26);
	}
	glVertex2i(955, 275);
	glVertex2i(955, 290);
	glVertex2i(970, 290);
	glVertex2i(970, 275);

	glEnd();

	///House_Small_Roof
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(850, 290);
	glVertex2i(857, 304);
	glVertex2i(890, 304);
	glVertex2i(890, 290);

	glEnd();

	///House_Small_Fence
	glBegin(GL_POLYGON);
	glColor3f(.555, .724, .930);
	glVertex2i(855, 270);
	glVertex2i(855, 290);
	glVertex2i(890, 290);
	glVertex2i(890, 270);

	glEnd();

	///House_Small_Door
	glBegin(GL_POLYGON);
	glColor3f(0.11, 0.23, 0.36);
	glVertex2i(860, 270);
	glVertex2i(860, 280);
	glVertex2i(885, 280);
	glVertex2i(885, 270);

	glEnd();

	///fish moving right
	glPushMatrix();
	glTranslatef(_run, 0.0, 0.0);

	///fish 1

	glColor3ub(105, 105, 105);
	glBegin(GL_TRIANGLES);
	glVertex2i(130, 40);
	glVertex2i(150, 60);
	glVertex2i(130, 80);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2i(130, 40);
	glVertex2i(130, 80);
	glVertex2i(80, 60);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2i(82, 60);
	glVertex2i(60, 75);
	glVertex2i(60, 45);
	glEnd();

	glPopMatrix();

	///bird

	glPushMatrix();
	glTranslatef(_run2, 0.0, 0.0);
	glColor3ub(244,164,96);

	glBegin(GL_TRIANGLES);
	glVertex2i(300, 860);
	glVertex2i(320, 870);
	glVertex2i(300, 880);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2i(300, 860);
	glVertex2i(300, 880);
	glVertex2i(250, 860);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2i(300, 880);
	glVertex2i(270, 920);
	glVertex2i(265, 860);
	glEnd();

	glPopMatrix();

	glFlush();
	glutSwapBuffers();
}


void update(int value) {

	_run += 1.0f;
	if (_run > 1000)
	{
		_run -= 1700;
	}

	_run1 += 1.0f;
	if (_run1 > 1000)
	{
		_run1 -= 1300;
	}

	_run2 += 3.5f;
	if (_run2 > 1000)
	{
		_run2 -= 1300;
	}

	_run3 += 0.8f;
	if (_run3 > 1000)
	{
		_run3 -= 1700;
	}

	if (onOff) {
		_ang_tri += 2.5f;
		if (_ang_tri > 1000) {
			_ang_tri = 1300;
		}
	}

	glutPostRedisplay(); //Tell GLUT that the display has changed
	glutTimerFunc(25, update, 0);
}


void railForward(int value) {

	if (frd) {

		_ang_tri += 2.2f;

		if (_ang_tri > 1000) {
			_ang_tri -= 1400;
		}

		glutPostRedisplay();
		glutTimerFunc(25, railForward, 0);
	}
}

void railBackward(int value) {
	if (bck) {

		_ang_tri -= 2.2f;

		if (_ang_tri < -350) {
			_ang_tri = 1100;
		}
		glutPostRedisplay();
		glutTimerFunc(25, railBackward, 0);
	}
}


void Rain(int value) {

	if (rainday) {

		_rain += 0.01f;

		glBegin(GL_POINTS);
		for (int i = 1; i <= 1280; i++)
		{
			int x = rand(), y = rand();
			x %= 1280; y %= 960;
			glBegin(GL_LINES);
			glColor3f(1.0, 1.0, 1.0);
			glVertex2d(x, y);
			glVertex2d(x + 5, y + 5);
			glEnd();
		}

		glutPostRedisplay();
		glutTimerFunc(5, Rain, 0);

		glFlush();

	}
}

void myKeyboard(unsigned char key, int x, int y) {
	switch (key)
	{
	case 'a':
		frd = false;
		bck = true;
		railBackward(_ang_tri);


		break;

	case 'd':
		frd = true;
		bck = false;
		railForward(_ang_tri);
		sndPlaySound("Train.wav", SND_ASYNC | SND_LOOP);
		break;

	case 's':
		frd = false;
		bck = false;
		break;

	case 'r':
		rainday = true;
		Rain(_rain);
		sndPlaySound("River.wav", SND_ASYNC | SND_LOOP);
		//sndPlaySound("River.wav",SND_MEMORY|SND_ASYNC);
		break;

	case 'e':
		rainday = false;
		sndPlaySound(NULL, SND_ASYNC);
		break;

	case 'n':
		night = true;
		sndPlaySound("Night.wav", SND_ASYNC | SND_LOOP);

		break;

	case 'b':
		night = false;

		break;





	case 27:     // ESC key
		exit(0);
		break;

	default:
		break;
	}
}



int main(int argc, char** argv)
{

	cout << endl << "*********** Natural Scenery ********************" << endl << endl;
	cout << "Press D : To Forward the Train" << endl << endl;
	cout << "Press A : To Backward the Train" << endl << endl;
	cout << "Press S : To Stop the Train" << endl << endl;

	cout << "Press R : For Rain " << endl << endl;
	cout << "Press E : For Stop Rain" << endl << endl;
	cout << "Press N : For Night " << endl << endl;
	cout << "Press B : For Day" << endl << endl;



	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1280, 960);
	glutInitWindowPosition(1, 10);
	glutCreateWindow("Natural View Of A Village0");     // creating the window
	glutDisplayFunc(display);
	glutKeyboardFunc(myKeyboard);
	glutTimerFunc(25, update, 0);
	init();
	glutMainLoop();
	return 0;
}
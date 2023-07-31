
#include <GL\glut.h>
#include <ctime>
#include<math.h>
void Circle(int x, int y, int rad, int mov, float r, float g, float b, bool fill);
void LinesCircle(int x, int y, int rad, float mov, float r, float g, float b);
void Car(int x, int y);
int x, y;
float i, j;
float Xcar = 1;
bool right = true;
float f = 0, fanP = .005; //for fans
float h = 0, s = 0, hTir = .02;
//	h for rotating car tires and s for sun
void greenRod()
{   glColor3f(0, 1, 0);
	glBegin(GL_POLYGON);
	glVertex2d(0, 400);
	glVertex2d(400, 400);
	glVertex2d(400, 350);
	glVertex2d(0, 350);
	glEnd();}
void Fan(int x, int y){
	float angle = 30, rad = 30;
	glColor3f(.8, 0, .9);
	glBegin(GL_POLYGON);
	glVertex2d(x, y);
	glVertex2d(x, y + 100);
	glVertex2d(x + 5, y + 100);
	glVertex2d(x + 5, y);
	glEnd();
	glColor3f(.8, .5, .5);
	for (int i = 0;i < 3;i++)
	{	glBegin(GL_POLYGON);
		glVertex2d(x + 2.5, y);
		glVertex2d(x + 2.5 + (rad * cos((angle + f) * 3.14 / 180)), y + (rad * sin((angle + f) * 3.14 / 180)));
		glVertex2d(x + 2.5 + (rad * cos(((angle + f) + 20) * 3.14 / 180)), y + (rad * sin(((angle + f) + 20) * 3.14 / 180)));
		angle += 120;
		glEnd();}
	angle = 30;
	for (int i = 0;i < 3;i++){
		glBegin(GL_POLYGON);
		glVertex2d(x + 2.5 + (rad * 2 * cos(((angle + f) + 10) * 3.14 / 180)), y + (rad * 2 * sin(((angle + f) + 10) * 3.14 / 180)));
		glVertex2d(x + 2.5 + (rad * cos((angle + f) * 3.14 / 180)), y + (rad * sin((angle + f) * 3.14 / 180)));
		glVertex2d(x + 2.5 + (rad * cos(((angle + f) + 20) * 3.14 / 180)), y + (rad * sin(((angle + f) + 20) * 3.14 / 180)));
		angle += 120;
		glEnd();	}
	f += fanP;
	if (f == 360)	f = 0;}
void specKeyboard(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:   Xcar -= 5;	break;
	case GLUT_KEY_RIGHT:  Xcar += 5;	break;
	case GLUT_KEY_UP:  fanP += .05;;	break;
	case GLUT_KEY_DOWN: fanP -= .05;	break;

	}
}
void GreenMount()
{
	glColor3f(0, 1, 0);
	glBegin(GL_POLYGON);
	glVertex2d(0, 280);
	glVertex2d(0, 250);
	glVertex2d(50, 200);
	glVertex2d(100, 240);
	glVertex2d(200, 170);
	glVertex2d(250, 240);
	glVertex2d(300, 190);
	glVertex2d(400, 250);
	//glVertex2d(400, 280);
	glEnd();
}
void Car(int x, int y) {
	Circle(x + Xcar + 85, 315, 15, 0, .5, .5, .5, true);
	Circle(x + Xcar + 85, 315, 15, 0, .1, .1, 0, false);
	Circle(x + Xcar + 85, 315, 3, 0, .1, .1, 0, true);
	
	Circle(x + Xcar + 25, 315, 15, 0, .5, .5, .5, true);
	Circle(x + Xcar + 25, 315, 15, 0, .1, .1, 0, false);
	Circle(x + Xcar + 25, 315, 3, 0, .1, .1, 0, true);
	LinesCircle(x + Xcar + 85, 315, 15, h, .1, .1, 0);
	LinesCircle(x + Xcar + 25, 315, 15, h, .1, .1, 0);

	if (h == 360)h = 0;
	else if (h == 0)h = 360;

	glColor3f(1, 0, 0);
	glBegin(GL_QUADS);
	glVertex2d(x + Xcar, y + 35);
	glVertex2d(x + Xcar + 110, y + 35);
	glVertex2d(x + Xcar + 110, y);
	glVertex2d(x + Xcar, y);
	glEnd();
	if ((x + Xcar) <= 0)	right = true;
	else  if ((x + Xcar) >= 300)	right = false;
	if (right) { Xcar =Xcar+ .01;	h += hTir; }
	else { Xcar =Xcar- .01;		h -= hTir; }
	glutPostRedisplay();

}
void greyRod()
{
	glColor3f(.2, .3, .3);
	glBegin(GL_QUADS);
	glVertex2d(0, 350);
	glVertex2d(400, 350);
	glVertex2d(400, 280);
	glVertex2d(0, 280);
	glEnd();
	glLineWidth(5);
	glColor3f(1, 1, 1);
	glBegin(GL_LINES);
	glVertex2d(0, 315);
	glVertex2d(400, 315);
	glEnd();
}
void init() {
	glClearColor(1, 1, 1, 1);
}
void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	////sun:
	//LinesCircle(330, 50, 70, s += .01, 1, 1, 0);
	//Circle(330, 50, 40, 0, 1, 1, 0, true);
	//Circle(330, 50, 40, 0, 1, 0, 0, false);
	//greenRod(); 
//	GreenMount();
	//greyRod();
	  //Fan(300, 150);
	//Fan(100, 150);    Fan(200, 150);
//	if (s == 360)s = 0;
	//Car(245, 275);
	float x = 80, y = 80, r = 50;
	double pi = 22 / 7;

	glBegin(GL_POLYGON);
	glColor3f(0, 1, 0);
	glVertex2i(1, 1);
	glVertex2i(3, 1);
	glVertex2i(1, 3);
	glVertex2i(3, 3);
	glEnd();
	glPointSize(15);
	glBegin(GL_POINTS);
	glColor3f(0, 0, 0);//median black at 90
	glVertex2f(x + cos((pi / 2)) * r, y + sin((pi / 2)) * r);glEnd();
	
     glFlush();
	//glutPostRedisplay();
}
void Circle(int x, int y, int rad, int mov, float r, float g, float b, bool fill)
{
	glLineWidth(1);
	float angle, x1, y1;
	glColor3f(r, g, b);
	if (fill) { glBegin(GL_POLYGON); }
	else if (!fill) { glLineWidth(3);	glBegin(GL_LINE_LOOP); }
	for (int i = 0;i < 64;i++)
	{//			2*pi
		angle = 6.2832 * i / 64;
		x1 = rad * cos(angle);
		y1 = rad * sin(angle);
		glVertex2d(x + x1, y + y1);
	}
	glEnd();
}
void LinesCircle(int x, int y, int rad, float mov, float r, float g, float b)
{
	float angle, x1, y1;
	glColor3f(r, g, b);
	glBegin(GL_LINES);

	for (int i = 0;i < 15;i++)
	{
		angle = 6.2832 * i / 15;
		x1 = rad * cos(angle + (mov * 3.14 / 180));
		y1 = rad * sin(angle + (mov * 3.14 / 180));
		glVertex2d(x + x1, y + y1);
		glVertex2d(x, y);
	}
	glEnd();
}
int main(int argc, char* argv[]) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Car");
	//		 left  right  bottom   top
	gluOrtho2D(0,  10,   0,    10);
	init();
	glutDisplayFunc(display);
	glutSpecialFunc(specKeyboard);
	glutMainLoop();

}
#include "iGraphics.h"
#define pi 3.1416
#include<time.h>
#include<math.h>

double x = 400, y = 400, r,r1,r2,s1, s2, c=0,c1=0,c3=0,h1,h2, m1, m2;
int h, m, s;

void second(void);
void minute(void);
void hour(void);

/*
	function iDraw() is called again and again by the system.

	*/


void iDraw()
{
    //place your drawing codes here

    iClear();
    iSetColor(250,0,0);
    iFilledCircle(x, y, 260,15);

    iSetColor(250,250,250);
    iFilledCircle(x,y,250);
    iSetColor(0,0,250);
    iFilledCircle(x,y,5);


    //iClear();
    //iSetColor(0, 250, 0);
    //iLine(400,400,400,300);
    iCircle(x, y, 260,15);

    //iFilledRectangle(10, 30, 20, 20);
    iSetColor(250,0,0);
    iText(393,635, "12");
    iText(400,165, "6");
    iText(518,604, "1");
    iText(635,400, "3");
    iText(165,400, "9");
    iText(604,518, "2");
    iText(282,604, "11");
    iText(196,518, "10");
    iText(196,282, "8");
    iText(282,196, "7");
    iText(604,282, "4");
    iText(518,196, "5");
    iSetColor(0,250,0);
    //iText(200,400, "*SAIKAT BUET CSE-PROJECT*");
    iSetColor(0,0,250);
    iLine(400,400,s1,s2);

    iSetColor(250,0,250);
    iLine(400,400,h1,h2);

    iSetColor(0,0,0);
    iLine(400,400,m1,m2);


}


/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my)
{
    printf("x = %d, y= %d\n",mx,my);
    //place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
        //	printf("x = %d, y= %d\n",mx,my);
        x += 10;
        y += 10;
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
        x -= 10;
        y -= 10;
    }
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key)
{
    if (key == 'q')
    {
        exit(0);
    }
    //place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key)
{

    if (key == GLUT_KEY_END)
    {
        exit(0);
    }
    //place your codes for other keys here
}
void second(void)
{

    s1=400+210*sin((pi/30)*s+(pi*c)/180);
    s2=400+210*cos((pi/30)*s+(pi*c)/180);
    c=c+6;
}


void minute(void)
{

    m1=400+180*sin((pi/30)*m+(pi/1800)*s+(pi*c1)/180);
    m2=400+180*cos((pi/30)*m+(pi/1800)*s+(pi*c1)/180);
    c1=c1+0.1;
}
void hour(void)
{

    h1=400+150*sin((pi/6)*h+(pi/360)*m+(pi/21600)*s+(pi*c3)/180);
    h2=400+150*cos((pi/6)*h+(pi/360)*m+(pi/21600)*s+(pi*c3)/180);
    c3=c3 +0.01;
}
int main()
{
    time_t t;
    time(&t);
    struct tm *s_t = localtime(&t);

    h = s_t->tm_hour%12;
    m = s_t->tm_min;
    s = s_t->tm_sec;

    iSetTimer(1000,second);
    iSetTimer(1000,minute);
    iSetTimer(1200,hour);
    //place your own initialization codes here.
    iInitialize(800,800,"Analog clock");


    return 0;
}


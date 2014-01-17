// Calc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


/*
Welcome to Antuan's 2010 programming

Name:       Antonio Vassell 0805694
Program:    Calculator
First Pseudo GUI
Date:       02.02.10

Secure:     True. hmmm..no keyboard inputs so kinda secure i guess for now

Bugs:       The functionality of the decimal point is not implemented as yet
You have to press equal after every operation but u can always use back the result
Measures to handle big big numbers are not implemented, It will crash handling big inputed numbers
I hate the colors but too much colors to choose from...
Wish i could put another function in place of the exit button
Not a bug: C is FOR CLEAR!!!!

This is not fully tested to find all the bugs so let us call it CALC BETA.
Report any bugs that is not yet report as development will continue on and on.
At this time comments are going to be low since running against time

Copyrighted 2010
*/

/*** THIS IS THE BETA VERSION!!!!! need more comments, soon work on that ****/

/************HEADER FILES************/
#define MOUSE_MOVED 52

#include <dos.h>
#include <stdio.h>
#include <conio.h>

#define _WIN32_WINNT 0x500    //Because am use DEV,, this is for the functionality of changing the window size funciton

#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <cmath>

/***************All of theses defines the values of each button**************/
#define DOWN        50    //
#define UP          51    //
#define CLICK       55    //
#define MOUSE_WHEEL 53    //
#define DOUBLE_CLIK 54    //

#define ADD         100   //
#define SUB         101   //
#define MULTY       102   //
#define DIVIDE      103   //
#define LOG         104
#define EQUAL       105   //
#define FACT        106   //
#define SIN         107   
#define COS         108
#define TAN         109

#define SQR         111   //
#define CUBE        112   //
#define SQRRT       113   //
#define CUBERT      114   //
#define POW         115   //
#define PERCENT     116   //
#define DECI_POINT  117   
#define POSI_NEGA   118   //


#define VIEW        119   //
#define GPA  300          

#define CLEAR       200   //

#define ONE      1        //
#define TWO      2        //
#define THREE    3        //
#define FOUR     4        //
#define FIVE     5        //
#define SIX      6        //
#define SEVEN    7        //
#define EIGHT    8        //
#define NINE     9        //
#define ZERO     0        //

#define BUTTON_TEXT_COLOR          9
#define BUTTON_COLOR               10
#define HIGHLIGHTED_BUTTON_COLOR   12

//If this is going to compile in Borland this next line needs to be commented out...
using namespace std;

/****** Structures to hold attributes of the buttons and mouse actions******/
struct BOTTON
{
	int x1, x2, y1, y2, label_value;
	char label[16];
};

struct MousePack
{
	int LeftClick;
	int RightClick;
	int DoubleClick;
	COORD MouseOver;
};

/***********Function prototypes********************
  hmmm...the gui needs to be separated on another
  source file, bad bad bad programming structure
  God help me
  */

void  clearDisplay(void);
void  welcomeScreen(void);
void  gotoxy(int, int);
void  drawTextBox(int, int, int, int);
void  printButton(BOTTON);
void  ShowConsoleCursor(BOOL);

float log(float, float);
float Action(int, char *);
float addition(float, float);
float subtraction(float, float);
float divide(float, float);
float multi(float, float);
void  changeWindowSize(int, int, int, int);
float square(float);
float cube(float);
float percent(float, float);
int   factorial(float);
float tangent(float);
float sine(float);
float cosine(float);
float sqrroot(float);
void  printLabel(int, char *);

MousePack MouseCheck();

//While comment further as time goes by
int main()
{
	//welcomeScreen();

	changeWindowSize(300, 300, 300, 575);  //Set the standard window size

	int index = 0;
	int count;

	HANDLE hconsole;                    //Creates a handle
	hconsole = GetStdHandle(STD_OUTPUT_HANDLE);   //Assigns that handle to the consoles window
	MousePack MouseAction;                        //Create a new MousePack
	BOTTON BottonArr[30];                         //Create array of buttons (structures)

	ShowConsoleCursor(FALSE);                    //This function tells the console not to show the cursor

	//From here on its mostly to assign the values of each button, This should have been somewhere else other than main..
	BottonArr[0].x1 = 2;
	BottonArr[0].x2 = 3;
	BottonArr[0].y1 = 12;
	BottonArr[0].y2 = 14;
	BottonArr[0].label_value = 0;

	strcpy(BottonArr[0].label, "7"); BottonArr[0].label_value = SEVEN;
	strcpy(BottonArr[1].label, "8"); BottonArr[1].label_value = EIGHT;
	strcpy(BottonArr[2].label, "9"); BottonArr[2].label_value = NINE;
	strcpy(BottonArr[3].label, "/"); BottonArr[3].label_value = DIVIDE;
	strcpy(BottonArr[4].label, "C"); BottonArr[4].label_value = CLEAR;

	strcpy(BottonArr[5].label, "4"); BottonArr[5].label_value = FOUR;
	strcpy(BottonArr[6].label, "5"); BottonArr[6].label_value = FIVE;
	strcpy(BottonArr[7].label, "6"); BottonArr[7].label_value = SIX;
	strcpy(BottonArr[8].label, "x"); BottonArr[8].label_value = MULTY;
	strcpy(BottonArr[9].label, "%"); BottonArr[9].label_value = PERCENT;

	strcpy(BottonArr[10].label, "1"); BottonArr[10].label_value = ONE;
	strcpy(BottonArr[11].label, "2"); BottonArr[11].label_value = TWO;
	strcpy(BottonArr[12].label, "3"); BottonArr[12].label_value = THREE;
	strcpy(BottonArr[13].label, "-"); BottonArr[13].label_value = SUB;
	strcpy(BottonArr[14].label, " "); BottonArr[14].label_value = SQRRT;  //Square Root 252, squareroot

	strcpy(BottonArr[15].label, "0"); BottonArr[15].label_value = ZERO;
	strcpy(BottonArr[16].label, "."); BottonArr[16].label_value = DECI_POINT;
	strcpy(BottonArr[17].label, " "); BottonArr[17].label_value = POSI_NEGA;  //Minus or negative 241  minus plus
	strcpy(BottonArr[18].label, "+"); BottonArr[18].label_value = ADD;
	strcpy(BottonArr[19].label, "="); BottonArr[19].label_value = EQUAL;

	strcpy(BottonArr[20].label, "Exit"); BottonArr[20].label_value = VIEW;
	strcpy(BottonArr[21].label, "x2"); BottonArr[21].label_value = SQR;
	strcpy(BottonArr[22].label, "x3"); BottonArr[22].label_value = CUBE;

	strcpy(BottonArr[23].label, "fact"); BottonArr[23].label_value = FACT;

	strcpy(BottonArr[24].label, "log"); BottonArr[24].label_value = LOG;
	strcpy(BottonArr[25].label, "Cos"); BottonArr[25].label_value = COS;
	strcpy(BottonArr[26].label, "Sin"); BottonArr[26].label_value = SIN;
	strcpy(BottonArr[27].label, "Tan"); BottonArr[27].label_value = TAN;


	index = 1;
	count = 1;

	//Please be advise that Botton is spelt wrong (button)
	//Most complex assignments,
	//This loop automatically asign x1,x2,y1,y2 values to the structures of each button

	while (count <= 4)
	{
		BottonArr[index].x1 = BottonArr[index - 1].x1 + 3;
		BottonArr[index].x2 = BottonArr[index - 1].x2 + 3;

		index++;
		count++;
	}

	count = 1;
	while (count <= 5)
	{
		BottonArr[index].x1 = BottonArr[index - 5].x1;
		BottonArr[index].x2 = BottonArr[index - 5].x2;

		index++;
		count++;
	}

	count = 1;
	while (count <= 5)
	{
		BottonArr[index].x1 = BottonArr[index - 10].x1;
		BottonArr[index].x2 = BottonArr[index - 10].x2;

		index++;
		count++;
	}

	count = 1;
	while (count <= 5)
	{
		BottonArr[index].x1 = BottonArr[index - 15].x1;
		BottonArr[index].x2 = BottonArr[index - 15].x2;

		index++;
		count++;
	}

	//Y values    
	count = 1;
	index = 1;

	while (count <= 4)
	{
		BottonArr[index].y1 = BottonArr[0].y1;
		BottonArr[index].y2 = BottonArr[0].y2;

		index++;
		count++;
	}

	count = 1;
	//index=7;
	while (count <= 5)
	{
		BottonArr[index].y1 = BottonArr[0].y1 + 3;
		BottonArr[index].y2 = BottonArr[0].y2 + 3;

		index++;
		count++;
	}

	count = 1;

	while (count <= 5)
	{
		BottonArr[index].y1 = BottonArr[0].y1 + 6;
		BottonArr[index].y2 = BottonArr[0].y2 + 6;

		index++;
		count++;
	}

	count = 1;

	while (count <= 5)
	{
		BottonArr[index].y1 = BottonArr[0].y1 + 9;
		BottonArr[index].y2 = BottonArr[0].y2 + 9;

		index++;
		count++;
	}

	count = 0;
	index = 0;

	/**************SPECIALL BUTTONS****************/
	//For the 'VEIW' button
	BottonArr[20].x1 = 2;
	BottonArr[20].x2 = 6;
	BottonArr[20].y1 = 9;
	BottonArr[20].y2 = 11;
	//For the 'x2' button
	BottonArr[21].x1 = 8;
	BottonArr[21].x2 = 10;
	BottonArr[21].y1 = 9;
	BottonArr[21].y2 = 11;
	//For the 'x3' button
	BottonArr[22].x1 = 12;
	BottonArr[22].x2 = 14;
	BottonArr[22].y1 = 9;
	BottonArr[22].y2 = 11;
	//For the 'fact' buton 
	BottonArr[23].x1 = 16;
	BottonArr[23].x2 = 20;
	BottonArr[23].y1 = 9;
	BottonArr[23].y2 = 11;

	//For the extra buttons
	index = 24;
	count = 12;

	while (index <= 27)
	{
		BottonArr[index].x1 = 17;
		BottonArr[index].x2 = 20;

		BottonArr[index].y1 = count;
		BottonArr[index].y2 = count + 2;

		index++;
		count += 3;
	}

	//Time to do some GUI! FINALLY!!

	SetConsoleTextAttribute(hconsole, 12);
	drawTextBox(1, 21, 0, 8);

	index = 1;
	count = 1;
	while (count <= 27)
	{
		SetConsoleTextAttribute(hconsole, BUTTON_COLOR);  //12  //BUTTON_COLOR
		printButton(BottonArr[index]);
		index++;
		count++;
	}

	int flag = 0;

	while (1)
	{
		MouseAction = MouseCheck();

		count = 0;
		index = 0;

		while (index <= 27)
		{
			if ((MouseAction.MouseOver.X >= BottonArr[index].x1 && MouseAction.MouseOver.X <= BottonArr[index].x2) && (MouseAction.MouseOver.Y >= BottonArr[index].y1 && MouseAction.MouseOver.Y <= BottonArr[index].y2))
			{
				SetConsoleTextAttribute(hconsole, HIGHLIGHTED_BUTTON_COLOR);  //7  HIGHLIGHTED_BUTTON_COLOR
				printButton(BottonArr[index]);
				flag = index;

				if (MouseAction.LeftClick == DOWN)
				{
					Action(BottonArr[index].label_value, BottonArr[index].label);
				}
			}

			if (!((MouseAction.MouseOver.X >= BottonArr[flag].x1 && MouseAction.MouseOver.X <= BottonArr[flag].x2) && (MouseAction.MouseOver.Y >= BottonArr[flag].y1 && MouseAction.MouseOver.Y <= BottonArr[flag].y2)))
			{
				SetConsoleTextAttribute(hconsole, BUTTON_COLOR);         //BUTTON_COLOR
				printButton(BottonArr[flag]);
			}

			index++;
			Sleep(1);
		}
	}

	return 0;
}

void changeWindowSize(int x1, int y1, int TOP, int BOTTOM)
{
	HWND console = GetConsoleWindow();     //Creates a handle and assigns it to the consoles windows
	RECT r;        //hmmmm....ask me later
	GetWindowRect(console, &r); //stores the console's current dimensions

	MoveWindow(console, x1, y1, TOP, BOTTOM, TRUE);
}

float Action(int Action, char label[16])
{
	static float result;
	static float num;
	static float num1;
	static float num2;
	static int symbol;
	static int flag = 0;
	static int another = 0;

	if ((Action >= 0) && (Action <= 9))
	{
		if (flag == 0)
		{
			num = Action;
			flag = 1;
		}
		else if (flag == 1)
		{
			num = num * 10;
			num += Action;
		}
	}

	if (another == 0)
	{
		num1 = num;
		gotoxy(2, 2);
		printf("    ");
		gotoxy(2, 2);
		printf("%4.0f", num);
	}
	else if (another == 1)
	{
		num2 = num;
		gotoxy(2, 3);
		printf("    ");
		gotoxy(2, 3);
		printf("%4.0f", num);
	}
	if (Action == POSI_NEGA)
	{
		if (another == 0)
		{
			num *= -1;
			num1 = num;
			gotoxy(2, 2);
			printf("        ");
			gotoxy(2, 2);
			printf("%4.0f", num1);
		}
		else if (another == 1)
		{
			num *= -1;
			num2 = num;
			gotoxy(2, 3);
			printf("        ");
			gotoxy(2, 3);
			printf("%4.0f", num2);
		}
	}
	if (Action == CLEAR)
	{
		num = 0;
		num1 = 0;
		num2 = 0;
		result = 0;
		another = 0;

		gotoxy(2, 2);
		printf("    ");
		gotoxy(2, 2);
		printf("%4.0f", num);

		gotoxy(2, 3);
		printf("    ");

		gotoxy(1, 5);
		printf("       ");

		clearDisplay();
	}
	if (Action == VIEW)
	{
		exit(0);
	}

	if ((Action >= 100) && (Action <= 117))
	{
		flag = 0;

		if (another == 0)
		{
			gotoxy(1, 3);
			printLabel(Action, label);    //Main function is to facilitate special keys
			symbol = Action;
			another = 1;
		}

		if (Action == EQUAL)
		{
			switch (symbol)
			{
			case ADD:     result = addition(num1, num2);
				break;
			case SUB:     result = subtraction(num1, num2);
				break;
			case DIVIDE:  result = divide(num1, num2);
				break;
			case MULTY:   result = multi(num1, num2);
				break;
			case PERCENT: result = percent(num1, num2);
				break;
			case SQR:     result = square(num);
				break;
			case CUBE:    result = cube(num);
				break;
			case SQRRT:   result = sqrroot(num);
				break;
			case CUBERT:  gotoxy(1, 6);
				printf("Soming Soon");
				break;
			case FACT:    result = (float)factorial(num);
				break;
			case LOG:     result = log(num1, num2);
				break;
			case COS:     result = cosine(num);
				break;
			case TAN:     result = tangent(num);
				break;
			case SIN:     result = sine(num);
				break;
			case VIEW:    exit(0);
				break;
			}
			another = 0;
			gotoxy(1, 4);
			printf("    ");
			gotoxy(1, 4);
			printf("______");
			gotoxy(1, 5);
			printf("       ");
			gotoxy(1, 5);
			printf("= %4.2f", result);
			another = 0;

			num = result;
		}
	}
}

float multi(float num1, float num2)
{
	return num1 * num2;
}

float subtraction(float num1, float num2)
{
	return num1 - num2;
}

float log(float num, float base)
{
	float result = base;

	for (int i = 1; i < num; i++)
	{
		result *= base;
	}

	return result;
}

float divide(float num1, float num2)
{
	if (num2 == 0)
	{
		gotoxy(1, 5);
		printf("       ");
		gotoxy(1, 6);
		printf("E!");
		return 0;
	}
	else
		return num1 / num2;
}

float sqrroot(float num)
{
	return sqrt(num);
}

float cosine(float num)
{
	return (float)cos((float)num);
}

float sine(float num)
{
	return (float)sin((float)num);
}

float tangent(float num)
{
	return (float)tan((float)num);
}

float addition(float num1, float num2)
{
	return num1 + num2;
}

int factorial(float num)
{
	int result = 1;
	for (int i = 1; i <= num; i++)
		result *= i;

	return result;
}

float percent(float num1, float num2)
{
	return (num1 / num2) * 100;
}

float square(float num)
{
	return num*num;
}

float cube(float num)
{
	return (num*num)*num;
}

void ShowConsoleCursor(BOOL bShow) //Not define in dev but in VC, hmmm....i could easily discard this when i switch
{
	static HANDLE		hOut;
	static BOOL		    firstTime = TRUE;
	CONSOLE_CURSOR_INFO cursorInfo;

	if (firstTime)
	{

		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		firstTime = FALSE;
	}

	cursorInfo.dwSize = 10;
	cursorInfo.bVisible = bShow;

	SetConsoleCursorInfo(hOut,
		&cursorInfo);
}

MousePack MouseCheck()
{
	static MousePack mousepack = { UP, UP, UP };

	HANDLE hIn;
	HANDLE hOut;
	bool Continue = TRUE;
	DWORD EventCount;
	int LoopCount = 0;
	int KeyEvents = 0;
	INPUT_RECORD InRec;
	DWORD NumRead;

	int MouseoverX;
	int MouseoverY;

	hIn = GetStdHandle(STD_INPUT_HANDLE);
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	GetNumberOfConsoleInputEvents(hIn, &EventCount);

	ReadConsoleInput(hIn,
		&InRec,
		1,
		&NumRead);

	if (InRec.EventType == MOUSE_EVENT)			//Check for a mouse event
	{
		if (InRec.Event.MouseEvent.dwEventFlags == 0)
		{
			if (InRec.Event.MouseEvent.dwButtonState & 0x01)	//Left
			{
				mousepack.LeftClick = DOWN;
			}
			else
			{
				mousepack.LeftClick = UP;
			}
			if (InRec.Event.MouseEvent.dwButtonState & 0x02)	//Right
			{
				mousepack.RightClick = DOWN;
			}
			else
			{
				mousepack.RightClick = UP;
			}
		}
		else if (InRec.Event.MouseEvent.dwEventFlags == MOUSE_MOVED)	//Check where the mouse pointer now
		{
			mousepack.MouseOver.X = InRec.Event.MouseEvent.dwMousePosition.X;
			mousepack.MouseOver.Y = InRec.Event.MouseEvent.dwMousePosition.Y;
		}
		else if (InRec.Event.MouseEvent.dwEventFlags == DOUBLE_CLICK)	//Check if a double click occured and where
		{
		}

	}
	return mousepack;
}

void gotoxy(int x, int y)
{
	COORD coord;

	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void drawTextBox(int x1, int x2, int y1, int y2)
{
	int i;
	gotoxy(x1 - 1, y1);

	printf("%c", (unsigned char)201);    //169

	for (i = 0; i < (x2 - x1); i++)
	{
		printf("%c", (unsigned char)196);
	}
	printf("%c\n", (unsigned char)187);  //191

	gotoxy(x1, y1 + 1);

	for (i = 0; i < (y2 - y1 - 1); i++)
	{
		gotoxy(x1 - 1, i + y1 + 1);
		printf("%c\n", (unsigned char)179);
	}

	gotoxy(x1 - 1, y2);
	printf("%c", (unsigned char)200);     //192

	for (i = 0; i < (x2 - x1); i++)
	{
		printf("%c", (unsigned char)196);
	}
	printf("%c", (unsigned char)188);    //217

	for (i = 1; i <= (y2 - y1 - 1); i++)                  //4
	{
		gotoxy(x2, (y2)-i);
		printf("%c", (unsigned char)179);
	}
}

void printButton(BOTTON Botton)
{
	static HANDLE hconsole;
	hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	drawTextBox(Botton.x1, Botton.x2, Botton.y1, Botton.y2);

	gotoxy(Botton.x1, Botton.y1 + 1);
	SetConsoleTextAttribute(hconsole, BUTTON_TEXT_COLOR);            //BUTTON_TEXT_COLOR

	switch (Botton.label_value)
	{
	case SQRRT:       printf("%c", (unsigned char)251); break;
	case POSI_NEGA:   printf("%c", (unsigned char)241); break;

	default:          printf("%s", Botton.label); break;
	}
}

void  welcomeScreen(void)
{
	char welcome_words[] = { "Welcome to Antuan's 2010 Programming" };
	int lenght = 1, index = 0;

	while (welcome_words[index] != '\0')
	{
		changeWindowSize(600, 300, lenght, 10);
		printf("%c", welcome_words[index]);

		lenght += 20;
		index++;
		Sleep(100);
	}

	Sleep(1000);
	changeWindowSize(600, 300, lenght, 60);
	printf("\n\t1.    Calc 1. Beta 1");
	Sleep(2000);
	gotoxy(1, 1);
	printf("                                             ");
}

void clearDisplay(void)
{
	for (int i = 1; i <= 7; i++)
	{
		gotoxy(1, i);
		printf("                    ");
	}
}

void printLabel(int Action, char label[16])
{
	switch (Action)
	{
	case SQRRT:       printf("%c", (unsigned char)251); break;
	default:          printf("%s", label); break;
	}
}



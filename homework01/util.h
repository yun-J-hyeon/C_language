#include "main.h"

#ifndef __COLOR_LIST_
#define __COLOR_LIST_

enum
{
	black,
	blue,
	green,
	cyan,
	red,
	purple,
	yellow,
	lightgray,
	gray,
	lightblue,
	lightgreen,
	lightcyan,
	lightred,
	lightpurple,
	lightyellow,
	white
};

#endif

void consol();
void gotoxy(int, int);
void setcolor(int, int);
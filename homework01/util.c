#include "util.h"

void consol() //콘솔창 크기 지정해서 불러오는건데 효과가 있는지 모르겠음
{
	system("mode con cols=60 lines=31 | title Grow your eggs");
}

void gotoxy(int x, int y) //커서 옮기는 함수
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void setcolor(int forground, int background) //글자 및 배경 색바꾸는 함수 | 첫번째 : 텍스트 두번째 : 배경
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	int code = forground + background * 16;
		SetConsoleTextAttribute(consoleHandle, code);
}
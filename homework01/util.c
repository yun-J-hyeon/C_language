#include "util.h"

void consol() //�ܼ�â ũ�� �����ؼ� �ҷ����°ǵ� ȿ���� �ִ��� �𸣰���
{
	system("mode con cols=60 lines=31 | title Grow your eggs");
}

void gotoxy(int x, int y) //Ŀ�� �ű�� �Լ�
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void setcolor(int forground, int background) //���� �� ��� ���ٲٴ� �Լ� | ù��° : �ؽ�Ʈ �ι�° : ���
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	int code = forground + background * 16;
		SetConsoleTextAttribute(consoleHandle, code);
}
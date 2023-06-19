#include "game.h"
#include "util.h"

int goto_main = 1, physical = 0, intelli = 0, mental = 0, death = 0; //���� �ý��ۿ��� ��ü������ ���Ǵ� �������� ����

char screen[30][60] = // �׵θ��� �ִ� �迭 �ҽ�
{
{"111111111111111111111111111111111111111111111111111111111111"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"111111111111111111111111111111111111111111111111111111111111"}
};

char main_screen[30][60] = // ����ȭ�� �迭 �ҽ�
{
{"111111111111111111111111111111111111111111111111111111111111"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000001111000111110000111110001000000010000000000001"},
{"100000000000010000000100001001000001001000000010000000000001"},
{"100000000000010001100111110001000001001000100010000000000001"},
{"100000000000010000100100010001000001000101010100000000000001"},
{"100000000000001111000100001000111110000010001000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000010000010001111100010000010011111000000000000001"},
{"100000000000001000100010000010010000010010000100000000000001"},
{"100000000000000010000010000010010000010011111000000000000001"},
{"100000000000000010000010000010010000010010000100000000000001"},
{"100000000000000010000001111100001111100010000010000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000011111110001111100001111100001111100000000000001"},
{"100000000000010000000010000000010000000010000000000000000001"},
{"100000000000011111110010000110010000110001111100000000000001"},
{"100000000000010000000010000010010000010000000010000000000001"},
{"100000000000011111110001111100001111100001111100000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"111111111111111111111111111111111111111111111111111111111111"}
};

char game_main[30][60] = // ���� ȭ�� �迭 �ҽ�
{
{"111111111111111111111111111111111111111111111111111111111111"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000001111110000000000000000000000000001"},
{"100000000000000000000000100000000100000000000000000000000001"},
{"100000000000000000000011110000000001000000000000000000000001"},
{"100000000000000000000111100000000011100000000000000000000001"},
{"100000000000000000000100000000001111100000000000000000000001"},
{"100000000000000000000100000000000111100000000000000000000001"},
{"100000000000000000000011110000000001000000000000000000000001"},
{"100000000000000000000001100000000010000000000000000000000001"},
{"100000000000000000000000011111111000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"111111111111111111111111111111111111111111111111111111111111"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"111111111111111111111111111111111111111111111111111111111111"}
};

char intelli_ending[30][60] = // ���� ���� �迭 �ҽ�
{
{"111111111111111111111111111111111111111111111111111111111111"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000111111111100000000000000000000000001"},
{"100000000000000000000011111111111111000000000000000000000001"},
{"100000000000000000000111111111111111100000000000000000000001"},
{"100000000000000000001000000000000000010000000000000000000001"},
{"100000000000000000001000001000010000010000000000000000000001"},
{"100000000000000000001000000000000000010000000000000000000001"},
{"100000000000000000000100010000001000100000000000000000000001"},
{"100000000000000000000010000111100001000000000000000000000001"},
{"100000000000000000000001000000000010000000000000000000000001"},
{"100000000000000000000001111111111110000000000000000000000001"},
{"100000000000000000011110000000000001111000000000000000000001"},
{"100000000000000000110000000000000000001100000000000000000001"},
{"100000000000000001100010000000000001000110000000000000000001"},
{"100000000000000001100010000000000001000110000000000000000001"},
{"100000000000000001111111111111111111111110000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"111111111111111111111111111111111111111111111111111111111111"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"111111111111111111111111111111111111111111111111111111111111"}
};

char mental_ending[30][60] = // �� ���� �迭 �ҽ�
{
{"111111111111111111111111111111111111111111111111111111111111"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000011110000000000000000000000000001"},
{"100000000000000000010000001110001000001000000000000000000001"},
{"100000000000000000011000001011110000000100000000000000000001"},
{"100000000000000000011100000011110000001100000000000000000001"},
{"100000000000000000011111001100001100111100000000000000000001"},
{"100000000000000000001111111000110111110000000000000000000001"},
{"100000000000000000000000011001110110000000000000000000000001"},
{"100000000000000000000000001000011100000000000000000000000001"},
{"100000000000000000000000000111110000000000000000000000000001"},
{"100000000000000000000000000010100000000000000000000000000001"},
{"100000000000000000000000001110111000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"111111111111111111111111111111111111111111111111111111111111"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"111111111111111111111111111111111111111111111111111111111111"}
};

char physical_ending[30][60] = // ������ ���� �迭 �ҽ�
{
{"111111111111111111111111111111111111111111111111111111111111"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000001111111111100000000000000000000000000000000001"},
{"100000000000110000000000001100000000000000000000000000000001"},
{"100000000011000000000000000011000000000000000000000000000001"},
{"100000000100001100000110000001100000000000000000000000000001"},
{"100000001000000000000000000000111111111111111000000000000001"},
{"100000010000010100000000000000011000000000001110000000000001"},
{"100000001000100000000001100000110000000000000011000000000001"},
{"100000000011001010000000011111100000000000000001110000000001"},
{"100000000100100000000000000000000000000000000001101000000001"},
{"100000000100100000000000000000000000000000000000010001000001"},
{"100001110010001000000000000000000000000000000001100001110001"},
{"100001000100000100011110000011000000111000000011000000110001"},
{"100000111000000010000101000011111111111110000010000000000001"},
{"100000000000000010000101000010000010000111000010000000000001"},
{"100000000000000011111101000010000011111101000010000000000001"},
{"100000000000000000000001111110000000000001111110000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"111111111111111111111111111111111111111111111111111111111111"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"100000000000000000000000000000000000000000000000000000000001"},
{"111111111111111111111111111111111111111111111111111111111111"}
};

char death_ending[30][60] = // ��� ���� �迭 �ҽ�
{
{ "111111111111111111111111111111111111111111111111111111111111" },
{ "100000000000000000000000000000000000000000000000000000000001" },
{ "100000000000000000000000000000000000000000000000000000000001" },
{ "100000000000000000000000000000000000000000000000000000000001" },
{ "100000000000000000000000000000000000000000000000000000000001" },
{ "100000000000000000000000000000000000000000000000000000000001" },
{ "100000000000000000000000001111110000000000000000000000000001" },
{ "100000000000000000000000100000000100000000000000000000000001" },
{ "100000000000000000000011120000000001000000000000000000000001" },
{ "100000000000000000000111120000000011100000000000000000000001" },
{ "100000000000000000000100202200001111100000000000000000000001" },
{ "100000000000000000000102000200000111100000000000000000000001" },
{ "100000000000000000000022110000002221000000000000000000000001" },
{ "100000000000000000002221100000220212222200000000000000000001" },
{ "100000000000022222222222211111221222222222220000000000000001" },
{ "100000000000000002222222222222222222222200000000000000000001" },
{ "100000000000000000000022200022222222000000000000000000000001" },
{ "100000000000000000000000000000000000000000000000000000000001" },
{ "111111111111111111111111111111111111111111111111111111111111" },
{ "100000000000000000000000000000000000000000000000000000000001" },
{ "100000000000000000000000000000000000000000000000000000000001" },
{ "100000000000000000000000000000000000000000000000000000000001" },
{ "100000000000000000000000000000000000000000000000000000000001" },
{ "100000000000000000000000000000000000000000000000000000000001" },
{ "100000000000000000000000000000000000000000000000000000000001" },
{ "100000000000000000000000000000000000000000000000000000000001" },
{ "100000000000000000000000000000000000000000000000000000000001" },
{ "100000000000000000000000000000000000000000000000000000000001" },
{ "111111111111111111111111111111111111111111111111111111111111" }
};

void main_control() //���� �ý��� �Լ�. ���߿� ���� �Լ��� �ű���� ����
{
	int select;
	while (goto_main != 0)
	{
		draw_title();
		gotoxy(24, 22);
		printf("1. ���� ����\n");
		gotoxy(24, 23);
		printf("2. ���� ����\n");
		gotoxy(24, 24);
		printf("3. ���� ����\n");
		gotoxy(17, 26);
		printf("1~3 ���ڸ� �Է��ϰ� ���� > ");
		scanf("%d", &select);
		if (select == 1)
		{
			game_system();
			ending();
			goto_main = 1;
		}
		else if (select == 2)
		{
			print_how_to_play();
			goto_main = 1;
		}
		else if (select == 3)
		{
			print_game_quit();
			goto_main = 0;
		}
		else
		{
			gotoxy(17, 27);
			printf("��ȿ�� ���ڸ� �Է��ϼ���.\n");
			Sleep(3000);
			goto_main = 1;
		}
	}
}

void game_system() //���� �÷��� �Լ�
{
	int toending, choice = 0; //toending : ���൵ ���� | choice : ������ Ȱ�� �޾ƿ���
	physical = 0, intelli = 0, mental = 0, death = 0;
	for (toending = 1; toending <= 13; toending += 1) //�� 13�� �ݺ���.
	{
		draw_gamescreen();
		printf("���൵ : %d/13", toending-1);
		gotoxy(17, 26);
		printf("1~3 ���ڸ� �Է��ϰ� ���� > ");
		scanf("%d", &choice);
		switch (choice)
		{
			case 1:
			{
				draw_intelli();
				intelli += 10;
			}
			break;
			case 2:
			{
				draw_mental();
				mental += 10;
			}
			break;
			case 3:
			{
				draw_physical();
				physical += 10;
			}
			break;
			default:
			{
				death += 1;
				draw_death();
			}
		}
	}

}

void ending() //���� �κ� �Լ�
{
	if (intelli > physical && intelli > mental && intelli > death)
	{
		print_intelli_ending();
	}
	else if (mental > intelli && mental > physical && mental > death)
	{
		print_mental_ending();
	}
	else if (physical > intelli && physical > mental && physical > death)
	{
		print_physical_ending();
	}
	else if (intelli == 0 && mental == 0 && physical == 0)
	{
		print_death_ending();
	}
}



void draw_title() //����ȭ�� �׸��� �Լ�. �迭 �ҽ��� �ִ� ���ڸ� ���ڷ� �ٲ���
{
	system("cls");
	int h, w; // h�� ����, w�� ����

	for (h = 0; h < 30; h++)
	{
		for (w = 0; w < 60; w++)
		{
			char temp = main_screen[h][w];
			if (temp == '0')
			{
				setcolor(black, black);
				printf(" ");
			}
			else if (temp == '1')
			{
				setcolor(white, white);
				printf("#");
			}
		}
		printf("\n");
	}
	setcolor(white, black);
}

void draw_screen()
{
	system("cls");
	int h, w; // h�� ����, w�� ����

	for (h = 0; h < 30; h++)
	{
		for (w = 0; w < 60; w++)
		{
			char temp = screen[h][w];
			if (temp == '0')
			{
				setcolor(black, black);
				printf(" ");
			}
			else if (temp == '1')
			{
				setcolor(white, white);
				printf("#");
			}
		}
		printf("\n");
	}
	setcolor(white, black);
}

void print_how_to_play()
{
	int htp_sel = 0;
	draw_screen();
	gotoxy(25, 3);
	printf("���� ����");
	gotoxy(23, 6);
	printf("���� Ű�켼��!");
	gotoxy(10, 8);
	printf("�˿��� å�� �о��ְų�, �뷡�� ���ְų�,");
	gotoxy(15, 10);
	printf("������ ��� ���� �� �ֽ��ϴ�!");
	gotoxy(5, 12);
	printf("����� ���ÿ� ���� � ������ ��ȭ���� �޶����ϴ�.");
	gotoxy(10, 14);
	printf("����� ���� �� ������ ���ɼ��� ���� ����");
	gotoxy(15, 16);
	printf("������ ��ȭ��ų �� ������� ?");
	gotoxy(14, 18);
	printf("å�Ӱ��� ���� �� ������ �ּ���!");

	gotoxy(24, 22);
	printf("1. ���� ������\n");
	gotoxy(24, 23);
	printf("2. ��������\n");
	gotoxy(17, 26);
	printf("1~2 ���ڸ� �Է��ϰ� ���� > ");
	scanf("%d", &htp_sel);

	if (htp_sel == 1)
	{
		print_how_to_play_sec();
	}
	else if (htp_sel == 2)
	{
		main_control();
	}
	else
	{
		gotoxy(17, 27);
		printf("��ȿ�� ���ڸ� �Է��ϼ���.");
		Sleep(3000);
		print_how_to_play();
	}
}

void print_how_to_play_sec()
{
	int htp_cho;
	draw_screen();
	gotoxy(17, 4);
	printf("����� �˿��� å �о��ֱ�,");
	gotoxy(16, 6);
	printf("�뷡 �ҷ��ֱ�, � �����ֱ�");
	gotoxy(9, 8);
	printf("�� ���� Ȱ�� �� �ϳ��� ������ �� �ֽ��ϴ�.");
	gotoxy(12, 10);
	printf("������ Ȱ���� ���� ���� �ش� �ɷ�ġ��");
	gotoxy(9, 12);
	printf("���൵�� �ö󰡰� ���൵�� �� �� ��������");
	gotoxy(9, 14);
	printf("���� ���� �ɷ�ġ�� �´� ������ ��ȭ�մϴ�.");
	gotoxy(15, 16);
	printf("����� ���ϴ� ��� Ű��������!");
	gotoxy(7, 18);
	printf("��, ���� �߿��� \'å�Ӱ�\'�� ���� ���� ������!");

	gotoxy(24, 22);
	printf("1. ���� ������\n");
	gotoxy(24, 23);
	printf("2. ��������\n");
	gotoxy(17, 26);
	printf("1~2 ���ڸ� �Է��ϰ� ���� > ");
	scanf("%d", &htp_cho);

	if (htp_cho == 1)
	{
		print_how_to_play();
	}
	else if (htp_cho == 2)
	{
		main_control();
	}
	else
	{
		gotoxy(17, 27);
		printf("��ȿ�� ���ڸ� �Է��ϼ���.");
		Sleep(3000);
		print_how_to_play_sec();
	}
}

void print_game_quit()
{
	int game_over;
	draw_screen();
	gotoxy(17, 10);
	printf("������ �����Ͻðڽ��ϱ�?");

	gotoxy(24, 13);
	printf("1. ��\n");
	gotoxy(24, 14);
	printf("2. �ƴϿ�\n");
	gotoxy(17, 16);
	printf("1~2 ���ڸ� �Է��ϰ� ���� > ");
	scanf("%d", &game_over);

	if (game_over == 1)
	{
		printf(" ");
	}
	else if (game_over == 2)
	{
		main_control();
	}
}

void draw_game()
{
	system("cls");
	int h, w; // h�� ����, w�� ����

	for (h = 0; h < 30; h++)
	{
		for (w = 0; w < 60; w++)
		{
			char temp = game_main[h][w];
			if (temp == '0')
			{
				setcolor(black, black);
				printf(" ");
			}
			else if (temp == '1')
			{
				setcolor(white, white);
				printf("#");
			}
		}
		printf("\n");
	}
	setcolor(white, black);
}

void draw_gamescreen()
{
	draw_game();
	gotoxy(19, 20);
	printf("�˿��� � �� ���ٱ�?");
	gotoxy(21, 22);
	printf("1. å �о��ֱ�");
	gotoxy(21, 23);
	printf("2. �뷡 �ҷ��ֱ�");
	gotoxy(21, 24);
	printf("3. � �����ֱ�");
	gotoxy(3, 2);
	printf("���� : %d", intelli);
	gotoxy(3, 3);
	printf("�� : %d", mental);
	gotoxy(3, 4);
	printf("������ : %d", physical);
	gotoxy(42, 2);
}

void draw_intelli()
{
	draw_gongback();
	gotoxy(18, 21);
	printf("�˿��� å�� �о��־���...");
	Sleep(1500);
	gotoxy(18, 23);
	printf("���� �ȶ����� �� ����...");
	Sleep(1500);
	gotoxy(23, 25);
	printf("���� 10 ���");
	Sleep(1500);
}

void draw_mental()
{
	draw_gongback();
	gotoxy(16, 21);
	printf("�˿��� �뷡�� �ҷ� �־���...");
	Sleep(1500);
	gotoxy(16, 23);
	printf("���� ��ܿ� �ϴ� �� ����...");
	Sleep(1500);
	gotoxy(23, 25);
	printf("�� 10 ���");
	Sleep(1500);
}

void draw_physical()
{
	draw_gongback();
	gotoxy(15, 21);
	printf("���� ������ ��� �� �־���...");
	Sleep(1500);
	gotoxy(17, 23);
	printf("�˿� ������ ���� �� ����...");
	Sleep(1500);
	gotoxy(23, 25);
	printf("������ 10 ���");
	Sleep(1500);
}

void draw_death()
{
	draw_gongback();
	gotoxy(13, 22);
	printf("�˿��� �ƹ��͵� ������ �ʾҴ�...");
	Sleep(2000);
	gotoxy(6, 24);
	printf("���� ����� ������ �ٶ󺸴� ���� ������ �����...");
	Sleep(2000);
	if (death == 1)
	{
		draw_gongback();
		gotoxy(24, 23);
		printf("�� �׷���?");
		Sleep(300);
	}
	else if (death == 3)
	{
		draw_gongback();
		gotoxy(23, 23);
		printf("�峭���� ��");
		Sleep(300);
	}
	else if (death == 5)
	{
		draw_gongback();
		gotoxy(26, 23);
		printf("��վ�?");
		Sleep(300);
	}
	else if (death == 8)
	{
		draw_gongback();
		gotoxy(24, 23);
		printf("���� �׸���");
		Sleep(300);
	}
	else if (death == 10)
	{
		draw_gongback();
		gotoxy(24, 23);
		printf(".........");
		Sleep(300);
	}
	else if (death == 13)
	{
		draw_gongback();
		gotoxy(25, 24);
		setcolor(red, black);
		printf("������");
		Sleep(300);
		setcolor(white, black);
	}
}

void draw_gongback()
{
	gotoxy(3, 20);
	printf("                                                        ");
	gotoxy(3, 21);
	printf("                                                        ");
	gotoxy(3, 22);
	printf("                                                        ");
	gotoxy(3, 23);
	printf("                                                        ");
	gotoxy(3, 24);
	printf("                                                        ");
	gotoxy(3, 25);
	printf("                                                        ");
	gotoxy(3, 26);
	printf("                                                        ");
	gotoxy(3, 27);
	printf("                                                        ");
}



void draw_intelli_ending()
{
	system("cls");
	int h, w; // h�� ����, w�� ����

	for (h = 0; h < 30; h++)
	{
		for (w = 0; w < 60; w++)
		{
			char temp = intelli_ending[h][w];
			if (temp == '0')
			{
				setcolor(white, white);
				printf(" ");
			}
			else if (temp == '1')
			{
				setcolor(black, black);
				printf("#");
			}
		}
		printf("\n");
	}
	setcolor(black, white);
}

void print_intelli_ending()
{
	draw_intelli_ending();
	gotoxy(3, 21);
	printf("- ���� ������ Ű���ּż� �����ؿ�!");
	Sleep(4000);
	draw_gongback();
	gotoxy(3, 21);
	printf("����� �� �տ��� ���̰� �� �ִ�.");
	Sleep(4000);
	draw_gongback();
	gotoxy(3, 21);
	printf("- ����� ���� �о��ֽ� å��, �ʹ� ����־����!");
	Sleep(4000);
	gotoxy(5, 22);
	printf("�׷��� �� �ȿ��� ��� ��ٷȴ�ϴ�. ��Ű� �Բ� å��");
	gotoxy(5, 23);
	printf("���� ������!");
	Sleep(4000);
	draw_gongback();
	gotoxy(3, 21);
	printf("���̴� ��۵��� Ȱ¦ �������.");
	Sleep(4000);
	draw_gongback();
	gotoxy(3, 21);
	printf("- ���� �¾ �� ����� ������ ������� ���ھ��.");
	Sleep(4000);
	gotoxy(5, 22);
	printf("���� ����� ������ �ʹ� �ʹ� �ູ�ϰŵ��!");
	Sleep(4000);
	draw_gongback();
	gotoxy(3, 21);
	printf("- �����ε� �Բ� ��� �ִ� å ���� ���� �����鼭");
	gotoxy(5, 22);
	printf("���� ���� �ູ�ϰ� ��ƿ�!");
	Sleep(5000);
	draw_gongback();
	gotoxy(23, 22);
	printf("Ending_01");
	Sleep(3000);
	gotoxy(14, 24);
	printf("���󿡼� ���� �ȶ��� ����");
	Sleep(5000);
}

void draw_mental_ending()
{
	system("cls");
	int h, w; // h�� ����, w�� ����

	for (h = 0; h < 30; h++)
	{
		for (w = 0; w < 60; w++)
		{
			char temp = mental_ending[h][w];
			if (temp == '0')
			{
				setcolor(white, white);
				printf(" ");
			}
			else if (temp == '1')
			{
				setcolor(black, black);
				printf("#");
			}
		}
		printf("\n");
	}
	setcolor(black, white);
}

void print_mental_ending()
{
	draw_mental_ending();
	gotoxy(3, 21);
	printf("- ������! ������!");
	Sleep(4000);
	draw_gongback();
	gotoxy(3, 21);
	printf("����� �� �տ��� �޹����� ���� �ִ�.");
	Sleep(4000);
	draw_gongback();
	gotoxy(3, 21);
	printf("- �뷡! ����! �ҷ���! �뷡!");
	Sleep(4000);
	gotoxy(5, 22);
	printf("(����� �ҷ��ִ� �뷡�� �����鼭 �׻�");
	gotoxy(5, 23);
	printf("��̰� �ູ�߾��)");
	Sleep(4000);
	draw_gongback();
	gotoxy(3, 21);
	printf("�޹����� ����� ��Ҹ��� �䳻���� �뷡�Ѵ�.");
	Sleep(4000);
	gotoxy(3, 22);
	printf("����� �˿��� �ҷ��� �ٷ� �� �뷡��.");
	draw_gongback();
	gotoxy(3, 21);
	printf("- �⻵! ����! ������!");
	Sleep(4000);
	gotoxy(5, 22);
	printf("(���� ����� ������ �ʹ� �⻵��!)");
	Sleep(4000);
	draw_gongback();
	gotoxy(3, 21);
	printf("- �뷡! ���! �Բ�!");
	gotoxy(5, 22);
	printf("(������ ���� ����� ���� �뷡�ҰԿ�");
	gotoxy(5, 23);
	printf("�������� �Բ� �ູ�� �ð��� ������)");
	Sleep(5000);
	draw_gongback();
	gotoxy(23, 22);
	printf("Ending_02");
	Sleep(3000);
	gotoxy(15, 24);
	printf("����� ������ ģ��");
	Sleep(5000);
}

void draw_physical_ending()
{
	system("cls");
	int h, w; // h�� ����, w�� ����

	for (h = 0; h < 30; h++)
	{
		for (w = 0; w < 60; w++)
		{
			char temp = physical_ending[h][w];
			if (temp == '0')
			{
				setcolor(white, white);
				printf(" ");
			}
			else if (temp == '1')
			{
				setcolor(black, black);
				printf("#");
			}
		}
		printf("\n");
	}
	setcolor(black, white);
}

void print_physical_ending()
{
	draw_physical_ending();
	gotoxy(3, 21);
	printf("- �ѿ����-!!!");
	Sleep(4000);
	draw_gongback();
	gotoxy(3, 21);
	printf("����� �� �տ��� �ڳ����� �� �ִ�...");
	Sleep(4000);
	draw_gongback();
	gotoxy(3, 21);
	printf("- �ѿ��!!! �ѿ��!!!");
	Sleep(4000);
	gotoxy(5, 22);
	printf("(������ �ݰ�����!!! ��!!! ����� ���� �۱���!!!");
	gotoxy(5, 23);
	printf("��ġ �Ʊ� ���ƿ�!!!)");
	Sleep(4000);
	draw_gongback();
	gotoxy(3, 21);
	printf("�ڳ����� �ڷ� ����� �Ӹ��� ���ɽ��� ���ٵ����.");
	Sleep(4000);
	draw_gongback();
	gotoxy(3, 21);
	printf("- �ѿ�!! �ѿ���!!!");
	Sleep(4000);
	gotoxy(5, 22);
	printf("(����� ���� ���ϰ� Ű���ּ����� �������ʹ�");
	gotoxy(5, 23);
	printf("���� ���� �־ ���� ����� ��ų�Կ�!)");
	Sleep(4000);
	draw_gongback();
	gotoxy(3, 21);
	printf("- �ѿ��-!!! �ѿ�-!!!");
	Sleep(4000);
	gotoxy(5, 22);
	printf("(������� ��Ű� ������ �� ��� �ſ�!)");
	Sleep(4000);
	gotoxy(5, 23);
	printf("(����... �ĺ��, �̸� ����ҰԿ�!)");
	Sleep(5000);
	draw_gongback();
	gotoxy(23, 22);
	printf("Ending_03");
	Sleep(3000);
	gotoxy(14, 24);
	printf("�������� ���� �������� Ű���");
	Sleep(5000);
}

void draw_death_ending()
{
	system("cls");
	int h, w; // h�� ����, w�� ����

	for (h = 0; h < 30; h++)
	{
		for (w = 0; w < 60; w++)
		{
			char temp = death_ending[h][w];
			if (temp == '0')
			{
				setcolor(black, black);
				printf(" ");
			}
			else if (temp == '1')
			{
				setcolor(white, white);
				printf("#");
			}
			else if (temp == '2')
			{
				setcolor(red, red);
				printf("@");
			}
		}
		printf("\n");
	}
	setcolor(white, black);
}

void print_death_ending()
{
	draw_death_ending();
	gotoxy(3, 21);
	printf("- ................");
	Sleep(3000);
	draw_gongback();
	gotoxy(3, 21);
	printf("����� �� �տ��� ���̾��� ���� �ִ�.");
	Sleep(3000);
	draw_gongback();
	gotoxy(3, 21);
	printf("- ................");
	Sleep(3000);
	draw_gongback();
	gotoxy(3, 21);
	printf("������ �¾���� ������?");
	Sleep(3000);
	gotoxy(3, 22);
	printf("�ƴ�, ������ Ʋ�ȴ�.");
	Sleep(3000);
	draw_gongback();
	gotoxy(3, 21);
	printf("�� ���� �����̵� �� �� �־���.");
	Sleep(3000);
	draw_gongback();
	gotoxy(3, 21);
	printf("- ................");
	Sleep(3000);
	draw_gongback();
	gotoxy(3, 21);
	printf("�����, �����̵�, �ڳ�����, �޹�����,");
	gotoxy(3, 22);
	printf("�쵵, �� �����̵�...");
	Sleep(3000);
	draw_gongback();
	gotoxy(3, 21);
	printf("- ................");
	Sleep(3000);
	draw_gongback();
	gotoxy(3, 21);
	printf("Ȥ�� ����� ���̰� �� ���� �־��� �ʹ�.");
	Sleep(3000);
	draw_gongback();
	gotoxy(3, 21);
	printf("����� �װͿ� ���� ���� �������Ҵ�.");
	Sleep(3000);
	draw_gongback();
	gotoxy(3, 21);
	printf("- ................");
	Sleep(3000);
	draw_gongback();
	gotoxy(3, 21);
	printf("������.");
	Sleep(3000);
	draw_gongback();
	gotoxy(3, 21);
	printf("������ ���� ������ ��ٸ��� �Ϸ� �Ϸ� �ڶ󳪴�");
	Sleep(3000);
	gotoxy(3, 22);
	printf("� �±�� ������ ������ ���� ����.");
	Sleep(3000);
	draw_gongback();
	gotoxy(3, 21);
	printf("- ................");
	Sleep(3000);
	draw_gongback();
	gotoxy(3, 21);
	printf("���� ����� �� ���� ���� ������ �ʾ�����");
	Sleep(3000);
	gotoxy(3, 22);
	printf("�װ��� �󸶳� �����ߴ��� ���� ���Ѵ�.");
	Sleep(3000);
	draw_gongback();
	gotoxy(3, 21);
	printf("\'���ǰ� �ƴϾ���.\'");
	Sleep(700);
	draw_gongback();
	gotoxy(3, 21);
	printf("���� �׷���?");
	Sleep(3000);
	draw_gongback();
	gotoxy(3, 21);
	printf("���� ��ſ��� �� ���̰� ��Ź�ߴ�.");
	Sleep(3000);

	draw_gongback();
	gotoxy(3, 21);
	printf("\'�� �׷���?\'  ");
	Sleep(500);
	gotoxy(3, 21);
	printf("\'�峭���� ��\' ");
	Sleep(500);
	gotoxy(3, 21);
	printf("\'��վ�?\'    ");
	Sleep(500);
	gotoxy(3, 21);
	printf("\'���� �׸���\' ");
	Sleep(500);

	draw_gongback();
	gotoxy(3, 21);
	printf("................");
	Sleep(3000);
	draw_gongback();
	gotoxy(3, 21);
	printf("�峭�̶�� �����ߴ°�?");
	Sleep(3000);
	draw_gongback();
	gotoxy(3, 21);
	printf("�ٽ� �����ϸ� �׸��̶��?");
	Sleep(3000);
	draw_gongback();
	gotoxy(3, 21);
	printf("- ................");
	Sleep(3000);
	draw_gongback();
	gotoxy(3, 21);
	printf("���� ���� ����.");
	Sleep(3000);
	draw_gongback();
	gotoxy(3, 21);
	printf("�׾��� �����̴�.");
	Sleep(3000);
	draw_gongback();
	gotoxy(3, 21);
	printf("����� �׿��� �����̴�.");
	Sleep(3000);
	draw_gongback();
	gotoxy(3, 21);
	printf("���� ������ ���� ����� �� �о�� �ٶ���.");
	Sleep(3000);
	draw_gongback();
	gotoxy(3, 21);
	printf("- �� ���� ���� ������ �ʵ���");
	Sleep(1000);
	draw_gongback();
	gotoxy(23, 22);
	printf("Ending_XX");
	Sleep(3000);
	gotoxy(26, 24);
	printf("å��");
	Sleep(5000);
}
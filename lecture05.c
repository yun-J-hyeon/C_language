#include <stdio.h>

int print_title_screen()
{
	printf("##########################################\n");
	printf("##					##\n");
	printf("##	     Run, Dino, Run!     	##\n");
	printf("##		- VO.1 -		##\n");
	printf("##					##\n");
	printf("##	1. Game Start			##\n");
	printf("##	2. How To Play			##\n");
	printf("##	3. Exit				##\n");
	printf("##					##\n");
	printf("##########################################\n");

	return 0;
}

int print_howtoplay()
{
	printf("##########################################\n");
	printf("##					##\n");
	printf("##		How To Play		##\n");
	printf("##					##\n");
	printf("##	     Jump by pressing		##\n");
	printf("##	      the space bar.		##\n");
	printf("##	If you run into an obstacle,	##\n");
	printf("##	    the game is OVER		##\n");
	printf("##					##\n");
	printf("##########################################\n");

	return 0;
}

int main()
{
	print_title_screen();
	int game_state = 1;
	int input = 0;
	while(game_state)
	{
		printf("input(1~3) : ");
		scanf("%d",&input);
		if(input==3)
		{
			game_state=0;
		}

		else if(input==2)
		{
			print_howtoplay();
			int htp = 1;
			while(htp)
			{
				printf("Return to menu? (1.yes 2.no) : ");
				scanf("%d",&input);
				if(input==1)
				{
					htp = 0;
					print_title_screen();
				}
				else if(input==2)
				{
					print_howtoplay();
				}
			}
		}

	}

	return 0;
}

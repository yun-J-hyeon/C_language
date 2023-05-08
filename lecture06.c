#include "dino_screen.h"
#include <stdio.h>

int main()
{
	screen();

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
			howtoplay();
			int htp = 1;
			while(htp)
			{
				printf("Return to menu? (1.yes 2.no) : ");
				scanf("%d",&input);
				if(input==1)
				{
					htp = 0;
					screen();
				}
				else if(input==2)
				{
					howtoplay();
				}
			}
		}

	}

	return 0;
}

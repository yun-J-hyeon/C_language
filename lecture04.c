#include <stdio.h>

int main()
{
	int enemy;
	enemy = 30;
	int hero;
	printf("주인공의 공격력을 입력하세요 : ");
	scanf("%d", &hero);
	printf("주인공은 공격력이 %d입니다.\n", hero);
	printf("주인공이 적을 공격하여 %d의 데미지를 입혔습니다.\n\n\n", hero);

	if(hero >= enemy)
	{
		printf("적의 잔여 HP : 0\n\n\n");
		printf("적을 물리쳤습니다!\nHappy End");
	}

	else
	{	
		printf("적의 잔여 HP : %d\n\n\n", (enemy - hero));
		printf("적이 주인공을 공격하여 주인공이 뒤졌습니다.\nGame Over");
	}

	return 0;
}

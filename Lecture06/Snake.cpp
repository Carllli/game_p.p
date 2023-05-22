#include <iostream>
#include <conio.h>
#include <Windows.h>

char* map_p[17][17];
int stage_width = 15, stage_height = 15;
char stage_map[17][17];
char* snake;

int print_titleScreen()
{
	printf("***************************************\n");
	printf("*                                     *\n");
	printf("*                                     *\n");
	printf("*             지렁이 게임             *\n");
	printf("*            (Snake  Bite)            *\n");
	printf("*                                     *\n");
	printf("*    1. 게임 시작                     *\n");
	printf("*    2. 게임 설명                     *\n");
	printf("*    3. 게임 랭킹 보기                *\n");
	printf("*    4. 게임 종료 (esc)               *\n");
	printf("***************************************\n");

	return 0;

}

int print_introductionScreen()
{
	system("cls");
	printf("\n************************************\n");
	printf("*       게임 설명 화면입니다.      *\n");
	printf("************************************\n");
	printf("타이틀 화면으로 돌아갈까요?(Y/N).\n\n");

	return 0;
}

int print_playScreen()
{
	printf("********************************************\n");
	printf("*                                          *\n");
	printf("*                                          *\n");
	printf("*                                          *\n");
	printf("*                                          *\n");
	printf("*                                          *\n");
	printf("*                                          *\n");
	printf("*                                          *\n");
	printf("*                                          *\n");
	printf("*                                          *\n");
	printf("*                                          *\n");
	printf("********************************************\n");
	printf("타이틀 화면으로 돌아갈까요? (Y/N).\n\n");
	return 0;
}
void gotoxy(int x, int y)

{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int print_game_screen(int width, int height)
{
	width += 1;
	height += 1;

	system("cls");
	for (int i = 0; i < width; i++) {
		printf("*");
	}
	for (int j = 0; j < height; j++) {
		gotoxy(0, j); printf("*");
		gotoxy(width, j); printf("*");
	}
	gotoxy(0, height);
	for (int i = 0; i <= width; i++) {
		printf("*");
	}
	printf("\n타이틀 화면으로 돌아갈까요? (Y/N).\n\n");

	return 0;
}

void map()
{
	system("cls");
	stage_height += 2;
	stage_width += 2;

	for (int h = 0; h < stage_height; h++)
	{
		for (int w = 0; w < stage_width; w++)
		{
			if (w == 0 || w == stage_width - 1 || h == 0 || h == stage_width - 1)
			{
				stage_map[h][w] = '*';
			}
			else stage_map[h][w] = ' ';

			map_p[h][w] = &stage_map[h][w];
		}
	}

	snake = (char*)malloc(2 * sizeof(char));
	*snake = '^';
	*map_p[5][5] = *snake;

	for (int h = 0; h < stage_height; h++)
	{
		for (int w = 0; w < stage_width; w++)
		{
			printf("%c", stage_map[h][w]);
			if (w == stage_width - 1) printf("\n");
		}
	}

	free(snake);

	printf("\n타이틀 화면으로 돌아갈까요? (Y/N).\n\n");

}



int main()
{


	char input;
	int game_status = 0, running = 1;
	int x, y;

	while (running)
	{
		switch (game_status)
		{
		case 0: print_titleScreen();
			while (1)
			{
				input = _getch();
				if (input == '1') {
					game_status = 1; break;
				}
				if (input == '2') {
					game_status = 2; break;
				}
				if (input == '4' || input == 27)
				{
					running = 0; break;
				}
				else
				{
					continue;
				}
			}
			break;
		case 1:
			/*printf("x축 값 : "); scanf_s("%d", &x);
			printf("y축 값 : "); scanf_s("%d", &y);
			print_game_screen(x, y);*/
			map();
			while (true)
			{
				input = _getch();
				if (input == 'y') {
					system("cls");
					game_status = 0; break;
				}
				else if (input == 'n') continue;
			}
			break;
		case 2: print_introductionScreen();
			while (1)
			{
				input = _getch();
				if (input == 'y') {
					system("cls");
					game_status = 0; break;
				}
				else if (input == 'n') continue;
			}
			break;
		default: break;
		}



	}
}
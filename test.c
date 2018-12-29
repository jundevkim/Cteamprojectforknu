#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>

void gotoxy(int, int);
void drawday();
void interFood();
void drawMenu();

void main() {
	int a, b, c;
	system("mode con:cols=160 lines=60");
	system("title 식단표");

	
	
	for (a = 0; a < 46; a++) {
		printf("|");
		if (a == 0 || a % 9 == 0) {
			for (b = 0; b < 139; b++) {
				gotoxy(b + 1, a);
				if ((b + 1) % 20 == 0)printf("|");
				printf("-");

			}
		}
		else {
			for (b = 0; b < 139; b++) {
				gotoxy(b + 1, a);
				if ((b + 1) % 20 == 0)printf("|");
				printf(" ");

			}
			
		}
		printf("|\n");
	}
	drawMenu();
	drawday();
	
	gotoxy(159, 50);
	printf("\n      F1.저장하기  F2.건강식단보기  F3.랜덤으로 섞기 F4.음식 찾기\n\n\n");
	
	gotoxy(141, 0);
	printf("▲");
	gotoxy(141, 45);
	printf("▼");
	gotoxy(159, 50);
/*
	for (i = 0; i < 30; i++){
		printf("|");
		
		for (x = 0; x < 90; x++) {
			gotoxy(x+1, i);
			printf("-");
			
		}printf("|\n");
	}

*/
/*
	for (x = 0; x < 50; x++) {
		printf("|");
		
		if (x == 0 || x == 49) {

			for (y = 0; y < 148; y++)printf("-");
			gotoxy(x, y);
		}
		printf("|\n");
	}//사각형 테두리 만들기
	*/

}

void gotoxy(int x, int y)

{

	COORD Pos = { x , y};

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

}

void drawday() {
	int a, b, count = 0;
	for (b = 0; b < 5; b++) {
		if (count == 31)return;
		
			gotoxy(1, b * 9 + 1);			
			printf("월");
			count++;
			if (count == 31)return;
			gotoxy(21, b * 9 + 1);
			printf("화");
			count++;
			if (count == 31)return;
			gotoxy(41, b * 9 + 1);
			printf("수");
			count++;
			if (count == 31)return;
			gotoxy(61, b * 9 + 1);
			printf("목");
			count++;
			gotoxy(81, b * 9 + 1);
			printf("금");
			count++;
			gotoxy(101, b * 9 + 1);
			printf("토");
			count++;
			gotoxy(121, b * 9 + 1);
			printf("일");
			count++;
		
	}
}

void drawMenu() {
	
	}


void interFood() {
	gotoxy(1, 2);
	printf("현미밥");
	gotoxy(1, 3);
	printf("두부 된장 찌개");
	gotoxy(1, 4);
	printf("오이무침");
}


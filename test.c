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
	system("title �Ĵ�ǥ");

	
	
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
	printf("\n      F1.�����ϱ�  F2.�ǰ��Ĵܺ���  F3.�������� ���� F4.���� ã��\n\n\n");
	
	gotoxy(141, 0);
	printf("��");
	gotoxy(141, 45);
	printf("��");
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
	}//�簢�� �׵θ� �����
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
			printf("��");
			count++;
			if (count == 31)return;
			gotoxy(21, b * 9 + 1);
			printf("ȭ");
			count++;
			if (count == 31)return;
			gotoxy(41, b * 9 + 1);
			printf("��");
			count++;
			if (count == 31)return;
			gotoxy(61, b * 9 + 1);
			printf("��");
			count++;
			gotoxy(81, b * 9 + 1);
			printf("��");
			count++;
			gotoxy(101, b * 9 + 1);
			printf("��");
			count++;
			gotoxy(121, b * 9 + 1);
			printf("��");
			count++;
		
	}
}

void drawMenu() {
	
	}


void interFood() {
	gotoxy(1, 2);
	printf("���̹�");
	gotoxy(1, 3);
	printf("�κ� ���� �");
	gotoxy(1, 4);
	printf("���̹�ħ");
}


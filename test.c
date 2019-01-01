#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>

void gotoxy(int, int);
//void drawday();
void drawMenu();
void drawTable(int, int);
void drawData();
void storeData();

struct date {
	int year, month, day;
};

struct meal {
	struct date meal_calendary;
	int meal_num;//메뉴 개수
	char meal_menu[4][16];

};

void main() {
	int a, b, c;
	system("mode con:cols=160 lines=60");
	system("title 식단표");

	drawTable(2, 2);
	
	struct date tmp_date = {19, 1, 1};
	struct meal meal_tmp[2] = {
		{tmp_date, 4, "현미밥", "소고기국", "멸치볶음", "김치"},
		{tmp_date, 2, "E", "D"}
	};

	drawData(meal_tmp);

	gotoxy(159, 49);

}

	/*
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
	//drawday();

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


	
		gotoxy(159, 50);

	
	}
	*/



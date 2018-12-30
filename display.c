#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>

void gotoxy(int, int);
void drawMenu();

void drawTable(int startpoint_y, int endpoint) {
	/*
		This function is purpose for drawing calendary table. I'm not sure to fix width, and height or change...
		startpoint is the point which is draw at first and draw (0,startpoint_y).
		endpoint is the point which is draw at last.

		Each blank is 10 heights, and 20 widhts.
	*/
	int line, column;
	
	drawMenu();

	
	gotoxy(0, startpoint_y);
	for (line = startpoint_y; line < 46 + startpoint_y; line++) {
		printf("|");
		if ((line - startpoint_y) == 0 || (line-startpoint_y) % 9  == 0) {
			for (column = 0; column < 139; column++) {
				gotoxy(column + 1, line);
				if ((column + 1) % 20 == 0)printf("|");
				printf("-");

			}
		}
		else {
			for (column = 0; column < 139; column++) {
				gotoxy(column + 1, line);
				if ((column + 1) % 20 == 0)printf("|");
				printf(" ");

			}

		}
		printf("|\n");
	}
}

void drawMenu() {
	//인수로 년, 월, 일 받게 하는게 좋을 거 같음.
	//고정된 크기로 출력하도록 해놓았음. 위치를 옮겨야 한다면 아예 새로 짜야할듯

	int a, b, c;
	gotoxy(0, 0);
	printf("|");

	for (a = 0; a < 39; a++) printf("-");

	printf("|");

	for(a = 0; a<5; a++) printf("-------------------|");

	gotoxy(0, 1);
	printf("|");
	for (a = 0; a < 39; a++) printf(" ");
	printf("|");
	for (a = 0; a < 5; a++) printf("                   |");

	gotoxy(41, 1);
	printf("F1. test1");

	gotoxy(61, 1);
	printf("F2. test2");

	gotoxy(81, 1);
	printf("F3. test3");

	gotoxy(101, 1);
	printf("F4. test4");

	gotoxy(121, 1);
	printf("F5. test5");

}

void inputData() {
	/*
		This function is purpose for input data which is data, food menu, or otherthings....
		by manipulate each blank as elements in array.

		따라서 인수를 구조체 배열 포인터로 받는게 좋을 것 같아효오오오

	*/
	
	int i, j, k;

	struct dummy{
		int a ;
		int b;
		double c;
	};

	

	struct blankcoord
	{
		int x, y;

	};

	struct blankcoord blank[31] = {
		{2,39}, {22, 3}, {42, 3}, {62, 3}, {82, 3}, {102, 3}, {122, 3},
		{2,12}, {22, 12}, {42, 12}, {62, 12}, {82, 12}, {102, 12}, {122, 12},
		{2,21}, {22, 21}, {42, 21}, {62, 21}, {82, 21}, {102, 21}, {122, 21},
		{2,30}, {22, 30}, {42, 30}, {62, 30}, {82, 30}, {102, 30}, {122, 30},
		{2,39}, {22, 39}, {42, 39}
	};//X and Y coordinate in decarte for each blanks.

	struct dummy dummy_data1;
	dummy_data1.a = 1;
	dummy_data1.b = 2;
	dummy_data1.c = 123.123;

	struct dummy dummy_data2;
	dummy_data2.a = 11;
	dummy_data2.b = 22;
	dummy_data2.c = 112233.112233;

	//이건 각 항목별로 실제로 데이터가 들어갈 동작부분임
	//줄바꿈하려면 Y좌표를 직접 바꿔줘야함.
	//인수로 받는 구조체 포인트 배열 개수는 해당달의 일의 개수가 될거 같기에 반복문에 조건 걸어두면 될거같음
	for (i = 0; i < 2; i++) {
		gotoxy(blank[0].x, blank[0].y);
		printf("%d", dummy_data1.a);
	}






}











void gotoxy(int x, int y)

{

	COORD Pos = { x , y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

}
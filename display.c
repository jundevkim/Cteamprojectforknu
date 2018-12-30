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
	//�μ��� ��, ��, �� �ް� �ϴ°� ���� �� ����.
	//������ ũ��� ����ϵ��� �س�����. ��ġ�� �Űܾ� �Ѵٸ� �ƿ� ���� ¥���ҵ�

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

		���� �μ��� ����ü �迭 �����ͷ� �޴°� ���� �� ����ȿ������

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

	//�̰� �� �׸񺰷� ������ �����Ͱ� �� ���ۺκ���
	//�ٹٲ��Ϸ��� Y��ǥ�� ���� �ٲ������.
	//�μ��� �޴� ����ü ����Ʈ �迭 ������ �ش���� ���� ������ �ɰ� ���⿡ �ݺ����� ���� �ɾ�θ� �ɰŰ���
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
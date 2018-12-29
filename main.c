#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>

void gotoxy(int, int);

void drawTable(int startpoint_y, int endpoint) {
	/*
		This function is purpose for drawing calendary table. I'm not sure to fix width, and height or change...
		startpoint is the point which is draw at first and draw (0,startpoint_y).
		endpoint is the point which is draw at last.
	*/
	int line, column;

	




	
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


void gotoxy(int x, int y)

{

	COORD Pos = { x , y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

}
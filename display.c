#include "dataset.h"

void gotoxy(int, int);
void drawMenu();


void drawTable(int startpoint_y, int endpoint) {
	/*
		This function is purpose for drawing calendary table. I'm not sure to fix width, and height or change...
		startpoint is drawing at first and (0,startpoint_y).
		endpoint is drawing at last.

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
	printf("F1. ���� �Ĵ� ¥��");

	gotoxy(61, 1);
	printf("F2. �ǰ��� ¥��");

	gotoxy(81, 1);
	printf("F3. ���� �߰�/�˻�");

	gotoxy(101, 1);
	printf("F4. ����/�ҷ�����");

	gotoxy(121, 1);
	printf("F5. �����ϱ�");


	gotoxy(1, 49);
	printf("��-----���� �Ĵ� ����");

	gotoxy(121, 49);
	printf("���� �Ĵ� ����-----��");

}

void drawData(struct meal *p, int *index_right, int *index_left) {
	/*
		This function is purpose for input data which is data, food menu, or otherthings....
		by manipulate each blank as elements in array.

		���� �μ��� ����ü �迭 �����ͷ� �޴°� ���� �� ����ȿ������

	*/
	
	int i, j, k, tmp, end;

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
		{2,3}, {22, 3}, {42, 3}, {62, 3}, {82, 3}, {102, 3}, {122, 3},
		{2,12}, {22, 12}, {42, 12}, {62, 12}, {82, 12}, {102, 12}, {122, 12},
		{2,21}, {22, 21}, {42, 21}, {62, 21}, {82, 21}, {102, 21}, {122, 21},
		{2,30}, {22, 30}, {42, 30}, {62, 30}, {82, 30}, {102, 30}, {122, 30},
		{2,39}, {22, 39}, {42, 39}
	};//X and Y coordinate in decarte for each blanks.


	//�̰� �� �׸񺰷� ������ �����Ͱ� �� ���ۺκ���
	//�ٹٲ��Ϸ��� Y��ǥ�� ���� �ٲ������.
	//�μ��� �޴� ����ü ����Ʈ �迭 ������ �ش���� ���� ������ �ɰ� ���⿡ �ݺ����� ���� �ɾ�θ� �ɰŰ���
	//�����Ŵ� main���� ó���ؾ��ҰŰ���
	//gotoxy(2, 45);
	//printf(" index = %d",  *index_right);
	*index_left = *index_right;


	
	switch ((p + *index_right)->meal_calendary.month) {
	case 2: {
		if (((p->meal_calendary.year) % 4 == 0) && ((p->meal_calendary.year) % 100 == 0))
			end = 29;
		else if (((p->meal_calendary.year) % 400 == 0))
			end = 29;
		else
			end = 28;
	}
			break;

	case 1: case 3: case 5: case 7: case 8:case 10: case 12: end = 31;
			break;

	default: end = 30;
	}
	
	
	gotoxy(2, 1);
	printf("%d�� �Ĵ�ǥ", (p + *index_right)->meal_calendary.year);
	

	for (i = (p + *index_right)->meal_calendary.day ; i <= end; i++) {
		gotoxy((p + *index_right)->x, (p + *index_right)->y);
		printf("%d�� %d�� ", (p + *index_right)->meal_calendary.month, (p + *index_right)->meal_calendary.day);
		
		for (j = 0; j < (p + *index_right)->meal_num; j++) {
			gotoxy((p + *index_right)->x, (p + *index_right)->y + j + 1);
			printf("%s", (p + *index_right)->meal_menu[j]);
		}
		
		(*index_right)++; 
		if (*index_right >= 365) {
			*index_right = 0;
			break;
		}
	}
	
}

void drawData_left(struct meal *p, int *index_right, int *index_left) {
	int i, j;

	if (*index_left == 0) {
		*index_right = 0;
		*index_left = 364;
	}
	else {
		*index_right = *index_left;
		(*index_left)--;
	}

	gotoxy(2, 1);
	printf("%d��", (p + *index_left)->meal_calendary.year);

	
	for (i = (p + *index_left)->meal_calendary.day; ;) {
		gotoxy((p + *index_left)->x, (p + *index_left)->y);
		printf("%d�� %d�� ", (p + *index_left)->meal_calendary.month, (p + *index_left)->meal_calendary.day);
		
		for (j = 0; j < (p + *index_left)->meal_num; j++) {
			gotoxy((p + *index_left)->x, (p + *index_left)->y + j + 1);
			printf("%s", (p + *index_left)->meal_menu[j]);
		}

		if ((p + *index_left)->meal_calendary.day == 1 || *index_left==0) {
			break;
		}

		
		(*index_left)--;
		
		
	}

}
















void gotoxy(int x, int y)

{

	COORD Pos = { x , y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

}
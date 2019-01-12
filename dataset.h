#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#pragma warning(disable: 4996)

void drawData(struct meal *, int *, int*);
void drawData_left(struct meal *, int *, int*);
void gotoxy(int, int);
void drawMenu();
void drawTable(int, int);
void input_data(struct meal *, struct food_category *, struct food_category *, struct food_category *, struct food_category *, struct food_category *, struct food_category *);
void storeData(struct food_category *, struct food_category *, struct food_category *, struct food_category *, struct food_category *, struct food_category *);
void drawSquare(int , int );



struct date {
	int year, month, day, mday;
};

struct meal {
	struct date meal_calendary;
	int meal_num;//메뉴 개수
	char meal_menu[4][16];
	int x, y;

};

struct food_category {
	int num;//해당 카테고리화 된 음식의 개수
	char food_name[100][16];
	int calorie[100];
};

struct blankcoord
{
	int x, y;

};

/*
struct blankcoord blank[31] = {
		{2,3}, {22, 3}, {42, 3}, {62, 3}, {82, 3}, {102, 3}, {122, 3},
		{2,12}, {22, 12}, {42, 12}, {62, 12}, {82, 12}, {102, 12}, {122, 12},
		{2,21}, {22, 21}, {42, 21}, {62, 21}, {82, 21}, {102, 21}, {122, 21},
		{2,30}, {22, 30}, {42, 30}, {62, 30}, {82, 30}, {102, 30}, {122, 30},
		{2,39}, {22, 39}, {42, 39}
};*/
//X and Y coordinate in decarte for each blanks.

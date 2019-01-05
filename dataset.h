#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#pragma warning(disable: 4996)

struct date {
	int year, month, day, mday;
};

struct meal {
	struct date meal_calendary;
	int meal_num;//메뉴 개수
	char meal_menu[4][16];

};

struct food_category {
	int num;//해당 카테고리화 된 음식의 개수
	char food_name[100][16];
};
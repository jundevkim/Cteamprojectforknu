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
	int meal_num;//�޴� ����
	char meal_menu[4][16];

};

struct food_category {
	int num;//�ش� ī�װ�ȭ �� ������ ����
	char food_name[100][16];
};
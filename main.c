#include "dataset.h"

void gotoxy(int, int);
void drawMenu();
void drawTable(int, int);
void storeData();


void main() {
	int i, a, b, c, index = 0;//index�� �迭 �����Ͱ� ��� ǥ���ؾ� ���� �˷��� ��ġ
	char keyboard_value;
	system("mode con:cols=160 lines=60");
	system("title �Ĵ�ǥ");

	drawTable(2, 2);

	struct food_category bob = { {10}, "���̹�","�������","����","��巹��","�ҹ�","Ŭ�η����","���ڹ�","�����","��1","��2","��3" };
	struct food_category gook = { {10}, "�Ұ�ⱹ","�̿���","����","��1","��2","��3","��4","��5","��6","��7","��8" };
	struct food_category banchan = { {10}, "�Ұ��������","��ġ����","����1","����2","����3","����4","����5","����6","����7","����8","����9" };
	struct food_category jjige = { {10}, "��ġ�","�����","�1","�2","�3","�4","�5","�6","�7","�8","�9" };
	struct food_category bread_meal = { {0} };//����
	struct food_category noodle = { {0} };//�� ����



	struct meal *cal_meal = (struct meal *)malloc(sizeof(struct meal)*365);
	srand((unsigned int)time(NULL));
	input_data(cal_meal, &bob, &gook, &jjige, &banchan);
	drawData(cal_meal, &index);


	do {
		
		keyboard_value = getch();
		fflush(stdin);
		keyboard_value = getch();
		switch (keyboard_value) {
		case 77:
			
			system("cls");
			drawTable(2, 2);
			drawData(cal_meal, &index);
			//������
			break;
		case 75:
			system("cls");
			drawTable(2, 2);
			drawData_left(cal_meal, &index);
			//����
			break;
		default:;//��� �޴� ��ư

		}
	} while (1);

	//printf("%d\n", cal_meal->meal_num);
	gotoxy(159, 49);



	free(cal_meal);
}



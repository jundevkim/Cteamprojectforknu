#include "dataset.h"

void gotoxy(int, int);
void drawMenu();
void drawTable(int, int);
void storeData();


void main() {
	int i, a, b, c, index_right = 0, index_left;//index�� �迭 �����Ͱ� ��� ǥ���ؾ� ���� �˷��� ��ġ
	int keyboard_value;
	system("mode con:cols=160 lines=60");
	system("title �Ĵ�ǥ");

	drawTable(2, 2);

	struct food_category bob = { {2}, "���̹�","�������","����","��巹��","�ҹ�","Ŭ�η����","���ڹ�","�����","��1","��2","��3" };
	struct food_category gook = { {2}, "�Ұ�ⱹ","�̿���","����","��1","��2","��3","��4","��5","��6","��7","��8" };
	struct food_category banchan = { {3}, "�Ұ��������","��ġ����","����1","����2","����3","����4","����5","����6","����7","����8","����9" };
	struct food_category jjige = { {2}, "��ġ�","�����","�1","�2","�3","�4","�5","�6","�7","�8","�9" };
	struct food_category bread_meal = { {0} };//����
	struct food_category noodle = { {0} };//�� ����



	struct meal *cal_meal = (struct meal *)malloc(sizeof(struct meal)*365);
	srand((unsigned int)time(NULL));
	input_data(cal_meal, &bob, &gook, &jjige, &banchan);
	drawData(cal_meal, &index_right, &index_left);
	
	

	do {
		
		keyboard_value = getch();
		
		if (keyboard_value == 224) {//ȭ��ǥ Ű ���� ���
			keyboard_value = getch();
			switch (keyboard_value) {
			case 77:
				system("cls");
				drawTable(2, 2);
				drawData(cal_meal, &index_right, &index_left);
				//������
				break;
			case 75:

				system("cls");
				drawTable(2, 2);
				drawData_left(cal_meal, &index_right, &index_left);
				//����
				break;
			default:;

			}
		}

		else {//���� �޴� ��ư
			switch (keyboard_value) {
			case 59:
				system("cls");
				gotoxy(35, 35);
				printf("F1 press!\n");
				break;
			case 60:
				break;
			case 61:
				break;
			case 62:
				break;
			case 63:
				break;
			default:;
			}

		}
		
	} while (1);

	//printf("%d\n", cal_meal->meal_num);
	gotoxy(159, 49);



	free(cal_meal);
}



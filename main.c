#include "dataset.h"


void main() {
	int i, a, b, c, index_right = 0, index_left;//index�� �迭 �����Ͱ� ��� ǥ���ؾ� ���� �˷��� ��ġ
	int keyboard_value;
	char removedfoodname[16];
	
	
	
	system("mode con:cols=160 lines=60");
	system("title �Ĵ�ǥ");

	NODE *food, *bob, *gook, *banchan, *jjige, *bread_meal, *noodle;
	NODE *tmp;
	struct meal *cal_meal = (struct meal *)malloc(sizeof(struct meal) * 365);
	
	srand((unsigned int)time(NULL));

	food = NULL;
	bob = NULL;
	gook = NULL;
	banchan = NULL;
	jjige = NULL;
	bread_meal = NULL;
	noodle = NULL;


	/*
	for (i = 0; i < 10; i++) {
		printf("���� �̸� : ");
		storeData(&food, &bob, &gook, &banchan, &jjige, &bread_meal, &noodle);
	}
	printf("���� ������? : ");
	scanf("%s", removedfoodname);
	remover_FoodName(&food, removedfoodname);
	*/
	readFrFile("menu.txt", &food, &bob, &gook, &banchan, &jjige, &bread_meal, &noodle);
	/*
	tmp = food;
	while (tmp != NULL) {
		printf("%s\n", tmp->food_name);
		tmp = tmp->link;
	}
	tmp = bob;
	while (tmp != NULL) {
		printf("%s\n", tmp->food_name);
		tmp = tmp->link;
	}
	tmp = banchan;
	while (tmp != NULL) {
		printf("%s\n", tmp->food_name);
		tmp = tmp->link;
	}
	*/
	remover_LinkedList(&food);
	tmp = food;
	while (tmp != NULL) {
		printf("%s\n", tmp->food_name);
		tmp = tmp->link;
	}

	
	/*
	system("cls");
	drawTable(2, 2);
	input_data(cal_meal, bob, gook, jjige, banchan, bread_meal, noodle);

	drawData(cal_meal, &index_right, &index_left);
	*/

	/*
	struct food_category bob = { {4}, "���̹�","�������","����","��巹��","�ҹ�"};
	struct food_category gook = { {2}, "�Ұ�ⱹ","�̿���","����","��1","��2","��3","��4","��5","��6","��7","��8" };
	struct food_category banchan = { {4}, "�Ұ��������","��ġ����","����1","����2","����3","����4","����5","����6","����7","����8","����9" };
	struct food_category jjige = { {2}, "��ġ�","�����","�1","�2","�3","�4","�5","�6","�7","�8","�9" };
	struct food_category bread_meal = { {2}, "��ġ���佺Ʈ", "��ٻ�����ġ", "������", "��ũ����", "�߻�" };//����
	struct food_category noodle = { {2}, "Į����", "�ø�" };//�� ����
	*/

	/*
	struct meal *cal_meal = (struct meal *)malloc(sizeof(struct meal)*365);
	srand((unsigned int)time(NULL));
	
	
	system("cls");
	drawTable(2, 2);
	input_data(cal_meal, &bob, &gook, &jjige, &banchan, &bread_meal, &noodle);

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
			case 59://���� �Ĵ� ¥��
				system("cls");
				free(cal_meal);
				cal_meal = (struct meal *)malloc(sizeof(struct meal ) * 365);
				input_data(cal_meal, &bob, &gook, &jjige, &banchan, &bread_meal, &noodle);
				drawTable(2, 2);
				index_right = 0;
				drawData(cal_meal, &index_right, &index_left);

			case 60://�ǰ��� ¥��
			*/
				/*�ǰ��� ¥�� ���� �ʿ�*/
	/*
				break;
			case 61://���� �˻�, �߰��� ����
				
				system("cls");
				drawSquare(2, 2);
				storeData(&bob, &gook, &jjige, &banchan, &bread_meal, &noodle);				
				break;
				
			case 62://�����ϱ�
				break;
			case 63://�����ϱ�
				exit(0);
				break;
			default:;
			}

		}
		
	} while (1);

	*/



	//free(cal_meal);
	
}



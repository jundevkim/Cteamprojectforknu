#include "dataset.h"

void storeData(struct food_category *bob, struct food_category *gook, struct food_category *jjige, struct food_category *banchan, struct food_category *bread_meal, struct food_category *noodle) {
	/*
		������ �߰��ϰ�, ī�װ� ���� �����մϴ�.
		������ ī�װ��� �� ������ ������ �ִ����� ���� �̸��� �����ͷ� ������ �ֽ��ϴ�.
	*/

	


		char tmp[16];

		int index ;//���� ī�װ��� ���� index��
		
		fflush(stdin);
		gets(tmp);
		

			if (strstr(tmp, "��") != NULL) {
				index = (*bob).num;				
				strcpy((*bob).food_name[index], tmp);
				((*bob).num)++;

			}
			else if (strstr(tmp, "����") != NULL) {
				index = (*noodle).num;
				strcpy((*noodle).food_name[index], tmp);
				((*noodle).num)++;
			}
			else if (strstr(tmp, "��") != NULL) {
				index = (*gook).num;
				strcpy((*gook).food_name[index], tmp);
				((*gook).num)++;

			}
			else if (strstr(tmp, "�") != NULL) {
				index = (*jjige).num;
				strcpy((*jjige).food_name[index], tmp);
				((*jjige).num)++;
				
			}
			else if (strstr(tmp, "�佺Ʈ") != NULL || strstr(tmp, "������ġ") != NULL || strstr(tmp, "��") != NULL) {
				index = (*bread_meal).num;				
				strcpy((*bread_meal).food_name[index], tmp);				
				((*bread_meal).num)++;
				
			}
			else {
				index = (*banchan).num;
				strcpy((*banchan).food_name[index], tmp);
				((*banchan).num)++;

			}//������, ������ ������ �� �ְ� ���� ������ �� ������ �������� ���ΰ� ������
		



	

			printf("���� �߰�!");
			Sleep(2000);

}

void input_data(struct meal *cal_meal, struct food_category *bob, struct food_category *gook, struct food_category *jjige, struct food_category *banchan, struct food_category *bread_meal, struct food_category *noodle)
{
	int i, j, k;
	int percentage;
	int tot;
	int flag, compare_num;
	
	
	time_t current;
	struct tm *cal_time;
	current = time(NULL);
	cal_time = localtime(&current);


	for (i = 0; i < 365; i++) {
		(cal_meal + i)->meal_calendary.year = cal_time->tm_year + 1900;
		(cal_meal + i)->meal_calendary.month = cal_time->tm_mon + 1;
		(cal_meal + i)->meal_calendary.day = cal_time->tm_mday;
		(cal_meal + i)->meal_calendary.mday = cal_time->tm_wday;
		current += 60 * 60 * 24;//�Ϸ� ����
		cal_time = localtime(&current);

		

	}//��¥ data & �޴� ���� �Է�

	
	//�ϴ� �ߺ� ���� ������� �ʰ� �޴��� �־������
	
	
	for (i = 0; i < 365; i++) {

		
		while (1) {
			percentage = rand() % 100;//1���� 1�ۼ�Ʈ Ȯ���� ������ �ϱ� ����(0, 1, 2, 3 �߿��� 0�� ���� Ȯ��)
			flag = 0;
			if (percentage != 0) {
				(cal_meal + i)->meal_num = rand() % 2 + 2;
				switch ((cal_meal + i)->meal_num) {//3 �Ǵ� 2�� ¥�� �κ�
				case 3:
					if (rand() % 2 == 0) {
						strcpy((cal_meal + i)->meal_menu[0], (*bob).food_name[rand() % ((*bob).num)]);
						strcpy((cal_meal + i)->meal_menu[1], (*gook).food_name[rand() % ((*gook).num)]);
						strcpy((cal_meal + i)->meal_menu[2], (*banchan).food_name[rand() % ((*banchan).num)]);
					}
					else {
						strcpy((cal_meal + i)->meal_menu[0], (*bob).food_name[rand() % ((*bob).num)]);
						strcpy((cal_meal + i)->meal_menu[1], (*jjige).food_name[rand() % ((*jjige).num)]);
						strcpy((cal_meal + i)->meal_menu[2], (*banchan).food_name[rand() % ((*banchan).num)]);

					}

					break;
				case 2:
					strcpy((cal_meal + i)->meal_menu[0], (*bob).food_name[rand() % ((*bob).num)]);
					strcpy((cal_meal + i)->meal_menu[1], (*jjige).food_name[rand() % ((*jjige).num)]);


					break;
				default:
					system("cls");
					printf("�߰�!");
					getch();
					exit(1);
					;
				}
			}
			else {//���Ͻ� ¥�� �κ�
				(cal_meal + i)->meal_num = 1;
				if ((*bread_meal).num > 0 && (*noodle).num > 0) {
					switch (rand() % 2 + 1) {
					case 1:strcpy((cal_meal + i)->meal_menu[0], (*noodle).food_name[rand() % ((*noodle).num)]);
						break;
					case 2:strcpy((cal_meal + i)->meal_menu[0], (*bread_meal).food_name[rand() % ((*bread_meal).num)]);
						break;
					default:
						system("cls");
						printf("�߰�!");
						getch();
						exit(1);
					}
				}
				
			}

			/*********�ߺ� �޴� üũ**********/

			if (i == 0)break;

			//3�������� ��
			if (i == 1)compare_num = 2;//��°���� ù°���� ��, �� �Ϸ縸 ���ϸ��
			else if (i == 2)compare_num = 1;//���� ��°���� ��Ʋ�� ���ϸ� ��
			else compare_num = 0;//�������� 3�� �Ĵ� �ߺ��� �� ������


			for (tot = 1; tot <= 3 - compare_num; tot++) {
				
				for (j = 0; j < (cal_meal + i)->meal_num; j++) {
					for (k = 0; k < (cal_meal + i - tot)->meal_num; k++) {
						if (strcmp((cal_meal + i)->meal_menu[j], (cal_meal + i - tot)->meal_menu[k]) == 0)
						{
							flag = 1;//�ߺ��� ������ �˷��� ����
							break;//�ߺ� �߰�
						}
					}
					if (flag == 1)break;//�ߺ� �߰�

				}
				if (flag == 1)break;//�ᱹ �ߺ� �߰�
				
			}





			if (flag == 0)break;//���������� �ߺ��� ������ Ȯ��
		}
	}
	
		

	//�Ϸ� �����Ҷ����� x��ǥ���� ����
	//������ ���� �� ���� y��ǥ���� �ϳ� ����
	for (i = 0; i < 365; i++) {
		(cal_meal + i)->x = 2+ 20*(((cal_meal + i)->meal_calendary.day - 1) % 7);
		(cal_meal + i)->y = 3 + 9 * (((cal_meal + i)->meal_calendary.day - 1) / 7);
	
	}
	
	
}



#include "dataset.h"

void storeData() {
	/*
		������ ī�װ� ���� �����մϴ�.
		������ ī�װ��� �� ������ ������ �ִ����� ���� �̸��� �����ͷ� ������ �ֽ��ϴ�.
	*/

	

/*
		char tmp[16];

		int i = 0, j = 0, k = 0, e = 0, t;//���� ī�װ��� ���� index��


		for (t = 0; t < 5; t++) {
			scanf("%s", tmp);

			if (strstr(tmp, "��") != NULL) {
				strcpy(bob.food_name[i], tmp);
				i++;
				bob.num = i;

			}
			else if (strstr(tmp, "��") != NULL) {
				strcpy(gook.food_name[j], tmp);
				j++;
				gook.num = j;

			}
			else if (strstr(tmp, "����") != NULL) {
				strcpy(jjige.food_name[e], tmp);
				e++;
				jjige.num = e;
			}
			else {
				strcpy(banchan.food_name[k], tmp);
				k++;
				banchan.num = k;

			}//������, ������ ������ �� �ְ� ���� ������ �� ������ �������� ���ΰ� ������
		}



		printf("������ �з��� ������ ������ %d�� �̸�,\n", bob.num);
		printf("������ �з��� ������ ������ %d�� �̸�,\n", gook.num);
		printf("�������� �з��� ������ ������ %d�� �̸�,\n", banchan.num);

		*/
	



}

void input_data(struct meal *cal_meal, struct food_category *bob, struct food_category *gook, struct food_category *jjige, struct food_category *banchan)
{
	int i, j, k;
	int count;
	int tot;
	int flag, compare_num;
	int tmp_index, tmp_before_indx;
	
	
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
			(cal_meal + i)->meal_num = rand() % 3 + 1;
			flag = 0;
			switch ((cal_meal + i)->meal_num) {
			case 3:
				strcpy((cal_meal + i)->meal_menu[0], (*bob).food_name[rand() % ((*bob).num)]);
				strcpy((cal_meal + i)->meal_menu[1], (*gook).food_name[rand() % ((*gook).num)]);
				strcpy((cal_meal + i)->meal_menu[2], (*banchan).food_name[rand() % ((*banchan).num)]);


				break;
			case 2:
				strcpy((cal_meal + i)->meal_menu[0], (*bob).food_name[rand() % ((*bob).num)]);
				strcpy((cal_meal + i)->meal_menu[1], (*jjige).food_name[rand() % ((*jjige).num)]);


				break;
			case 1:
				strcpy((cal_meal + i)->meal_menu[0], (*banchan).food_name[rand() % ((*banchan).num)]);


				break;
			default:;
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
				if (flag == 1)break;//�ߺ� �߰�
				
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



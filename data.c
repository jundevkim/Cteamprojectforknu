#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable: 4996)

struct date {
	int year, month, day;
};

struct meal {
	struct date meal_calendary;
	int meal_num;//�޴� ����
	char meal_menu[4][16];

};

void storeData() {

	

		struct food_category {
			int num;//�ش� ī�װ�ȭ �� ������ ����
			char food_name[100][16];
		};

		struct food_category bob = { 0 };
		struct food_category gook = { 0 };
		struct food_category banchan = { 0 };
		struct food_category jjige = { 0 };

		

		/*
		char bob[100][16];
		char gook[100][16];
		char banchan[100][16];
		*/

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


	



}

void input_data(struct food_category *tmp_food){
	

	struct meal calendary_meal[31];


}


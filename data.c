#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable: 4996)

struct date {
	int year, month, day;
};

struct meal {
	struct date meal_calendary;
	int meal_num;//메뉴 개수
	char meal_menu[4][16];

};

void storeData() {

	

		struct food_category {
			int num;//해당 카테고리화 된 음식의 개수
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

		int i = 0, j = 0, k = 0, e = 0, t;//음식 카테고리에 대한 index값


		for (t = 0; t < 5; t++) {
			scanf("%s", tmp);

			if (strstr(tmp, "밥") != NULL) {
				strcpy(bob.food_name[i], tmp);
				i++;
				bob.num = i;

			}
			else if (strstr(tmp, "국") != NULL) {
				strcpy(gook.food_name[j], tmp);
				j++;
				gook.num = j;

			}
			else if (strstr(tmp, "지깨") != NULL) {
				strcpy(jjige.food_name[e], tmp);
				e++;
				jjige.num = e;
			}
			else {
				strcpy(banchan.food_name[k], tmp);
				k++;
				banchan.num = k;

			}//반찬임, 반찬은 구분할 수 있게 해줄 음운이 안 보여서 마지막에 놔두게 좋을듯
		}



		printf("밥으로 분류된 음식의 개수는 %d개 이며,\n", bob.num);
		printf("국으로 분류된 음식의 개수는 %d개 이며,\n", gook.num);
		printf("반찬으로 분류된 음식의 개수는 %d개 이며,\n", banchan.num);


	



}

void input_data(struct food_category *tmp_food){
	

	struct meal calendary_meal[31];


}


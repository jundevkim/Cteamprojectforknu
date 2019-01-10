#include "dataset.h"

void storeData() {
	/*
		음식을 카테고리 별로 본류합니다.
		각각의 카테고리는 몇 종류의 음식이 있는지와 음식 이름을 데이터로 가지고 있습니다.
	*/

	

/*
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
		current += 60 * 60 * 24;//하루 증가
		cal_time = localtime(&current);

		

	}//날짜 data & 메뉴 개수 입력

	
	//일단 중복 조건 고려하지 않고 메뉴만 넣었을경우
	
	
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

			/*********중복 메뉴 체크**********/

			if (i == 0)break;

			//3일전까지 비교
			if (i == 1)compare_num = 2;//둘째날은 첫째날과 비교, 즉 하루만 비교하면됨
			else if (i == 2)compare_num = 1;//따라서 셋째날은 이틀을 비교하면 됨
			else compare_num = 0;//나머지는 3일 식단 중복이 안 나오게


			for (tot = 1; tot <= 3 - compare_num; tot++) {
				
				for (j = 0; j < (cal_meal + i)->meal_num; j++) {
					for (k = 0; k < (cal_meal + i - tot)->meal_num; k++) {
						if (strcmp((cal_meal + i)->meal_menu[j], (cal_meal + i - tot)->meal_menu[k]) == 0)
						{
							flag = 1;//중복이 있음을 알려줄 변수
							break;//중복 발견
						}
					}
					if (flag == 1)break;//중복 발견

				}
				if (flag == 1)break;//중복 발견
				
			}





			if (flag == 0)break;//최종적으로 중복이 없음을 확인
		}
	}
	
		

	//하루 증가할때마다 x좌표값이 증가
	//일주일 지날 때 마다 y좌표값이 하나 증가
	for (i = 0; i < 365; i++) {
		(cal_meal + i)->x = 2+ 20*(((cal_meal + i)->meal_calendary.day - 1) % 7);
		(cal_meal + i)->y = 3 + 9 * (((cal_meal + i)->meal_calendary.day - 1) / 7);
	
	}
	
	
}



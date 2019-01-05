#include "dataset.h"

void storeData() {
	/*
		음식을 카테고리 별로 본류합니다.
		각각의 카테고리는 몇 종류의 음식이 있는지와 음식 이름을 데이터로 가지고 있습니다.
	*/

		//일단은 테스트용 데이터
	/*
	struct food_category bob = { {10}, "현미밥","검은콩밥","잡곡밥","곤드레밥","쌀밥","클로렐라밥","감자밥","밥줘용","밥1","밥2","밥3" };
		struct food_category gook = { {10}, "소고기국","미역국","무국","국1","국2","국3","국4","국5","국6","국7","국8" };
		struct food_category banchan = { {10}, "소고기장조림","멸치볶음","반찬1","반찬2","반찬3","반찬4","반찬5","반찬6","반찬7","반찬8","반찬9" };
		struct food_category jjige = { {10}, "김치찌개","된장찌개","찌개1","찌개2","찌개3","찌개4","찌개5","찌개6","찌개7","찌개8","찌개9" };
		*/
		

		/*
		char bob[100][16];
		char gook[100][16];
		char banchan[100][16];
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

void input_data(struct meal *cal_meal, struct food_category *bob, struct food_category *gook, struct food_category *jjige, struct food_category *banchan){
	int i, j, k;
	
	
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

		(cal_meal + i)->meal_num = rand() % 3 + 1;

	}//날짜 data & 메뉴 개수 입력

	
	//일단 중복 조건 고려하지 않고 메뉴만 넣었을경우
	
	for (i = 0; i < 365; i++) {
		switch ((cal_meal + i)->meal_num) {
		case 3:
			strcpy((cal_meal + i)->meal_menu[0], (*bob).food_name[rand()%9 + 1]);
			strcpy((cal_meal + i)->meal_menu[1], (*gook).food_name[rand() % 9 + 1]);
			strcpy((cal_meal + i)->meal_menu[2], (*banchan).food_name[rand() % 9 + 1]);
			

			break;
		case 2:
			strcpy((cal_meal + i)->meal_menu[0], (*bob).food_name[rand() % 9 + 1]);
			strcpy((cal_meal + i)->meal_menu[1], (*jjige).food_name[rand() % 9 + 1]);


			break;
		case 1:
			strcpy((cal_meal + i)->meal_menu[0], (*banchan).food_name[rand() % 9 + 1]);


			break;
		default:;
		}
	}
	

}


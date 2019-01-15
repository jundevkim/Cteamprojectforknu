#include "dataset.h"


void main() {
	int i, a, b, c, index_right = 0, index_left;//index는 배열 데이터가 어디를 표현해야 할지 알려줄 위치
	int keyboard_value;
	char removedfoodname[16];
	
	
	
	system("mode con:cols=160 lines=60");
	system("title 식단표");

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
		printf("음식 이름 : ");
		storeData(&food, &bob, &gook, &banchan, &jjige, &bread_meal, &noodle);
	}
	printf("지울 데이터? : ");
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
	struct food_category bob = { {4}, "현미밥","검은콩밥","잡곡밥","곤드레밥","쌀밥"};
	struct food_category gook = { {2}, "소고기국","미역국","무국","국1","국2","국3","국4","국5","국6","국7","국8" };
	struct food_category banchan = { {4}, "소고기장조림","멸치볶음","반찬1","반찬2","반찬3","반찬4","반찬5","반찬6","반찬7","반찬8","반찬9" };
	struct food_category jjige = { {2}, "김치찌개","된장찌개","찌개1","찌개2","찌개3","찌개4","찌개5","찌개6","찌개7","찌개8","찌개9" };
	struct food_category bread_meal = { {2}, "햄치즈토스트", "쿠바샌드위치", "도너츠", "생크림빵", "쭉빵" };//빵식
	struct food_category noodle = { {2}, "칼국수", "냉면" };//면 종류
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
		
		if (keyboard_value == 224) {//화살표 키 누른 경우
			keyboard_value = getch();
			switch (keyboard_value) {
			case 77:
				system("cls");
				drawTable(2, 2);
				drawData(cal_meal, &index_right, &index_left);
				//오른쪽
				break;
			case 75:
				system("cls");
				drawTable(2, 2);
				drawData_left(cal_meal, &index_right, &index_left);
				//왼쪽
				break;
			default:;

			}
		}

		else {//여긴 메뉴 버튼
			switch (keyboard_value) {
			case 59://랜덤 식단 짜기
				system("cls");
				free(cal_meal);
				cal_meal = (struct meal *)malloc(sizeof(struct meal ) * 365);
				input_data(cal_meal, &bob, &gook, &jjige, &banchan, &bread_meal, &noodle);
				drawTable(2, 2);
				index_right = 0;
				drawData(cal_meal, &index_right, &index_left);

			case 60://건강식 짜기
			*/
				/*건강식 짜기 구현 필요*/
	/*
				break;
			case 61://음식 검색, 추가및 삭제
				
				system("cls");
				drawSquare(2, 2);
				storeData(&bob, &gook, &jjige, &banchan, &bread_meal, &noodle);				
				break;
				
			case 62://저장하기
				break;
			case 63://종료하기
				exit(0);
				break;
			default:;
			}

		}
		
	} while (1);

	*/



	//free(cal_meal);
	
}



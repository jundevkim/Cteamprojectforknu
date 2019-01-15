#include "dataset.h"



void storeData(struct food_category **food, struct food_category **bob, struct food_category **gook, struct food_category **jjige, struct food_category **banchan, struct food_category **bread_meal, struct food_category **noodle) {
	/*
		음식을 추가하고, 카테고리 별로 본류합니다.
		각각의 카테고리는 몇 종류의 음식이 있는지와 음식 이름을 데이터로 가지고 있습니다.
	*/
		NODE *tmp, *new_node, *new_node_sub;
		
		new_node = (NODE *)malloc(sizeof(NODE));
		new_node->link = NULL;
		tmp = *food;

		gets(new_node->food_name);
		
		if (tmp == NULL) {
			//빈 연결 리스트면 첫 번째 노드를 연결
			*food = new_node;
		}

		else {
			while (tmp->link != NULL) {
				tmp = tmp->link;
			}
			tmp->link = new_node;
		}
		
	
		/*****************음식 분류**************************/
		
			if (strstr(new_node->food_name, "밥") != NULL) {
				tmp = *bob;
				new_node_sub = (NODE *)malloc(sizeof(NODE));
				new_node_sub->link = NULL;
				strcpy(new_node_sub->food_name, new_node->food_name);
				if (tmp == NULL) {
					//빈 연결 리스트면 첫 번째 노드를 연결
					*bob = new_node_sub;
				}
				
				else {
					
					while (tmp->link != NULL) {
						tmp = tmp->link;
						
					}
					
					
					tmp->link = new_node_sub;
					printf("1\n");
				}
				

			}
			else if (strstr(new_node->food_name, "국수") != NULL) {
				tmp = *noodle;
				new_node_sub = (NODE *)malloc(sizeof(NODE));
				new_node_sub->link = NULL;
				strcpy(new_node_sub->food_name, new_node->food_name);

				if (tmp == NULL) {
					//빈 연결 리스트면 첫 번째 노드를 연결
					*noodle = new_node_sub;
				}

				else {
					while (tmp->link != NULL) {
						tmp = tmp->link;
					}
					tmp->link = new_node_sub;
				}
			}
			else if (strstr(new_node->food_name, "국") != NULL) {
				tmp = *gook;
				new_node_sub = (NODE *)malloc(sizeof(NODE));
				new_node_sub->link = NULL;
				strcpy(new_node_sub->food_name, new_node->food_name);

				if (tmp == NULL) {
					//빈 연결 리스트면 첫 번째 노드를 연결
					*gook = new_node_sub;
				}

				else {
					while (tmp->link != NULL) {
						tmp = tmp->link;
					}
					tmp->link = new_node_sub;
				}

			}
			else if (strstr(new_node->food_name, "찌개") != NULL) {
				tmp = *jjige;
				new_node_sub = (NODE *)malloc(sizeof(NODE));
				new_node_sub->link = NULL;
				strcpy(new_node_sub->food_name, new_node->food_name);

				if (tmp == NULL) {
					//빈 연결 리스트면 첫 번째 노드를 연결
					*jjige = new_node_sub;
				}

				else {
					while (tmp->link != NULL) {
						tmp = tmp->link;
					}
					tmp->link = new_node_sub;
				}

			}
			else if (strstr(new_node->food_name, "토스트") != NULL || strstr(new_node->food_name, "샌드위치") != NULL || strstr(new_node->food_name, "빵") != NULL) {
				tmp = *bread_meal;
				new_node_sub = (NODE *)malloc(sizeof(NODE));
				new_node_sub->link = NULL;
				strcpy(new_node_sub->food_name, new_node->food_name);

				if (tmp == NULL) {
					//빈 연결 리스트면 첫 번째 노드를 연결
					*bread_meal = new_node_sub;
				}

				else {
					while (tmp->link != NULL) {
						tmp = tmp->link;
					}
					tmp->link = new_node_sub;
				}

			}
			else {
				tmp = *banchan;
				new_node_sub = (NODE *)malloc(sizeof(NODE));
				new_node_sub->link = NULL;
				strcpy(new_node_sub->food_name, new_node->food_name);
				
				if (tmp == NULL) {
					//빈 연결 리스트면 첫 번째 노드를 연결
					*banchan = new_node_sub;
				}

				else {
					while (tmp->link != NULL) {
						tmp = tmp->link;
					}
					tmp->link = new_node_sub;
				}
			
			}//반찬임, 반찬은 구분할 수 있게 해줄 음운이 안 보여서 마지막에 놔두게 좋을듯



			

			
			printf("음식 추가!\n");
			
		

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
		current += 60 * 60 * 24;//하루 증가
		cal_time = localtime(&current);

		

	}//날짜 data & 메뉴 개수 입력

	
	//일단 중복 조건 고려하지 않고 메뉴만 넣었을경우
	
	
	for (i = 0; i < 365; i++) {

		
		while (1) {
			percentage = rand() % 100;//1식이 1퍼센트 확률로 나오기 하기 위함(0, 1, 2, 3 중에서 0이 나올 확률)
			flag = 0;
			if (percentage != 0) {
				(cal_meal + i)->meal_num = rand() % 2 + 2;
				switch ((cal_meal + i)->meal_num) {//3 또는 2식 짜는 부분
				case 3:
					if (rand() % 2 == 0) {
						strcpy((cal_meal + i)->meal_menu[0], (food_name(bob)));
						strcpy((cal_meal + i)->meal_menu[1], (food_name(gook)));
						strcpy((cal_meal + i)->meal_menu[2], (food_name(banchan)));
					}
					else {
						strcpy((cal_meal + i)->meal_menu[0], (food_name(bob)));
						strcpy((cal_meal + i)->meal_menu[1], (food_name(jjige)));
						strcpy((cal_meal + i)->meal_menu[2], (food_name(banchan)));

					}

					break;
				case 2:
					strcpy((cal_meal + i)->meal_menu[0], (food_name(bob)));
					strcpy((cal_meal + i)->meal_menu[1], (food_name(jjige)));


					break;
				default:
					system("cls");
					printf("발견!");
					getch();
					exit(1);
					;
				}
			}
			else {//단일식 짜는 부분
				(cal_meal + i)->meal_num = 1;
				if (food_name_number(bread_meal) > 0 && food_name_number(noodle) > 0) {
					switch (rand() % 2 + 1) {
					case 1:strcpy((cal_meal + i)->meal_menu[0], (food_name(noodle)));
						break;
					case 2:strcpy((cal_meal + i)->meal_menu[0], (food_name(bread_meal)));
						break;
					default:
						system("cls");
						printf("발견!");
						getch();
						exit(1);
					}
				}
				
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
				if (flag == 1)break;//결국 중복 발견
				
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

void find_food_propertise(NODE *food, char *target) {
	/*********************

	찾고자 하는 음식의 이름을 입력하면 
	음식의 칼로리와 가격을 표시해줌

	**********************/

	NODE *tmp, *prev;
	tmp = food;
	prev = tmp;

	if (strcmp(tmp->food_name, target) == 0) {
		printf("음식 이름 : %s", tmp->food_name);
		printf("칼로리 : %d(kal)", tmp->calorie);
		printf("가격 : %d원", tmp->price);
		return;
	}

	while (1) {


		if (strcmp(tmp->food_name, target) == 0) {
			//해당 음식을 발견했다면 지우고 해당 카테고리의 다른 음식 node를 연결
			printf("음식 이름 : %s", tmp->food_name);
			printf("칼로리 : %d(kal)", tmp->calorie);
			printf("가격 : %d원", tmp->price);
			return;


		}
		else {
			prev = tmp;
			tmp = tmp->link;
		}
	}
	printf("해당 음식은 없습니다!");
	Sleep(1500);
	system("cls");


}


char* food_name(NODE *food) {
	/*********************

	해당 카테고리에 있는 음식들중에서
	무작위로 하나를 반환해주는 함수
	
	**********************/
	int count = 0, rand_i, i;//노드(음식) 개수
	NODE *tmp;


	tmp = food;
	count = food_name_number(tmp);
	/*
	while (1) {
		if (tmp == NULL) {
			break;
		}
		else {
			count++;
			tmp = tmp->link;
		}
	}
	*/
	
	rand_i = rand() % count;
	for (i = 0; i < rand_i; i++) {
		tmp = tmp->link;
	}
	return tmp->food_name;

}


int food_name_number(NODE *food) {
	/*********************

	해당 카테고리화된 음식이 
	몇개있는지 알려주는 함수

	**********************/
	int count = 0, rand_i, i;//노드(음식) 개수
	NODE *tmp;


	tmp = food;
	while (1) {
		if (tmp == NULL) {
			break;
		}
		else {
			count++;
			tmp = tmp->link;
		}
	}
	
	return count;

}

void remover_FoodName(NODE **p, char *target) {
	NODE *tmp, *prev;
	tmp = *p;
	prev = tmp;

	if (strcmp(tmp->food_name, target) == 0) {
		*p = tmp->link;
		free(tmp);
		return;
	}

	while (1) {
		

		if (strcmp(tmp->food_name, target) == 0) {
			//해당 음식을 발견했다면 지우고 해당 카테고리의 다른 음식 node를 연결
			prev->link = tmp->link;
			free(tmp);
			return;


		}
		else {
			prev = tmp;
			tmp = tmp->link;
		}
	}
	printf("해당 음식은 없습니다!");
	Sleep(1500);
	system("cls");
	
}

void remover_LinkedList(NODE **p) {
	//연결 리스트p를 메모리 해제 하는 함수

	NODE *tmp, *cur;
	tmp = *p;

	while (tmp != NULL) {
		cur = tmp->link;
		free(tmp);
		tmp = cur;
	}

}

void readFrFile(char * filename, NODE **food, NODE **bob, NODE **gook, NODE **banchan, NODE **jjige, NODE **bread_meal, NODE **noodle) {

	/************************************
	파일로부터 데이터를 읽어서 
	음식에 대한 연결리스트 자료 구조 형성
	************************************/

	FILE *fp;
	NODE *new_node, *tmp_1 ,*new_node_sub ,*tmp;

	fp = fopen(filename, "rt");
	if (fp == NULL) {
		printf("해당 파일은 없습니다!\n");
		return;
	}
	tmp_1 = *food;
	while (!feof(fp)) {
		new_node = (NODE *)malloc(sizeof(NODE));
		new_node->link = NULL;
		fscanf(fp, "%s %d %d", new_node->food_name, &new_node->price, &new_node->calorie);

		if (tmp_1 == NULL) {
			*food = new_node;
			tmp_1 = new_node;
			
		}
		else {
			tmp_1->link = new_node;
			tmp_1 = tmp_1->link;
		}

		if (strstr(new_node->food_name, "밥") != NULL) {
			tmp = *bob;
			new_node_sub = (NODE *)malloc(sizeof(NODE));
			new_node_sub->link = NULL;
			strcpy(new_node_sub->food_name, new_node->food_name);
			if (tmp == NULL) {
				//빈 연결 리스트면 첫 번째 노드를 연결
				*bob = new_node_sub;
			}

			else {

				while (tmp->link != NULL) {
					tmp = tmp->link;

				}


				tmp->link = new_node_sub;
				printf("1\n");
			}


		}
		else if (strstr(new_node->food_name, "국수") != NULL) {
			tmp = *noodle;
			new_node_sub = (NODE *)malloc(sizeof(NODE));
			new_node_sub->link = NULL;
			strcpy(new_node_sub->food_name, new_node->food_name);

			if (tmp == NULL) {
				//빈 연결 리스트면 첫 번째 노드를 연결
				*noodle = new_node_sub;
			}

			else {
				while (tmp->link != NULL) {
					tmp = tmp->link;
				}
				tmp->link = new_node_sub;
			}
		}
		else if (strstr(new_node->food_name, "국") != NULL) {
			tmp = *gook;
			new_node_sub = (NODE *)malloc(sizeof(NODE));
			new_node_sub->link = NULL;
			strcpy(new_node_sub->food_name, new_node->food_name);

			if (tmp == NULL) {
				//빈 연결 리스트면 첫 번째 노드를 연결
				*gook = new_node_sub;
			}

			else {
				while (tmp->link != NULL) {
					tmp = tmp->link;
				}
				tmp->link = new_node_sub;
			}

		}
		else if (strstr(new_node->food_name, "찌개") != NULL) {
			tmp = *jjige;
			new_node_sub = (NODE *)malloc(sizeof(NODE));
			new_node_sub->link = NULL;
			strcpy(new_node_sub->food_name, new_node->food_name);

			if (tmp == NULL) {
				//빈 연결 리스트면 첫 번째 노드를 연결
				*jjige = new_node_sub;
			}

			else {
				while (tmp->link != NULL) {
					tmp = tmp->link;
				}
				tmp->link = new_node_sub;
			}

		}
		else if (strstr(new_node->food_name, "토스트") != NULL || strstr(new_node->food_name, "샌드위치") != NULL || strstr(new_node->food_name, "빵") != NULL) {
			tmp = *bread_meal;
			new_node_sub = (NODE *)malloc(sizeof(NODE));
			new_node_sub->link = NULL;
			strcpy(new_node_sub->food_name, new_node->food_name);

			if (tmp == NULL) {
				//빈 연결 리스트면 첫 번째 노드를 연결
				*bread_meal = new_node_sub;
			}

			else {
				while (tmp->link != NULL) {
					tmp = tmp->link;
				}
				tmp->link = new_node_sub;
			}

		}
		else {
			tmp = *banchan;
			new_node_sub = (NODE *)malloc(sizeof(NODE));
			new_node_sub->link = NULL;
			strcpy(new_node_sub->food_name, new_node->food_name);

			if (tmp == NULL) {
				//빈 연결 리스트면 첫 번째 노드를 연결
				*banchan = new_node_sub;
			}

			else {
				while (tmp->link != NULL) {
					tmp = tmp->link;
				}
				tmp->link = new_node_sub;
			}

		}//반찬임, 반찬은 구분할 수 있게 해줄 음운이 안 보여서 마지막에 놔두게 좋을듯

	}
	fclose(fp);

}



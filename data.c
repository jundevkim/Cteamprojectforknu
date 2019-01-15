#include "dataset.h"



void storeData(struct food_category **food, struct food_category **bob, struct food_category **gook, struct food_category **jjige, struct food_category **banchan, struct food_category **bread_meal, struct food_category **noodle) {
	/*
		������ �߰��ϰ�, ī�װ� ���� �����մϴ�.
		������ ī�װ��� �� ������ ������ �ִ����� ���� �̸��� �����ͷ� ������ �ֽ��ϴ�.
	*/
		NODE *tmp, *new_node, *new_node_sub;
		
		new_node = (NODE *)malloc(sizeof(NODE));
		new_node->link = NULL;
		tmp = *food;

		gets(new_node->food_name);
		
		if (tmp == NULL) {
			//�� ���� ����Ʈ�� ù ��° ��带 ����
			*food = new_node;
		}

		else {
			while (tmp->link != NULL) {
				tmp = tmp->link;
			}
			tmp->link = new_node;
		}
		
	
		/*****************���� �з�**************************/
		
			if (strstr(new_node->food_name, "��") != NULL) {
				tmp = *bob;
				new_node_sub = (NODE *)malloc(sizeof(NODE));
				new_node_sub->link = NULL;
				strcpy(new_node_sub->food_name, new_node->food_name);
				if (tmp == NULL) {
					//�� ���� ����Ʈ�� ù ��° ��带 ����
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
			else if (strstr(new_node->food_name, "����") != NULL) {
				tmp = *noodle;
				new_node_sub = (NODE *)malloc(sizeof(NODE));
				new_node_sub->link = NULL;
				strcpy(new_node_sub->food_name, new_node->food_name);

				if (tmp == NULL) {
					//�� ���� ����Ʈ�� ù ��° ��带 ����
					*noodle = new_node_sub;
				}

				else {
					while (tmp->link != NULL) {
						tmp = tmp->link;
					}
					tmp->link = new_node_sub;
				}
			}
			else if (strstr(new_node->food_name, "��") != NULL) {
				tmp = *gook;
				new_node_sub = (NODE *)malloc(sizeof(NODE));
				new_node_sub->link = NULL;
				strcpy(new_node_sub->food_name, new_node->food_name);

				if (tmp == NULL) {
					//�� ���� ����Ʈ�� ù ��° ��带 ����
					*gook = new_node_sub;
				}

				else {
					while (tmp->link != NULL) {
						tmp = tmp->link;
					}
					tmp->link = new_node_sub;
				}

			}
			else if (strstr(new_node->food_name, "�") != NULL) {
				tmp = *jjige;
				new_node_sub = (NODE *)malloc(sizeof(NODE));
				new_node_sub->link = NULL;
				strcpy(new_node_sub->food_name, new_node->food_name);

				if (tmp == NULL) {
					//�� ���� ����Ʈ�� ù ��° ��带 ����
					*jjige = new_node_sub;
				}

				else {
					while (tmp->link != NULL) {
						tmp = tmp->link;
					}
					tmp->link = new_node_sub;
				}

			}
			else if (strstr(new_node->food_name, "�佺Ʈ") != NULL || strstr(new_node->food_name, "������ġ") != NULL || strstr(new_node->food_name, "��") != NULL) {
				tmp = *bread_meal;
				new_node_sub = (NODE *)malloc(sizeof(NODE));
				new_node_sub->link = NULL;
				strcpy(new_node_sub->food_name, new_node->food_name);

				if (tmp == NULL) {
					//�� ���� ����Ʈ�� ù ��° ��带 ����
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
					//�� ���� ����Ʈ�� ù ��° ��带 ����
					*banchan = new_node_sub;
				}

				else {
					while (tmp->link != NULL) {
						tmp = tmp->link;
					}
					tmp->link = new_node_sub;
				}
			
			}//������, ������ ������ �� �ְ� ���� ������ �� ������ �������� ���ΰ� ������



			

			
			printf("���� �߰�!\n");
			
		

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
					printf("�߰�!");
					getch();
					exit(1);
					;
				}
			}
			else {//���Ͻ� ¥�� �κ�
				(cal_meal + i)->meal_num = 1;
				if (food_name_number(bread_meal) > 0 && food_name_number(noodle) > 0) {
					switch (rand() % 2 + 1) {
					case 1:strcpy((cal_meal + i)->meal_menu[0], (food_name(noodle)));
						break;
					case 2:strcpy((cal_meal + i)->meal_menu[0], (food_name(bread_meal)));
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

void find_food_propertise(NODE *food, char *target) {
	/*********************

	ã���� �ϴ� ������ �̸��� �Է��ϸ� 
	������ Į�θ��� ������ ǥ������

	**********************/

	NODE *tmp, *prev;
	tmp = food;
	prev = tmp;

	if (strcmp(tmp->food_name, target) == 0) {
		printf("���� �̸� : %s", tmp->food_name);
		printf("Į�θ� : %d(kal)", tmp->calorie);
		printf("���� : %d��", tmp->price);
		return;
	}

	while (1) {


		if (strcmp(tmp->food_name, target) == 0) {
			//�ش� ������ �߰��ߴٸ� ����� �ش� ī�װ��� �ٸ� ���� node�� ����
			printf("���� �̸� : %s", tmp->food_name);
			printf("Į�θ� : %d(kal)", tmp->calorie);
			printf("���� : %d��", tmp->price);
			return;


		}
		else {
			prev = tmp;
			tmp = tmp->link;
		}
	}
	printf("�ش� ������ �����ϴ�!");
	Sleep(1500);
	system("cls");


}


char* food_name(NODE *food) {
	/*********************

	�ش� ī�װ��� �ִ� ���ĵ��߿���
	�������� �ϳ��� ��ȯ���ִ� �Լ�
	
	**********************/
	int count = 0, rand_i, i;//���(����) ����
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

	�ش� ī�װ�ȭ�� ������ 
	��ִ��� �˷��ִ� �Լ�

	**********************/
	int count = 0, rand_i, i;//���(����) ����
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
			//�ش� ������ �߰��ߴٸ� ����� �ش� ī�װ��� �ٸ� ���� node�� ����
			prev->link = tmp->link;
			free(tmp);
			return;


		}
		else {
			prev = tmp;
			tmp = tmp->link;
		}
	}
	printf("�ش� ������ �����ϴ�!");
	Sleep(1500);
	system("cls");
	
}

void remover_LinkedList(NODE **p) {
	//���� ����Ʈp�� �޸� ���� �ϴ� �Լ�

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
	���Ϸκ��� �����͸� �о 
	���Ŀ� ���� ���Ḯ��Ʈ �ڷ� ���� ����
	************************************/

	FILE *fp;
	NODE *new_node, *tmp_1 ,*new_node_sub ,*tmp;

	fp = fopen(filename, "rt");
	if (fp == NULL) {
		printf("�ش� ������ �����ϴ�!\n");
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

		if (strstr(new_node->food_name, "��") != NULL) {
			tmp = *bob;
			new_node_sub = (NODE *)malloc(sizeof(NODE));
			new_node_sub->link = NULL;
			strcpy(new_node_sub->food_name, new_node->food_name);
			if (tmp == NULL) {
				//�� ���� ����Ʈ�� ù ��° ��带 ����
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
		else if (strstr(new_node->food_name, "����") != NULL) {
			tmp = *noodle;
			new_node_sub = (NODE *)malloc(sizeof(NODE));
			new_node_sub->link = NULL;
			strcpy(new_node_sub->food_name, new_node->food_name);

			if (tmp == NULL) {
				//�� ���� ����Ʈ�� ù ��° ��带 ����
				*noodle = new_node_sub;
			}

			else {
				while (tmp->link != NULL) {
					tmp = tmp->link;
				}
				tmp->link = new_node_sub;
			}
		}
		else if (strstr(new_node->food_name, "��") != NULL) {
			tmp = *gook;
			new_node_sub = (NODE *)malloc(sizeof(NODE));
			new_node_sub->link = NULL;
			strcpy(new_node_sub->food_name, new_node->food_name);

			if (tmp == NULL) {
				//�� ���� ����Ʈ�� ù ��° ��带 ����
				*gook = new_node_sub;
			}

			else {
				while (tmp->link != NULL) {
					tmp = tmp->link;
				}
				tmp->link = new_node_sub;
			}

		}
		else if (strstr(new_node->food_name, "�") != NULL) {
			tmp = *jjige;
			new_node_sub = (NODE *)malloc(sizeof(NODE));
			new_node_sub->link = NULL;
			strcpy(new_node_sub->food_name, new_node->food_name);

			if (tmp == NULL) {
				//�� ���� ����Ʈ�� ù ��° ��带 ����
				*jjige = new_node_sub;
			}

			else {
				while (tmp->link != NULL) {
					tmp = tmp->link;
				}
				tmp->link = new_node_sub;
			}

		}
		else if (strstr(new_node->food_name, "�佺Ʈ") != NULL || strstr(new_node->food_name, "������ġ") != NULL || strstr(new_node->food_name, "��") != NULL) {
			tmp = *bread_meal;
			new_node_sub = (NODE *)malloc(sizeof(NODE));
			new_node_sub->link = NULL;
			strcpy(new_node_sub->food_name, new_node->food_name);

			if (tmp == NULL) {
				//�� ���� ����Ʈ�� ù ��° ��带 ����
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
				//�� ���� ����Ʈ�� ù ��° ��带 ����
				*banchan = new_node_sub;
			}

			else {
				while (tmp->link != NULL) {
					tmp = tmp->link;
				}
				tmp->link = new_node_sub;
			}

		}//������, ������ ������ �� �ְ� ���� ������ �� ������ �������� ���ΰ� ������

	}
	fclose(fp);

}



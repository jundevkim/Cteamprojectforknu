#include "dataset.h"

void gotoxy(int, int);
void drawMenu();
void drawTable(int, int);
void storeData();


void main() {
	int i, a, b, c, index_right = 0, index_left;//index´Â ¹è¿­ µ¥ÀÌÅÍ°¡ ¾îµð¸¦ Ç¥ÇöÇØ¾ß ÇÒÁö ¾Ë·ÁÁÙ À§Ä¡
	int keyboard_value;
	system("mode con:cols=160 lines=60");
	system("title ½Ä´ÜÇ¥");

	drawTable(2, 2);

	struct food_category bob = { {2}, "Çö¹Ì¹ä","°ËÀºÄá¹ä","Àâ°î¹ä","°ïµå·¹¹ä","½Ò¹ä","Å¬·Î·¼¶ó¹ä","°¨ÀÚ¹ä","¹äÁà¿ë","¹ä1","¹ä2","¹ä3" };
	struct food_category gook = { {2}, "¼Ò°í±â±¹","¹Ì¿ª±¹","¹«±¹","±¹1","±¹2","±¹3","±¹4","±¹5","±¹6","±¹7","±¹8" };
	struct food_category banchan = { {3}, "¼Ò°í±âÀåÁ¶¸²","¸êÄ¡ººÀ½","¹ÝÂù1","¹ÝÂù2","¹ÝÂù3","¹ÝÂù4","¹ÝÂù5","¹ÝÂù6","¹ÝÂù7","¹ÝÂù8","¹ÝÂù9" };
	struct food_category jjige = { {2}, "±èÄ¡Âî°³","µÈÀåÂî°³","Âî°³1","Âî°³2","Âî°³3","Âî°³4","Âî°³5","Âî°³6","Âî°³7","Âî°³8","Âî°³9" };
	struct food_category bread_meal = { {0} };//»§½Ä
	struct food_category noodle = { {0} };//¸é Á¾·ù



	struct meal *cal_meal = (struct meal *)malloc(sizeof(struct meal)*365);
	srand((unsigned int)time(NULL));
	input_data(cal_meal, &bob, &gook, &jjige, &banchan);
	drawData(cal_meal, &index_right, &index_left);
	
	

	do {
		
		keyboard_value = getch();
		
		if (keyboard_value == 224) {//È­»ìÇ¥ Å° ´©¸¥ °æ¿ì
			keyboard_value = getch();
			switch (keyboard_value) {
			case 77:
				system("cls");
				drawTable(2, 2);
				drawData(cal_meal, &index_right, &index_left);
				//¿À¸¥ÂÊ
				break;
			case 75:

				system("cls");
				drawTable(2, 2);
				drawData_left(cal_meal, &index_right, &index_left);
				//¿ÞÂÊ
				break;
			default:;

			}
		}

		else {//¿©±ä ¸Þ´º ¹öÆ°
			switch (keyboard_value) {
			case 59:
				system("cls");
				gotoxy(35, 35);
				printf("F1 press!\n");
				break;
			case 60:
				break;
			case 61:
				break;
			case 62:
				break;
			case 63:
				break;
			default:;
			}

		}
		
	} while (1);

	//printf("%d\n", cal_meal->meal_num);
	gotoxy(159, 49);



	free(cal_meal);
}



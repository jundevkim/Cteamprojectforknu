#include "dataset.h"

void gotoxy(int, int);
void drawMenu();
void drawTable(int, int);
void storeData();


void main() {
	int i, a, b, c;
	system("mode con:cols=160 lines=60");
	system("title 식단표");

	drawTable(2, 2);

	struct food_category bob = { {10}, "현미밥","검은콩밥","잡곡밥","곤드레밥","쌀밥","클로렐라밥","감자밥","밥줘용","밥1","밥2","밥3" };
	struct food_category gook = { {10}, "소고기국","미역국","무국","국1","국2","국3","국4","국5","국6","국7","국8" };
	struct food_category banchan = { {10}, "소고기장조림","멸치볶음","반찬1","반찬2","반찬3","반찬4","반찬5","반찬6","반찬7","반찬8","반찬9" };
	struct food_category jjige = { {10}, "김치찌개","된장찌개","찌개1","찌개2","찌개3","찌개4","찌개5","찌개6","찌개7","찌개8","찌개9" };

	struct meal *cal_meal = (struct meal *)malloc(sizeof(struct meal)*365);
	srand((unsigned int)time(NULL));
	input_data(cal_meal, &bob, &gook, &jjige, &banchan);
	drawData(cal_meal);

	gotoxy(159, 49);
	
	

	free(cal_meal);
}



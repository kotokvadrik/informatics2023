#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "FILELAB.h"

int main(){
	srand(time(NULL));
	car* mas = NULL; int n; int command;
	do{
		printf("\nВведите команду:\n1)Ввод данных\n2)Вывод данных\n3)Генерация массива\n4)Сортировки\n5)Выход\n");
		scanf("%d", &command); scanf("%*c");
		switch(command){
			case 1:
				entermenu(&mas, &n);
				break;
			case 2:
				outmenu(mas, n);
				break;
			case 3:
				generationmenu(&mas, &n);
				break;
			case 4:
				sortsmenu(mas, n);
				break;
			default:
				if (command != 5){printf("Ошибка операции. Повторите ещё раз.\n");}
				break;
		}
	}while(command != 5);
	if (mas != NULL){osvob(&mas,n);}
	return 0;
}

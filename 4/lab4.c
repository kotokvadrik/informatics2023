#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <time.h>
#include "FILELAB.h"

int main() {
	int command;
	printf("Список команд:\n1) Выполнение задания со встроенными функциями\n2) Выполнение задания со своими функциями\n3) Завершить выполнение\n");
	do {
	printf("Enter the command: ");
	command = 0;
	scanf("%d",&command);
	switch (command){
		case 1: prog1();break;
		case 2: prog2();break;
		case 3: return 0;
		default: scanf("%*[^\n]");scanf("%*c");printf("Wrong command! ");break;
	} 	
	}while(1);
}

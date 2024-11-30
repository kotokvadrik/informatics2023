#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <time.h>
#include "FILELAB.h"

char* format(char* str){
	    if (str[0] == '\0') {char* res = calloc(3, sizeof(char)); res[0] = '"'; res[1] = '"'; res[2] = '\0'; return res;}
		for (int i = 0; i < strlen(str); i++){
			if (str[i] == '\t'){str[i] = ' ';}
		}
        char* res = calloc(strlen(str) + 1, sizeof(char));
        int flag = 0;
        for (int i = 0; i < strlen(str); i++){ // создание копии введённой строки с отформатированными пробелами
                if (str[i] == ' ') {
                        if ((flag == 0) ||(str[i+1] == ' ')){continue;} // флаг = 0 только когда пробелы в начале
                        } 
                res[flag] = str[i];
                flag++;
        }
        int n = strlen(res);
        if (res[n-1] == ' '){res[n-1] = '\0';} // удаление пробела в конце
        res = realloc(res, strlen(res)+1); // все двойные пробелы, пробелы в начале и в конце удалены
        flag = 0;
        for (int j = 0; j < strlen(res); j++){ // цикл удаления пробелов после знаков конца предложения (для индивидуального задания)
                if ((res[j] == '.') || (res[j] == '!') || (res[j] == '?')) {flag = 1; continue;} // пред символ знак препинания
                if ((res[j] != '.') && (res[j] != '!') && (res[j] != '?') && (res[j] != ' ')) {flag = 0; continue;} 
                if ((res[j] == ' ') && (flag == 1)){ // если нашли пробел после окончания предложения ->
                        for(int k = j; k < strlen(res); k++ ){
                                res[k] = res[k+1]; // сдвиг влево части строки после пробела
                        }
                        flag = 0;
                        j = j - 1; // коррекция прохода по строке
                        res = realloc(res, strlen(res)+1);
                }
        }
        return res;
}

char* myformat(char* str){
		if (str[0] == '\0') {char* res = calloc(3, sizeof(char)); res[0] = '"'; res[1] = '"'; res[2] = '\0'; return res;}
		for (int i = 0; i < mystrlen(str); i++){
			if (str[i] == '\t'){str[i] = ' ';}
		}
        char* res = calloc(mystrlen(str) + 1, sizeof(char));
        int flag = 0;
        for (int i = 0; i < mystrlen(str); i++){ // создание копии введённой строки с отформатированными пробелами
                if (str[i] == ' ') {
                        if ((flag == 0) ||(str[i+1] == ' ')){continue;} // флаг = 0 только когда пробелы в начале
                        } 
                res[flag] = str[i];
                flag++;
        }
        int n = mystrlen(res);
        if (res[n-1] == ' '){res[n-1] = '\0';} // удаление пробела в конце
        res = realloc(res, mystrlen(res)+1); // все двойные пробелы, пробелы в начале и в конце удалены
        flag = 0;
        for (int j = 0; j < mystrlen(res); j++){ // цикл удаления пробелов после знаков конца предложения (для индивидуального задания)
                if ((res[j] == '.') || (res[j] == '!') || (res[j] == '?')) {flag = 1; continue;} // пред символ знак препинания
                if ((res[j] != '.') && (res[j] != '!') && (res[j] != '?') && (res[j] != ' ')) {flag = 0; continue;} 
                if ((res[j] == ' ') && (flag == 1)){ // если нашли пробел после окончания предложения ->
                        for(int k = j; k < mystrlen(res); k++ ){
                                res[k] = res[k+1]; // сдвиг влево части строки после пробела
                        }
                        flag = 0;
                        j = j - 1; // коррекция прохода по строке
                        res = realloc(res, mystrlen(res)+1);
                }
        }
        return res;
}

char* kav(char* str){ // на вход подается готовая строка, используем эту функцию для подготовки ответа
		if ((strlen(str) == 2) && (str[0] == '"') && (str[1] == '"')){return str;}
        char* res = calloc(strlen(str)*2+2,sizeof(char)); // расстановка кавычек для предложений, разделённых началом или \n или \0
        res[0] = '"';
        int j = 1;
        for (int i = 0; i < strlen(str); i++){ // проход по готовой строке и формирование новой, строки - результата
                if (str[i] == '\n'){ // если нашли переход(конец предложения) ->
                        res[j] = '"';
                        j ++;
                        res[j] = '\n';
                        j ++;
                        res[j] = '"';
                        j ++;
                        continue;
                }
                res[j] = str[i]; // копирование элементов
                j++; 
        }
        res = realloc(res, strlen(res)+1);
        if ((res[strlen(res)-1] == '"') && (res[strlen(res)-2] == '\n')){ //коррекция кавычек в зависимости от конца строки
                res[strlen(res)-1] = '\0';
                return res;
        }
        res = realloc(res, strlen(res)+2); // добавление кавычки в конце
        res[strlen(res)+1] = '\0';
        res[strlen(res)] = '"';
        return res;
}

char* mykav(char* str){ // на вход подается готовая строка, используем эту функцию для подготовки ответа
		if ((mystrlen(str) == 2) && (str[0] == '"') && (str[1] == '"')){return str;}
        char* res = calloc(mystrlen(str)*2+2,sizeof(char)); // расстановка кавычек для предложений, разделённых началом или \n или \0
        res[0] = '"';
        int j = 1;
        for (int i = 0; i < mystrlen(str); i++){ // проход по готовой строке и формирование новой, строки - результата
                if (str[i] == '\n'){ // если нашли переход(конец предложения) ->
                        res[j] = '"';
                        j ++;
                        res[j] = '\n';
                        j ++;
                        res[j] = '"';
                        j ++;
                        continue;
                }
                res[j] = str[i]; // копирование элементов
                j++; 
        }
        res = realloc(res, mystrlen(res)+1);
        if ((res[mystrlen(res)-1] == '"') && (res[mystrlen(res)-2] == '\n')){ //коррекция кавычек в зависимости от конца строки
                res[mystrlen(res)-1] = '\0';
                return res;
        }
        res = realloc(res, mystrlen(res)+2); // добавление кавычки в конце
        res[mystrlen(res)+1] = '\0';
        res[mystrlen(res)] = '"';
        return res;
}

char* mysepar(char* str){ // функция разделения отформатированной строки на предложения + заглавная буква
		if ((mystrlen(str)== 2) && (str[0] == '"') && (str[1] == '"')){return str;}
        char* scopy = calloc(mystrlen(str)+1, sizeof(char));
        mystrcpy(scopy,str);
        if ((scopy[0] >= 97) && (scopy[0] <= 122)){scopy[0] -= 32;} // заглавная буква в начале строки
    	for(int i = 1; i < mystrlen(scopy); i++) // проход по строке и поиск нужных разделителей
            {
            // если найдены крайние "!?.", то делим строку после них 
                    if (((scopy[i] == '.') || (scopy[i] == '!') || (scopy[i] == '?')) && ((scopy[i+1]!= '.') && (scopy[i+1]!= '!') && (scopy[i+1]!= '?'))) 
                            {
                                        scopy = realloc(scopy, (mystrlen(scopy)+2) * sizeof(char));
                                        for (int j = mystrlen(scopy)+1; j > i; j--)
                                        {
                                                scopy[j] = scopy[j-1]; // сдвиг элементов вправо начиная с (i + 1) ого (элементы после разделителя)
                                        }
                                        scopy[i+1] = '\n'; // разделение предложения
                                                i += 2; // коррекция прохода, теперь scopy[i] указывает на 1ую букву следующего предложения или на \0
                                                if ((scopy[i] >= 97) && (scopy[i] <= 122)){scopy[i] -= 32;} // заглавная буква
                            }
                }
        scopy = realloc(scopy, (mystrlen(scopy)+1) * sizeof(char));
        return scopy;
}

char* separ(char* str){ // функция разделения отформатированной строки на предложения + заглавная буква
		if ((strlen(str)== 2) && (str[0] == '"') && (str[1] == '"')){return str;}
        char* scopy = calloc(strlen(str)+1, sizeof(char));
        strcpy(scopy,str);
        if ((scopy[0] >= 97) && (scopy[0] <= 122)){scopy[0] -= 32;} // заглавная буква в начале строки
    	for(int i = 1; i < strlen(scopy); i++) // проход по строке и поиск нужных разделителей
            {
            // если найдены крайние "!?.", то делим строку после них 
                    if (((scopy[i] == '.') || (scopy[i] == '!') || (scopy[i] == '?')) && ((scopy[i+1]!= '.') && (scopy[i+1]!= '!') && (scopy[i+1]!= '?'))) 
                            {
                                        scopy = realloc(scopy, (strlen(scopy)+2) * sizeof(char));
                                        for (int j = strlen(scopy)+1; j > i; j--)
                                        {
                                                scopy[j] = scopy[j-1]; // сдвиг элементов вправо начиная с (i + 1) ого (элементы после разделителя)
                                        }
                                        scopy[i+1] = '\n'; // разделение предложения
                                                i += 2; // коррекция прохода, теперь scopy[i] указывает на 1ую букву следующего предложения или на \0
                                                if ((scopy[i] >= 97) && (scopy[i] <= 122)){scopy[i] -= 32;} // заглавная буква
                            }
                }
        scopy = realloc(scopy, (strlen(scopy)+1) * sizeof(char));
        return scopy;
}

char* mystrcpy(char* s1, const char* s2){ // реализация strcpy
        while (*s2 != '\0'){
                *s1 = *s2;
                s1++;
                s2++;
        }
        *s1 = '\0';
        return s1;
}

size_t mystrlen(const char* str){ //реализация mystrlen
        size_t k = 0;
        while(*str != '\0'){
                k++;
                str++;
        }
        return k;
}

char* mystrcat(char* s1, char* s2){ // реализация strcat
    int n1 =  mystrlen(s1);
	int n2 =  mystrlen(s2);
	int j = 0;
	for (int i = n1; i < n1+n2; i++){
		s1[i] = s2[j];
		j++;
	}
	s1[n1+n2] = '\0';
	return s1;
}

char* myreadline(){
        printf(PROMPTED);
        char *ptr = (char*)malloc(1);
        char buf[81];
        int n, len = 0;
        *ptr = '\0';
        do {
                n = scanf("%80[^\n]",buf);
                if (n < 0){
                        free(ptr);
                        ptr = NULL;
                        continue;
                }
                if (n == 0){scanf("%*c");}
                else {
                        len += strlen(buf);
                        ptr = (char*) realloc(ptr,len + 1);
                        mystrcat(ptr,buf);
                }
        } while(n > 0);
        return ptr;
}

void prog1(){
        clock_t start = clock();
        char* str = readline(PROMPTED);
        printf("Введенная строка: \"%s\"\n", str);
        char* strclear = format(str); //форматирование пробелов
        char* predl = separ(strclear);
        char* res = kav(predl);
        clock_t end = clock();
        printf("Полученные предложения (встроенные функции):\n");
        printf("%s\nВремя выполнения задания программой 1: %lf с\n\n", res, (double)(end-start)/CLOCKS_PER_SEC);
        if (strlen(str) == 0){free(str);free(strclear);}
        else{free(str);free(strclear);free(predl);free(res);}
}

void prog2(){
        scanf("%*c"); // удаление символа \n из буфера который выходит после ввода command
        clock_t start = clock();
        char* str = myreadline();
        printf("Введенная строка: \"%s\"\n", str);
        char* strclear = myformat(str); //форматирование пробелов
        char* predl = mysepar(strclear);
        char* res = mykav(predl);
        clock_t end = clock();
        printf("Полученные предложения (свои функции):\n");
        printf("%s\nВремя выполнения задания программой 2: %lf с\n\n", res,(double)(end-start)/CLOCKS_PER_SEC);
        if (mystrlen(str) == 0){free(str);free(strclear);}
        else{free(str);free(strclear);free(predl);free(res);}
}

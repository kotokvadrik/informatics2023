#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "FILELAB.h"

char* myreadline(){
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
                        strcat(ptr,buf);
                }
        } while(n > 0);
        return ptr;
}

char* myfilereadline(FILE* file){
        char *ptr = (char*)malloc(1);
        char buf[81];
        int n, len = 0;
        *ptr = '\0';
        do {
                n = fscanf(file,"%80[^\n]",buf);
                if (n < 0){
                        free(ptr);
                        ptr = NULL;
                        continue;
                }
                if (n == 0){fscanf(file,"%*c");}
                else {
                        len += strlen(buf);
                        ptr = (char*) realloc(ptr,len + 1);
                        strcat(ptr,buf);
                }
        } while(n > 0);
        return ptr;
}

void swap(car* car1, car* car2){
        car t; 
        memcpy(&t,car1,sizeof(car));
        memcpy(car1,car2,sizeof(car));
        memcpy(car2,&t,sizeof(car));
}

int vvod_car_klav(car* mashina){//память на структуру выделили до, выводит 0 или 1 в зависимости от успешности ввода
        printf("Введите марку: ");
        scanf("%16[^\n]", (mashina -> mark));// проверка на остаток символов, проверка на соответствие тому что в задании
        (mashina -> mark)[16] = '\0';
        if (scanf("%1[^\n]",(mashina -> mark)) == 1){scanf("%*[^\n]");scanf("%*c"); printf("Марка больше 16 символов! Введите ещё раз.\n"); return 0;}
        for (int i = 0; i < strlen(mashina -> mark); i++){
                if ((((mashina -> mark)[i] <= 122 && (mashina -> mark)[i] >= 97) || ((mashina -> mark)[i] <= 90 && (mashina -> mark)[i] >= 65) || ((mashina -> mark)[i] == 45) || ((mashina -> mark)[i] == 32)) == 0){
                        scanf("%*[^\n]");scanf("%*c"); printf("Недопустимые символы поля \"Марка\". Введите ещё раз.\n"); return 0;
                }
        }
        scanf("%*c");
        printf("Введите фио: ");
        mashina -> fio = myreadline();
        printf("Введите пробег: ");
        scanf("%f", &(mashina -> probeg)); // проверка что не осталось больше элементов в сканфе, что число
        scanf("%*[^\n]");
        scanf("%*c");
        return 1;
}

void inicializationKlav(car** mas, int* n){ // в мейне car* mas; int n;
        int r;
        if (*mas != NULL){osvob(mas,*n);}
        printf("Введите количество структур: ");
        scanf("%d", n);
        scanf("%*c");
        *mas = calloc(*n, sizeof(car));
        for (int i = 0; i < *n; i++){
                do{
                        r = vvod_car_klav(&((*mas)[i]));
                }while(r == 0);
        }
}

void output(car* mas, int n){
        if (mas == NULL){printf("Массив не введён!\n"); return;}
        printf("Вывод массива структур:\n");
        for (int i = 0; i < n; i++){
                printf("Марка: \"%s\" ФИО: \"%s\" Пробег: \"%f\"\n", mas[i].mark, mas[i].fio, mas[i].probeg);
        }
        printf("Массив выведен.\n\n");
}

void osvob(car** mas, int n){
        for (int i = 0; i < n; i++){
                free((*mas)[i].fio);
        }
        free(*mas);
        *mas = NULL;
}

void recordText(car* mas, int n){
        if (mas == NULL){printf("Массив не введён!\n"); return;}
        printf("Введите имя текстового файла (+.txt): ");
        char * filename = myreadline();
        FILE* file = fopen(filename,"w+t");
        for (int i = 0; i < n; i++){
                fprintf(file,"%s\n%s\n%f\n", mas[i].mark, mas[i].fio, mas[i].probeg);
        }
        fclose(file);
        free(filename);
}

void readingText(car** mas, int* n){
        printf("Введите имя текстового файла (+.txt): ");
        char * filename = myreadline();
        FILE* file = fopen(filename,"r+t");
                if(file != NULL){
                        if (*mas != NULL){osvob(mas,*n);}
                        *n = 0;
                        int i = 0;
                        *mas = (car*)calloc(1,sizeof(car));
                        while (fscanf(file,"%16[^\n]", (*mas)[i].mark) != EOF){
                                (*mas)[i].mark[16] = '\0';
                                fscanf(file,"%*c");
                                (*mas)[i].fio = myfilereadline(file);
                                fscanf(file, "%f", &((*mas)[i].probeg));
                                fscanf(file,"%*c");
                                *n += 1;
                                i++;
                                *mas = (car*)realloc(*mas, (*n+1) * sizeof(car));
                        }
                        *mas = (car*)realloc(*mas, (*n) * sizeof(car));
                        fclose(file);
                        free(filename);
                }
                else{
                        printf("Ошибка чтения файла .txt\n");
                        fclose(file);
                        if (filename != NULL){free(filename);}
                }
}

void recordBin(car* mas, int n){
        if (mas == NULL){printf("Массив не введён!\n"); return;}
        printf("Введите имя бинарного файла (+.bin): ");
        char * filename = myreadline();
        FILE* file = fopen(filename,"w+b");
        int k;
        for (int i = 0; i < n; i++){
                k = strlen(mas[i].mark);
                fwrite(&k, sizeof(int), 1, file);
                fwrite(mas[i].mark, sizeof(char), k, file);
                k = strlen(mas[i].fio);
                fwrite(&k, sizeof(int), 1, file);
                fwrite(mas[i].fio, sizeof(char), k, file);
                fwrite(&(mas[i].probeg), sizeof(float), 1, file);
        }
        fclose(file);
        free(filename);
}

void readingBin(car** mas, int* n){
        printf("Введите имя текстового файла (+.bin): ");
        char * filename = myreadline();
        FILE* file = fopen(filename,"r+b");
                if(file != NULL){
                        if (*mas != NULL){osvob(mas,*n);}
                        *n = 0;
                        int i = 0;
                        int size;
                        *mas = (car*)calloc(1, sizeof(car));
                        while (fread(&size, sizeof(int), 1, file) == 1){
                                fread((*mas)[i].mark, sizeof(char), size, file);
                                (*mas)[i].mark[size] = '\0';
                                fread(&size, sizeof(int), 1, file);
                                (*mas)[i].fio = calloc(size+1, sizeof(char));
                                fread((*mas)[i].fio, sizeof(char), size, file);
                                (*mas)[i].fio[size] = '\0';
                                fread(&((*mas)[i].probeg), sizeof(float), 1, file);
                                *n += 1;
                                i++;
                                *mas = (car*)realloc(*mas, (*n+1) * sizeof(car));
                        }
                        *mas = (car*)realloc(*mas, (*n) * sizeof(car));
                        fclose(file);
                        free(filename);
                }
                else{
                        printf("Ошибка чтения файла .bin\n");
                        fclose(file);
                        if (filename != NULL){free(filename);}
                }
}

void masGeneration(car** mas, int* n){ // n - кол во в массиве,перед отдельным mas generation надо очищать 
        int randomlen;
        char randomletter;
        *mas = calloc(*n, sizeof(car));
        for (int i = 0; i < *n; i++){
                randomlen = rand()%16+1;
                for(int j = 0; j < randomlen; j++){
                        randomletter = rand()%26+97;
                        ((*mas)[i].mark)[j] = randomletter;
                }
                ((*mas)[i].mark)[randomlen] = '\0';
                randomlen = rand()%10+10;
                (*mas)[i].fio = calloc(randomlen+1, sizeof(char));
                for(int j = 0; j < randomlen; j++){
                        randomletter = rand()%26+97;
                        ((*mas)[i].fio)[j] = randomletter;
                }
                ((*mas)[i].fio)[randomlen] = '\0';
                (*mas)[i].probeg = (float)(rand()%500000+1000);
        }
}

void GenerationFunc(car** mas, int* n){ // исследование сортировки (программа 2)
        clock_t summary; int m; int k; int a; int b; int c;
        clock_t end; clock_t start;
        printf("Выберите сортировку:\n1 - qsort\n2 - bubbleSort\n3 - doubleSelectionSort\n");
        scanf("%d", &a); scanf("%*c");
        printf("Выберите поле:\n1 - марка\n2 - ФИО\n3 - пробег\n");
        scanf("%d", &b); scanf("%*c");
        printf("Выберите направление:\n1 - по возрастанию\n2 - по убыванию\n");
        scanf("%d", &c); scanf("%*c");
        printf("Введите количество генераций массива: ");
        scanf("%d", &m); scanf("%*c");
        printf("Введите количество элементов в генерируемом массиве: ");
        scanf("%d", &k); scanf("%*c");
        if(*mas != NULL){osvob(mas, *n);}
        *n = k;
        for (int i = 0; i < m; i++){
                if(*mas != NULL){osvob(mas, *n);}
                masGeneration(mas,n);
                start = clock();
                if (a == 1){
                        if(b == 1){
                                if (c == 1){qsort(*mas, *n, sizeof(car), compMarkVozr);}
                                else if (c == 2){qsort(*mas, *n, sizeof(car), compMarkUbiv);}
                        }
                        else if (b == 2){
                                if (c == 1){qsort(*mas, *n, sizeof(car), compFioVozr);}
                                else if (c == 2){qsort(*mas, *n, sizeof(car), compFioUbiv);}
                        }
                        else if (b == 3){
                                if (c == 1){qsort(*mas, *n, sizeof(car), compProbegVozr);}
                                else if (c == 2){qsort(*mas, *n, sizeof(car), compProbegUbiv);}
                        }
                }
                else if(a == 2){
                        if(b == 1){
                                if (c == 1){bubbleMark(*mas, *n, 0);}
                                else if (c == 2){bubbleMark(*mas, *n, 1);}
                        }
                        else if (b == 2){
                                if (c == 1){bubbleFio(*mas, *n, 0);}
                                else if (c == 2){bubbleFio(*mas, *n, 1);}
                        }
                        else if (b == 3){
                                if (c == 1){bubbleProbeg(*mas, *n, 0);}
                                else if (c == 2){bubbleProbeg(*mas, *n, 1);}
                        }
                }
                else if(a == 3){
                        if(b == 1){
                                if (c == 1){doubleSelectionMark(*mas, *n, 0);}
                                else if (c == 2){doubleSelectionMark(*mas, *n, 1);}
                        }
                        else if (b == 2){
                                if (c == 1){doubleSelectionFio(*mas, *n, 0);}
                                else if (c == 2){doubleSelectionFio(*mas, *n, 1);}
                        }
                        else if (b == 3){
                                if (c == 1){doubleSelectionProbeg(*mas, *n, 0);}
                                else if (c == 2){doubleSelectionProbeg(*mas, *n, 1);}
                        }
                }
                end = clock();
                summary += (end - start);
        }
        osvob(mas,*n);
        printf("Среднее время сортировки одного массива (на входе %d массивов из %d элементов) - %lf с\n", m, k, ((double)summary) / m / CLOCKS_PER_SEC);}

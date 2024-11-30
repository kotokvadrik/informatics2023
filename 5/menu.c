#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "FILELAB.h"

void entermenu(car** mas, int* n){
        printf("\n1)Ввод с клавиатуры\n2)Ввод из .txt\n3)Ввод из .bin\n4)Выход в главное меню\n");
        int command;
        scanf("%d", &command); scanf("%*c");
        switch(command){
                case 1:
                        inicializationKlav(mas, n);
                        return;
                case 2:
                        readingText(mas, n);
                        return;
                case 3:
                        readingBin(mas, n);
                        return;
                default:
                        return;
        }
}

void outmenu(car* mas, int n){
        printf("\n1)Вывод на экран\n2)Запись в .txt\n3)Запись в .bin\n4)Выход в главное меню\n");
        int command;
        scanf("%d", &command); scanf("%*c");
        switch(command){
                case 1:
                        output(mas, n);
                        return;
                case 2:
                        recordText(mas, n);
                        return;
                case 3:
                        recordBin(mas, n);
                        return;
                default:
                        return;
        }
}

void generationmenu(car** mas, int* n){
        printf("\n1)Генерация массива структур заданной длины (1 массив)\n2)Исследование сортировки (программа 2)\n3)Выход в главное меню\n");
        int command;
        scanf("%d", &command); scanf("%*c");
        switch(command){
                case 1:
                        if (*mas != NULL){osvob(mas,*n);}
                        printf("Введите количество элементов массива структур: ");
                        scanf("%d", n); scanf("%*c");
                        masGeneration(mas, n);
                        printf("Массив из %d элементов успешно сгенерирован!\n", *n);
                        return;
                case 2:
                        GenerationFunc(mas, n);
                        return;
                default:
                        return;
        }
}

void sortsmenu(car* mas, int n){
        printf("\n1)qsort\n2)bubbleSort\n3)doubleSelectionSort\n4)Выход в главное меню\n");
        int a; int b; int c;
        scanf("%d", &a); scanf("%*c");
        if ((a == 1) || (a == 2) || (a == 3)){
        	printf("\nВыберите поле:\n1 - марка\n2 - ФИО\n3 - пробег\n");
        	scanf("%d", &b); scanf("%*c");
     	    printf("\nВыберите направление:\n1 - по возрастанию\n2 - по убыванию\n");
     	    scanf("%d", &c); scanf("%*c");
        }
        switch(a){
                case 1:
                        if(b == 1){
                                if (c == 1){qsort(mas, n, sizeof(car), compMarkVozr);}
                                else if (c == 2){qsort(mas, n, sizeof(car), compMarkUbiv);}
                        }
                        else if (b == 2){
                                if (c == 1){qsort(mas, n, sizeof(car), compFioVozr);}
                                else if (c == 2){qsort(mas, n, sizeof(car), compFioUbiv);}
                        }
                        else if (b == 3){
                                if (c == 1){qsort(mas, n, sizeof(car), compProbegVozr);}
                                else if (c == 2){qsort(mas, n, sizeof(car), compProbegUbiv);}
                        }
                        return;
                case 2:
                        if(b == 1){
                                if (c == 1){bubbleMark(mas, n, 0);}
                                else if (c == 2){bubbleMark(mas, n, 1);}
                        }
                        else if (b == 2){
                                if (c == 1){bubbleFio(mas, n, 0);}
                                else if (c == 2){bubbleFio(mas, n, 1);}
                        }
                        else if (b == 3){
                                if (c == 1){bubbleProbeg(mas, n, 0);}
                                else if (c == 2){bubbleProbeg(mas, n, 1);}
                        }
                        return;
                case 3:
                        if(b == 1){
                                if (c == 1){doubleSelectionMark(mas, n, 0);}
                                else if (c == 2){doubleSelectionMark(mas, n, 1);}
                        }
                        else if (b == 2){
                                if (c == 1){doubleSelectionFio(mas, n, 0);}
                                else if (c == 2){doubleSelectionFio(mas, n, 1);}
                        }
                        else if (b == 3){
                                if (c == 1){doubleSelectionProbeg(mas, n, 0);}
                                else if (c == 2){doubleSelectionProbeg(mas, n, 1);}
                        }
                        return;
                default:
                        return;
        }
}

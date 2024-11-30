#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "FILELAB.h"

void doubleSelectionProbeg(car* mas, int n, int code){ // code == 0 - по возрастанию, code == 1 - по убыванию
        if (mas == NULL){printf("Массив не введён!\n"); return;}
        int indmax;int indmin;
        float minvalue;float maxvalue;
        clock_t start = clock();
        for (int i = 0; i < (n/2); i++){
                minvalue = mas[i].probeg;
                maxvalue = mas[i].probeg;
                indmax = i; indmin = i;
                for (int j = i; j < n - i; j++){
                        if (mas[j].probeg > maxvalue){
                                maxvalue = mas[j].probeg;
                                indmax = j;
                        }
                        if (mas[j].probeg < minvalue){
                                minvalue = mas[j].probeg;
                                indmin = j;
                        }
                }
                if (code == 0){
                        if ((i == indmax) && ((n-i-1) == indmin)){swap(&(mas[i]),&(mas[n-i-1]));}// максимум в начале, мин в конце
                        else if((i == indmax) && ((n-i-1 != indmin))){swap(&(mas[n-i-1]), &(mas[indmax])); swap(&(mas[i]), &(mas[indmin]));} // в начале макс, мин не в конце
                        else{
                                if (indmin != i){swap(&(mas[i]), &(mas[indmin]));}
                                if (indmax != n-i-1){swap(&(mas[n-i-1]), &(mas[indmax]));}
                        }
                }
                else if (code == 1){
                        if ((indmax == n-i-1) && (indmin == i)){swap(&(mas[i]), &(mas[n-i-1]));} // максимум в начале, мин в конце
                        else if ((indmax == n-i-1) && (indmin != i)){swap(&(mas[i]), &(mas[indmax]));swap(&(mas[n-i-1]), &(mas[indmin]));} // в конце макс, мин не в начале
                        else{
                                if (indmin != n-i-1){swap(&(mas[n-i-1]), &(mas[indmin]));}
                                if (indmax != i){swap(&(mas[i]), &(mas[indmax]));}
                                }
                }
        }
        clock_t end = clock();
        printf("Сортировка заняла %lf с\n", (double)(end - start)/CLOCKS_PER_SEC);
}

void doubleSelectionMark(car* mas, int n, int code){ // code == 0 - по возрастанию, code == 1 - по убыванию
        if (mas == NULL){printf("Массив не введён!\n"); return;}
        char* minvalue;
        char* maxvalue;
        int indmax;
        int indmin;
        clock_t start = clock();
        for (int i = 0; i < (n/2); i++){
                minvalue = calloc(17, sizeof(char));
                maxvalue = calloc(17, sizeof(char));
                strcpy(minvalue, mas[i].mark);
                strcpy(maxvalue, mas[i].mark);
                indmax = i; indmin = i;
                for (int j = i; j < n - i; j++){
                        if ((strcmp(mas[j].mark, maxvalue)) > 0){
                                free(maxvalue);
                                maxvalue = calloc(17, sizeof(char));
                                strcpy(maxvalue,mas[j].mark);
                                indmax = j;
                        }
                        if ((strcmp(mas[j].mark, minvalue)) < 0){
                                free(minvalue);
                                minvalue = calloc(17, sizeof(char));
                                strcpy(minvalue,mas[j].mark);
                                indmin = j;
                        }
                }
                if (code == 0){
                        if ((i == indmax) && ((n-i-1) == indmin)){swap(&(mas[i]),&(mas[n-i-1]));}// максимум в начале, мин в конце
                        else if((i == indmax) && ((n-i-1 != indmin))){swap(&(mas[n-i-1]), &(mas[indmax])); swap(&(mas[i]), &(mas[indmin]));} // в начале макс, мин не в конце
                        else{
                                if (indmin != i){swap(&(mas[i]), &(mas[indmin]));}
                                if (indmax != n-i-1){swap(&(mas[n-i-1]), &(mas[indmax]));}
                        }
                }
                else if (code == 1){
                        if ((indmax == n-i-1) && (indmin == i)){swap(&(mas[i]), &(mas[n-i-1]));} // максимум в начале, мин в конце
                        else if ((indmax == n-i-1) && (indmin != i)){swap(&(mas[i]), &(mas[indmax]));swap(&(mas[n-i-1]), &(mas[indmin]));} // в конце макс, мин не в начале
                        else{
                                if (indmin != n-i-1){swap(&(mas[n-i-1]), &(mas[indmin]));}
                                if (indmax != i){swap(&(mas[i]), &(mas[indmax]));}
                        }
                }
                free(minvalue);
                free(maxvalue);
        }
        clock_t end = clock();
        printf("Сортировка заняла %lf с\n", (double)(end - start)/CLOCKS_PER_SEC);
}

void doubleSelectionFio(car* mas, int n, int code){ // code == 0 - по возрастанию, code == 1 - по убыванию
        if (mas == NULL){printf("Массив не введён!\n"); return;}
        char* minvalue;
        char* maxvalue;
        int indmax;
        int indmin;
        clock_t start = clock();
        for (int i = 0; i < (n/2); i++){
                minvalue = calloc(strlen(mas[i].fio)+1, sizeof(char));
                maxvalue = calloc(strlen(mas[i].fio)+1, sizeof(char));
                strcpy(minvalue, mas[i].fio);
                strcpy(maxvalue, mas[i].fio);
                indmax = i; indmin = i;
                for (int j = i; j < n - i; j++){
                        if ((strcmp(mas[j].fio, maxvalue)) > 0){
                                free(maxvalue);
                                maxvalue = calloc(strlen(mas[j].fio)+1, sizeof(char));
                                strcpy(maxvalue,mas[j].fio);
                                indmax = j;
                        }
                        if ((strcmp(mas[j].fio, minvalue)) < 0){
                                free(minvalue);
                                minvalue = calloc(strlen(mas[j].fio)+1, sizeof(char));
                                strcpy(minvalue,mas[j].fio);
                                indmin = j;
                        }
                }
                if (code == 0){
                        if ((i == indmax) && ((n-i-1) == indmin)){swap(&(mas[i]),&(mas[n-i-1]));}// максимум в начале, мин в конце
                        else if((i == indmax) && ((n-i-1 != indmin))){swap(&(mas[n-i-1]), &(mas[indmax])); swap(&(mas[i]), &(mas[indmin]));} // в начале макс, мин не в конце
                        else{
                                if (indmin != i){swap(&(mas[i]), &(mas[indmin]));}
                                if (indmax != n-i-1){swap(&(mas[n-i-1]), &(mas[indmax]));}
                        }
                }
                else if (code == 1){
                        if ((indmax == n-i-1) && (indmin == i)){swap(&(mas[i]), &(mas[n-i-1]));} // максимум в начале, мин в конце
                        else if ((indmax == n-i-1) && (indmin != i)){swap(&(mas[i]), &(mas[indmax]));swap(&(mas[n-i-1]), &(mas[indmin]));} // в конце макс, мин не в начале
                        else{
                                if (indmin != n-i-1){swap(&(mas[n-i-1]), &(mas[indmin]));}
                                if (indmax != i){swap(&(mas[i]), &(mas[indmax]));}
                        }
                }
                free(minvalue);
                free(maxvalue);
        }
        clock_t end = clock();
        printf("Сортировка заняла %lf с\n", (double)(end - start)/CLOCKS_PER_SEC);
}

void bubbleProbeg(car* mas, int n, int code){ // code == 0 - по возрастанию, code == 1 - по убыванию
        if (mas == NULL){printf("Массив не введён!\n"); return;}
        clock_t start = clock();
        for(int i = 0; i < n-1; i++){
                for(int j = 0; j < n-i-1; j++){
                        if (code == 0){
                                if (mas[j].probeg > mas[j+1].probeg){
                                        swap(&mas[j],&mas[j+1]);
                                }
                        }
                        if (code == 1){
                                if (mas[j].probeg < mas[j+1].probeg){
                                        swap(&mas[j],&mas[j+1]);
                                }
                        }
                }
        }
        clock_t end = clock();
        printf("Сортировка заняла %lf с\n", (double)(end - start)/CLOCKS_PER_SEC);
}

void bubbleMark(car* mas, int n, int code){ // code == 0 - по возрастанию, code == 1 - по убыванию
        if (mas == NULL){printf("Массив не введён!\n"); return;}
        clock_t start = clock();
        for(int i = 0; i < n-1; i++){
                for(int j = 0; j < n-i-1; j++){
                        if (code == 0){
                                if ((strcmp(mas[j].mark, mas[j+1].mark)) > 0){
                                        swap((&mas[j]),&(mas[j+1]));
                                }
                        }
                        if (code == 1){
                                if ((strcmp(mas[j].mark, mas[j+1].mark)) < 0){
                                        swap((&mas[j]),&(mas[j+1]));
                                }
                        }
                }
        }
        clock_t end = clock();
        printf("Сортировка заняла %lf с\n", (double)(end - start)/CLOCKS_PER_SEC);
}

void bubbleFio(car* mas, int n, int code){ // code == 0 - по возрастанию, code == 1 - по убыванию
        if (mas == NULL){printf("Массив не введён!\n"); return;}
        clock_t start = clock();
        for(int i = 0; i < n-1; i++){
                for(int j = 0; j < n-i-1; j++){
                        if (code == 0){
                                if ((strcmp(mas[j].fio, mas[j+1].fio)) > 0){
                                        swap(&mas[j],&mas[j+1]);
                                }
                        }
                        if (code == 1){
                                if ((strcmp(mas[j].fio, mas[j+1].fio)) < 0){
                                        swap(&mas[j],&mas[j+1]);
                                }
                        }
                }
        }
        clock_t end = clock();
        printf("Сортировка заняла %lf с\n", (double)(end - start)/CLOCKS_PER_SEC);
}

int compProbegVozr(const void * a, const void * b){
        const car* first = (const car*) a;
        const car* second = (const car*) b;
        return (first->probeg - second->probeg);
}

int compProbegUbiv(const void * a, const void * b){
        const car* first = (const car*) a;
        const car* second = (const car*) b;
        return (second->probeg - first->probeg);
}

int compMarkVozr(const void * a, const void * b){
        const car* first = (const car*) a;
        const car* second = (const car*) b;
        return (strcmp(first->mark,second->mark));
}

int compMarkUbiv(const void * a, const void * b){
        const car* first = (const car*) a;
        const car* second = (const car*) b;
        return (-(strcmp(first->mark,second->mark)));
}

int compFioVozr(const void * a, const void * b){
        const car* first = (const car*) a;
        const car* second = (const car*) b;
        return (strcmp(first->fio,second->fio));
}

int compFioUbiv(const void * a, const void * b){
        const car* first = (const car*) a;
        const car* second = (const car*) b;
        return (-(strcmp(first->fio,second->fio)));
}

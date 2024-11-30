#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "FILELAB.h"


void output(float *m, int *n) { // функция вывода массива
    printf("Array: [");
    for(int i = 0; i < *n; i++){
        printf(" %f;", m[i]);
    }
    printf("]\n");
}


float* input(float *m, int *n, int code){// функция инициализации массива
    if (code == 1){free(m);}
    printf("Enter the number of members of array: ");
    n = prov(n, 1); // функция ввода и проверки n
    m = (float*)malloc(*n * sizeof(float));
    for(int i = 0; i < *n; i++){
        printf("Enter %d float member of array (<= 5 meaningful signs): ", i+1);
        int r = scanf("%f", &m[i]);
        while (r != 1){
            scanf("%*[^\n]");
            printf("Please, enter correct float number!\n");
            r = scanf("%f", &m[i]);
        }
    }
    output(m,n);
    return m;
}


float* deleted(float *m, int *n, int *index, int code){ // функция удаления элемента из массива
    if (code == 0){ // "code" value нужен для использования функции в mytask()
        printf("Enter the index value (to delete): ");
        index = prov(index,2);
        if (*index >= *n){
        printf("Error, delete index value >= n\n");
        output(m,n);
        return m;
        }
    }
    
    for (int i = 0; i < *n; i++){
        if (i > *index){
            m[i-1] = m[i];
        }
    }
    *n = *n - 1;
    m = realloc(m, sizeof(float) * *n);
    if (code == 0){ // в mytask() нам не будет это требоваться
        output(m,n);
    }
    return m;
}


float* vst(float *m, int *n, int *index){ // функция вставки элемента в массив
    printf("Enter the index value (to vst): ");
    index = prov(index,2); // ввод индекса и проверка
    if (*index >= *n){
        (*index) = (*n); // если индекс >= n => index = n
    }
    *n = *n + 1;
    m = realloc(m,sizeof(float) * *n);
    if (*index == *n-1){ // если мы вставляем элемент в самый конец
        floatvvod(m,*index);
    }
    else { // иначе
        for (int i = *n-2; i >= 0; i--){
            if (i > *index){
                m[i+1] = m[i];
            }
            else if (i == *index){
                m[i+1] = m[i];
                floatvvod(m,i);
            break;
            }
        }
    }
    output(m,n);
    return m;
}


float* mytask(float *m, int *n){ // индивидуальное задание
    float* mas = 0;
    int k = 0;
    for (int i = 0; i < *n; i++){
        if (uslovie(m[i]) == 1) {
            mas = realloc(mas, sizeof(float) * (k+1));
            k = k + 1;
            mas[k-1] = m[i];
            m = deleted(m,n,&i,1);
            i = i - 1;
        }
    }
    output(m,n);
    printf("Task ");
    output(mas,&k);
    free(mas);
    return m;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "FILELAB.h"


int* prov(int *n, int code){ // функция ввода и проверки n, code для n и index
    if (code == 1) {
        int p = scanf("%d", &*n);
        while (p != 1 || *n <= 0){
            scanf("%*[^\n]");
            printf("Incorrect n value, enter again\n");
            p = scanf("%d", &*n);
        }
        return n;
    }
    if (code == 2){
        int p = scanf("%d", &*n);
        while (p != 1 || *n < 0){
            scanf("%*[^\n]");
            printf("Incorrect index value (<0 or not int), enter again\n");
            p = scanf("%d", &*n);
        }
        return n;
    }
}


void floatvvod(float *m, int index){ // функция ввода вещественного числа (+проверка)
    printf("Enter the vst float number: ");
    int r = scanf("%f", &m[index]);
    while (r != 1){
        scanf("%*[^\n]");
        printf("Please, enter correct float number!\n");
        r = scanf("%f", &m[index]);
    }
}


int uslovie(float n){ // функция условия, которому должно соответствовать
    // число в mytask() - первая значимая цифра числа - 9
    n = fabsf(n);
    int intpart = n; // целая часть числа
    float floatpart = n - intpart; // дробная часть числа
    if (intpart > 0){ // если есть значимая целая часть, то...
        int newintpart = 0;
        while (intpart > 0){
            newintpart = (intpart%10);
            intpart /= 10;
        }
        if (newintpart == 9){return 1;}
        else return 0;
    }
    int prov;
    for (int i = 0; i < 5; i++){ // проверка дробной части
        floatpart *= 10;
        prov = floatpart;
        if ((prov != 0) && (prov != 9)){return 0;}
        else if (prov == 9){return 1;}
    }
}


int intro(float* m, int* command, int flag){ // функция main'а
	if (flag == 0){printf("\nCommands list:\n1) Enter mas\n2) Insert element\n3) Delete element\n4) Individual task\n5) Output mas\n6) Stop the program");}
    printf("\nEnter the command\n");
    int r = scanf("%d",command);
    if (r == EOF){free(m); return 0;}
    while (r != 1 || *command <= 0 || *command >= 7){
        scanf("%*[^\n]");
        printf("This command doesn't exist, try again\n");
        r = scanf("%d",command);
    }
    return 1;
}

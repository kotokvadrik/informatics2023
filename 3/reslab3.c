#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "FILELAB.h"

int main(){
    int n, index, command, flag = 0;
    float* m = 0;
    do {
        if (intro(m,&command,flag) == 0){return 0;}
        switch (command){
        case 1: m = input(m,&n,flag);break;
        case 2: m = vst(m,&n,&index);break;
        case 3: m = deleted(m,&n,&index,0);break;
        case 4: m = mytask(m,&n);break;
        case 5: output(m,&n);break;
        case 6: free(m);return 0;
        default: break;
        }
    flag = 1; 
    } while(1);
}

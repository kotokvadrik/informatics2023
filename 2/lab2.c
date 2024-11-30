#include <stdio.h>
#include <math.h>

double calcn(double x, int n) { // функция для n
    double s = x;  // x - первый член ряда, s - будущая сумма ряда
    double t = x;  // сохраняем x в переменную t
    int i = 1; // инициализируем счетчик количества членов ряда
    long long kvfac = 1; 
    long long lin = 1;
    
    while(i != n){
        t = -t * lin / kvfac / 4 * lin * (lin + 1) /kvfac * x * x / (lin + 2);
         // выполняем преобразования с i-тым членом ряда теперь t - (i + 1)ый член ряда
        s += t; // суммируем
        lin += 2;
        kvfac += 1;
        i++; 
    }

    return s; // возвращаем значение суммы
 }

 double calceps(double x, double e, int* n) { // функция для e
    double s = x;  // x - первый член ряда, s - будущая сумма ряда
    double t = x;  // сохраняем x в переменную t
    long long kvfac = 1; 
    long long lin = 1;
    double lastvalue;

    do {
        lastvalue = t; // запоминаем значение предыдущего члена последовательности
        t = -t * lin / kvfac / 4 * lin * (lin + 1) /kvfac * x * x / (lin + 2); 
        // выполняем преобразования с предыдущим членом, генерируем следующий
        s += t; // суммируем
        lin += 2;
        kvfac += 1;
        *n += 1; // обновляем количество членов ряда
    } while(fabs(t-lastvalue) > e);

    return s; // возвращаем значение суммы
 }

 int main(){
    short flag, provd, cnt;
    do {
        printf("Enter <1> to count with n or enter <2> to count with e\n"); // выбор подсчёта ряда (n или e)
        provd = scanf("%hd", &flag);
        while (provd != 1 || ((flag != 1) && (flag != 2))){ // проверка для ввода 1/2
            scanf("%*[^\n]");
            printf("Please, enter correct value (1 or 2)\n");
            provd = scanf("%hd", &flag);
        }
        
        if (flag == 1){ // расчёт при заданных x и n
            double x;
            int n;
            printf("Enter x and n.\n");
            int r = scanf("%lf %d", &x, &n);
            while (r != 2 || fabs(x) >= 1 || n < 1){ // проверка входных данных
                scanf("%*[^\n]");
                if (r != 2) {
                printf("Incorrect input type.\n");
                }
                else if (fabs(x) >= 1) {
                printf("Please, enter x from -1 to 1.\n");
                }
                else if (n < 1) {
                printf("Please, enter correct count of row members.\n");
                }
                r = scanf("%lf %d", &x, &n);
            }
            printf("Calculated - %.15lf; Math.h value - %.15lf\n", calcn(x, n), log(x + sqrt(x * x + 1)));   
        }

        else if (flag == 2){ // расчёт при заданных х и е
            double x;
            double e;
            int n = 1;
            printf("Enter x and e.\n");
    
            int r = scanf("%lf %lf", &x, &e);

            while (r != 2 || fabs(x) >= 1 || e <= 0){ // проверка входных данных
                scanf("%*[^\n]");
                if (r != 2) {
                printf("Incorrect input type.\n");
                }
                else if (fabs(x) >= 1) {
                printf("Please, enter x from -1 to 1.\n");
                }
                else if (e <= 0){
                printf("Please, enter correct epsilon value\n");
                }
                r = scanf("%lf %lf", &x, &e);
            }
    
            printf("Calculated - %.15lf; Math.h value - %.15lf\n", calceps(x, e, &n), log(x + sqrt(x * x + 1)));
            printf("Accuracy tooks %d row members\n", n);
        }

        printf("If you want to continue, please, enter <1> or another number to exit\n"); // продолжить/завершить работу
        scanf("%hd",&cnt);
        scanf("%*[^\n]");
    } while (cnt == 1);
    return 0;
}

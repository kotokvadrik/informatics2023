#include <stdio.h>

int minch(int n)
{
    int ch = 0;
    for(int i = 0; i <= 9; i ++) // перебор цифр от 0 до 9, считаем количество цифры i в числе
    {
        int ncopy = n; // создаем копию числа n,используем её для подсчета цифры i
        int counter = 0;
        while (ncopy > 0) // цикл подсчёта цифры i в ncopy
        {
            int a = ncopy % 10; 
            if (a == i) {counter ++; }
            ncopy /= 10;
        }
        for(int j = 1; j <= counter; j++) { // прибавляем к результату ch цифру i counter раз
        ch = ch * 10 + i;
        } 
    }
    return ch; // вернуть результат
}

int main()
{
    int x,k;
    printf("Введите x\n");
    scanf("%d", &x); // ввод числа на вход
    if (x < 0)
    {
        x = -x; // поменять знак числа, если оно меньше 0
    }
    k = minch(x); // записываем в переменную k результат работы функции minch(x)
    printf("Полученное значение: ");
    printf("%d\n",k); // вывод результата
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "LIST.h"
#include "main_func.h"

int main(){
    size_t len = 0;
    char num = 0;
    char *answer = NULL;
    char *word_input = NULL, *word_find = NULL, *znak = NULL;
    printf("Введите пример: ");
    List my_List = get_List(&len);
    do {
        answer = str_from_List(&my_List, len);
        printf("Строка: \"%s\"\n", answer);
        free(answer);
        print_menu();
        do {
            num = getchar();
        } while (num == '\n' || num == 0);
        switch (num)
        {
        case '1':
            free(input_word());
            printf("Введите число которое хотите удалить: ");
            word_find = input_word();
            del_words_list(&my_List, &len, word_find);
            free(word_find);
            break;
        case '2':
            free(input_word());
            printf("Введите число перед которым хотите вставить новое: ");
            word_input = input_word();
            printf("Введите число которое хотите вставить: ");
            word_find = input_word();
            printf("Введите знак: ");
            znak = input_word();
            input_word_List(&my_List, &len, word_find, word_input, znak);
            free(word_input);
            break;
        case '3':
            my_program(&my_List, &len);
            break;
        case '4':
        	scanf("%*c");
            List_destructor(&my_List);
            printf("Введите пример: ");
            my_List = get_List(&len);
            break;
        }
    } while (num != '5');
    List_destructor(&my_List);
    return 0;
}

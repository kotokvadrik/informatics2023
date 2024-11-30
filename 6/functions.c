#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "LIST.h"
#include "main_func.h"

void print_menu(){
    printf("Что вы хотите сделать?\n");
    printf("(1) Удалить все вхождения некоторого слова\n");
    printf("(2) Вставить новое слово перед первым вхождением указанного слова\n");
    printf("(3) Выполнить обработку\n");
    printf("(4) Записать новый список\n");
    printf("(5) Выйти\n");
}

List get_List(size_t *len){
    List my_List = {NULL, NULL};
    char *word = (char *) calloc(1, sizeof(char));
    char new_symbol = (char) getchar();
    *len = 0;
    while (new_symbol != '\n') {    // Пробегаемся по всем введённым символам
        if (new_symbol >= '0' && new_symbol <= '9') {   // Если это число
            word = (char *) realloc(word, (strlen(word) + 2) * sizeof(char));
            word[strlen(word) + 1] = 0;
            word[strlen(word)] = new_symbol;
        } 
        else if (strlen(word) != 0 && strchr("+-", new_symbol)){ // Если встретили знак
            push_back(&my_List, word);
            word = (char *) calloc(2, sizeof(char));
            word[0] = new_symbol;
            push_back(&my_List, word);
            word = (char *) calloc(1, sizeof(char));
            *len += 2;
        } 
        else if (strlen(word) == 0 && strchr("+-", new_symbol) && *len != 0) {
            (my_List.tailer -> data)[0] = new_symbol; 
        }
        new_symbol = (char) getchar();
    }
    if (strlen(word) != 0){
        push_back(&my_List, word);
        (*len)++;
    }
    return my_List;
}

char *str_from_List(List *my_List, const size_t len){ // Перевод списка в строку
    char *str = (char *) calloc(1, sizeof(char));   // Объявляем строку, в которую мы будем добавлять элементы списка
    char *elem = NULL;  // Объявляем переменную в которой мы будем хранить данные элемента списка
    for (size_t i = 0; i < len; ++i) {  // Пробегаемся по всем элементам списка
        elem = pop_top(my_List); // Достаём данные списка
        push_back(my_List, elem);  // И кладём их обратно
        if (i != 0) {   // Если это не первый элемент
            str = realloc(str, (strlen(str) + strlen(elem) + 2) * sizeof(char));
            str[strlen(str) + 1] = 0;
            str[strlen(str)] = ' '; // Добавляем пробел
        } 
        else {
            str = realloc(str, (strlen(str) + strlen(elem) + 1) * sizeof(char));
        }
        strcat(str, elem);  // Прибавляем к строке данные списка
    }
    return str;
}

void my_program(List *my_List, size_t *len){ // Индивидуальное задание
    char *elem = NULL, *result = NULL, *symbol = NULL; 
    char znak = '+';
    long long int sum = 0, sum_copy = 0, num = 0;
    size_t len_result = 0;
    for (size_t i = 0; i < *len; ++i) { // Пробегаемся по всем элементам списка
        elem = pop_top(my_List);
        if (elem[0] != '=') {   // Достаём элемент из спика
            push_back(my_List, elem);    // Кладём его обратно
        } 
        else {    // Если встретили знак '=' 
            free(elem); // Очищаем знак '='
            free(pop_top(my_List));    // Очищаем ответ
            *len -= 2;
            break;
        }
        if (elem[0] >= '0' && elem[0] <= '9') {
            switch (znak)
            {
            case '+':
                sscanf(elem, "%lld", &num);
                sum += num;
                break;
            case '-':
                sscanf(elem, "%lld", &num);
                sum -= num;
                break;
            }
        } 
        else if (strlen(elem) > 1) {
            if (elem[1] >= '0' && elem[1] <= '9') {
                switch (znak)
                {
                case '+':
                    sscanf(elem, "%lld", &num);
                    sum += num;
                    break;
                case '-':
                    sscanf(elem, "%lld", &num);
                    sum -= num;
                    break;
                }
            }
        } 
        else {
            znak = elem[0];
        }
    }
    sum_copy = sum;
    while (sum_copy) {  // Определяем сколько знаков занимает ответ (ст 179-187)
        sum_copy /= 10;
        len_result++;
    }
    if (sum <= 0) {
        len_result++;
    }
    result = (char *) calloc(len_result + 1, sizeof(char));
    sprintf(result, "%lld", sum);
    symbol = (char *) calloc(2, sizeof(char));
    symbol[0] = '=';
    push_back(my_List, symbol);
    push_back(my_List, result);
    *len += 2;
}

char *input_word(){
    char new_symbol = (char) getchar();
    char *str = (char *) calloc(1, sizeof(char));
    while (new_symbol != '\n') {
        str = (char *) realloc(str, (strlen(str) + 2) * sizeof(char));
        str[strlen(str) + 1] = 0;
        str[strlen(str)] = new_symbol;
        new_symbol = (char) getchar();
    }
    return str;
}

void input_word_List(List *my_List, size_t *len, char *word_input, char *word_find, char *znak){
    Node *elem = my_List -> header;
    Node *new_elem = NULL, *new_znak = NULL, *prev = NULL;
    while (elem) {
        if (!strcmp(elem -> data, word_find)) {
            new_elem = (Node *) malloc(sizeof(Node));
            new_znak = (Node *) malloc(sizeof(Node));
            if (prev) {
                prev -> next = new_elem;
            } 
            else {
                my_List -> header = new_elem;
            }
            new_elem -> next = new_znak;
            new_znak -> next = elem;
            new_elem -> data = word_input;
            new_znak -> data = znak;
            *len += 2;
            break;
        }
        prev = elem;
        elem = elem -> next;
    }
}

void del_words_list(List *my_List, size_t *len, char *word){
    Node *elem = my_List -> header;
    Node *next = NULL;
    Node *prev = NULL;
    while (elem) {
        next = elem -> next;
        if (!strcmp(elem -> data, word)) {
            if (!next) {
                my_List -> tailer = prev;
            }
            if (prev) {
                prev -> next = next;
            } 
            else {
                my_List -> header = next;
            }
            free(elem -> data);
            free(elem);
            (*len)--;
        } 
        else {
            prev = elem;
        }
        elem = next;
    }
    elem = my_List -> header;
    prev = NULL;
    while (elem) {
        next = elem -> next;
        if (next) {
            if ((!strcmp(elem -> data, "+") || !strcmp(elem -> data, "-")) && (!strcmp(next -> data, "+") || !strcmp(next -> data, "-"))) {
                if (prev) {
                    prev -> next = next;
                } 
                else {
                    my_List -> header = next;
                }
                free(elem -> data);
                free(elem);
                (*len)--;
            } 
            else if (!prev) {
                if (!strcmp(elem -> data, "+") || !strcmp(elem -> data, "-")) {
                    if (prev) {
                        prev -> next = next;
                    } 
                    else {
                        my_List -> header = next;
                    }
                    free(elem -> data);
                    free(elem);
                    (*len)--;
                } 
                else {
                    prev = elem;
                }
            } 
            else {
                prev = elem;
            }
        } 
        else if (!next) {
            if (!strcmp(elem -> data, "+") || !strcmp(elem -> data, "-")) {
                my_List -> tailer = prev;
                if (prev) {
                    prev -> next = next;
                } 
                else {
                    my_List -> header = next;
                }
                free(elem -> data);
                free(elem);
                (*len)--;
            } 
            else {
                prev = elem;
            }
        } 
        else {
            if (prev) {
                if ((!strcmp(elem -> data, "+") || !strcmp(elem -> data, "-")) && prev -> data[0] == '=') {
                    if (!next) {
                        my_List -> tailer = prev;
                    }
                    prev -> next = next;
                    free(elem -> data);
                    free(elem);
                    (*len)--;
                } 
                else {
                    prev = elem;
                }
            } 
            else if (!strcmp(elem -> data, "+") || !strcmp(elem -> data, "-")) {
                if (!next) {
                    my_List -> tailer = prev;
                }
                my_List -> header = next;
                free(elem -> data);
                free(elem);
                (*len)--;
            } 
            else {
                prev = elem;
            }
        }
        elem = next;
    }
}

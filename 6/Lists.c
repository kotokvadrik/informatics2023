#include "LIST.h"
#include <stdlib.h>
#include <stdio.h>

void push_back(List *my_List, char *data) // Функция вставки в конец списка
{
    Node *new_elem = (Node *) malloc(sizeof(Node)); // Выделяем память под элемент списка
    new_elem -> data = data;    // Записываем данные в элемент
    new_elem -> next = NULL;
    if (my_List -> tailer) {    // Вставляем элемент в список (ст 10-17)
        (my_List -> tailer) -> next = new_elem;
    }
    my_List -> tailer = new_elem;
    if (!(my_List -> header)) {
        my_List -> header = new_elem;
    }
}

char *pop_top(List *my_List) // Функция удаления из начала списка
{
    Node *elem = my_List -> header; // Берём начальный элемент
    char *data = elem -> data;  // Записываем данные из элемента списка
    my_List -> header = elem -> next;   // Сдвигаем элементы (ст 24-27)
    if (!(elem -> next)) {
        my_List -> tailer = NULL;
    }
    free(elem); // Очищаем элемент списка
    return data; // Возвращаем данные
}

void List_destructor(List *my_List) // Функция очистки списка
{
    Node *elem = my_List -> header;
    Node *copy_elem = elem;
    while (elem) { // Пробегаемся по списку
        elem = elem -> next; // Переходим на след. элемент
        free(copy_elem -> data); // Очищаем данные текущего элемента
        free(copy_elem);    // Очищаем сам элемент
        copy_elem = elem;
    }
    my_List -> header = NULL;
    my_List -> tailer = NULL;
}

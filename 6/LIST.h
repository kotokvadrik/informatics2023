#ifndef LIST_H
#define LIST_H

typedef struct Node{
    char *data;
    struct Node *next;
} Node;

typedef struct List{
    Node *header;
    Node *tailer;
} List;

void push_back(List *, char *);
char *pop_top(List *);
void List_destructor(List *);
void print_List(const List);

#endif

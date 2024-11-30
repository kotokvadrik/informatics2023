#ifndef MAIN_FUNC
#define MAIN_FUNC
void print_menu();
List get_List(size_t *);
char *str_from_List(List *, const size_t);
void my_program(List *, size_t *);
char *input_word();
void input_word_List(List *, size_t *, char *, char *, char *);
void del_words_list(List *, size_t *, char *);
#endif

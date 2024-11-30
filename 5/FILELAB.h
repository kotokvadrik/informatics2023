#ifndef FILELAB_H
#define FILELAB_H

typedef struct car { // наша структура
        char mark[17];
        char* fio;
        float probeg;
} car;

void inicializationKlav(car** mas, int* n);// для работы с массивом
void masGeneration(car** mas, int* n);
void GenerationFunc(car** mas, int* n); 
void output(car* mas, int n);
void osvob(car** mas, int n);
int vvod_car_klav(car* mashina);
char* myreadline();
char* myfilereadline(FILE* file);
void swap(car* car1, car* car2);

void recordText(car*mas, int n); // запись считывание из файлов
void readingText(car** mas, int* n);
void recordBin(car* mas, int n);
void readingBin(car** mas, int* n);

void entermenu(car** mas, int* n); // все меню
void outmenu(car* mas, int n);
void generationmenu(car** mas, int* n);
void sortsmenu(car* mas, int n);

void doubleSelectionProbeg(car* mas, int n, int code); // сортировки
void doubleSelectionMark(car* mas, int n, int code);
void doubleSelectionFio(car* mas, int n, int code);
void bubbleProbeg(car* mas, int n, int code);
void bubbleMark(car* mas, int n, int code);
void bubbleFio(car* mas, int n, int code);

int compProbegVozr(const void * a, const void * b); // компараторы (для ксорта)
int compProbegUbiv(const void * a, const void * b);
int compMarkVozr(const void * a, const void * b);
int compMarkUbiv(const void * a, const void * b); 
int compFioVozr(const void * a, const void * b);
int compFioUbiv(const void * a, const void * b);
#endif

#include <stdio.h>
#include "UserMenu.h"
#include <conio.h>

int usermenu() {
    printf("Integer type testing: 1\n");
    printf("Double type testing: 2\n");
    printf("Your type testing: 3\n");
    printf("End programme: Esc\n");
    char ch = getch();
    return ch;
}

void waitingPressEnter(void)
{
    printf("PRESS Enter to End\n");
    do {} while (_getch() != 13);
}

void print_vector(void *array) {
    Vector *array0 = (Vector*)array;
    if(array0 == NULL) return;
    switch (array0->size_type) {
    case sizeof(int):
            for (size_t i = 0; i < array0->n_coord; i++)
            {
                printf("vect[%d] = %d\n", i, *(int*)(array0->ivect[i]));
            }
            break;
    case sizeof(double):
            for (size_t i = 0; i < array0->n_coord; i++)
            {
                printf("vect[%d] = %lf\n", i, *(double*)(array0->ivect[i]));
            }
            break;
    default:
            printf("Указанный тип данных не поддерживается функцией\n");
    }
}

void print_value(void* value, size_t type) {
    switch (type) {
    case sizeof(int):
            printf("%d\n", *(int*)value);
            break;
    case sizeof(double):
            printf("%lf\n", *(double*)value);
            break;
    default:
            printf("Указанный тип данных не поддерживается функцией\n");
    }
}

Vector *create_arr_user(){
    printf("Select the type for the vector:\n");
    printf("Integer type: 1\n Double type: 2\n");
    char type;
    do {
        type = getch();
    } while(type != '1' && type != '2');
    printf("%c\n", type);
    printf("Choose a space for the vector: ");
    int n;
    scanf("%d", &n);
    Vector *vect;
    switch(type) {
        case '1':
            vect = create_arr(sizeof(int), n);
            for(int i = 0; i < n; i++) {
                printf("vector[%d] = ", i);
                scanf("%d", (int*)vect->ivect[i]);
            }
            break;
        case '2':
            vect = create_arr(sizeof(double), n);
            for(int i = 0; i < n; i++) {
                printf("vector[%d] = ", i);
                scanf("%lf", (double*)vect->ivect[i]);
            }
            break;
    }
    return vect;
}
#ifndef USERMENU_H
#define USERMENU_H

#include "Vector.h"

int usermenu();

void waitingPressEnter();

void print_vector(void *array);

void print_value(void* value, size_t type);

Vector *create_arr_user();

#endif
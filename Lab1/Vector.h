#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>

typedef struct Vector
{
    size_t size_type; // размер типа
    size_t n_coord; // n-мерное пространство
    void **ivect; // указатель на массив
    void* (*vector_add)(void *, void *); // векторное сложение
    void* (*scalar_mult)(void *, void *); // скалярное произведение
}Vector;

void* Vector_Get(Vector* vector, size_t index);

void VectorSet(Vector* v, size_t index, void* value);

void TypeFynction(Vector* v);

void* CreateValue(size_t type);

void AddingValue(void* result, void* value, size_t type);

Vector* Vector_Add(Vector* v1, Vector* v2);

void* Scalar_Mult(Vector* v1, Vector* v2);

Vector *create_arr(size_t size_type, size_t n);

void delete_vect(Vector* array);

#endif

#include <stdio.h>
#include <malloc.h>
#include <conio.h>

#include "Vector.h"
#include "UserMenu.h"

void delete_vect(Vector* array);

void* Add_INT(void* a1, void* a2)
{
	int* ia1 = (int*)a1;
	int* ia2 = (int*)a2;
    int* res = malloc(sizeof(int));
	*res = *ia1 + *ia2;
	return (void*)res;
}

void* Add_DOUBLE(void* a1, void* a2)
{
	double* ia1 = (double*)a1;
	double* ia2 = (double*)a2;
    double* res = malloc(sizeof(double));
	*res = *ia1 + *ia2;
	return (void*)res;
}

void* Scalar_INT(void* a1, void* a2)
{
	int* ia1 = (int*)a1;
	int* ia2 = (int*)a2;
    int* res = malloc(sizeof(int));
	*res =  (*ia1) * (*ia2);
	return (void*)res;
}

void* Scalar_DOUBLE(void* a1, void* a2)
{
	double* ia1 = (double*)a1;
	double* ia2 = (double*)a2;
	double* res = malloc(sizeof(double));
	*res = (*ia1) * (*ia2);
	return (void*)res;
}

void* Vector_Get(Vector* vector, size_t index) {
    if(vector->ivect[index]) {
        return vector->ivect[index];
    }
    return NULL;
}

void VectorSet(Vector* v, size_t index, void* value) {
    if(v->ivect[index]){
        free(v->ivect[index]);
    }
    v->ivect[index] = value;
}

void TypeFynction(Vector* v) {
    if(v->size_type == sizeof(int)) {
        v->vector_add = &Add_INT;
        v->scalar_mult = &Scalar_INT;
    } 
    if(v->size_type == sizeof(double)) {
        v->vector_add = &Add_DOUBLE;
        v->scalar_mult = &Scalar_DOUBLE;
    }
}

void* CreateValue(size_t type) {
    if(type == sizeof(int)) {
        int* result = malloc(type);
        *result = 0;
        return (void*)result;
    }
    if(type == sizeof(double)) {
        double* result = malloc(type);
        *result = 0;
        return (void*)result;
    }
}

void AddingValue(void* result, void* value, size_t type) {
    if(type == sizeof(int)) {
        *(int*)result = *(int*)result + *(int*)value;
    }
    if(type == sizeof(double)) {
        *(double*)result = *(double*)result + *(double*)value;
    }
}

Vector* Vector_Add(Vector* v1, Vector* v2)
{
    Vector* v3 = create_arr(v1->size_type, v1->n_coord);
    if((v1->size_type != v2->size_type) || (v1->n_coord != v2->n_coord)) {
        delete_vect(v3);
        return NULL;
    }
    for (size_t index = 0; index < v1->n_coord; index++)
    {
        VectorSet(v3, index, v3->vector_add(Vector_Get(v1, index), Vector_Get(v2, index)));
    }
    return v3;
}

void* Scalar_Mult(Vector* v1, Vector* v2) {
    void* result = CreateValue(v1->size_type);
    if((v1->size_type != v2->size_type) || (v1->n_coord != v2->n_coord) || (v1->n_coord == 0)) {
        free(result);
        return NULL;
    }
    for (size_t index = 0; index < v1->n_coord; index++)
    {
       AddingValue(result, v1->scalar_mult(Vector_Get(v1, index), Vector_Get(v2, index)), v1->size_type);
    }
    return result;
}

Vector *create_arr(size_t size_type, size_t n){
    Vector* array = NULL;
    array = malloc(sizeof(Vector)); //Выделение памяти.
    array->size_type = size_type;
    array->n_coord = n;
    array->ivect = malloc(sizeof(void *) * n);
    for (int i = 0; i < n; i++)
    {
        array->ivect[i] = malloc(size_type); //Выделяем память под отдельный элемент.
    }
    TypeFynction(array);
    return array;
}

void delete_vect(Vector* array) {
    Vector *array0 = (Vector*)array;
    for (int i = 0; i < array0->n_coord; i++)
    {
        free(array0->ivect[i]);//Освобождаем память, выделенную под каждый элемент.
    }
    free(array0->ivect); //Освободи память, выделенную под массив указателей.
    free(array0);
}
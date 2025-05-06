#include <stdio.h>
#include <stdlib.h>
#include "Vector.h"
#include "TestVector.h"
#include "UserMenu.h"

void testMapVectorInt(void) {
    int TestVectorInt1[10] = {1, 30, 100, 0, 265, 8198, 12, 45, 125, 5};
    Vector *MyVector1 = create_arr(sizeof(int), 10);
    for (int i = 0; i < 10; i++)
	{
		*(int*)(MyVector1->ivect[i]) = TestVectorInt1[i]; //заполняем массив 1
    }
    printf("VectorInt 1:\n");
    print_vector(MyVector1);
    int TestVectorInt2[10] = {7, 70, 0, 79, 4, 2, 6, 45, 1, 5};
    Vector *MyVector2 = create_arr(sizeof(int), 10);
    for (int i = 0; i < 10; i++)
	{
		*(int*)(MyVector2->ivect[i]) = TestVectorInt2[i]; //заполняем массив 2
    }
    printf("VectorInt 2:\n");
    print_vector(MyVector2);
    // векторное сложение
    Vector *array_add = Vector_Add(MyVector1, MyVector2);
    printf("Vector_Adding:\n");
    print_vector(array_add);
    // скалярное произведение
    int* result = (int*)Scalar_Mult(MyVector1, MyVector2);
    printf("Scalar_Multiplication:\n");
    printf("%d\n", *result);
    // удаление векторов
    delete_vect(MyVector1);
    delete_vect(MyVector2);
    if(array_add) {
        delete_vect(array_add);
        free(result);
    }
}

void testMapVectorDouble(void) {
    double TestVectorDouble1[5] = {2.5, 1.0, 12.1, 2.5, 10.5};
    Vector *MyVector1 = create_arr(sizeof(double), 5);
    for (int i = 0; i < 5; i++)
	{
		*(double*)(MyVector1->ivect[i]) = TestVectorDouble1[i]; //заполняем массив 1
    }
    printf("VectorDouble 1:\n");
    print_vector(MyVector1);
    double TestVectorDouble2[5] = {1.0, 23.43, 0, 79.566, 4.12};
    Vector *MyVector2 = create_arr(sizeof(double), 5);
    for (int i = 0; i < 5; i++)
	{
		*(double*)(MyVector2->ivect[i]) = TestVectorDouble2[i]; //заполняем массив 2
    }
    printf("VectorDouble 2:\n");
    print_vector(MyVector2);
    // векторное сложение
    Vector *array_add = Vector_Add(MyVector1, MyVector2);
    printf("Vector_Adding:\n");
    print_vector(array_add);
    // скалярное произведение
    double* result = (double*)Scalar_Mult(MyVector1, MyVector2);
    printf("Scalar_Multiplication:\n");
    printf("%lf\n", *result);
    // удаление векторов
    delete_vect(MyVector1);
    delete_vect(MyVector2);
    if(array_add) {
        delete_vect(array_add);
        free(result);
    }
}

void testMapVectorYourType(void) {
    printf("Fill in the coefficients of the 1st vector\n");
    Vector *Vector1 = create_arr_user();
    printf("Fill in the coefficients of the 2nd vector\n");
    Vector *Vector2 = create_arr_user();
    Vector *array_add = Vector_Add(Vector1, Vector2);
    printf("Vector_Adding:\n");
    print_vector(array_add);
    void *result = Scalar_Mult(Vector1, Vector2);
    printf("Scalar_Multiplication:\n");
    if(result != NULL) {
        print_value(result, array_add->size_type);
    }
    delete_vect(Vector1);
    delete_vect(Vector2);
    if(array_add) {
        delete_vect(array_add);
        free(result);
    }
}

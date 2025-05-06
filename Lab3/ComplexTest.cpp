#include <iostream>
#include "ComplexTest.h"

int TestComplex() {
    int length1, length2, length3;
    double real, imagine;
    complex value, scalar, norm = {0, 0};
    std::cout << "Enter size of Vector1: " << std::endl;
    std::cin >> length1;
    Vector<complex> Vector1 = Vector<complex>(length1);
    for(int i = 0; i < Vector1.GetLength(); i++) {
        std::cout << "real = ";
        std::cin >> real;
        std::cout << "imagine = ";
        std::cin >> imagine;
        value = {real, imagine};
        Vector1.InsertAt(i, value);
    }
    std::cout << "Vector1 = " << Vector1 << std::endl; 
    std::cout << "Norm of vector Vector1 = " << Vector1.Norm() << std::endl;
    std::cout << "Vector2 = Vector1" << std::endl;
    Vector<complex> Vector2 = Vector1;
    std::cout << " Scalar:" << std::endl;
    std::cout << "real = ";
    std::cin >> real;
    std::cout << "imagine = ";
    std::cin >> imagine;
    scalar = {real, imagine};
    Vector2.VectorScal(scalar);
    std::cout << "Multiply Vector2 on scalar:" << std::endl;
    std::cout << "Vector2 = " << Vector2 << std::endl;
    std::cout << "Checking function ScalarMult:" << std::endl;
    std::cout << "Enter size of Vector3: " << std::endl;
    std::cin >> length2;
    Vector<complex> Vector3 = Vector<complex>(length2);
    for(int i = 0; i < Vector3.GetLength(); i++) {
        std::cout << "real = ";
        std::cin >> real;
        std::cout << "imagine = ";
        std::cin >> imagine;
        value = {real, imagine};
        Vector3.InsertAt(i, value);
    }
    std::cout << "Vector3 = " << Vector3 << std::endl;
    std::cout << "ScalarMult(Vector1, Vector3) = " << Vector1.ScalarMult(&Vector3) << std::endl;
    std::cout << "Checking function VectorSum:" << std::endl;
    std::cout << "Enter size of Vector4: " << std::endl;
    std::cin >> length3;
    Vector<complex> Vector4 = Vector<complex>(length3);
    for(int i = 0; i < Vector4.GetLength(); i++) {
        std::cout << "real = ";
        std::cin >> real;
        std::cout << "imagine = ";
        std::cin >> imagine;
        value = {real, imagine};
        Vector4.InsertAt(i, value);
    }
    std::cout << "Vector4 = " << Vector4 << std::endl;
    std::cout << "auto add = Vector1 + Vector4" << std::endl;
    Vector<complex> add = Vector1 + Vector4;
    std::cout << "add = " << add << std::endl;
    return 0;
}
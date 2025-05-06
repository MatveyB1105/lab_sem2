#include <iostream>
#include <cassert>
#include <conio.h>
#include "ComplexTest.h"
#include "Vector.h"
#include "Complex.h"
#include <cmath>

template <typename T>
int TestVector() {
    int length1, length2, length3;
    T value,  scalar, norm = 0, mult = 0;
    std::cout << "Enter size of Vector1: " << std::endl;
    std::cin >> length1;
    auto Vector1 = Vector<T>(length1);
    for(int i = 0; i < Vector1.GetLength(); i++) {
        std::cout << " Vector1["<<i<<"] = ";
        std::cin >> value;
        Vector1.InsertAt(i, value);
    }
    std::cout << "Vector1 = " << Vector1 << std::endl; 
    for(int i = 0; i < Vector1.GetLength(); i++) {
        norm = norm + Vector1[i] * Vector1[i];
    }
    assert(Vector1.Norm() == (T)(sqrt(norm)));
    std::cout << "Norm of vector Vector1 = " << Vector1.Norm() << std::endl;
    std::cout << "Vector2 = Vector1" << std::endl;
    auto Vector2 = Vector1;
    std::cout << " Scalar = ";
    std::cin >> scalar;
    Vector2.VectorScal(scalar);
    std::cout << "Multiply Vector2 on scalar:" << std::endl;
    for(int i = 0; i < Vector2.GetLength(); i++) {
        assert(Vector2[i] == scalar * Vector1[i]);
    }
    std::cout << "Vector2 = " << Vector2 << std::endl;
    std::cout << "Checking function ScalarMult:" << std::endl;
    std::cout << "Enter size of Vector3: " << std::endl;
    std::cin >> length2;
    auto Vector3 = Vector<T>(length2);
    for(int i = 0; i < Vector3.GetLength(); i++) {
        std::cout << " Vector3["<<i<<"] = ";
        std::cin >> value;
        Vector3.InsertAt(i, value);
        mult = mult + Vector1[i] * Vector3[i];
    }
    std::cout << "Vector3 = " << Vector3 << std::endl;
    assert(Vector1.ScalarMult(&Vector3) == mult);
    std::cout << "ScalarMult(Vector1, Vector3) = " << Vector1.ScalarMult(&Vector3) << std::endl;
    std::cout << "Checking function VectorSum:" << std::endl;
    std::cout << "Enter size of Vector4: " << std::endl;
    std::cout << "Vector1 + Vector4: " << std::endl;
    std::cin >> length3;
    auto Vector4 = Vector<T>(length3);
    for(int i = 0; i < Vector4.GetLength(); i++) {
        std::cout << " Vector4["<<i<<"] = ";
        std::cin >> value;
        Vector4.InsertAt(i, value);
    }
    std::cout << "Vector4 = " << Vector4 << std::endl;
    std::cout << "auto add = Vector1 + Vector4" << std::endl;
    auto add = Vector1 + Vector4;
    std::cout << "add = " << add << std::endl;
    return 0;
}

int main() {
    std::cout << "Choose stored type:" << std::endl;
    std::cout << "1 - integer, 2 - double, 3 - complex" << std::endl;
    char type = getch();
    switch (type) {
    case '1':
        return TestVector<int>();
    case '2':
        return TestVector<double>();
    case '3':
        return TestComplex();
    }
}
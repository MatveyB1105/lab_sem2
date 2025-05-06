#include <iostream>
#include <cassert>
#include "DynamicArray.h"

using namespace std;

#define COUNT 5
#define NEWCOUNT 10
#define VALUE -1

void TestDynamicArrayConstructors() {
    cout << "Checking the constructors of class DynamicArray" << endl;
    int array[COUNT] = {1, 2, 3, 4, 5};
    for (int i = 0; i < COUNT; i++) {
        cout << "a[" << i << "] = " << array[i] << endl;
	}
    cout << "copy elements from array to DynArr1" << endl;
    DynamicArray<int> DynArr1(array, COUNT);
    for(int i = 0; i < DynArr1.GetSize(); i++) {
        assert(DynArr1[i] == array[i]);
        cout << "DynArr1[" << i << "] = " << DynArr1[i]<< endl;
    }
    cout << "create an DynArr2 of the specified length: 5" << endl;
    DynamicArray<int> DynArr2(COUNT);
    assert(DynArr2.GetSize() == COUNT);
    cout << "Size of DynArr2: " << DynArr2.GetSize() << endl;
    cout << "copy elements from DynArr1 to DynArr3" << endl;
    DynamicArray<int> DynArr3(DynArr1);
    for(int i = 0; i < DynArr3.GetSize(); i++) {
        assert(DynArr3[i] == DynArr1[i]);
        cout << "DynArr3[" << i << "] = " << DynArr3[i]<< endl;
    }
    cout << "Success" << endl;
}

void TestDynamicArrayDecomposition() {
    cout << "Checking the decomposition of class DynamicArray" << endl;
    int array[COUNT] = {6, 7, 8, 9, 10};
    for (int i = 0; i < COUNT; i++) {
        cout << "a[" << i << "] = " << array[i] << endl;
	}
    cout << "copy elements from array to DynArr1" << endl;
    DynamicArray<int> DynArr1(array, COUNT);
    cout << "Checking Function GetSize" << endl;
    assert(DynArr1.GetSize() == COUNT);
    cout << "Size of DynArr1: " << DynArr1.GetSize() << endl;
    cout << "Checking Function Get" << endl;
    for(int i = 0; i < DynArr1.GetSize(); i++) {
        assert(DynArr1.Get(i) == array[i]);
        cout << "DynArr1[" << i << "] = " << DynArr1.Get(i)<< endl;
    }
    cout << "Success" << endl;
}

void TestDynamicArrayOperations() {
    cout << "Checking the operations of class DynamicArray" << endl;
    int array[COUNT] = {0, 0, 0, 0, 0};
    for (int i = 0; i < COUNT; i++) {
        cout << "a[" << i << "] = " << array[i] << endl;
	}
    cout << "create an DynArr1 of the specified length" << endl;
    DynamicArray<int> DynArr1(COUNT);
    cout << "Checking Function Set" << endl;
    cout << "DynArr1[i] = i" << endl;
    for(int i = 0; i < DynArr1.GetSize(); i++) {
        DynArr1.Set(i, i);
        assert(DynArr1[i] == i);
        cout << "DynArr1[" << i << "] = " << DynArr1.Get(i)<< endl;
    }
    cout << "Checking Function Resize" << endl;
    DynArr1.Resize(NEWCOUNT, VALUE);
    assert(DynArr1.GetSize() == NEWCOUNT);
    for(int i = 0; i < COUNT; i++) {
        assert(DynArr1[i] == i);
        cout << "DynArr1[" << i << "] = " << DynArr1[i]<< endl;
    }
    for(int i = COUNT; i < NEWCOUNT; i++) {
        assert(DynArr1[i] == VALUE);
        cout << "DynArr1[" << i << "] = " << DynArr1[i]<< endl;
    }
    cout << "Success" << endl;
}

int main() {
    TestDynamicArrayConstructors();
    TestDynamicArrayDecomposition();
    TestDynamicArrayOperations();
    return 0;
}
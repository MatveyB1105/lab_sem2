#include <iostream>
#include <cassert>

#include "ArraySequence.h"

using namespace std;

#define COUNT 5

void TestArraySequenceConstructors() {
    cout << "Checking the constructors of class ArraySequence" << endl;
    int array[COUNT] = {1, 2, 3, 4, 5};
    for (int i = 0; i < COUNT; i++) {
        cout << "a[" << i << "] = " << array[i] << endl;
	}
    cout << "copy elements from array to arrSeq1" << endl;
    ArraySequence<int>* arrSeq1 = new ArraySequence<int>(array, COUNT);
    for(int i = 0; i < arrSeq1->GetLength(); i++) {
        assert(arrSeq1->Get(i) == array[i]);
        cout << "arrSeq1[" << i << "] = " << arrSeq1->Get(i)<< endl;
    }
    cout << "create an empty arrSeq2" << endl;
    ArraySequence<int>* arrSeq2 = new ArraySequence<int>;
    assert(arrSeq2->GetLength() == 0);
    cout << "copy elements from arrSeq1 to arrSeq3" << endl;
    ArraySequence<int>* arrSeq3 = new ArraySequence<int>(*arrSeq1);
    for(int i = 0; i < arrSeq3->GetLength(); i++) {
        assert(arrSeq3->Get(i) == arrSeq1->Get(i));
        cout << "arrSeq3[" << i << "] = " << arrSeq3->Get(i)<< endl;
    }
    cout << "Success" << endl;
}

void TestArraySequenceDecomposition() {
    cout << "Checking the decomposition of class ArraySequence" << endl;
    int array[COUNT] = {1, 2, 3, 4, 5};
    for (int i = 0; i < COUNT; i++) {
        cout << "a[" << i << "] = " << array[i] << endl;
	}
    cout << "copy elements from array to arrSeq1" << endl;
    ArraySequence<int>* arrSeq1 = new ArraySequence<int>(array, COUNT);
    cout << "Checking Function GetLenght" << endl;
    cout << "Length of arrSeq1: " << arrSeq1->GetLength() << endl;
    cout << "Checking Function Get" << endl;
    assert(arrSeq1->GetLength() == COUNT);
    for(int i = 0; i < arrSeq1->GetLength(); i++) {
        assert(arrSeq1->Get(i) == array[i]);
        cout << "arrSeq1[" << i << "] = " << arrSeq1->Get(i)<< endl;
    }
    cout << "Checking Function GetFirst" << endl;
    assert(arrSeq1->GetFirst() == array[0]);
    cout << "arrSeq1->GetFirst() = " << arrSeq1->GetFirst() << endl;
    cout << "Checking Function GetLast" << endl;
    assert(arrSeq1->GetLast() == array[COUNT - 1]);
    cout << "arrSeq1->GetLast() = " << arrSeq1->GetLast() << endl;
    cout << "Checking Function GetSubsequence" << endl;
    Sequence<int>* arrSeq2 = arrSeq1->GetSubsequence(0, COUNT / 2);
    for(int i = 0; i < arrSeq2->GetLength(); i++) {
        assert(arrSeq2->Get(i) == arrSeq1->Get(i));
        cout << "arrSeq2[" << i << "] = " << arrSeq2->Get(i)<< endl;
    }
    cout << "Success" << endl;
}

void TestArraySequenceOperations() {
    cout << "Checking the operations of class DynamicArray" << endl;
    int array[COUNT] = {1, 2, 3, 4, 5};
    for (int i = 0; i < COUNT; i++) {
        cout << "a[" << i << "] = " << array[i] << endl;
	}
    cout << "copy elements from array to arrSeq1" << endl;
    ArraySequence<int>* arrSeq1 = new ArraySequence<int>(array, COUNT);
    for(int i = 0; i < arrSeq1->GetLength(); i++) {
        assert(arrSeq1->Get(i) == array[i]);
        cout << "arrSeq1[" << i << "] = " << arrSeq1->Get(i)<< endl;
    }
    cout << "Checking Function Append" << endl;
    cout << "Append(6)" << endl;
    arrSeq1->Append(6);
    assert(arrSeq1->Get(COUNT) == 6);
    cout << "arrSeq1[COUNT] = " << arrSeq1->Get(COUNT)<< endl;
    cout << "Checking Function Prepend" << endl;
    cout << "Prepend(6)" << endl;
    arrSeq1->Prepend(0);
    assert(arrSeq1->Get(0) == 0);
    cout << "arrSeq1[0] = " << arrSeq1->Get(0)<< endl;
    cout << "Checking Function InsertAt" << endl;
    cout << "InsertAt(10, 2)" << endl;
    arrSeq1->InsertAt(10,2);
    assert(arrSeq1->Get(2) == 10);
    cout << "arrSeq1[2] = " << arrSeq1->Get(2)<< endl;
    cout << "Checking Function Concat" << endl;
    cout << "create an arrSeq2" << endl;
    ArraySequence<int>* arrSeq2 = new ArraySequence<int>;
    cout << "arrSeq2[0] = -1" << endl;
    arrSeq2->Append(-1);
    cout << "arrSeq1->Concat(arrSeq1)" << endl;
    arrSeq2->Concat(arrSeq1);
    assert(arrSeq2->Get(0) == -1);
    cout << "arrSeq2[0] = " << arrSeq2->Get(0) << endl;
    for(int i = 1; i < arrSeq2->GetLength(); i++) {
        assert(arrSeq2->Get(i) ==  arrSeq1->Get(i - 1));
        cout << "arrSeq2[" << i << "] = " << arrSeq2->Get(i)<< endl;
    }
    cout << "Success" << endl;
}

int main() {
    TestArraySequenceConstructors();
    TestArraySequenceDecomposition();
    TestArraySequenceOperations();
    return 0;
}





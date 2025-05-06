#include <iostream>
#include <cassert>

#include "LinkedListSequence.h"

using namespace std;

#define COUNT 5

bool whereFunc(int value) {
    return value % 2 == 0;
}

int mapFunc(int a) {
	return a * a;
}

int reduceFunc(int a, int b) {
    return 2*a + 3*b;
}

void TestListSequenceConstructors() {
    cout << "Checking the constructors of class LinkedListSequence" << endl;
    int array[COUNT] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        cout << "a[" << i << "] = " << array[i] << endl;
	}
    cout << "copy elements from array to Seq1" << endl;
    Sequence<int>* Seq1 = new LinkedListSequence<int>(array, COUNT);
    for(int i = 0; i < Seq1->GetLength(); i++) {
        assert(Seq1->Get(i) == array[i]);
        cout << "Seq1[" << i << "] = " << Seq1->Get(i)<< endl;
    }
    cout << "create an empty Seq2" << endl;
    Sequence<int>* Seq2 = new LinkedListSequence<int>;
    assert(Seq2->GetLength() == 0);
    cout << "copy elements from Seq1 to Seq3" << endl;
    Sequence<int>* Seq3 = new LinkedListSequence<int>(*Seq1);
    for(int i = 0; i < Seq3->GetLength(); i++) {
        assert(Seq3->Get(i) == Seq1->Get(i));
        cout << "Seq3[" << i << "] = " << Seq3->Get(i)<< endl;
    }
    cout << "Success" << endl;
}

void TestListSequenceDecomposition() {
    cout << "Checking the decomposition of class LinkedListSequence" << endl;
    int array[COUNT] = {1, 2, 3, 4, 5};
    for (int i = 0; i < COUNT; i++) {
        cout << "a[" << i << "] = " << array[i] << endl;
	}
    cout << "copy elements from array to Seq1" << endl;
    Sequence<int>* Seq1 = new LinkedListSequence<int>(array, COUNT);
    cout << "Checking Function GetLenght" << endl;
    assert(Seq1->GetLength() == COUNT);
    cout << "Length of Seq1: " << Seq1->GetLength() << endl;
    cout << "Checking Function Get" << endl;
    for(int i = 0; i < Seq1->GetLength(); i++) {
        assert(Seq1->Get(i) == array[i]);
        cout << "Seq1[" << i << "] = " << Seq1->Get(i)<< endl;
    }
    cout << "Checking Function GetFirst" << endl;
    assert(Seq1->GetFirst() == array[0]);
    cout << "Seq1->GetFirst() = " << Seq1->GetFirst() << endl;
    cout << "Checking Function GetLast" << endl;
    assert(Seq1->GetLast() == array[COUNT - 1]);
    cout << "Seq1->GetLast() = " << Seq1->GetLast() << endl;
    cout << "Checking Function GetSubsequence" << endl;
    Sequence<int>* Seq2 = Seq1->GetSubsequence(0, COUNT / 2);
    for(int i = 0; i < Seq2->GetLength(); i++) {
        assert(Seq2->Get(i) == Seq1->Get(i));
        cout << "Seq2[" << i << "] = " << Seq2->Get(i)<< endl;
    }
    cout << "Success" << endl;
}

void TestListSequenceOperations() {
    cout << "Checking the operations of class LinkedListSequence" << endl;
    int array[COUNT] = {1, 2, 3, 4, 5};
    for (int i = 0; i < COUNT; i++) {
        cout << "a[" << i << "] = " << array[i] << endl;
	}
    cout << "copy elements from array to Seq1" << endl;
    Sequence<int>* Seq1 = new LinkedListSequence<int>(array, COUNT);
    for(int i = 0; i < Seq1->GetLength(); i++) {
        assert(Seq1->Get(i) == array[i]);
        cout << "Seq1[" << i << "] = " << Seq1->Get(i)<< endl;
    }
    cout << "Checking Function Append" << endl;
    cout << "Append(6)" << endl;
    Seq1->Append(6);
    assert(Seq1->Get(COUNT) == 6);
    cout << "Seq1[COUNT] = " << Seq1->Get(COUNT)<< endl;
    cout << "Checking Function Prepend" << endl;
    cout << "Prepend(0)" << endl;
    Seq1->Prepend(0);
    assert(Seq1->Get(0) == 0);
    cout << "Seq1[0] = " << Seq1->Get(0)<< endl;
    cout << "Checking Function InsertAt" << endl;
    cout << "InsertAt(10, 2)" << endl;
    Seq1->InsertAt(10,2);
    assert(Seq1->Get(2) == 10);
    cout << "Seq1[2] = " << Seq1->Get(2)<< endl;
    cout << "Checking Function Concat" << endl;
    cout << "create an Seq2" << endl;
    Sequence<int>* Seq2 = new LinkedListSequence<int>;
    cout << "Seq2[0] = -1" << endl;
    Seq2->Append(-1);
    cout << "Seq2->Concat(Seq1)" << endl;
    Seq2 = Seq2->Concat(Seq1);
    cout << "Seq2[0] = " << Seq2->Get(0) << endl;
    for(int i = 1; i < Seq2->GetLength(); i++) {
        assert(Seq2->Get(i) ==  Seq1->Get(i - 1));
        cout << "Seq2[" << i << "] = " << Seq2->Get(i) << endl;
    }
    cout << "Success" << endl;
}

void TestListSequenceFunction() {
    cout << "Сhecking the functions" << endl;
    int array[3] = {1, 2, 3};
    for (int i = 0; i < 3; i++) {
        cout << "a[" << i << "] = " << array[i] << endl;
	}
    Sequence<int>* Seq = new LinkedListSequence<int>(array, 3);
    cout << "Checking Function Map" << endl;
    Sequence<int>* Seq1 = Seq->map(mapFunc);
    for(int i = 0; i < Seq1->GetLength(); i++) {
        assert(Seq1->Get(i) == (array[i] * array[i]));
        cout << "Seq1[" << i << "] = " << Seq1->Get(i) << endl;
    }
    cout << "Checking Function Where" << endl;
    Sequence<int>* Seq2 = Seq->where(whereFunc);
    for(int i = 0; i < Seq2->GetLength(); i++) {
        assert(Seq2->Get(i) % 2 == 0);
        cout << "Seq2[" << i << "] = " << Seq2->Get(i) << endl;
    }
    cout << "Checking Function Reduce" << endl;
    int value = Seq->reduce(reduceFunc, 0);
    assert(value == 144);
    cout << "value = " << value << endl;
    cout << "Success" << endl;
}

int main() {
    TestListSequenceConstructors();
    TestListSequenceDecomposition();
    TestListSequenceOperations();
    TestListSequenceFunction();
    return 0;
}
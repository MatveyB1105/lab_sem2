#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cassert>

#include "LinkedList.h"

using namespace std;

#define COUNT 5

char RandomChar(void) {
    return char(rand() % 51 + 50);
}

void TestLinkedListConstructors() {
    srand(time(NULL));
    cout << "Checking the constructors of class LinkedList" << endl;
    char array[COUNT];
    for (int i = 0; i < COUNT; i++) {
		array[i] = RandomChar();
	}
    cout << "Array char:" << endl;
	for (int i = 0; i < COUNT; i++) {
		cout << "a[" << i << "] = " << array[i] << endl;
	}
    cout << "copy elements from array to List1" << endl;
    LinkedList<char> List1(array, COUNT);
    cout << "listChar1: " << endl;
    for(int i = 0; i < COUNT; i++) {
		assert(List1.Get(i) == array[i]);
		cout << "List1[" << i << "] = " << List1[i]->data << endl;
	}
    cout << "create an empty List2" << endl;
    LinkedList<char> List2;
    assert(List2.GetLength() == 0);
    cout << "copy elements from List1 to List3" << endl;
    LinkedList<char> List3(List1);
    for(int i = 0; i < List3.GetLength(); i++) {
        assert(List3[i]->data == List1[i]->data);
        cout << "List3[" << i << "] = " << List3[i]->data << endl;
    }
    cout << "Success" << endl;
}

void TestLinkedListDecomposition() {
    cout << "Checking the decomposition of class LinkedList" << endl;
    char array[COUNT];
    for (int i = 0; i < COUNT; i++) {
		array[i] = RandomChar();
	}
    cout << "Array char:" << endl;
	for (int i = 0; i < COUNT; i++) {
		cout << "a[" << i << "] = " << array[i] << endl;
	}
    cout << "copy elements from array to List1" << endl;
    LinkedList<char> List1(array, COUNT);
    cout << "Checking Function GetFirst" << endl;
    assert(List1.GetFirst() == array[0]);
    cout << "List1[0] = " << List1[0]->data << ";" << "array[0] = " << array[0] << endl;
    cout << "Checking Function GetLast" << endl;
    assert(List1.GetLast() == array[COUNT - 1]);
    cout << "List1[COUNT - 1] = " << List1[COUNT - 1]->data << ";" << "array[COUNT - 1] = " << array[COUNT - 1] << endl;
    cout << "Checking Function Get" << endl;
    for (int i = 0; i < List1.GetLength(); i++) {
		assert(List1.Get(i) == array[i]);
		cout << "List1.Get(" << i << ") = " << List1.Get(i) << endl;
	}
    cout << "Checking Function GetSubList [0, COUNT/2]" << endl;
    cout << "create an empty List2" << endl;
    LinkedList<char>* List2;
    List2 = List1.GetSubList(0, COUNT/2);
    cout << "listChar2: " << endl;
    for(int i = 0; i < List2->GetLength(); i++) {
        assert(List2->Get(i) == List1.Get(i));
        cout << "List2->Get(" << i << ") = " << List2->Get(i) << endl;
    }
    cout << "Checking Function Getlenght" << endl;
    assert(List1.GetLength() == COUNT);
    cout << "Size of List1: " << List1.GetLength() << endl;
    cout << "Success" << endl;
}

void TestLinkedListOperations() {
    cout << "Checking the operations of class LinkedList" << endl;
    char array[COUNT];
    for (int i = 0; i < COUNT; i++) {
		array[i] = RandomChar();
	}
    cout << "Array char:" << endl;
	for (int i = 0; i < COUNT; i++) {
		cout << "a[" << i << "] = " << array[i] << endl;
	}
    cout << "Checking Function Append" << endl;
    cout << "copy elements from array to List1" << endl;
    LinkedList<char> List1(array, COUNT);
    List1.Append('#');
    assert(List1.GetLast() == '#');
    cout << "List1.GetLast(): " << List1.GetLast() << endl;
    cout << "Checking Function Prepend" << endl;
    List1.Prepend('#');
    assert(List1.GetFirst() == '#');
    cout << "List1.GetFirst(): " << List1.GetFirst() << endl;
    cout << "Checking Function InsertAt" << endl;
    cout << "List1.InsertAt('#', 6)" << endl;
    List1.InsertAt('#', 6); 
    assert(List1.Get(6) == '#');
    cout << "List1.Get(2): " << List1.GetFirst() << endl;
    cout << "Checking Function Concat" << endl;
    cout << "create an empty List2" << endl;
    LinkedList<int> List2;
    for(int i = 0; i < COUNT; i++) {
        List2.Append(i);
        cout << "List2[" << i << "] = " << List2[i]->data << endl;
    }
    cout << "create an empty List3" << endl;
    LinkedList<int> List3;
    List3.Append(5);
    cout << "List3[0] = " << List3[0]->data << endl;
    List3.Concat(&List2);
    cout << "List3: " << endl;
    assert(List3.Get(0) == 5);
    cout << "List3[0] = " << List3[0]->data << endl;
    for(int i = 1; i < List3.GetLength(); i++) {
        assert(List3.Get(i) == List2.Get(i - 1));
        cout << "List3[" << i << "] = " << List3[i]->data << endl;
    }
    cout << "Success" << endl;
}

int main() {
    TestLinkedListConstructors();
    TestLinkedListDecomposition();
    TestLinkedListOperations();
    return 0;
}
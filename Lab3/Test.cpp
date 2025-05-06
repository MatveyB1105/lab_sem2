#include <iostream>
#include <conio.h>
#include "Vector.h"
using namespace std;

void ChoiceFunc() {
    cout << "Choose Functions" << endl;
    cout << "1 - Create new vector" << endl;
    cout << "2 - Check function VectorSum" << endl;
    cout << "3 - Check function VectorScal" << endl;
    cout << "4 - Check function ScalarMult" << endl;
    cout << "5 - Find Norm of a Vector" << endl;
    cout << "6 - End of checking" << endl;
}

template <typename T>
void TestVectorInt() {
    char ch;
    Vector<int>* Vector1;
    do {
    ChoiceFunc();
    ch = getch();
		switch(ch) {
		case '1':
            int lenght;
            cout << "Enter Size of Vector" << endl;
            cin >> lenght;
            Vector1 = new Vector<int>()
			break;
		case '2':
			TestVectorDouble();
			break;
		case '3':
			TestVectorComplex();
			break;
		default:
			break;
		}
	} while (ch != '6');
}
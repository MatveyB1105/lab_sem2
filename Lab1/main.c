#include <stdio.h>
#include "Vector.h"
#include "UserMenu.h"
#include "TestVector.h"

#include <windows.h>
#include <conio.h>

int main() {
	char userChoice;
	do {
    userChoice = usermenu();
		switch(userChoice) {
		case '1':
			testMapVectorInt();
			waitingPressEnter();
			break;
		case '2':
			testMapVectorDouble();
			waitingPressEnter();
			break;
		case '3':
			testMapVectorYourType();
			waitingPressEnter();
			break;
		default:
			break;
		}
    system("cls");
	} while ((int)userChoice != 27);
	return 0;
}
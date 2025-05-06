#include <iostream>
#include <conio.h>
#include "BinaryTreeValue.h"
#include "Complex.h"
#include "Function.h"

void PrintMenu() {
    std::cout << " ---PrintMenu--- " << std::endl;
    std::cout << " 1 - Create new BinaryTree" << std::endl;
    std::cout << " 2 - Add element in tree" << std::endl;
    std::cout << " 3 - Search Element " << std::endl;
    std::cout << " 4 - Get Height of BinaryTree " << std::endl;
    std::cout << " 5 - Test Map " << std::endl;
    std::cout << " 6 - Test Where" << std::endl;
    std::cout << " 7 - Concat BinaryTrees" << std::endl;
    std::cout << " 8 - PrintTree" << std::endl;
	std::cout << " 9 - Ending program" << std::endl;
}

void MenuInt()
{
	int choice = 0;
	BinaryTree<int>* tree = new BinaryTree<int>();
	BinaryTree<int>* tree2 = new BinaryTree<int>();
	BinaryTree<int>* tree3 = new BinaryTree<int>();
	BinaryTree<int>* tree4 = new BinaryTree<int>();

	while (choice != 9) {

		PrintMenu();
		std::cin >> choice;
		char ch = '1';

		switch (choice)
		{
		case 1:			
			if(tree){delete tree;}
            tree = new BinaryTree<int>();
			break;
        case 2:
            while(ch != '0') {
                std::cout << "Enter element:" << std::endl;
                int value;
                std::cin >> value;
                tree->Add(value);
				std::cout << "Edding - 0" << std::endl;
				ch = getch();
            }
			break;
		case 3:
            while(ch != '0') {
                std::cout << "Check value in tree" << std::endl;
                int value;
                std::cin >> value;
                if(tree->SearchItem(tree->GetRoot(),value)) {std::cout << "Yes" << std::endl;}
                else {std::cout << "No" << std::endl;}
				std::cout << "Edding - 0" << std::endl;
				ch = getch();
            }
			break;
		case 4:
            std::cout << "Height of tree:" << tree->GetHeight(tree->GetRoot()) << std::endl;
			break;
		case 5:
            std::cout << "Check Map" << std::endl;
			tree2 = tree->Map(MultTwo);
			tree2->PrintTree();
			break;
		case 6:
			std::cout << "Check Where (value > 0)" << std::endl;
			tree3 = tree->Where(BigZero);
			tree3->PrintTree();
			break;
		case 7:
			while(ch != '0') {
                std::cout << "Enter element:" << std::endl;
                int value;
                std::cin >> value;
                tree4->Add(value);
                std::cout << "Edding - 0" << std::endl;
				ch = getch();
            }
            tree4 = tree->Concat(tree4);
            tree4->PrintTree();
		case 8:
			std::cout << "Tree: " << std::endl;
            tree->PrintTree();
			break;
		case 9: 
			break;
		default:
			std::cout << "Error choice" << std::endl;
			break;
		}
	}
}

void MenuFloat()
{
	int choice = 0;
	BinaryTree<float>* tree = new BinaryTree<float>();
	BinaryTree<float>* tree2 = new BinaryTree<float>();
	BinaryTree<float>* tree3 = new BinaryTree<float>();
	BinaryTree<float>* tree4 = new BinaryTree<float>();

	while (choice != 9) {

		PrintMenu();
		std::cin >> choice;
		char ch = '1';

		switch (choice)
		{
		case 1:			
			if(tree){delete tree;}
            tree = new BinaryTree<float>();
			break;
        case 2:
            while(ch != '0') {
                std::cout << "Enter element:" << std::endl;
                float value;
                std::cin >> value;
                tree->Add(value);
                std::cout << "Edding - 0" << std::endl;
				ch = getch();
            }
			break;
		case 3:
            while(ch != '0') {
                std::cout << "Check value in tree" << std::endl;
                float value;
                std::cin >> value;
                if(tree->SearchItem(tree->GetRoot(),value)) {std::cout << "Yes" << std::endl;}
                else {std::cout << "No" << std::endl;}
                std::cout << "Edding - 0" << std::endl;
				ch = getch();
            }
			break;
		case 4:
            std::cout << "Height of tree:" << tree->GetHeight(tree->GetRoot()) << std::endl;
			break;
		case 5:
            std::cout << "Check Map" << std::endl;
			tree2 = tree->Map(MultTwo);
			tree2->PrintTree();
			break;
		case 6:
			std::cout << "Check Where (value > 0)" << std::endl;
			tree3 = tree->Where(BigZero);
			tree3->PrintTree();
			break;
		case 7:
			while(ch != '0') {
                std::cout << "Enter element:" << std::endl;
                float value;
                std::cin >> value;
                tree4->Add(value);
                std::cout << "Edding - 0" << std::endl;
				ch = getch();
            }
            tree4 = tree->Concat(tree4);
            tree4->PrintTree();
		case 8:
			std::cout << "Tree: " << std::endl;
            tree->PrintTree();
			break;
		case 9: 
			break;
		default:
			std::cout << "Error choice" << std::endl;
			break;
		}
	}
}

void MenuComplex()
{
	int choice = 0;
	BinaryTree<complex>* tree = new BinaryTree<complex>();
	BinaryTree<complex>* tree2 = new BinaryTree<complex>();
	BinaryTree<complex>* tree3 = new BinaryTree<complex>();
	BinaryTree<complex>* tree4 = new BinaryTree<complex>();

	while (choice != 9) {

		PrintMenu();
		std::cin >> choice;
		char ch = '1';

		switch (choice)
		{
		case 1:			
			if(tree){delete tree;}
            tree = new BinaryTree<complex>();
			break;
        case 2:
            while(ch != '0') {
                std::cout << "Enter element:" << std::endl;
                float real, imagine;
                std::cout <<"real = ";
                std::cin>>real;
                std::cout <<"imagine = ";
                std::cin>>imagine;
                complex value(real,imagine);
                tree->Add(value);
                std::cout << "Edding - 0" << std::endl;
				ch = getch();
            }
			break;
		case 3:
            while(ch != '0') {
                std::cout << "Check value in tree" << std::endl;
                float real, imagine;
                std::cout <<"real = ";
                std::cin>>real;
                std::cout <<"imagine = ";
                std::cin>>imagine;
                complex value(real,imagine);
                if(tree->SearchItem(tree->GetRoot(),value)) {std::cout << "Yes" << std::endl;}
                else {std::cout << "No" << std::endl;}
                std::cout << "Edding - 0" << std::endl;
				ch = getch();
            }
			break;
		case 4:
            std::cout << "Height of tree:" << tree->GetHeight(tree->GetRoot()) << std::endl;
			break;
		case 5:
            std::cout << "Check Map" << std::endl;
			tree2 = tree->Map(MultTwo);
			tree2->PrintTree();
			break;
		case 6:
			std::cout << "Check Where (value == 2)" << std::endl;
			tree3 = tree->Where(EqTwo);
			tree3->PrintTree();
			break;
		case 7:
			while(ch != '0') {
                std::cout << "Enter element:" << std::endl;
                float real, imagine;
                std::cout <<"real = ";
                std::cin>>real;
                std::cout <<"imagine = ";
                std::cin>>imagine;
                complex value(real,imagine);
                tree4->Add(value);
                std::cout << "Edding - 0" << std::endl;
				ch = getch();
            }
            tree4 = tree->Concat(tree4);
            tree4->PrintTree();
		case 8:
			std::cout << "Tree: " << std::endl;
            tree->PrintTree();
			break;
		case 9: 
			break;
		default:
			std::cout << "Error choice" << std::endl;
			break;
		}
	}
}

int main()
{
	int choice = 0 ;
	std::cout << "-Menu-" << std::endl;
	std::cout << "Enter type" << std::endl;
	std::cout << "1. Int\n2. Float\n3. Complex" << std::endl;
	std::cin >> choice;
	switch (choice)
	{
	case 1:
		MenuInt();
		break;
	case 2:
		MenuFloat();
		break;
    case 3:
        MenuComplex();
	default:
		break;
	}
    return 0;
}
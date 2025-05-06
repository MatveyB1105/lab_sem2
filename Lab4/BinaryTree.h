#pragma once

#include <iostream>

template <typename T> struct Node {
    public:
        T data;
        T key;
        Node<T>* parent;
        Node<T>* left;
        Node<T>* right;
        Node(T data1, T key1) {
            data = data1;
            key = key1;
            parent = NULL;
            left = NULL;
            right = NULL;
        }
        Node(Node& other) {
            key = other.key;
            data = other.value;
            parent = other.parent;
            other.parent = nullptr;
            left = other.left;
            other.left = nullptr;
            right = other.right;
            other.right = nullptr;
        }
        friend Node<T>* MostRight(Node<T>* startNode) noexcept
		{
			if (startNode == nullptr)
				return nullptr;

			Node<T>* current = startNode;

			while (current->right != nullptr)
				current = current->right.Get();

			return (current != startNode) ? current : nullptr;
		}

		friend Node<T>* MostLeft(Node<T>* startNode) noexcept
		{
			if (startNode == nullptr)
				return nullptr;

			Node<T>* current = startNode;

			while (current->left != nullptr)
				current = current->left.Get();

			return (current != startNode) ? current : nullptr;
		}
};

template <typename T> class BinaryTree {   
private:
    Node<T>* root;
    void DeleteTree(Node<T>* node) {
        if(node != nullptr) {
            DeleteTree(node->left);
            DeleteTree(node->right);
            delete node;
        }
    }
    bool RoundSearchTree(Node<T>* root1, Node<T>* root2, bool result) {
        if (root2 == nullptr) {
            return true;
        }
        else if ((root1 == nullptr) && (root2 != nullptr)) {
            return false;
        }
        else if (root1 != nullptr) {
            if (((root1->data) == (root2->data)) && ((root1->key) == (root2->key))) {
                if (RoundSearchTree(root1->left, root2->left, result) && RoundSearchTree(root1->right, root2->right, result)) {
                    return true;
                }
            }
            result = RoundSearchTree(root1->left, root2, result) || RoundSearchTree(root1->right, root2, result);
        }
        return result;
    }
    BinaryTree<T>* RoundMap(Node<T>* node, T (*func)(T), BinaryTree<T>* result) {
        if(node != nullptr) {
            result->Add(node->key, func(node->data));
            result = RoundMap(node->left, func, result);
            result = RoundMap(node->right, func, result);
        }
        return result;
    }
    BinaryTree<T>* RoundWhere(Node<T>* node, bool (*func)(T), BinaryTree<T>* result) {
        if(node != nullptr) {
            if(func(node->data)) {
                result->Add(node->key, node->data);
            }
            result = RoundWhere(node->left, func, result);
            result = RoundWhere(node->right, func, result);
        }
        return result;
    }
    BinaryTree<T>* Unite(Node<T>* node1, BinaryTree<T>* result) { // слияние бинарных деревьев
        if(node1 == nullptr) {return nullptr;}
        else {
            result->Add(node1->key, node1->data);
            if(node1->left != NULL) {
                result = Unite(node1->left, result);
            }
            if(node1->right != NULL) {
                result = Unite(node1->right, result);
            }
            return result;
        }
    }
    
    void RootLeftRight(Node<T>* node) {
        if(node != nullptr) {
            std::cout << "{" << node->data << "}";
            RootLeftRight(node->left);
            RootLeftRight(node->right);
        }
    }

    void RightLeftRoot(Node<T>* node) {
        if(node != nullptr) {
            RightLeftRoot(node->right);
            RightLeftRoot(node->left);
            std::cout << "{" << node->data << "}";
        }
    }

    void LeftRootRight(Node<T>* node) {
        if(node != nullptr) {
            LeftRootRight(node->left);
            std::cout << "{" << node->data << "}";
            LeftRootRight(node->right);
            
        }
    }

    void RightRootLeft(Node<T>* node) {
        if(node != nullptr) {
            RightRootLeft(node->right);
            std::cout << "{" << node->data << "}";
            RightRootLeft(node->left);
            
        }
    }

    void LeftRightRoot(Node<T>* node) {
        if(node != nullptr ) {
            LeftRightRoot(node->left);
            LeftRightRoot(node->right);
            std::cout << "{" << node->data << "}";
            
            
        }
    }

    void RootRightLeft(Node<T>* node) {
        if(node != nullptr) {
            std::cout << "{" << node->data << "}";
            RootRightLeft(node->right);
            RootRightLeft(node->left);
        }
    }
public:
    Node<T>* GetRoot() {
        return this->root;
    }
    BinaryTree() {
        root = nullptr;
    }
    ~BinaryTree() {
        DeleteTree(this->root);
    }

    Node<T>* AddNode(Node<T>* node, T key, T data, Node<T>* parent) {
        if (node == nullptr) {
            node = new Node<T>(data, key);
            node->left = nullptr;
            node->right = nullptr;
            node->parent = parent;
			if (root == nullptr){
                root = node;
            }
        } 
        else if(key < node->key) {
            node->left = AddNode(node->left, key, data, node);
        }
        else if(key > node->key) {
            node->right = AddNode(node->right, key, data, node);
        }
        return node;
    }
    void Add(T key, T data) {
        Node<T>* start = root;
        start = AddNode(start, key, data, nullptr);
    }
    Node<T>* SearchElement(Node<T>* node, T key) {
        if(node->key == key) {
            return node;
        }
        else if(key < node->key) {
            return SearchElement(node->left, key);
        }
        else if(key > node->key) {
            return SearchElement(node->right, key);
        }
        return nullptr;
    }
    bool SearchItem(Node<T>* node, T key) {
        if(node == nullptr) {return false;}
        if(node->key == key) {
            return true;
        }
        else if(key < node->key) {
            return SearchItem(node->left, key);
        }
        else if(key > node->key) {
            return SearchItem(node->right, key);
        }
    }
    bool SearchTree(BinaryTree<T>* tree1, BinaryTree<T>* tree2) {
        bool result = false;
	    result = RoundSearchTree(tree1->GetRoot(), tree2->GetRoot(), result);
	    return result;
    }

    int GetHeight(Node<T>* node) {
        if(node == nullptr) {
            return 0;
        }
        return (1 + std::max(GetHeight(node->right), GetHeight(node->left)));
    }

    BinaryTree<T>* Map(T (*func)(T)) {
        BinaryTree<T>* result = new BinaryTree<T>();
        result = RoundMap(this->GetRoot(), func, result);
        return result;
    }

    BinaryTree<T>* Where(bool (*func)(T)) {
        BinaryTree<T>* result = new BinaryTree<T>();
        result = RoundWhere(root, func, result);
        return result;
    }

    BinaryTree<T>* Concat(BinaryTree<T>* other) {
        BinaryTree<T>* result = new BinaryTree<T>();
        result = Unite(this->GetRoot(), result);
        result = Unite(other->GetRoot(), result);
        return result;
    }
    
    void PrintTree() {
        int choice;
        std::cout << "Choose a path of BinaryTree" << std::endl;
        std::cout << "1 - KLR, 2 - KRL, 3 - LRK, 4 - LKR, 5 - RLK, 6 - RKL" << std::endl;
        std::cin >> choice;
        switch (choice) {
        case 1:
            RootLeftRight(this->GetRoot());
            break;
        case 2:
            RootRightLeft(this->GetRoot());
            break;
        case 3:
            LeftRightRoot(this->GetRoot());
            break;
        case 4:
            LeftRootRight(this->GetRoot());
            break;
        case 5:
            RightLeftRoot(this->GetRoot());
            break;
        case 6:
            RightRootLeft(this->GetRoot());
            break;
        default:
            std::cout << "Error";
            break;
        }
    }
};
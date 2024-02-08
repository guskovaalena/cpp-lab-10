
#ifndef CPP_LAB_10_MYBINARYTREE_H
#define CPP_LAB_10_MYBINARYTREE_H

#include "node.h"
#include <iostream>

int tabs  = 0;

template <typename T>
class MyBinaryTree {

    node<T>* root;

public:

    explicit MyBinaryTree(T rootValue){
        root = create(rootValue);
    }

    node<T>* getRoot(){
        return root;
    }

    static node<T>* create(T i){
        node<T>* elem = new node<T>;
        elem->value = i;
        elem->left = nullptr;
        elem->right = nullptr;
        return elem;
    }

    static void push(node<T>* root, node<T>* elem){
        if (elem->value < root->value){
            if (root->left == nullptr){
                root->left = elem;
            } else{
                push(root->left, elem);
            }
        } else{
            if (root->right == nullptr){
                root->right = elem;
            } else{
                push(root->right, elem);
            }
        }
    }

    static void printAscend(node<T>* elem){
        if (elem->left != nullptr){
            printAscend(elem->left);
        }
        std::cout<<elem->value<<std::endl;
        if (elem->right != nullptr){
            printAscend(elem->right);
        }
    }

    static void printDescend(node<T>* elem){
        if (elem->right != nullptr){
            printDescend(elem->right);
        }
        std::cout<<elem->value<<std::endl;
        if (elem->left != nullptr){
            printDescend(elem->left);
        }
    }

//    static void printTree(node<T>* elem){
//
//        tabs += 5;
//        if (elem->right != nullptr){
//            printTree(elem->right);
//        }
//        for (int i = 0; i < tabs; i++){
//            std::cout<<' ';
//        }
//        std::cout<<elem->value<<std::endl;
//        if (elem->left != nullptr){
//            printTree(elem->left);
//        }
//        tabs -= 5;
//    }

    static void output (std::ostream& out, const node<T>* elem){
        tabs += 5;
        if (elem->left != nullptr){
            output(out, elem->left);
        }
        for (int i = 0; i < tabs; i++){
            out << ' ';
        }
        out << elem->value << std::endl;
        if (elem->right != nullptr){
            output(out, elem->right);
        }
        tabs -= 5;
    }

    friend std::ostream& operator<<(std::ostream &out, const MyBinaryTree<T>& elem){
        output(out, elem.root);
        return out;
    }
};

#endif //CPP_LAB_10_MYBINARYTREE_H

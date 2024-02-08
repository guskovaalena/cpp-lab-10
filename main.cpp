#include <iostream>

template <typename T>
struct node{
    T value;
    node* left;
    node* right;
};

template <typename T>
node<T>* create(T i){
    node<T>* elem = new node<T>;
    elem->value = i;
    elem->left = nullptr;
    elem->right = nullptr;
    return elem;
}

template <typename T>
void push(node<T>* root, node<T>* elem){
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

template <typename T>
void print(node<T>* elem){
    if (elem->left != nullptr){
        print(elem->left);
    }
    std::cout<<elem->value<<std::endl;
    if (elem->right != nullptr){
        print(elem->right);
    }
}

template <typename T>
class MyBinaryTree{
public:
    node<T>* root;
    explicit MyBinaryTree(T rootValue){
        root = create(rootValue);
    }
};

int main() {

    int arr[7] = {-3, 1, -5, 42, 2, -6, 8};

    MyBinaryTree<int> tree(0);

    for (int i = 0; i < 7; i++){
        node<int>* elem = create(arr[i]);
        push(tree.root, elem);
    }

    std::cout<<"MY TREE:"<<std::endl;
    print(tree.root);

    return 0;
}

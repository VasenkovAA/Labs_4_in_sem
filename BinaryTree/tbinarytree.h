#ifndef TBINARYTREE_H
#define TBINARYTREE_H
#include <exception>
#include<queue>
using namespace std;


template <typename T>

class TBinaryTree;

template <typename T>
class TBinaryTreeNode{
public:
    T data;
    TBinaryTreeNode * left;
    TBinaryTreeNode * right;
    TBinaryTreeNode(T _data):data(_data),left(nullptr),right(nullptr),pearent(nullptr){}
    TBinaryTreeNode (TBinaryTreeNode<T>&val):data(val.data),left(val.left),right(val.right),pearent(val.pearent){}
    TBinaryTreeNode*pearent;
    friend TBinaryTree<T>;
    ~TBinaryTreeNode(){
        right = nullptr;
        left = nullptr;
        //delete data;
    };
};
template <typename T>
class TBinaryTree
{
public:
TBinaryTreeNode<T> *top;
int count;
int length;
public:
TBinaryTree (){
    count = 0;
    length = 0;
    top = nullptr;
}
TBinaryTree(TBinaryTree& val):top(val.top),count(val.count),length(val.length) {}

void BFS(void(*function)(TBinaryTreeNode<T>*)){
    queue<TBinaryTreeNode<T>*> q;
    q.push(top);
    while (!q.empty()) {
        TBinaryTreeNode<T>* current = q.front();
        q.pop();
        function(current);
        if (current->left != nullptr) {
            q.push(current->left);
        }
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
}
void DFS(void(*function)(TBinaryTreeNode<T>*)){
    DFSUtil(top, function);
}

void DFSUtil(TBinaryTreeNode<T>* node, void(*function)(TBinaryTreeNode<T>*)){
    if (node == nullptr) {
        return;
    }
    function(node);
    DFSUtil(node->left, function);
    DFSUtil(node->right, function);
}


void del(T data){
    top = delRecursive(top, data);
}

TBinaryTreeNode<T>* delRecursive(TBinaryTreeNode<T>* current, T data){
    if(current == nullptr){
        return nullptr;
    }

    if(data < current->data){
        current->left = delRecursive(current->left, data);
    } else if(data > current->data){
        current->right = delRecursive(current->right, data);
    } else {
        if(current->left == nullptr){
            TBinaryTreeNode<T>* temp = current->right;
            delete current;
            count--;
            return temp;
        } else if(current->right == nullptr){
            TBinaryTreeNode<T>* temp = current->left;
            delete current;
            count--;
            return temp;
        } else {
            // Узел с двумя потомками
            TBinaryTreeNode<T>* temp = minValueNode(current->right);
            current->data = temp->data;
            current->right = delRecursive(current->right, temp->data);
        }
    }

    return current;
}

TBinaryTreeNode<T>* minValueNode(TBinaryTreeNode<T>* node){
    TBinaryTreeNode<T>* current = node;
    while(current && current->left != nullptr){
        current = current->left;
    }
    return current;
}
T& find(T data){
    TBinaryTreeNode<T>* node = findRecursive(top,data);
if(node != nullptr){
return node->data;
}
throw ;//std::logic_error("Element not found");
}

TBinaryTreeNode<T>* findRecursive(TBinaryTreeNode<T>* current, T data){
if(current == nullptr || current->data == data){
return current;
}

if(data < current->data){
return findRecursive(current->left, data);
} else {
return findRecursive(current->right, data);
}
}

void add(T data){
    top = addRecursive(top, data);
}

TBinaryTreeNode<T>* addRecursive(TBinaryTreeNode<T>* current, T data){
    if(current == nullptr){
        count++;
        return new TBinaryTreeNode<T>(data);
    }

    if(data < current->data){
        current->left = addRecursive(current->left, data);
    } else if(data > current->data){
        current->right = addRecursive(current->right, data);
    } // Handle the case where the data is equal to the current node's data as per your requirement

    return current;
}

};


#endif // TBINARYTREE_H

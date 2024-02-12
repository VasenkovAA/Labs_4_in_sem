#include <iostream>
#include "tbinarytree.h"
using namespace std;



int main() {
    TBinaryTree<int> tree;
    tree.add(20);
    tree.add(10);
    tree.add(5);
    tree.add(15);
    tree.add(40);
    tree.add(45);
    tree.add(30);

    cout << "DFS: ";
    tree.DFS([](TBinaryTreeNode<int>* node) {
        cout << node->data << " ";
    });

    cout << endl;
    cout<<endl;
    cout << "BFS: ";
    tree.BFS([](TBinaryTreeNode<int>* node) {
        cout << node->data << " ";
    });
    cout << endl;



tree.del(30);

    cout << "DFS: ";
    tree.DFS([](TBinaryTreeNode<int>* node) {
        cout << node->data << " ";
    });


    cout << endl;
    cout<<endl;
    cout << "BFS: ";
    tree.BFS([](TBinaryTreeNode<int>* node) {
        cout << node->data << " ";
    });
    cout << endl;


    return 0;
}

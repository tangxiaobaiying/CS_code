#include<iostream>
using namespace std;
struct AVLNode{
    int key;
    AVLNode *L_child;
    AVLNode *R_child;
    // AVLNode *Parent;
    // int index;
    AVLNode(int temp){
        key=temp;
        // index=index_;
        L_child=NULL;
        R_child=NULL;
        // Parent=NULL;
    }
};
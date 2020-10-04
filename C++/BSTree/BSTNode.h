#include<iostream>
using namespace std;
struct BSTNode{
    int key;
    BSTNode *L_child;
    BSTNode *R_child;
    BSTNode *Parent;
    BSTNode(int temp){
        key=temp;
        L_child=NULL;
        R_child=NULL;
        Parent=NULL;
    }
};
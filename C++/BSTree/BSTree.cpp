#include<iostream>
#include "BSTNode.h"
using namespace std;

class BSTree{
private:
    BSTNode *Root;
public:
    BSTree();
    BSTNode *GetRoot();
    BSTNode *FindBST(int);
    void UpdataBSTNode(int,int);
    void insertBSTNode(int);
    void DeleteNoOrOnechildBSTNode(BSTNode *,BSTNode *);
    void DeleteBSTNode(int);
    void PreOrder(BSTNode *);
    void InOrder(BSTNode *);
    void SufOrder(BSTNode *);
};

BSTree::BSTree(){
    Root=NULL;
}

//寻找根节点
BSTNode *BSTree::GetRoot(){
    return this->Root;
} 

BSTNode *BSTree::FindBST(int temp){
    BSTNode *cur=this->Root;
    BSTNode *temp_point=NULL;
    while(cur!=NULL){
        if(cur->key==temp)
            break;
        else if(cur->key>temp){
            temp_point=cur;
            cur=cur->L_child;
            cur->Parent=temp_point;
            }
        else
        {
            temp_point=cur;
            cur=cur->R_child;
            cur->Parent=temp_point;
        }
    }
    return cur;
}

void BSTree::insertBSTNode(int temp){
    BSTNode *cur=this->Root;
    BSTNode *pre=NULL;
    while(cur!=NULL){
        cur->Parent=pre;
        pre=cur;
        if(cur->key>temp)
            cur=cur->L_child;
        else
            cur=cur->R_child;
    }
    BSTNode *tempNode=new BSTNode(temp);
    if(pre==NULL)
        this->Root=tempNode;
    else if(pre->key>tempNode->key)
        pre->L_child=tempNode;
    else
    {
        pre->R_child=tempNode;
    }
    
}

void BSTree::UpdataBSTNode(int oldkey,int newkey){
    DeleteBSTNode(oldkey);
    insertBSTNode(newkey);
}

void BSTree::DeleteNoOrOnechildBSTNode(BSTNode *pre,BSTNode *cur){
    if(cur->L_child==NULL&&cur->R_child==NULL){
        if(pre==NULL)
            Root=NULL;
        else if(pre->L_child==cur)
            pre->L_child=NULL;
        else
            pre->R_child=NULL;
        delete cur;
    }
    else if(cur->L_child!=NULL){
        if(pre=NULL)
            Root=cur->L_child;
        else if(pre->L_child==cur)
            pre->L_child=cur->R_child;
        else
            pre->R_child=cur->R_child;
        delete cur;
    }
    else if(cur->L_child!=NULL)
    {
        if(pre==NULL)
            Root=cur->L_child;
        else if(pre->L_child==cur)
            pre->L_child=cur->L_child;
        else
            pre->R_child=cur->L_child;
        delete cur;
    }
}

void BSTree::DeleteBSTNode(int temp){
    BSTNode *pre=NULL;
    BSTNode *cur=Root;
    while(cur!=NULL){
        if(cur->key==temp)
            break;
        else
        {
            pre=cur;
            if(cur->key>temp)
                cur=cur->L_child;
            else
                cur=cur->R_child;
        }
    }
    if(cur==NULL)
        return ;
    if(cur->L_child==NULL||cur->R_child==NULL)
        DeleteNoOrOnechildBSTNode(pre,cur);
    else
    {
        BSTNode *rPre=cur;
        BSTNode *rCur=cur->R_child;
        while(rCur->L_child!=NULL){
            rPre=rCur;
            rCur=rCur->L_child;
        }
        cur->key=rCur->key;
        DeleteNoOrOnechildBSTNode(rPre,rCur);
    }
}

void BSTree::PreOrder(BSTNode *tempRoot)
{
    if(tempRoot==NULL)
        return ;
    cout<<tempRoot->key<<"  ";
    PreOrder(tempRoot->L_child);
    PreOrder(tempRoot->R_child);
}

void BSTree::InOrder(BSTNode *tempRoot){
    if(tempRoot==NULL)
        return;
    InOrder(tempRoot->L_child);
    cout<<tempRoot->key<<"  ";
    InOrder(tempRoot->R_child);
}

void BSTree::SufOrder(BSTNode *tempRoot){
    if(tempRoot==NULL)
        return;
    SufOrder(tempRoot->L_child);
    SufOrder(tempRoot->R_child);
    cout<<tempRoot->key<<"  ";
}

int main()
{
	int val;
    BSTree myBSTree;
    while(cin>>val)
    {
        if(val==0)
            break;
        myBSTree.insertBSTNode(val);
    }
    cout<<endl<<"*****************************"<<endl;
    myBSTree.PreOrder(myBSTree.GetRoot());
    cout<<endl<<"============================="<<endl;
    myBSTree.InOrder(myBSTree.GetRoot());
    cout<<endl<<"============================="<<endl;
    myBSTree.SufOrder(myBSTree.GetRoot());
    cout<<endl<<"============================="<<endl;
//	myBSTree.RotateBSTPrint(myBSTree.GetRoot(),0);
//	cout<<endl<<"*****************************"<<endl;
    while(cin>>val)
    {
        if(!val)
            break;
        myBSTree.DeleteBSTNode(val);
        cout<<endl<<"*****************************"<<endl;
        myBSTree.PreOrder(myBSTree.GetRoot());
        cout<<endl<<"============================="<<endl;
        myBSTree.InOrder(myBSTree.GetRoot());
        cout<<endl<<"============================="<<endl;
        myBSTree.SufOrder(myBSTree.GetRoot());
        cout<<endl<<"============================="<<endl;
        //myBSTree.RotateBSTPrint(myBSTree.GetRoot(),0);
        //cout<<endl<<"*****************************"<<endl;
    }
	system("pause");
	return 0;
}
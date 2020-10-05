#include<iostream>
#include "AVLNode.h"
using namespace std;
class AVLTree{
private:
    AVLNode *root;
public:
    AVLTree();
    AVLNode *GetRoot();
    int _Hight(AVLNode *);
    bool search(int key);
    AVLNode *Insert(int,AVLNode *);
    void insert(int);
    int BalanceFactor(AVLNode *,AVLNode *);
    AVLNode *Rotate(AVLNode *);
    AVLNode *RotateLL(AVLNode *);
    AVLNode *RotateRR(AVLNode *);
    AVLNode *RotateLR(AVLNode *);
    AVLNode *RotateRL(AVLNode *);
    void PreOrderPrint(AVLNode *);
    void InOrderPrint(AVLNode *);
    void SufOrderPrint(AVLNode *);
};
AVLTree::AVLTree(){
    this->root=NULL;
}
AVLNode *AVLTree::GetRoot(){
    return this->root;
}
int AVLTree::_Hight(AVLNode *root){
    if(root==NULL)
        return 0;
    int left=_Hight(root->L_child);
    int right=_Hight(root->R_child);
    return  left>right?left+1:right+1;
}
bool AVLTree::search(int key){
    AVLNode *temp=this->root;
    while(true){
        if(temp==NULL)
            return false;
        else{
            if(temp->key==key)
                return true;
            else if(temp->key>key)
                temp=temp->L_child;
            else if(temp->key<key)
                temp=temp->R_child;
        }
    }
}

int AVLTree::BalanceFactor(AVLNode *left,AVLNode *right){
    return this->_Hight(left)-this->_Hight(right);
}

/*LL旋转    
          k1                                k2
        /    \                            /    \
       k2     h-1       --->             h      k1
      /  \                                     /  \
     h    h-1                                h-1  h-1
*/
AVLNode *AVLTree::RotateLL(AVLNode *root){
    AVLNode *node=root->L_child;
    root->L_child=node->R_child;
    node->R_child=root;
    // this->root=node;
    return node;
}

/*LR旋转    
          k1                                 k3
        /    \                           /       \
       k2     h-1       --->            k2        k1
      /  \                            /   \     /    \
    h-1   k3                        h-1    h-1  h     h-1
         /  \
       h-1   h                             
*/
AVLNode *AVLTree::RotateLR(AVLNode *root){
    root->L_child=RotateRR(root->L_child);
    return RotateLL(root);
}
/*RR旋转    与LL类似
          k1                                k2
        /    \                            /    \
      h-1     k2        --->             k1     h
             /  \                       /  \
            h-1  h                    h-1  h-1
*/
AVLNode *AVLTree::RotateRR(AVLNode *root){
    AVLNode *node=root->R_child;
    root->R_child=node->L_child;
    node->L_child=root;
    // this->root=node;
    return node;
}

/*RL旋转    与LR类似
          k1                                 k3
        /    \                L           /       \
      h-1     k2      --->              k1        k2
             /  \                     /   \     /    \
            k3   h-1                h-1    h-1  h     h-1
           /  \
         h-1   h                        
*/
AVLNode *AVLTree::RotateRL(AVLNode *root){
    root->R_child=RotateLL(root->R_child);
    return RotateRR(root);
}

AVLNode *AVLTree::Rotate(AVLNode *root){
    AVLNode *left=root->L_child;
    AVLNode *right=root->R_child;
    int bf;
    int bf_;
    bf=this->BalanceFactor(left,right);
    if(bf>1){
        bf_=this->BalanceFactor(left->L_child,left->R_child);
        if(bf_>0)
        {   cout<<"LL------"<<endl;
            return this->RotateLL(root);
        }
        else
        {
            cout<<"LR------"<<endl;
            return this->RotateLR(root);
        }
        
    }
    else if(bf<-1){
        bf_=this->BalanceFactor(right->L_child,right->R_child);
        if(bf_>=0){
            cout<<"RL------"<<endl;
            return this->RotateRL(root);
        }else
        {
            cout<<"RR------"<<endl;
            return this->RotateRR(root);
        }
    }
    else
    {
        return root;
    }
    
}

void AVLTree::insert(int key){
    this->root=this->Insert(key,this->root);
}
AVLNode *AVLTree::Insert(int key,AVLNode *root){
    if(root==NULL){
        root=new AVLNode(key);
    }
    else if(key>root->key){
        root->R_child=Insert(key,root->R_child);
        root=this->Rotate(root);
    }
    else if(key<root->key){
        root->L_child=Insert(key,root->L_child);
        root=this->Rotate(root);
    }
    return root;
}
//while循环遍历（还没弄出来）
//     else{
//         AVLNode *temp=root;
//         while(temp!=NULL){
//             cout<<"start insert value"<<endl;
//             if(temp->key<=key)
//             {
//                 cout<<temp->key<<"------------->temp"<<endl;
//                 temp=temp->R_child;
//                 // temp->R_child=new AVLNode(key);
//                 cout<<temp->key<<"------------>temp.right"<<endl;
//             }
//             else
//             {
//                 cout<<temp->key<<"------------->temp"<<endl;
//                 temp=temp->L_child;
//                 // temp->L_child=new AVLNode(key);
//                 cout<<temp->key<<"------------>temp.left"<<endl;
//             }
//         }
//         temp=new AVLNode(key);
//         // temp->key=key;
//         cout<<temp->key<<"----------<ss"<<endl;
//     }
//     this->Rotate(root);
//     return root;
// }

void AVLTree::PreOrderPrint(AVLNode *temproot){
    AVLNode *temp=temproot;
    if(temp==NULL)
        return;
    this->PreOrderPrint(temp->L_child);
    cout<<temp->key<<" ";
    this->PreOrderPrint(temp->R_child);
}
void AVLTree::InOrderPrint(AVLNode *temproot){
    AVLNode *temp=temproot;
    if(temp==NULL)
        return;
    cout<<temp->key<<" ";
    this->PreOrderPrint(temp->L_child);
    this->PreOrderPrint(temp->R_child);
}
void AVLTree::SufOrderPrint(AVLNode *temproot){
    AVLNode *temp=temproot;
    if(temp==NULL)
        return;
    this->PreOrderPrint(temp->L_child);
    this->PreOrderPrint(temp->R_child);
    cout<<temp->key<<" ";
}

int main(){
    AVLTree myAVLTree;
    //int index=0;
    int val;
    // AVLNode *node;
    while(true){
        cout<<"插入（输入0停止建树）";
        cin>>val;
        if(val==0){
            cout<<"stop\n";
            break;
            }
        else
        {
            myAVLTree.insert(val);
        }
    }
    AVLNode *root=myAVLTree.GetRoot();
    cout<<"**********前序遍历***********"<<endl;
    myAVLTree.PreOrderPrint(root);
    cout<<"\n***********中序遍历**********"<<endl;
    myAVLTree.InOrderPrint(root);
    cout<<"\n**********后序遍历***********"<<endl;
    myAVLTree.SufOrderPrint(root);
    while(true){
        cout<<"\n查找(输入0停止查找)";
        cin>>val;
        if(val==0){
            cout<<"stop\n";
            break;
        }
        else{
            cout<<myAVLTree.search(val)<<endl;
        }
    }
    cout<<"**********前序遍历***********"<<endl;
    myAVLTree.PreOrderPrint(root);
    cout<<"\n***********中序遍历**********"<<endl;
    myAVLTree.InOrderPrint(root);
    cout<<"\n**********后序遍历***********"<<endl;
    myAVLTree.SufOrderPrint(root);
}
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
    AVLNode *search(int key);
    void Insert(AVLNode *);
    int BalanceFactor(AVLNode *,AVLNode *);
    void Rotate(AVLNode *,AVLNode *);
    void RotateLL(AVLNode *);
    void RotateRR(AVLNode *);
    void RotateLR(AVLNode *);
    void RotateRL(AVLNode *);
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
AVLNode *AVLTree::search(int key){
    AVLNode *temproot=this->root;
    while(true){
        if(temproot->key=key)
            return temproot;
        else if(temproot->key<key)
            temproot=temproot->R_child;
        else
            temproot=temproot->L_child;
    }
}
// int AVLTree::GetMaxIndex(){
//     return 
// }
void AVLTree::Insert(AVLNode *node){
    AVLNode *temproot=this->root;        
    while(true){
        if(temproot->key>node->key){
            temproot=temproot->L_child;
        }
        else if(temproot->key<=node->key)
        {
            temproot=temproot->R_child;
        }
        else if(temproot==NULL){
            temproot=node;
            break;    
        }
    }
    AVLNode *L_subtree=this->root->L_child;
    AVLNode *R_subtree=this->root->R_child;
    Rotate(L_subtree,R_subtree);
}

void AVLTree::Rotate(AVLNode *L_sub,AVLNode *R_sub){
    AVLNode *L_TreeSub=L_sub;
    AVLNode *R_TreeSub=R_sub;
    int bf;
    int bf_;
    bf=BalanceFactor(L_TreeSub,R_TreeSub);
    if(bf>1){
        bf_=BalanceFactor(L_TreeSub->L_child,L_TreeSub->R_child);
        if(bf_>1)
            RotateLL(this->root);
        else
        {
            RotateLR(this->root);
        }
    }
    else if(bf<-1){
        bf_=BalanceFactor(R_TreeSub->L_child,R_TreeSub->R_child);
        if(bf_>1)
            RotateRL(this->root);
        else
        {
            RotateRR(this->root);
        }
    }
} 
int AVLTree::BalanceFactor(AVLNode *L_sub,AVLNode *R_sub){
    return _Hight(L_sub)-_Hight(R_sub);
}


int AVLTree::_Hight(AVLNode *node){
    AVLNode *temproot=node;
    if(temproot==NULL)
        return 0;
    int high=0;
    int left=_Hight(temproot->L_child);
    int right=_Hight(temproot->R_child);
    if(left>right)
        high=left;
    else
        high=right;
    return high+1;
}

void AVLTree::RotateLL(AVLNode *temproot){//hight_L>hight_R,左子树左儿子高度大于右子树
    AVLNode *node=temproot;//左右子树不平衡的节点
    AVLNode *Newroot=node->L_child;//旋转节点后，node的左子树节点会顶替node的位置
    AVLNode *Newroot_Rchild=Newroot->R_child;
    // AVLNode *nodeParent=node->Parent;
    // if(nodeParent->L_child==node){
    //     nodeParent->L_child=Newroot;//newnode的parent指针指向node的parent指针
    // }
    // else{
    //     nodeParent->R_child=Newroot;//newnode的parent指针指向node的parent指针
    // }
    node->L_child=Newroot_Rchild;//newroot的右儿子变成node的左儿子。
    Newroot->R_child=node;
    // node->Parent=Newroot;//node成为newnode的右子树节点
}

void AVLTree::RotateRR(AVLNode *temproot){//hight_L<hight_R,右子树右儿子高度大于左子树
    AVLNode *node=temproot;//左右子树不平衡的节点
    AVLNode *Newroot=node->R_child;//旋转节点后，node的左子树节点会顶替node的位置
    AVLNode *Newroot_Lchild=Newroot->L_child;
    // AVLNode *nodeParent=node->Parent;
    // if(nodeParent->L_child==node){
    //     nodeParent->L_child=Newroot;//newnode的parent指针指向node的parent指针
    // }
    // else{
    //     nodeParent->R_child=Newroot;//newnode的parent指针指向node的parent指针
    // }
    node->R_child=Newroot_Lchild;//newroot的右儿子变成node的左儿子。
    Newroot->L_child=node;
    // node->Parent=Newroot;//node成为newnode的右子树节点
}
void AVLTree::RotateLR(AVLNode *temproot){//左子树右儿子高度大于右子树
    AVLNode *node=temproot;//左右子树不平衡的节点
    AVLNode *Newroot_Parent=node->L_child;//旋转节点后，node的左子树节点会顶替node的位置
    AVLNode *Newroot=Newroot_Parent->R_child;
    // AVLNode *nodeParent=node->Parent;
    // if(nodeParent->L_child==node){
    //     nodeParent->L_child=Newroot;//newnode的parent指针指向node的parent指针
    // }
    // else{
    //     nodeParent->R_child=Newroot;//newnode的parent指针指向node的parent指针
    // }
    Newroot_Parent->R_child=Newroot->L_child;
    // Newroot->L_child->Parent=Newroot_Parent;
    // Newroot_Parent->Parent=Newroot;
    Newroot->L_child=Newroot_Parent;
    node->L_child=Newroot->R_child;
    // node->L_child->Parent=node;
    Newroot->R_child=node;
    // Newroot->R_child->Parent=Newroot;
}
void AVLTree::RotateRL(AVLNode *temproot){//右子树左儿子高度大于左子树
     AVLNode *node=temproot;//左右子树不平衡的节点
    AVLNode *Newroot_Parent=node->R_child;//旋转节点后，node的左子树节点会顶替node的位置
    AVLNode *Newroot=Newroot_Parent->L_child;
    // AVLNode *nodeParent=node->Parent;
    // if(nodeParent->L_child==node){
    //     nodeParent->L_child=Newroot;//newnode的parent指针指向node的parent指针
    // }
    // else{
    //     nodeParent->R_child=Newroot;//newnode的parent指针指向node的parent指针
    // }
    Newroot_Parent->L_child=Newroot->R_child;
    // Newroot->R_child->Parent=Newroot_Parent;
    // Newroot_Parent->Parent=Newroot;
    Newroot->R_child=Newroot_Parent;
    node->R_child=Newroot->L_child;
    // node->R_child->Parent=node;
    Newroot->L_child=node;
    // Newroot->L_child->Parent=Newroot;
}
void AVLTree::PreOrderPrint(AVLNode *temproot){
    AVLNode *temp=temproot;
    if(temp==NULL)
        return;
    PreOrderPrint(temp->L_child);
    cout<<temp->key<<" ";
    PreOrderPrint(temp->R_child);
}
void AVLTree::InOrderPrint(AVLNode *temproot){
    AVLNode *temp=temproot;
    if(temp==NULL)
        return;
    cout<<temp->key<<" ";
    PreOrderPrint(temp->L_child);
    PreOrderPrint(temp->R_child);
}
void AVLTree::SufOrderPrint(AVLNode *temproot){
    AVLNode *temp=temproot;
    if(temp==NULL)
        return;
    PreOrderPrint(temp->L_child);
    PreOrderPrint(temp->R_child);
    cout<<temp->key<<" ";
}

int main(){
    cout<<"test"<<endl;
    AVLTree myAVLTree;
    int index=0;
    int val;
    AVLNode *node;
    AVLNode *root=myAVLTree.GetRoot();
    while(true){
        cin>>val;
        if(val==0){
            cout<<"error";
            break;
            }
        else
        {
            // cout<<val<<"successful";
            // cout<<node<<endl;
            // node->key=val;
            index+=1;
            // cout<<index<<"  didi"<<endl;
            // node->index=index;
            // cout<<node->index<<endl;
            // node->key=val;
            node=new AVLNode(val);
            myAVLTree.Insert(node);
        }
    }
    cout<<"**********前序遍历***********"<<endl;
    myAVLTree.PreOrderPrint(root);
    cout<<"**********中序遍历***********"<<endl;
    myAVLTree.InOrderPrint(root);
    cout<<"**********后序遍历***********"<<endl;
    myAVLTree.SufOrderPrint(root);

}

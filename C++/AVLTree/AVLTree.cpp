#include<iostream>
#include "AVLNode.h"
using namespace std;
class AVLTree{
    // test 
private:
    AVLNode *root;
public:
    AVLTree();
    AVLNode *GetRoot();
    int _Hight(AVLNode *);
    AVLNode *search(int key);
    AVLNode *Insert(int,AVLNode *);
    void insert(int);
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
void AVLTree::insert(int val){
    this->root=this->Insert(val,this->root);
}

AVLNode *AVLTree::Insert(int val,AVLNode *root){
    if(root==NULL){
        this->root=new AVLNode(val);
        cout<<root<<"------intital"<<endl;
    }
    AVLNode *temproot=this->root;    
    while(true){
        if(temproot==NULL){
            temproot=new AVLNode(val);
            cout<<temproot->key<<"------------temproot"<<endl;
            break;
        }
        else if(temproot->key<=val)
        {
            temproot=temproot->R_child;
        }
        else if(temproot->key>val){
            temproot=temproot->L_child;
        }
    }
    AVLNode *L_subtree=this->root->L_child;
    AVLNode *R_subtree=this->root->R_child;
    this->Rotate(L_subtree,R_subtree);
    this->PreOrderPrint(root);
}

void AVLTree::Rotate(AVLNode *L_sub,AVLNode *R_sub){
    AVLNode *L_TreeSub=L_sub;
    AVLNode *R_TreeSub=R_sub;
    int bf;//根节点的两个子树
    int bf_;
    cout<<"test"<<endl;
    bf=this->BalanceFactor(L_TreeSub,R_TreeSub);
    cout<<bf<<"--------bf"<<endl;
    if(bf>1){
        bf_=this->BalanceFactor(L_TreeSub->L_child,L_TreeSub->R_child);
        if(bf_>1){
            this->RotateLL(this->root);
            }
        else
        {
            this->RotateLR(this->root);
        }
    }
    else if(bf<-1){
        bf_=this->BalanceFactor(R_TreeSub->L_child,R_TreeSub->R_child);
        if(bf_>1)
            this->RotateRL(this->root);
        else
        {
            this->RotateRR(this->root);
        }
    }
    cout<<bf_<<"-------------_bf"<<endl;
} 
int AVLTree::BalanceFactor(AVLNode *L_sub,AVLNode *R_sub){
    int left=this->_Hight(L_sub);
    int right=this->_Hight(R_sub);
    cout<<left<<"---------------leftsubtree"<<endl;
    cout<<right<<"--------------rightsubtree"<<endl;
    return left-right;
}


int AVLTree::_Hight(AVLNode *node){
    AVLNode *temproot=node;
    if(temproot==NULL)
        return 0;
    int high=0;
    int left=this->_Hight(temproot->L_child);
    int right=this->_Hight(temproot->R_child);
    if(left>right)
        high=left;
    else
        high=right;
    return high+1;
}

void AVLTree::RotateLL(AVLNode *temproot){//hight_L>hight_R,左子树左儿子高度大于右子�?
    AVLNode *node=temproot;//左右子树不平衡的节点
    AVLNode *Newroot=node->L_child;//旋转节点后，node的左子树节点会顶替node的位�?
    AVLNode *Newroot_Rchild=Newroot->R_child;
    // AVLNode *nodeParent=node->Parent;
    // if(nodeParent->L_child==node){
    //     nodeParent->L_child=Newroot;//newnode的parent指针指向node的parent指针
    // }
    // else{
    //     nodeParent->R_child=Newroot;//newnode的parent指针指向node的parent指针
    // }
    node->L_child=Newroot_Rchild;//newroot的右儿子变成node的左儿子�?
    Newroot->R_child=node;
    // node->Parent=Newroot;//node成为newnode的右子树节点
}

void AVLTree::RotateRR(AVLNode *temproot){//hight_L<hight_R,右子树右儿子高度大于左子�?
    AVLNode *node=temproot;//左右子树不平衡的节点
    AVLNode *Newroot=node->R_child;//旋转节点后，node的左子树节点会顶替node的位�?
    AVLNode *Newroot_Lchild=Newroot->L_child;
    // AVLNode *nodeParent=node->Parent;
    // if(nodeParent->L_child==node){
    //     nodeParent->L_child=Newroot;//newnode的parent指针指向node的parent指针
    // }
    // else{
    //     nodeParent->R_child=Newroot;//newnode的parent指针指向node的parent指针
    // }
    node->R_child=Newroot_Lchild;//newroot的右儿子变成node的左儿子�?
    Newroot->L_child=node;
    // node->Parent=Newroot;//node成为newnode的右子树节点
}
void AVLTree::RotateLR(AVLNode *temproot){//左子树右儿子高度大于右子�?
    AVLNode *node=temproot;//左右子树不平衡的节点
    AVLNode *Newroot_Parent=node->L_child;//旋转节点后，node的左子树节点会顶替node的位�?
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
void AVLTree::RotateRL(AVLNode *temproot){//右子树左儿子高度大于左子�?
     AVLNode *node=temproot;//左右子树不平衡的节点
    AVLNode *Newroot_Parent=node->R_child;//旋转节点后，node的左子树节点会顶替node的位�?
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
    cout<<"test"<<endl;
    AVLTree myAVLTree;
    //int index=0;
    int val;
    // AVLNode *node;
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
            // cout<<index<<"  didi"<<endl;
            // node->index=index;
            
            // node->key=val;
            // node=new AVLNode(val);
            myAVLTree.insert(val);
        }
    }
    cout<<"**********ǰ�����***********"<<endl;
    myAVLTree.PreOrderPrint(root);
    cout<<"**********�������***********"<<endl;
    myAVLTree.InOrderPrint(root);
    cout<<"**********�������***********"<<endl;
    myAVLTree.SufOrderPrint(root);

}

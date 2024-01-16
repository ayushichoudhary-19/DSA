#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/
void findceil(BinaryTreeNode<int> *node, int x,int &ceil){
    if(node==nullptr) return;
    if(node->data==x){
        ceil=node->data;
        return;
    };
    if(node->data>x){
        ceil=node->data;
        findceil(node->left,x,ceil);
    }
    else if(node->data<x){
        findceil(node->right,x,ceil);
    }
}
int findCeil(BinaryTreeNode<int> *node, int x){
    
    if(node==nullptr) return -1;
    int ceil=-1;
    findceil(node, x, ceil);
    return ceil;
}






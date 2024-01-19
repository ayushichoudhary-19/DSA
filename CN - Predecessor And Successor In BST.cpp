/*************************************************************

    Following is the Binary Tree node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/
void succ(TreeNode *root, int key, int &s){
    if(root==nullptr) return;
    
    if(root->data>key){
        s=root->data;
        succ(root->left,key,s);
    }
    else if(root->data<=key){
        succ(root->right,key,s);
    }
}
void pred(TreeNode *root, int key, int &p){
    if(root==nullptr) return;
    
    if(root->data>=key){
        pred(root->left,key,p);
    }
    else if(root->data<key){    
        p=root->data;
        pred(root->right,key,p);
    }
}
pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    int s=-1;
    int p=-1;
    succ(root,key,s);
    pred(root,key,p);
    return {p,s};
}


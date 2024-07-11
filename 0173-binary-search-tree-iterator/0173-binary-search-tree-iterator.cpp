/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
private:
    void findinorder(TreeNode* root,vector<TreeNode*> &inorder){
        if(!root) return;
        findinorder(root->left,inorder);
        inorder.push_back(root);
        findinorder(root->right,inorder);
    }

public:

    vector<TreeNode*> inorder;
    int index;
    BSTIterator(TreeNode* root) {
        index=-1;
        findinorder(root,inorder);
    }
    
    int next() {
        return inorder[++index]->val;
    }
    
    bool hasNext() {
        return index+1<inorder.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
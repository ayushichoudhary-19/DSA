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
class Solution {
private:
    void findPreorder(TreeNode* root, vector<TreeNode*> &preorder){
        if(root==NULL) return;
        
        preorder.push_back(root);
        findPreorder(root->left,preorder);
        findPreorder(root->right,preorder);
    }
    
public:
    void flatten(TreeNode* root) {
        if(root==nullptr) return;
        //find preorder
        vector<TreeNode*> preorder;
        findPreorder(root,preorder);
        
        //now link them
        int i;
        for(i=0;i<preorder.size()-1;i++){
            preorder[i]->right=preorder[i+1];
            preorder[i]->left=NULL;
        }
        //for the last node
        preorder[preorder.size()-1]->left=NULL;
        preorder[preorder.size()-1]->right=NULL;
    }
};
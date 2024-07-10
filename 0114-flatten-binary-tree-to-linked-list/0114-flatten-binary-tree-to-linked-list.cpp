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
public:
    void findPreorder(TreeNode* root, vector<TreeNode*> &preorder){
        if(root==NULL) return;
        
        preorder.push_back(root);
        findPreorder(root->left,preorder);
        findPreorder(root->right,preorder);
    }
    void flatten(TreeNode* root) {
        if(!root) return;
        vector<TreeNode*> preorder;
        findPreorder(root,preorder);

        for(int i=0; i<preorder.size()-1; i++){
            preorder[i]->left=NULL;
            preorder[i]->right=preorder[i+1];
        }
        preorder[preorder.size()-1]->right=NULL;
        preorder[preorder.size()-1]->left=NULL;
        return;
    }
};
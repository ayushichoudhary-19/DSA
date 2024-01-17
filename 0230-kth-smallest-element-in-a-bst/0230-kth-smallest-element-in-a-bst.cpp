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
    void helper(TreeNode* root, int k, vector<int> &inorder){
        if(root==nullptr) return;
        
        helper(root->left,k,inorder);
        inorder.push_back(root->val);
        helper(root->right,k,inorder);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        if(root==nullptr) return -1;

        vector<int> inorder;
        helper(root,k,inorder);
        return inorder[k-1];
    }
};
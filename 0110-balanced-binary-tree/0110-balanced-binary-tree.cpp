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
    int findHeight(TreeNode* root, bool &ans){
        if(root==NULL) return 0;

        int lh=findHeight(root->left, ans);
        int rh=findHeight(root->right, ans);
        if(abs(lh-rh)>1) ans=false;

        return 1+max(lh,rh);
    }

    bool isBalanced(TreeNode* root) {
        if(root==nullptr) return -1;
        bool ans=true;
        int lh=0, rh=0;
        if(root->left) lh=findHeight(root->left, ans);
        if(root->right) rh=findHeight(root->right, ans);

        if(abs(lh-rh)>1) return false;
        return ans;
    }

};
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
    void inorderTraversal(TreeNode* root, int &count, int k, int &ans){
        if(root==NULL) return;
        
        inorderTraversal(root->left,count,k,ans);
        count++;
        if(count==k) ans = root->val;
        inorderTraversal(root->right,count,k,ans);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans=-1;
        int count=0;
        inorderTraversal(root,count,k,ans);
        return ans;
    }
};
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

    int maxSum=INT_MIN;

    int maxSumFinder(TreeNode* root){
        if(root==NULL) return 0;
        //discard negative sum paths
        int leftSum=max(0,maxSumFinder(root->left)); //do not consider -ve sum path
        int rightSum=max(0,maxSumFinder(root->right));//do not consider -ve sum path

        maxSum=max(maxSum,root->val + leftSum + rightSum);
        return root->val + max(leftSum,rightSum);
    }

    int maxPathSum(TreeNode* root) {
        maxSumFinder(root);
        return maxSum;
    }
};
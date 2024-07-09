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
    int maxHeight = INT_MIN;
    int heightFinder(TreeNode* root){
        if(root==NULL) return 0;
        int lh=heightFinder(root->left);
        int rh=heightFinder(root->right);
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(root==NULL) return 0;

        int lh=heightFinder(root->left);
        int rh=heightFinder(root->right);

        maxHeight=max(maxHeight,rh+lh);

        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);

        return maxHeight;
    }
};
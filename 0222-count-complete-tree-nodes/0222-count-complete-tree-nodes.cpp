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
    int getLeftHeight(TreeNode* root){
        int lh = 0;
        while(root){
            root = root ->left;
            lh ++;
        }
        return lh;
    }
    
    int getRightHeight(TreeNode* root){
        int rh = 0;
        while(root){
            root = root ->right;
            rh ++;
        }
        return rh;
    }
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;

        int lh = getLeftHeight(root);
        int rh = getRightHeight(root);

        if(lh == rh){
            return (1 << lh) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr) return nullptr;
        
        while(true){
            if(root==p || root==q){
                return root;
            }
            if(p->val < root->val && q->val <root->val){
                root=root->left;
            }
            else if(p->val >root->val && q->val > root->val){
                root=root->right;
            }
            else //when one of them is on left other on right
            return root;
        }
        return root;
    }
};
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
    void findinorder(TreeNode* root, vector<int> &inorder){
        if(root==NULL) return;
        
        findinorder(root->left,inorder);
        inorder.push_back(root->val);
        findinorder(root->right,inorder);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        //first find the inorder
        vector<int> inorder;
        findinorder(root,inorder);
        
        //run normal 2sum function
        int i=0,j=inorder.size()-1;
        while(i<j){
            int currsum = inorder[i]+inorder[j];
            if(currsum==k) return true;
            
            else if(currsum<k) i++;
            else j--;
        }
        return false;
    }
};
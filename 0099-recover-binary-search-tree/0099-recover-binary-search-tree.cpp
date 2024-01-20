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
    void findInorder(TreeNode* root, vector<int>& inorder) {
        if (root == nullptr) return;

        findInorder(root->left, inorder);
        inorder.push_back(root->val);
        findInorder(root->right, inorder);
    }
    void helper(TreeNode* root, vector<int> inorder,int &index ){
        if(root==nullptr) return;
        
        helper(root->left,inorder,index);
        
        if(inorder[index]!=root->val){
            swap(inorder[index],root->val);
                                    }
        index++;
        helper(root->right,inorder,index);

        
    }
    void recoverTree(TreeNode* root) {
        if(root==nullptr) return;
        
        vector<int> inorder;
        findInorder(root,inorder);
        sort(inorder.begin(),inorder.end());
        int index=0;      
        helper(root,inorder,index);
    }
};
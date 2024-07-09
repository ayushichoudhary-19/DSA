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
    void f(TreeNode* node, vector<string> &ans, string str){
        if(node==nullptr) return;

        if(node->left==nullptr && node->right==nullptr){
            str = str + to_string(node->val);
            ans.push_back(str);
            return;
        }
        else{
            str = str + to_string(node->val)+"->";
            if(node->left) f(node->left,ans,str);
            if(node->right) f(node->right,ans,str); 
        }
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string str;
        f(root,ans,str);
        return ans;
    }
};
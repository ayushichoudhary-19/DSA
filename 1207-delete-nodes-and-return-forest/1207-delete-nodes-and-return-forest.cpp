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
    void helper( vector<TreeNode*> &ans, TreeNode* &root, unordered_set<int> &toBeDeleted){
        if(root==NULL) return;
        helper(ans,root->left,toBeDeleted);
        helper(ans,root->right, toBeDeleted);

        if(toBeDeleted.find(root->val)!=toBeDeleted.end()){
            //delete this node
            if(root->left) ans.push_back(root->left);
            if(root->right) ans.push_back(root->right);
            root=NULL;
            delete root;
        }
        
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;

        unordered_set<int> toBeDeleted;

        for(auto node: to_delete){
            toBeDeleted.insert(node);
        }

        helper(ans,root,toBeDeleted);

        if(root!=NULL) ans.push_back(root);

        return ans;
    }
};
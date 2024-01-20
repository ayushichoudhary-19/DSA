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
    void voilationDetection(TreeNode* root, vector<TreeNode*>&voilations,TreeNode* &prev){
        if(root==nullptr) return;
        
        voilationDetection(root->left,voilations,prev);
        if(prev!=nullptr && prev->val>root->val){
            voilations.push_back(prev);
            voilations.push_back(root);
        }
        prev=root;
        voilationDetection(root->right,voilations,prev);
    }
public:
    void recoverTree(TreeNode* root) {
        if(root==nullptr) return;
        //storing voilations in increasing inorder
        vector<TreeNode*> voilations;
        TreeNode* prev=nullptr;
        voilationDetection(root,voilations,prev);
        if (!voilations.empty()) 
         swap(voilations[0]->val,voilations[voilations.size()-1]->val);
    }
};
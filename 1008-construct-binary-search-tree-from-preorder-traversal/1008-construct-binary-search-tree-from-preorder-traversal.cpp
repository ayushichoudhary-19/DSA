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
    TreeNode* formBst(vector<int>& preorder, int &index, int ub){
        if(index==preorder.size() || preorder[index]>ub) return NULL;
        
        TreeNode* root=new TreeNode(preorder[index++]);
        root->left=formBst(preorder,index,root->val);
        root->right=formBst(preorder,index,ub);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index=0;
        return formBst(preorder,index,INT_MAX);
    }
};
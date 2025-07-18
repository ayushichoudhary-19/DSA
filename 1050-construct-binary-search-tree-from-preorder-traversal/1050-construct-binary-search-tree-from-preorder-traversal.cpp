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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
       return build(preorder, i, 1001);
    }
    TreeNode *build(vector<int>& preorder, int &i, int bound){
        if(i==preorder.size() || preorder[i]>bound) return nullptr;

        TreeNode* node = new TreeNode(preorder[i]);
        i++;
        node->left = build(preorder, i, node->val);
        node->right = build(preorder, i, bound);
        return node;
    }
};
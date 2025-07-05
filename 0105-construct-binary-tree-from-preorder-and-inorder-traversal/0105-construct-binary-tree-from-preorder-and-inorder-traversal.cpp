/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr, right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int,int>& inorderNodeLoc) {
        if (preStart > preEnd || inStart > inEnd) return nullptr;

        TreeNode *root = new TreeNode(preorder[preStart]);
        int rootLocInInorder = inorderNodeLoc[root->val];
        int nodesOnLeft = rootLocInInorder - inStart;

        root->left = buildTreeHelper(preorder, preStart + 1, preStart + nodesOnLeft, inorder, inStart, rootLocInInorder - 1, inorderNodeLoc);
        root->right = buildTreeHelper(preorder, preStart + nodesOnLeft + 1, preEnd, inorder, rootLocInInorder + 1, inEnd, inorderNodeLoc);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderNodeLoc;
        for (int i = 0; i < inorder.size(); i++) {
            inorderNodeLoc[inorder[i]] = i;
        }

        TreeNode* root = buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inorderNodeLoc);
        return root;
    }
};

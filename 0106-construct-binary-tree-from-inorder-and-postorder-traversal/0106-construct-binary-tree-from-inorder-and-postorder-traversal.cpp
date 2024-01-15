class Solution {
private:
    TreeNode* buildTrees(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, unordered_map<int, int>& m) {
        if (inStart > inEnd || postEnd > postStart) return nullptr;

        TreeNode* root = new TreeNode(postorder[postStart]);

        int rootLocInInorder = m[root->val];
        int nodesonright = inEnd - rootLocInInorder;

        root->left = buildTrees(inorder, inStart, rootLocInInorder - 1, postorder, postStart - nodesonright - 1, 0, m);
        root->right = buildTrees(inorder, rootLocInInorder + 1, inEnd, postorder, postStart - 1, postStart - nodesonright, m);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> m;
        for (int i = 0; i < inorder.size(); i++) {
            m[inorder[i]] = i;
        }

        TreeNode* root = buildTrees(inorder, 0, inorder.size() - 1, postorder, postorder.size() - 1, 0, m);
        return root;
    }
};

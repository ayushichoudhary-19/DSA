class Solution {
private:
    void solve(TreeNode* root, int smallest, int& ans, bool& found) {
        if (!root) return;

        if (root->val > smallest) {
            if (!found || root->val < ans) {
                ans = root->val;
                found = true;
            }
        }

        solve(root->left, smallest, ans, found);
        solve(root->right, smallest, ans, found);
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        int smallest = root->val;
        int ans = -1;
        bool found = false;
        solve(root, smallest, ans, found);

        return found ? ans : -1;
    }
};

class Solution {
private:
    int solve(int &maxSum, TreeNode* root){
        if(root == nullptr) return 0;

        int l = max(0,solve(maxSum, root->left));
        int r = max(0,solve(maxSum, root->right));

        maxSum = max(maxSum, l + r + root->val);
        return max(l , r) + root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int maxSum = INT_MIN;
        solve(maxSum, root);
        return maxSum;
    }
};	
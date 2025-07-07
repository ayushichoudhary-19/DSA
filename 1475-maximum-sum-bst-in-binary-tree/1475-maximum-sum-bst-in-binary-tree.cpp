/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
 * };
 **/

class NodeValue {
public:
    int minval, maxval, sum;
    NodeValue(int minval, int maxval, int sum){
        this->minval = minval;
        this->maxval = maxval;
        this->sum = sum;
    }
};

class Solution {
private:
    int maxSum = 0; //because there can be a case where adding -ve valued new node brings sum down, so the root's sum at the end might not be the largest.
    NodeValue solve(TreeNode* root) {
        if (!root) {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }

        NodeValue left = solve(root->left);
        NodeValue right = solve(root->right);

        if (left.maxval < root->val && root->val < right.minval) {
            int currsum = root->val + left.sum + right.sum;
            maxSum = max(currsum, maxSum);
            int currMin = min(left.minval, root->val);
            int currMax = max(right.maxval, root->val);
            return NodeValue(currMin, currMax, currsum);
        }

        return NodeValue(INT_MIN, INT_MAX, max(left.sum, right.sum));
    }

public:
    int maxSumBST(TreeNode* root) {
        int sum = solve(root).sum;
        return maxSum;
    }
};

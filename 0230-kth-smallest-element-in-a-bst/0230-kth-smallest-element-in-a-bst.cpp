/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
private:
    void inorder(TreeNode* root, vector<int> &order){
        if(!root) return;

        inorder(root->left,order);
        order.push_back(root->val);
        inorder(root->right,order);
    }
public:
	int kthSmallest(TreeNode* root,int k){
		vector<int> order;
        inorder(root, order);

        return order[k-1];
	}
};
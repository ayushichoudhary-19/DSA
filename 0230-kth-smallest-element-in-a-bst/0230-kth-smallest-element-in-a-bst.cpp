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
    void inorder(TreeNode* root, int &smallCounter, int k, int &smallAns){
        if(!root || smallAns) return;

        inorder(root->left, smallCounter, k , smallAns);
        smallCounter++;
        if(smallCounter == k){
            smallAns = root->val;
            return;
        }
        inorder(root->right, smallCounter, k , smallAns);
    }
public:
	int kthSmallest(TreeNode* root,int k){
        int smallCounter = 0;
        int smallAns = 0;
        inorder(root, smallCounter, k, smallAns);
        return smallAns;
	}
};
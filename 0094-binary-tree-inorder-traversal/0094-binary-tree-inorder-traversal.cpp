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
    vector<int> inorderTraversal(TreeNode* root) {
        
        //left -> root-> right

        vector<int> ans;
        
        TreeNode* curr=root;
        while(curr!=NULL){
            //at every root node, check its left subtree's rightmost node and connect it to the root

            if(curr->left==NULL){
                //if no left subtree is there then store this 
                //as inorder is left, root, right. with no left, write the root
                ans.push_back(curr->val);
                //move to the right subtree
                curr=curr->right;
            }
            else{
                //left subtree exsists, go to its rightmost node
                TreeNode* leftChild=curr->left;
                //get to the leftmost node of this subtree whose root node is leftchild node
                while(leftChild->right!=NULL){
                    leftChild=leftChild->right;
                }
                //now connect the rightmost to the parent root which is pointed by curr
                leftChild->right=curr;

                //now to make sure already traversed left subtree is never traversed back, make it null
                TreeNode* temp = curr;
                curr = curr -> left;
                temp -> left = NULL;
            }

        }
        return ans;

    }
};
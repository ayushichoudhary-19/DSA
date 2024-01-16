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
    TreeNode * findRightMost(TreeNode* root){
        if(root->right==nullptr){
            return root;
        }
        root=root->right;
        return findRightMost(root);
    }
private: 
    TreeNode* helper(TreeNode*root){
        if(root->left==nullptr){
            return root->right;
        }
        else if(root->left==nullptr){
            return root->left;
        }
        TreeNode* rightChild=root->right;
        TreeNode* rightMost=findRightMost(root->left);
        rightMost->right=rightChild;
        return root->left;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) return root;
        
        //if root itself is the key
        if(root->val==key){
            return helper(root); //helper function takes the root matching the key
        }

        TreeNode* head=root;
        while(root!=nullptr){
            if(root->val>key){ //means key is on the left
                if(root->left!=nullptr && root->left->val==key)  //does left exist
                {
                //new root's left after removing this left which is key
                root->left=helper(root->left); //helper function takes the root matching the key
                break;
                }
                else{
                    //maybe value didn't match check further
                    root=root->left;
                }
            }

            else{ //means key is on the right
                if(root->right!=nullptr && root->right->val==key) 
                {
                //new root's right after removing this right which is key
                root->right=helper(root->right); //helper function takes the root matching the key
                break;
                }
                else{
                    //maybe value didn't match check further
                    root=root->right;
                }
            }
        }
        return head;
    }
};
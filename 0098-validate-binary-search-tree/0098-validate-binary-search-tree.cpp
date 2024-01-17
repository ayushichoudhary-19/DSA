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
    bool validChecker(TreeNode* root, long long low, long long high){
        if(root==nullptr) return true;
        
        if(root->val>=high || root->val<=low) return false;
        
        bool left=true,right=true;
        //check left and right subtree now that current node is correct 
        if(root->left)
                left=validChecker(root->left,low,root->val);
                if(!left) return false;
            
        if(root->right)
               right=validChecker(root->right,root->val,high); 
        
        return left&&right;
    }
public:
    bool isValidBST(TreeNode* root) {
        if(root==nullptr) return true;
         
        //single node
        if(!root->left && !root->right) return true;
        
        //Starting range is [int_min to int_max]
        long long low = LLONG_MIN, high = LLONG_MAX;
       
        return validChecker(root,low,high);  
}
};
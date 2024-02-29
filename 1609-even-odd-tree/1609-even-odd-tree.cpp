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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> levelQ;
        if(root->val %2 == 0) return false;
        levelQ.push(root);
        int level = 1;
        while(!levelQ.empty()){
            int parents = levelQ.size();
            int prevOdd = 0, prevEven = 1000002;
            for(int parent=0; parent<parents; parent++){
                root = levelQ.front();
                if(level%2==0) //even level 
                {
                    //check for increasing odds
                    if(root -> left){
                        levelQ.push(root->left);
                        if(root->left->val %2 !=0){
                            if(prevOdd < root->left->val) prevOdd = root->left->val;
                            else return false;
                        }
                        else return false;
                    }
                    if(root -> right){
                        levelQ.push(root->right);
                        if(root->right->val %2 !=0){
                            if(prevOdd < root->right->val) prevOdd = root->right->val;
                            else return false;
                        }
                        else return false;
                    }
                }
                else{ //odd level
                    //check for decreasing evens
                    if(root -> left){
                        levelQ.push(root->left);
                        if(root->left->val %2 ==0){
                            if(prevEven > root->left->val) prevEven = root->left->val;
                            else return false;
                        }
                        else return false;
                    }
                    if(root -> right){
                        levelQ.push(root->right);
                        if(root->right->val %2 ==0){
                            if(prevEven > root->right->val) prevEven = root->right->val;
                            else return false;
                        }
                        else return false;
                    }
                }
                levelQ.pop();
            }
            level++;
        }
        return true;
    }
};
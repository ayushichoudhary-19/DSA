/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

    //\U0001f52e BRUTE FORCE \U0001f52e
// private:
//     void findPath(TreeNode* root, TreeNode* p, vector<TreeNode*> path,vector<vector<TreeNode*>>&ancestors){
//         if(root==nullptr) return;
//         if(root==p) {
//             path.push_back(p);
//             ancestors.push_back(path);
//             return;
//         }
//         path.push_back(root);
//         findPath(root->left,p,path,ancestors);
//         findPath(root->right,p,path,ancestors);
//     }
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         //find paths of root to p and root to q;
//         vector<TreeNode*> pathP,pathQ;
//         vector<vector <TreeNode*>> ancestors;
//         findPath(root,p,pathP,ancestors);
//         findPath(root,q,pathQ,ancestors);

//         if (ancestors[0].empty() || ancestors[1].empty()) {
//             return nullptr;
//         }
//         int n=min(ancestors[0].size(),ancestors[1].size())-1;

//         for (int i = n; i >= 0; i--) {
//             if (ancestors[0][i] == ancestors[1][i]) {
//                 return ancestors[0][i];
//             }
//         }
//         return NULL;
//     }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr) return NULL;
        //if the node is a p/q we return the node
        if(root==p || root==q){
            return root;}
        
        //we have already returned the p and q nodes if came in way
        //so now if we are at the leaf node and still not returned due to p/q then we are at
        //a normal leaf node
        if(root->left==nullptr && root->right==nullptr){
            return nullptr;
        }

        //now check what left and right child return
        
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);

        //now that we have a right and a left return from the subtress we apply three rules
        if(left==nullptr && right==nullptr){
            return nullptr;
        }
        //if both are not null, that is, both returned an actual node
        else if(left!=nullptr && right!=nullptr){
            //In this case we return the entire current node itself
            return root;
        }
        //when one of left/right is null and the other one is not
        else{
             //return the not null one
            if(left) return left;
            else return right;
        }
    }
};
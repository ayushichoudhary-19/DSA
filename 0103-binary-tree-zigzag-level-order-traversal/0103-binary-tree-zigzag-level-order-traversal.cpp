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
    void helper(vector<vector<int>> &levelOrder, TreeNode* root){
        queue<TreeNode*> q;
        if(root==nullptr) return;
        q.push(root);

        while(!q.empty()){
            int nodesAtThisLevel=q.size();
            vector<int> level;
            
            for(int i=0; i<nodesAtThisLevel;i++){
              TreeNode* node=q.front();
              level.push_back(node->val);
              if(node->left) q.push(node->left);
              if(node->right) q.push(node->right);
              q.pop();
            }
            levelOrder.push_back(level);
            level.clear();
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> levelOrder;
        helper(levelOrder, root);

        for(int i=0; i<levelOrder.size(); i++){
            if(i%2!=0) reverse(levelOrder[i].begin(),levelOrder[i].end());
        }
        return levelOrder;
    }
};
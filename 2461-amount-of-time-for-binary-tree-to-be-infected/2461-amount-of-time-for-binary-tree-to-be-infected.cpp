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
    void buildGraph(TreeNode* root, unordered_map<int, vector<int>> &m){
        if(root==nullptr) return;

        if(root->left){
            m[root->val].push_back(root->left->val);
            m[root->left->val].push_back(root->val);
            buildGraph(root->left,m);
        }
        if(root->right){
            m[root->val].push_back(root->right->val);
            m[root->right->val].push_back(root->val);
            buildGraph(root->right,m);
        }
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> m;
        queue<int> q;
        q.push(start);

        buildGraph(root,m);
        unordered_set<int> visited;
        int ans = -1;
        while(!q.empty()){
            int size = q.size();
            ans++;
            for(int i=0; i<size; i++){
                int curr = q.front();
                q.pop();
                visited.insert(curr);
                for(int adj:m[curr]){
                    if(!visited.count(adj)){
                        q.push(adj);
                    }
                }
            }
        }
        return ans;
    }
};
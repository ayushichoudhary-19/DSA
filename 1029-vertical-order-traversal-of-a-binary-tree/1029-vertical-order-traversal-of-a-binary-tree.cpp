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
    void solve(map <int, vector<pair<int,int>>>  &colMap, TreeNode* root, int col, int row){
        if(root == nullptr){
            return;
        }

        colMap[col].push_back({row, root->val});
        solve(colMap, root->left, col - 1, row + 1);
        solve(colMap, root->right, col + 1, row + 1);
    }
public:
    vector<vector<int> > verticalTraversal(TreeNode* root) {
    	vector<vector<int> > ans;
        map <int, vector<pair<int,int>>> colMap;
        solve(colMap, root, 0, 0);

        for(auto &it: colMap){
            sort((it.second).begin(), (it.second).end());
            vector<int> temp;
            for(auto pair: it.second){
                temp.push_back(pair.second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
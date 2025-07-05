class Solution {
private:
    void solve(map <int, multiset<pair<int,int>>>  &colMap, TreeNode* root, int col, int row){
        if(root == nullptr){
            return;
        }

        colMap[col].insert({row, root->val});
        solve(colMap, root->left, col - 1, row + 1);
        solve(colMap, root->right, col + 1, row + 1);
    }
public:
    vector<vector<int> > verticalTraversal(TreeNode* root) {
    	vector<vector<int> > ans;
        map <int, multiset<pair<int,int>>> colMap;
        solve(colMap, root, 0, 0);

        for(auto &it: colMap){
            vector<int> temp;
            for(auto pair: it.second){
                temp.push_back(pair.second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
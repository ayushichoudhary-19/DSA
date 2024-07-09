class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root==NULL) return {};

        queue<pair<TreeNode*,pair<int,int>>> q;
        map<int, map <int, multiset <int> > > m;

        q.push({root,{0,0}});
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int line = q.front().second.first;
            int level = q.front().second.second;
            q.pop();

            m[line][level].insert(node->val);

            if(node->left) q.push({node->left,{line - 1, level + 1}});
            if(node->right) q.push({node->right,{line + 1, level + 1}});
        }


        vector<vector<int>> ans;

        for(auto p:m){
            vector<int> col;
            for(auto q:p.second){
                //concatinate a vector in another empty vector
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};
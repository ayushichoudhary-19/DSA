class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

        queue<tuple<TreeNode*, int, int>> q;
        q.push({root, 0, 0});

        while (!q.empty()) {
            auto [node, row, col] = q.front(); q.pop();
            if (node) {
                pq.push({col, row, node->val});
                q.push({node->left, row + 1, col - 1});
                q.push({node->right, row + 1, col + 1});
            }
        }

        vector<vector<int>> ans;
        map<int, vector<int>> colMap;

        while (!pq.empty()) {
            auto [col, row, val] = pq.top(); pq.pop();
            colMap[col].push_back(val);
        }

        for (auto& [col, vec] : colMap) {
            ans.push_back(vec);
        }

        return ans;
    }
};

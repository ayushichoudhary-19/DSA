class Solution {
public:
    vector<int> inorder;
    
    int lower(int x) {
        int left = 0, right = inorder.size() - 1;
        int floor = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (inorder[mid] == x) return x;
            if (inorder[mid] < x) {
                floor = inorder[mid];
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return floor;
    }
    
    int upper(int x) {
        int left = 0, right = inorder.size() - 1;
        int ceil = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (inorder[mid] == x) return x;
            if (inorder[mid] > x) {
                ceil = inorder[mid];
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ceil;
    }
    
    void inorderFinder(TreeNode* root) {
        if (root == nullptr) return;
        inorderFinder(root->left);
        inorder.push_back(root->val);
        inorderFinder(root->right);
    }
    
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> ans;
        inorderFinder(root);
        for (int query : queries) {
            ans.push_back({lower(query), upper(query)});
        }
        return ans;
    }
};

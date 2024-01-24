 
class Solution {
public:
    void check_palin(vector<int>& arr , int& ans){
        int one_cnt = 0;
        for(auto& it : arr){
            if(it % 2) one_cnt++;
        }
        if(one_cnt <= 1) ans++;
        return;
    }
    void solve(TreeNode* root , int& ans , vector<int>& arr){
        if(!root -> left && !root -> right){
            check_palin(arr , ans);
            return ;
        }
        if(root -> left){
            arr[root -> left -> val]++;
            solve(root -> left , ans , arr);
            arr[root -> left -> val]--;
        }
        if(root -> right){
            arr[root -> right -> val]++;
            solve(root -> right , ans , arr);
             arr[root -> right -> val]--;
        }
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans = 0;
        vector<int> arr(10 , 0);
        arr[root -> val]++;
        solve(root , ans , arr);
        return ans;
    }
};
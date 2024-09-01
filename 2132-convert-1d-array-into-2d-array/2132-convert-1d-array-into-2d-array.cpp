class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(original.size() != m*n) return {};
        vector<vector<int>> ans(m, vector<int> (n,0));
        
        for(int i=0; i<m*n; i++){
            int row = i/n;
            int col = i%n;
            ans[row][col] = original[i];
        }
        return ans;
    }
};
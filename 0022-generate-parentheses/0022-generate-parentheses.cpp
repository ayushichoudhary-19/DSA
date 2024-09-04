class Solution {
private:
    void solve(vector<string> &ans, string seq, int n, int open, int close){
        if(open == n && close == n){
            ans.push_back(seq);
            return;
        }

        if(open < n){
            solve(ans, seq+'(', n, open+1, close);
        }
        if(close < open){
            solve(ans, seq+')', n, open, close+1);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string seq;
        int open=0, close=0;
        solve(ans, seq,n, open, close);
        return ans;
    }
};
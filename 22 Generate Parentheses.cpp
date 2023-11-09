class Solution {
public:
    void solution(vector<string>& ans, int n, string seq, int& open, int& close) {
        if (seq.length() == 2 * n) {
            ans.push_back(seq);
            return;
        }

        if (open < n && open >= close) {
            open++;
            solution(ans, n, seq + "(", open, close);
            open--;
        }

        if (close < open) {
            close++;
            solution(ans, n, seq + ")", open, close);
            close--;
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string seq = "";
        int open = 0;
        int close = 0;
        solution(ans, n, seq, open, close);
        return ans;
    }
};

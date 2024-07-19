class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<int> prev(n + 1, 0), curr(n + 1, 0);

        // base cases
        for (int idx2 = 0; idx2 <= n; idx2++) {
            prev[idx2] = idx2;
        }

        for (int idx1 = 1; idx1 <= m; idx1++) {
            curr[0] = idx1;  // Initialize the first column of the current row
            for (int idx2 = 1; idx2 <= n; idx2++) {
                if (word1[idx1 - 1] == word2[idx2 - 1]) {
                    curr[idx2] = prev[idx2 - 1];
                } else {
                    int insertions = 1 + curr[idx2 - 1];
                    int deletions = 1 + prev[idx2];
                    int replacements = 1 + prev[idx2 - 1];
                    curr[idx2] = min({insertions, deletions, replacements});
                }
            }
            prev = curr;  // Move current row to previous row for next iteration
        }
        return prev[n];  // Return the result from the last filled row
    }
};

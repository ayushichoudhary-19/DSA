class Solution {
public:
    string reverseWords(string s) {
        string ans;
        string word;
        int n = s.size();
        
        for (int i = 0; i < n; ++i) {
            char ch = s[i];
            if (ch != ' ') {
                word += ch;
            } else if (ch == ' ') {
                if (!word.empty()) { // Only add non-empty words
                    if (ans.empty()) {
                        ans = word; // For the first word, no need to add a space
                    } else {
                        ans = word + " " + ans; // Prepend word to the answer
                    }
                    word = "";
                }
            }
        }
        
        if (!word.empty()) {
            if (ans.empty()) {
                ans = word;
            } else {
                ans = word + " " + ans;
            }
        }
        
        return ans;
    }
};

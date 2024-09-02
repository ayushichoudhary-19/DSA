class Solution {
public:
    bool isPalindrome(string s) {
        string snew;

        for(auto& ch: s){
            if(isalpha(ch) || isdigit(ch)){
                snew.push_back(tolower(ch));
            }
            // else if(isdigit(ch))
        }
        string rev = snew;
        cout<<rev;
        reverse(snew.begin(),snew.end());
        return rev == snew;
    }
};
class Solution {
public:
    bool isPalindrome(string s) {
        string snew;

        for(auto& ch: s){
            if(ch <= 'Z' && ch >= 'A' || ch <= 'z' && ch >= 'a' || ch>= '0' && ch<= '9'){
                snew.push_back(tolower(ch));
            }
        }
        string rev = snew;
        cout<<rev;
        reverse(snew.begin(),snew.end());
        return rev == snew;
    }
};
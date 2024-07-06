class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen=0;
        string maxLenPal;
        int sLen=s.length();
        for(int ch = 0; ch < sLen; ch++){
            //odd length palindrome with this char as center
            int l=ch,r=ch;
            while(l>=0 && r<sLen && s[l]==s[r]){
                if(r-l+1 > maxLen){
                    maxLen=r-l+1;
                    maxLenPal = s.substr(l,r-l+1);
                }
                l--;
                r++;
            } 

            //even length palindome with this char as semi center
            l=ch, r=ch+1;
            while(l>=0 && r<sLen && s[l]==s[r]){
                if(r-l+1 > maxLen){
                    maxLen=r-l+1;
                    maxLenPal = s.substr(l,r-l+1);
                }
                l--;
                r++;
            } 
        }
        return maxLenPal;
    }
};
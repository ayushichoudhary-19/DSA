class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.length();
        string sub;
        string ans;
        for(int l = n/2; l>=1; l--){
            if(n%l==0){
                //take this lengthed substr else don't
                sub=s.substr(0,l);
                ans="";

                int times = n/l;
                
                for(int i=1; i<=times; i++){
                   ans = ans + sub;
                }
                if(ans==s) return true;
            }
        }
        return false;
    }
};
class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> str(26,0);
        for(auto ch:s){
            str[ch-'a']++;
        }
        string ans="";
        for(auto ch:order){
            if(str[ch-'a']>0){
                while(str[ch-'a']){
                  ans+=ch;
                  str[ch-'a']--;  
                }
                
            }
        }
        for(int ch=0;ch<26;ch++){
            if(str[ch]>0) {
                while(str[ch]){
                    ans+=ch+'a';
                    str[ch]--;
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        ans+=s[0];
        int cnt=1;
        for(int i=1; i<s.length(); i++){
            if(s[i]==s[i-1]) cnt++;
            else cnt=1;

            if(cnt<3){
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};
class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        int n=s.length();
        unordered_map<char,int> map;
        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;
        int ch=0;
        while(ch<n){
            if(ch<n-1 && map[s[ch]]<map[s[ch+1]]){
                ans = ans + map[s[ch+1]]-map[s[ch]];
                ch+=2;
            }
            else{
                ans= ans + map[s[ch]];
                ch++;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0, r=0, n=s.length();
        unordered_map<int,int> map(26);
        int maxfreq=0, maxLen=0;
        while(r<n){
            map[s[r]-'A']++;
            maxfreq = max(maxfreq, map[s[r]-'A']);

            int len = r-l+1;
            if(len-maxfreq <=k ) //this is a valid string
            {
                maxLen = max(maxLen, len);
            }
            else{
                map[s[l]-'A']--;
                l++;
                //update max freq
                int maxi=0;
                for(auto it=map.begin(); it!=map.end(); it++){
                    maxi = max(maxi,it->second);
                }
                maxfreq=maxi;
            }
            r++;
        }
        return maxLen;
    }
};
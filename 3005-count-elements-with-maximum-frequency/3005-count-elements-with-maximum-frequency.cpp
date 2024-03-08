class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int ans=0;
        int maxfreq=INT_MIN;
        unordered_map<int,int> m;
        for(auto num:nums){
            m[num]++;
            maxfreq=max(maxfreq,m[num]);
        }
        for(auto it=m.begin();it!=m.end();it++){
            if(maxfreq==it->second){
                ans+=it->second;
            }
        }
        return ans;
        
    }
};
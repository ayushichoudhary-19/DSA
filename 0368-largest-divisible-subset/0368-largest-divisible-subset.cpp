class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> ans;

        sort(nums.begin(), nums.end());
        int n=nums.size();

        vector<int> dp(n+1,1), hash(n,0);

        int maxi=INT_MIN, lastIdx=0;
        for(int idx=0; idx<n; idx++){
            hash[idx] = idx;
            for(int prev=0; prev<idx; prev++){

                if(nums[idx]%nums[prev]==0 && dp[idx]<dp[prev]+1){
                    dp[idx] = dp[prev] + 1;
                    hash[idx] = prev;
                }
            }
            if(maxi < dp[idx]){
                maxi = dp[idx];
                lastIdx=idx;
            }
        }

        ans.push_back(nums[lastIdx]);
        while(hash[lastIdx]!=lastIdx){
            lastIdx = hash[lastIdx];
            ans.push_back(nums[lastIdx]);
        }

        reverse(ans.begin(), ans.end());
    return ans;
    }

};
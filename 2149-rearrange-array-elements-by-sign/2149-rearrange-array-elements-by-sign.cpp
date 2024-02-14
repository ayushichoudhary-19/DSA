class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int size=nums.size();
        vector<int> pos;
        vector<int> neg;
        
        for(auto num:nums){
            if(num>0) pos.push_back(num);
            else neg.push_back(num);
        }
        
        // merge two arrays
        vector<int> ans;
        for(int i=0;i<size/2;i++){
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }
        return ans;
    }
};
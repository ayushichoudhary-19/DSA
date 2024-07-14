class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n=nums.size();
        nums.insert(nums.end(),nums.begin(), nums.end());

        vector<int> ans(nums.size(),-1);
        for(int i=nums.size()-1; i>=0; i--){
            while(!st.empty() && st.top()<=nums[i]){
                st.pop();
            }
            if(!st.empty()) ans[i]=st.top();
            st.push(nums[i]);
        }
        
        vector<int> res(n,-1);
        for(int i=0; i<n; i++){
            res[i]=ans[i];
        }

        return res;
    }
};
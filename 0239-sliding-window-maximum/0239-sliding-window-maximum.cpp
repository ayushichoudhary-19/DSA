class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> deq;
        vector<int> ans;

        for(int i=0; i<nums.size(); i++){
            //step - 1 maintain window size of k
            //thus remove i-k or lesser indexes
            while(!deq.empty() && deq.front()<=i-k){
                deq.pop_front();
            }

            //step - 2 remove all lesser values than curr value from back of deq
            while(!deq.empty() && nums[deq.back()]<nums[i]){
                deq.pop_back();
            }

            //step - 3 add current 
            deq.push_back(i);

            //we start storing answer once we reach a window size k for starting
            if(i>=k-1) {
                ans.push_back(nums[deq.front()]);
            }
        }
        return ans;
    }
};
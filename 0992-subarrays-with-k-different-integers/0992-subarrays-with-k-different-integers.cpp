class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        map<int, int> mp;
        map<int, int> mp2;

        int left1 = 0;
        int left2 = 0;

        int right = 0;
        int ans = 0;
        int lastUnique = 0;

        while(right < nums.size())
        {
            mp[nums[right]]++;
            mp2[nums[right]]++;

            while(mp.size() > k)
            {
                mp[nums[left1]]--;

                if(mp[nums[left1]]==0)
                {
                    mp.erase(nums[left1]);
                }
                left1++;
            }

            while(mp.size() >= k)
            {
                mp2[nums[left2]]--;

                if(mp2[nums[left2]]==0)
                {
                    mp2.erase(nums[left2]);
                }

                if(mp2.size() < k)
                {
                    mp2[nums[left2]] = 1;
                    lastUnique = left2;
                    break;
                }

                left2++;
            }

            if(mp.size() == k)
            {
                ans += lastUnique - left1 + 1;
            }

            right++;
        }
        
        return ans;
    }
};
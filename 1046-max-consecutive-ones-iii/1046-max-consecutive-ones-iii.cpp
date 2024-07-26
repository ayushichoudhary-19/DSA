#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int K = k;
        int ans = 0;
        int l = 0, r = 0;
        int n = nums.size();

        while (l <= r && r < n) {
            if (nums[r] == 1) {
                r++;
            } else if (nums[r] == 0 && K > 0) {
                r++;
                K--;
            } else {
                // k is exhausted and a 0 is found
                while(nums[l]!=0){
                    l++;
                }
                l++;
                r = l;
                K = k;
            }

            ans = max(ans, r-l);
        }

        return ans;
    }
};

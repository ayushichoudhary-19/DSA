class Solution {
private:
  int sumD(vector<int> &nums, int divisor){
      int sum = 0;

      for(int num:nums){
         sum += ceil((double)(num)/(double)(divisor)); 
      }

      return sum;
  }
public:
  int smallestDivisor(vector<int> &nums, int limit) {
        int maxInNums = *max_element(nums.begin(), nums.end());

        int low = 1, high = maxInNums;
        int mid;
        while(low <= high){
          mid = low + (high - low)/2;

        //find divisor sum
        int divisorSum = sumD(nums, mid);

        if(divisorSum <= limit){
          high = mid - 1;
        }
        else{
          low = mid + 1;
        }
        }
        return low;
    }
};
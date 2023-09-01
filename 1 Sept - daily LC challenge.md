# Counting Bits
Leetcode Problem:
https://leetcode.com/problems/counting-bits/description/?envType=daily-question&envId=2023-09-01 
# Complexity

**Time Complexity:**
The code has a loop that runs from 0 to `n`. In each iteration of the loop, it performs a while loop that runs until the value of `num` (which starts as `i`) becomes 0. The while loop, in the worst case, runs until `num` becomes 0, which means it iterates for the number of bits required to represent `num`. In the worst case, this is O(log₂(n)), where `n` is the input number.

Since the outer loop runs for all integers from 0 to `n`, the overall time complexity is O(n * log₂(n)).

**Space Complexity:**
The primary data structure is the vector `arr`. The size of this vector is `(n + 1)`.
Therefore, the space complexity is O(n + 1), which simplifies to O(n).

# Code
```
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> arr;
        int i,count; 
        for(i=0;i<=n;i++){
            int num=i;
            count=0;
            while(num>0){
            if(num&1){
                count++;
            }
            num=num>>1;
            }
            arr.push_back(count);
        }
        return arr;
        }
    
};
```

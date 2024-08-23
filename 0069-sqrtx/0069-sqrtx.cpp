class Solution {
public:
    int mySqrt(int n) {
        long long low = 0, high = n;
        int floorsqrt=0;
        while(low <= high){
            long long mid = low + (high-low)/2;

            if((long long)(mid*mid) <= (long long)(n)){
                floorsqrt = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return floorsqrt;
    }
};
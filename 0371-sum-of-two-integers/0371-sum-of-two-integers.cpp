class Solution {
public:
    int getSum(int a, int b) {
        int sum = a^b;
        int carry = (a&b)<<1;

        while(carry!=0){
            a=sum;
            b=carry;
            sum = a^b;
            carry=(a&b)<<1;
            
        }
        return sum;
    }
};
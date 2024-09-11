class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorRes = start ^ goal;
        int count = 0;

        //now count number of 1s in xor res , those number of bits 
        //are different and needs to be flipped

        while(xorRes){
            count += (xorRes & 1);
            xorRes = xorRes >> 1;
        }
        return count;
    }
};
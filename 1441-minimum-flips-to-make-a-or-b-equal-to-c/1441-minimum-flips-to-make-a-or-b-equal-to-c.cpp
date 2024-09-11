class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;

        for(int i=0; i<32; i++){
            int bita = a & 1;
            a = a>>1;
            int bitb = b & 1;
            b = b>>1;
            int bitc = c & 1;
            c = c>>1;

            if(bitc == 1){
                if(bita != 1 && bitb != 1) flips++;
            }
            else{
                if(bita == 1) flips++;
                if(bitb == 1) flips++;
            }
        }
        return flips;
    }
};
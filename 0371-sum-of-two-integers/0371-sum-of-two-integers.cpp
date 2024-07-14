class Solution {
public:
    int getSum(int a, int b) {
        if(b>=0){
            for(int i=1; i<=b; i++){
                a++;
            }
        }
        else{
            for(int i=b; i<0; i++){
                a--;
            }
        }
        return a;
    }
};
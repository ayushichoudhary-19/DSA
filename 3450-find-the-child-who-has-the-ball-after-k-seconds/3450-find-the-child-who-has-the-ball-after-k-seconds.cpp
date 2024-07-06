class Solution {
public:
    int numberOfChild(int n, int k) {
        int timer=0;
        int person=0;
        int direction=0;
        while(timer<k){
           if(person==n-1){
                direction=1;
            }
            else if(person==0){
                direction=0;
            }
            if(direction==0){
                person++;
            }
            else{
                person--;
            }
            timer++;
        }
        return person;
    }
};
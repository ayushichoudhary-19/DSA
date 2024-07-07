class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=numBottles;
        //these bottles are emptied after first all drinks
        int newBottles=numBottles/numExchange;
        int leftEmpty=numBottles%numExchange;
        //keep exchanging the empty bottles and adding those to drinkables
        int emptyBottles=newBottles + leftEmpty;

        ans+=newBottles;
        while(emptyBottles>=numExchange){
            int newBottles=emptyBottles/numExchange;
            ans+=newBottles;
            leftEmpty=emptyBottles%numExchange;
            emptyBottles=newBottles+leftEmpty;
        }
        return ans;
    }
};
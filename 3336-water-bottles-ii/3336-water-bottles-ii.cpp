class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int totalBottlesDrunk = 0;

        while (numBottles > 0) {
            if (numBottles >= numExchange) {
                totalBottlesDrunk += numExchange;
                numBottles -= numExchange;
                numBottles += 1; // Gain one full bottle from exchange
                numExchange += 1; // Increase exchange rate
            } else {
                totalBottlesDrunk += numBottles;
                numBottles = 0; // No more bottles to drink
            }
        }
        return totalBottlesDrunk;
    }
};

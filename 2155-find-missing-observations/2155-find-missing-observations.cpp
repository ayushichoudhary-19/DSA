class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int Sm = accumulate(rolls.begin(), rolls.end(), 0);  // More concise sum calculation
        int m = rolls.size();

        // Calculate the sum for the missing rolls
        int Sn = (n + m) * mean - Sm;

        // If Sn is not within the possible range of dice rolls, return an empty vector
        if (Sn > n * 6 || Sn < n) return {};

        // Base value for each roll
        int eachRoll = Sn / n;
        int remainder = Sn % n;

        // Initialize the result vector with the base value
        vector<int> nRolls(n, eachRoll);

        // Distribute the remainder by incrementing the first 'remainder' rolls
        for (int i = 0; i < remainder; i++) {
            nRolls[i]++;
        }

        return nRolls;
    }
};

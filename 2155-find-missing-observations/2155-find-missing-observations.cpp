class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int Sm = 0;
        int m = rolls.size();
        for(auto& num: rolls){
            Sm += num;
        }

        int Sn = (n+m)*mean - Sm;

        if(Sn > n*6 || n > Sn) return {};

        int eachRoll = Sn/n;
        vector<int> nRolls(n, eachRoll);
        
        int remainder = Sn%n;
        //now distribute this remainder in each value

        for(int i=0; i<n && remainder>0; i++){
            if (nRolls[i] < 6) {
                nRolls[i]++;
                remainder--;
            }
        }
        return nRolls;

    }
};
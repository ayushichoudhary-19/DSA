class Solution {
private:
    int getSumOfDigits(string snew, int k){
        int sum;
        while(k){
            sum=0;
            for(auto& ch: snew){
                // sum += stoi(string(1,ch));
                sum += ch-'0';
            }
            snew = to_string(sum);
            k--;
        }
        return sum;
    }
public:
    int getLucky(string s, int k) {
        string snew;
        for(auto& ch: s){
            int val = ch-'a'+1;
            //push_back adds a single character
            // snew.push_back(to_string(val));
            //append adds a whole string
            snew.append(to_string(val));
        }
        
        return getSumOfDigits(snew,k);
    }
};
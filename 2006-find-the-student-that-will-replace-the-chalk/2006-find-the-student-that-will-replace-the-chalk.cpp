class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum=0;
        for(auto& ch:chalk) sum+=ch;

        //fine rounds where k lasts for all
        long long f = k/sum;

        //now whatever is left for that sum, we need to go over the chalk array
        long long kLeftAfterFineRounds = k%sum;

        for(int i=0; i<chalk.size(); i++){
            if(kLeftAfterFineRounds >= chalk[i]){
                kLeftAfterFineRounds -= chalk[i];
            }
            else return i;
        }        
        return 0;

    }
};
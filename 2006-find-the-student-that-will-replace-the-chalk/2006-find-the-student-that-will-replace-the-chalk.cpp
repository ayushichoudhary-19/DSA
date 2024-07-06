class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum=0;
        for(auto ch:chalk){
            sum+=ch;
        }
        // chalksLeftForDecisingRound
        k=k%sum;
        for(int stu=0; stu<chalk.size(); stu++){
            if(chalk[stu]<=k) {
                    k-=chalk[stu];
                }
                else return stu;
        }
        return -1;
    }
};
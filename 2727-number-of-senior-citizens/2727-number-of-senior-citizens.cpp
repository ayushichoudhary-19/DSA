class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt=0;
        //till idx 9 : num; idx 10 is gen; idx 11 & 12 is ans
        int upperbound=60;

        for(auto detail:details){
        string age = string(1,detail[11]) + string(1,detail[12]);
        if(stoi(age)>upperbound) cnt++;
        }
        return cnt;
    }
};
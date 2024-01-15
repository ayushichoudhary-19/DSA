class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        vector<vector<int>> answer;
        map<int,int> loseCount;
        
        //notice that we have to only return two lists
        //one with no loser and other with those who lost only once 
        //so we can focus on only the losers in matches to get an answer
        
        for(auto match:matches){
            int loser=match[1];
            int winner=match[0];
        
            loseCount[loser]++;
            if(!loseCount[winner]) loseCount[winner]=0;
        }
        
        // map looks like:
        // 1 -> 0
        // 3 -> 3
        // 2 -> 0
        // 6 -> 2...so on
        
        vector<int> neverALoser, onceALoser;
        
        for(auto it=loseCount.begin();it!=loseCount.end();it++){
            if(it->second==0)
                neverALoser.push_back(it->first);
            if(it->second==1)
                onceALoser.push_back(it->first);
        }
        answer.push_back(neverALoser);
        answer.push_back(onceALoser);
        return answer;
    }
};
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int l=0, r=0, n=answerKey.length();
        int maxf=0, maxl=0;
        unordered_map<char,int> map(2);
        while(r<n){
            map[answerKey[r]]++;
            maxf=max(maxf,map[answerKey[r]]);

            int len = r-l+1;
            if(len - maxf <= k){
                maxl = max(maxl,len);
            }
            else{
                map[answerKey[l]]--;
                l++;
                maxf=0;
                for(auto it=map.begin(); it!= map.end(); it++){
                    maxf=max(maxf,it->second);
                }
            }
            r++;
        }
        return maxl;
    }
};
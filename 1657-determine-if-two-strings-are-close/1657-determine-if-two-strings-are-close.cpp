class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        if(word1.length()!=word2.length()) return false;

//         string temp1=word1,temp2=word2;
//         sort(temp1.begin(),temp1.end());
//         sort(temp2.begin(),temp2.end());
//         if(temp1==temp2) return true;
        //now above are useful for operation 1 but also, the following steps incorporate both op1&2
        
        

        vector<int> w1(26,0),w2(26,0);

//Two rules to ensure closenes:
//1. frequencies of elements should be same in both. Not matching the chars but only freq should match.


//2. along with frequencies, all the characters should be same means
        //'cabbba' and 'abbccc' have same chars which are a,b,c means if a char exists in word1 then it should exist in word2 also and no different char should be present in any one of them
        
        for(char ch:word1){
            w1[ch-'a']++;
        }
        for(char ch:word2){
            w2[ch-'a']++;
        }
        //1
        for(int i=0;i<26;i++){
            if(w1[i]>0 && w2[i]>0) continue;
            if(w1[i]==0 && w2[i]==0) continue;
            else return false;
            
           
        }
        //2
        sort(w1.begin(),w1.end());
        sort(w2.begin(),w2.end());
        return w1==w2;
        
        

    }
};
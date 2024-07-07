class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";

        string say = countAndSay(n-1);
        string res;

        int len = say.length();
        for(int i=0; i<len; i++){
            char ch = say[i];
            int cnt = 1;

            while(i< len-1 && say[i]==say[i+1]){
                cnt++;
                i++;
            }
            res = res + to_string(cnt) + say[i];
        }
        return res;
    }
};
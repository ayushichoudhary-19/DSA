class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> openPositions;
        int len = s.length();
        for(int i=0; i<len; i++){
            if(s[i]=='(') openPositions.push(i);
            if(s[i]==')'){
                int from = openPositions.top();
                int to = i;
                openPositions.pop();
                reverse(s.begin()+from+1, s.begin()+to);
            }
        }

        string ans;

        for(auto ch:s){
            if(ch!='(' && ch!=')') ans+=ch;
        }
        return ans;
    }
};
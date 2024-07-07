class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.length();
        if(n==1) return 1;

        stack<char> st;

        for(auto ch:s){
            if(ch=='('){
                st.push(ch);
            }
            else{
                if(st.size()>0 && st.top()=='('){
                st.pop();
                }
                else st.push(ch);
            }
        }
        return st.size();
    }
};
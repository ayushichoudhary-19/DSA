class Solution {
public:
    bool isValid(string s) {
        stack<int> st;

        for(auto& ch:s){
            if(ch == '(' || ch == '{' || ch == '[')
                st.push(ch);
            else{
                if(st.empty()) return false;
                char top = st.top();
                if(ch == ')' && top == '(' || ch == '}' && top=='{' || ch == ']' && top == '['){
                    st.pop();
                }
                else return false;
            }
        }
        return st.size()==0;
    }
};
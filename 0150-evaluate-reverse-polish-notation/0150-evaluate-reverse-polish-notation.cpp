class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> stk;

        for(auto& str:tokens){
            if(str=="*" || str=="/" || str=="+" || str=="-"){
                int a = stoi(stk.top());
                stk.pop();
                int b = stoi(stk.top());
                stk.pop();

                int ans = 0;
                
                if(str=="*") ans += (a*b);
                else if(str == "/") ans += (b/a);
                else if(str == "+") ans += (a+b);
                else ans += (b-a);

                stk.push(to_string(ans));
            }
            else stk.push(str);
        }
        return stoi(stk.top());
    }
};
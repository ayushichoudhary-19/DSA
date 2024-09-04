class MinStack {
public:
    stack<int> st;
    stack<int> minstack;
    MinStack() {}
    
    void push(int val) {
        if(st.empty() || val <= minstack.top()) {
            minstack.push(val);
        }
        st.push(val);
    }

    void pop() {
        if(st.top() == minstack.top())
        {minstack.pop();}
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin(){
        return minstack.top();
    }
};

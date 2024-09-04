class MinStack {
public:
    stack<pair<int,int>> st;
    MinStack() {}
    
    void push(int val) {
        int mini;
        if(st.empty()) mini = val;
        else mini = min(val, st.top().first);
        st.push({mini,val});
    }

    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().second;
    }
    
    int getMin(){
        return st.top().first;
    }
};

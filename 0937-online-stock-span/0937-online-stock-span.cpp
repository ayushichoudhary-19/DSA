class StockSpanner {
public:
    vector<int> arr;
    stack<int> st;
    int index;
    StockSpanner() {
        st.push(-1);
        index=-1;
    }
    
    int next(int price) {
        arr.push_back(price);
        index++;
        while(st.top()!=-1 && arr[st.top()]<=arr[index]){
            st.pop();
        }
        int ans=index-st.top();
        st.push(index);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
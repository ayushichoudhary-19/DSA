class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size=temperatures.size();
        vector<int> answer(size,0);
        stack<pair<int,int>>st;

        for(int i=size-1;i>=0;i--){
            while(!st.empty() && st.top().first<=temperatures[i]){
                st.pop();
            }
            // now top most is greater than the current element
            if(!st.empty()){
                answer[i]=st.top().second-i;
            }
            else{
                answer[i]=0;
            }
            st.push({temperatures[i],i});
        }
        return answer;
    }
};
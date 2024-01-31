using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int> answer(size, 0);
        stack<int> st;

        for (int i = size - 1; i >= 0; i--) {
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }
            if (!st.empty()) {
                answer[i] = st.top() - i;
            }
            st.push(i);
        }
        return answer;
    }
};

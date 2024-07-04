class Solution {
public:
    void NSL(vector<int> &nsl, vector<int>& heights){
        int size=heights.size();
        stack<int> st;
        for(int i=0; i<size; i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()) nsl[i]=-1;
            else nsl[i]=st.top();
            
            st.push(i);
        }
    }

    void NSR(vector<int> &nsr, vector<int>& heights){
        int size=heights.size();
        stack<int> st;
        for(int i=size-1; i>=0; i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()) nsr[i]=size;
            else nsr[i]=st.top();
            
            st.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        int size=heights.size();
        if(size==1) return heights[0];

        vector<int> nsl(size,-1);
        vector<int> nsr(size,size);
        NSR(nsr,heights);
        NSL(nsl,heights);
        
        int maxArea=0;
        for(int i=0; i<size; i++){
            int currArea=heights[i] * (nsr[i]-nsl[i]-1);
            cout<<currArea<<" ";
            maxArea=max(maxArea,currArea);
        }
        return maxArea;
        
    }
};
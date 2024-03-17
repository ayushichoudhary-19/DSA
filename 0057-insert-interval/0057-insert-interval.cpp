class Solution {
private:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        
        for(int i=0;i<intervals.size();i++){
                if(ans.empty()) ans.push_back(intervals[i]);
                else if(ans.back()[1]>=intervals[i][0]){
                    if(ans.back()[1]>=intervals[i][1]) continue;
                    else ans.back()[1]=intervals[i][1];
                }
                else ans.push_back(intervals[i]);
            }   
        return ans;
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> newintervals;
        if(intervals.size()==0) return {newInterval};
        //insert in sorted place
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0]>newInterval[0]){
                newintervals.push_back(newInterval);
            }
            newintervals.push_back(intervals[i]);
        }
            if(newintervals.size()!=intervals.size()+1) newintervals.push_back(newInterval);
            return merge(newintervals);
        }
};
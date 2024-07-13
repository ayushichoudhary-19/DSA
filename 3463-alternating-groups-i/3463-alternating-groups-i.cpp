class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        for(int i=0; i<2; i++){
            colors.push_back(colors[i]);
        }
        int n=colors.size();
        int cnt=1, ans=0;
        for(int i=1; i<n; i++){
            if(colors[i]!=colors[i-1]){
                cnt++;
            }
            else{
                cnt=1;
            }
            if(cnt>=3) ans++;
        }
        return ans;
    }
};
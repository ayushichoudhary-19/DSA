int f(int day,int previdx,vector<vector<int>> &dp,vector<vector<int>> &points){
    if(day==0){
        int maxi=0;
        for(int task=0;task<3;task++){
                if(task!=previdx){
                    maxi=max(maxi,points[day][task]);
        }  
        }
        return dp[day][previdx]= maxi;
    }

    //if this problem has already been solved 
    if(dp[day][previdx]!=-1) return dp[day][previdx];

    int maxi=0;
    for(int task=0;task<3;task++){
        if(task!=previdx){
            int point=points[day][task] + f(day-1,task,dp,points);
            maxi=max(maxi,point);
        }  
        }
    return dp[day][previdx]=maxi;

} 

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n,vector<int> (4,-1));
    return f(n-1,3,dp,points);
}

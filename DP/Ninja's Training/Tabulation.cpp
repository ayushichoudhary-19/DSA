

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n,vector<int> (4,-1));

    // base case
    dp[0][0] = max(points[0][1],points[0][2]);
    dp[0][1] = max(points[0][0],points[0][2]);
    dp[0][2] = max(points[0][0],points[0][1]);
    dp[0][3] = max(points[0][0],max(points[0][1],points[0][2]));

    //bottom - up
    for(int day=1;day<n;day++){
        for(int previdx=0;previdx<4;previdx++){
        dp[day][previdx]=-1;   
        int maxi=0;
        for(int task=0;task<3;task++){
                    if (task != previdx) {
                      int point = points[day][task] + dp[day - 1][task];
                      maxi = max(maxi, point);
                    }
        }
        dp[day][previdx]=maxi;
        }
    }
    
    return dp[n-1][3];
}

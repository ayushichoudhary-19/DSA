class Solution {
private:
    int countPaths(int currentStep, vector<int> &dp){
        if(currentStep==0) return 1;
        if(currentStep<0) return 0;

        if(dp[currentStep]!=-1) return dp[currentStep];

        int singleJump = countPaths(currentStep-1,dp);
        int doubleJump = countPaths(currentStep-2,dp);

        return dp[currentStep] = singleJump + doubleJump;

    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return countPaths(n,dp);
    }
};
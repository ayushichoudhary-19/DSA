int f(int index, int k, vector<int> &dp, vector<int> &height) {
    if (index == 0) return 0;
    if (dp[index] != -1) return dp[index];

    int minValue = INT_MAX;
    for (int i = 1; i <= k && index - i >= 0; i++) {
        int currentCost = f(index - i, k, dp, height) + abs(height[index] - height[index - i]);
        if (currentCost < minValue) {
            minValue = currentCost;
        }
    }

    return dp[index] = minValue;
}

int minimizeCost(int n, int k, vector<int> &height) {
    vector<int> dp(n, -1);
    int ans = f(n-1, k, dp, height);
    return ans;
}

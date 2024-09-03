class Solution {
public:
    int maxArea(vector<int>& height) {
        int low = 0, high = height.size()-1;
        int maxA = 0;
        while(low < high){
            int area = (high-low) * min(height[low],height[high]);
            maxA = max(maxA,area);
            if(height[low] < height[high]){
                low++;
            }
            else high--;
        }
        return maxA;
    }
};
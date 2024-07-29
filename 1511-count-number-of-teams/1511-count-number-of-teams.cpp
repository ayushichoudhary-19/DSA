class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        if (n < 3) return 0;
        
        int count = 0;
        // Iterate over all possible middle elements of the team
        for (int j = 1; j < n - 1; ++j) {
            int left_smaller = 0, left_larger = 0, right_smaller = 0, right_larger = 0;
            
            // Count elements on the left of j
            for (int i = 0; i < j; ++i) {
                if (rating[i] < rating[j]) {
                    ++left_smaller;
                } else if (rating[i] > rating[j]) {
                    ++left_larger;
                }
            }
            
            // Count elements on the right of j
            for (int k = j + 1; k < n; ++k) {
                if (rating[k] < rating[j]) {
                    ++right_smaller;
                } else if (rating[k] > rating[j]) {
                    ++right_larger;
                }
            }
            
            // Calculate the number of valid teams with j as the middle element
            count += left_smaller * right_larger + left_larger * right_smaller;
        }
        
        return count;
    }
};

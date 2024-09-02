class Solution {
private:
    int binarySearchForLowerBound(vector<long long> &prefixSum, long long k){
        int low = 0, high = prefixSum.size()-1;

        while(low<high){
            int mid = (low)+ (high-low)/2;

            if(prefixSum[mid] <= k){
                low = mid + 1;
            }
            else high = mid;
        }
        return high;
    }
public:
    int chalkReplacer(vector<int>& chalk, int k) {
       
        int n = chalk.size();
        vector<long long> prefixSum(n,0);
        prefixSum[0] = chalk[0];
        for(int i=1; i<n; i++){
            prefixSum[i] = prefixSum[i-1] + chalk[i];
        }

        long long sum = prefixSum[n-1];
        

        //fine rounds where k lasts for all
        long long f = k/sum;

        //now whatever is left for that sum, we need to go over the chalk array
        long long kLeftAfterFineRounds = k%sum;

        return binarySearchForLowerBound(prefixSum,kLeftAfterFineRounds);
    }
};
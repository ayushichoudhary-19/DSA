class Solution {
public:
    int pivotInteger(int n) {
       vector<int> prefixSum(n,0);
       vector<int> suffixSum(n,0);
       prefixSum[0]=1;
       suffixSum[n-1]=n;
       for(int i=1;i<n;i++){
            prefixSum[i]=(i+1)+prefixSum[i-1];
            suffixSum[n-i-1]=(n-i)+suffixSum[n-i];
       } 
       for(int i=0;i<n;i++){
        if(prefixSum[i]==suffixSum[i]){
            return i+1;
        }
       }
       return -1;
    }
};
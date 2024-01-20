class Solution {
public:
    // int sumSubarrayMins(vector<int>& arr) {
    //     int n=arr.size();
    //     int sum=0;
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<n-i;j++){
    //             int curr_min=INT_MAX;
    //             for(int k=i;k<n-j;k++){
                   
    //                  curr_min=min(curr_min,arr[k]);
    //                }
    //         sum+=curr_min;
    //         }

    //     }
    // return sum;
    // }


    // int sumSubarrayMins(vector<int>& arr){
    //     stack<int> st;
    //     int sum=0;
    //     int mini=INT_MAX;
    //     for(int i=0;i<arr.size();i++){
    //         for(int j=i;j<arr.size();j++){
    //             mini=min(arr[j],mini);
    //             sum+=mini;
    //             }
    //             mini=INT_MAX;
    //         }
    //     return sum;
    // }

        void NSR(vector<int> &suffix,vector<int> arr,int n){
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()) suffix[i]=n;
            else suffix[i]=st.top();

            st.push(i);
        }
    }
    void NSL(vector<int> &prefix,vector<int> arr,int n){
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()) prefix[i]=-1;
            else prefix[i]=st.top();

            st.push(i);
        }        
    }
int sumSubarrayMins(vector<int>& arr){
    long long sum=0;
    int n=arr.size();
    vector<int> prefix(n,-1);
    vector<int> suffix(n,n);
    NSR(suffix,arr,n);
    NSL(prefix,arr,n);

    for(int i=0;i<n;i++){
        long long p=i-prefix[i];
        long long q=suffix[i]-i;
        long long currSum=p*q;
        currSum=arr[i]*currSum;
sum = (sum + currSum) % static_cast<long long>(1e9 + 7);

    }
    return sum;
}


};
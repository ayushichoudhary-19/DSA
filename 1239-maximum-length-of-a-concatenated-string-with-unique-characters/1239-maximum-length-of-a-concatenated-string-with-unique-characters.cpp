class Solution {
private:
    bool hasDuplicate(string &s1, string&s2){
        int arr[26]={0};
        //also check the case where: "aa", "bb" string itself has duplciates
        for(char &ch:s1){
            if(arr[ch-'a']>0){
                return true;
            }
            arr[ch-'a']++;
        }
        for(char &ch: s2){
            if(arr[ch-'a']>0)
                return true;
        }
        return false;
    }
    int solve(int i, vector<string> &arr, string temp, int n){
        if(i>=n) return temp.length();
        
        int include=0;
        int exclude=0;
        if(hasDuplicate(arr[i],temp)) //exclusion in the only option
            exclude = solve(i+1,arr,temp,n);
                
        else{
            exclude = solve(i+1, arr,temp,n);
            include = solve(i+1, arr, temp+arr[i],n);
        }
        return max(exclude,include);
    }
public:
    int maxLength(vector<string>& arr) {
     string temp=""; //no concatinaation
        
    int n=arr.size();
    int i=0;
    return solve(i,arr,temp,n);
    }
};
vector<int> superiorElements(vector<int>&a) {
    vector<int> ans;
    int n=a.size();
    int maxsmaller=a[n-1];
    ans.push_back(a[n-1]);

    for(int i=n-2;i>=0;i--){
        if(a[i]>maxsmaller){
            ans.push_back(a[i]);
            maxsmaller=a[i];
        }
    }
    return ans;
}
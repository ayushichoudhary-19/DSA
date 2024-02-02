int frogJump(int n, vector<int> &heights)
{
    int preprev=0, prev=0;

    for(int i=1;i<n;i++){
        int left = prev+ abs(heights[i-1]-heights[i]);
        int right=INT_MAX;
        if(i>1)
            right = preprev + abs(heights[i]-heights[i-2]);
        int curr=min(right,left);
        preprev=prev;
        prev=curr;
    }
    return prev;
}

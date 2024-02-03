
// GREEY FAILS
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // greedy
    int maxidx=-1,maxthatday=0, prevmax=-1;
    int sum=0;
    for(auto day:points){
        for(int act=0; act<points[0].size();act++){
            if(act!=prevmax && maxthatday<day[act] ){
                // cout<<act<<" = "<<maxidx<<endl;
                maxidx=act;
                maxthatday=day[act];
            }
            
        }
        // cout<<"max was found at"<<maxidx<<endl;
        // cout<<"max that day: "<<maxthatday<<endl;
        sum+=maxthatday;
        prevmax=maxidx;
        maxthatday=0;
    }
    return sum;
}

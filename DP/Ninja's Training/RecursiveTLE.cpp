int f(int day,int previdx,vector<vector<int>> &points){
    if(day==0){
        int maxi=0;
        for(int task=0;task<3;task++){
                if(task!=previdx){
                    maxi=max(maxi,points[day][task]);
        }  
        }
        return maxi;
    }

    int maxi=0;
    for(int task=0;task<3;task++){
        if(task!=previdx){
            int point=points[day][task] + f(day-1,task,points);
            maxi=max(maxi,point);
        }  
        }
    return maxi;

} 

int ninjaTraining(int n, vector<vector<int>> &points)
{

    return f(n-1,-1,points);
}

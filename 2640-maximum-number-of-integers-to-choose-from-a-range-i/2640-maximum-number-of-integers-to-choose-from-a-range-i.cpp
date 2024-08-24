class Solution {
private:
    bool numIsBanned(int num, set<int> &banned){
        if(banned.find(num)!=banned.end()) return true;
        else return false;
    }
    
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int num;
        int ans=0;

        set<int> st;

        for(int b:banned){
            if(b<=n) st.insert(b);
        }

        int sum=0;

        for(int num=1; num<=n; num++){
            if(!numIsBanned(num,st)){
                cout<<"taking "<<num<<endl;
                sum += num;
                if(sum>maxSum) break;
                ans++;
            }
            if(sum>maxSum) break;
        }
        return ans;
    }
};
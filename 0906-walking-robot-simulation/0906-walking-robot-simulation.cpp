class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<pair<int,int>> direction = {{0,1},{1,0},{0,-1},{-1,0}};
        long long x=0, y=0;
        long long d = 0, res = 0;

        set<pair<int,int>> st;
        for(auto& obs: obstacles){
            st.insert({obs[0],obs[1]});
        }

        for(auto& c: commands){
            if(c==-1){
                d = (d+1)%4; //+1 means we go clockwise in direction vector
            }
            else if(c==-2){
                d = (d+3)%4; // -1 means going anti clocwise and % 4 to ensure we do not go out of bounds of 4 as d is index that we will use for directions vector
            }
            else{
                int dx = direction[d].first;
                int dy = direction[d].second;
                //now go to c times one step at a time and stop before obs
                for(int i=0; i<c; i++){
                    
                    if(st.find({x+dx, y+dy}) != st.end()){break;}
                    x = x + dx;
                    y = y + dy;
                
                }

                res = max(res, x*x + y*y);
            }
        }
        return res;
    }
};
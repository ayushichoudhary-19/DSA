//BRUTEFORCE
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    bool found=false;
    int ans=-1;
    
    int celebrity(vector<vector<int>> &M, int n) 
    {
        stack<int> st;
        for(int j=0;j<n;j++){
            for(int i=0;i<n;i++){
                if(M[i][j]==1 && M[j][i]==0)
                    st.push(M[i][j]);
                if(i!=j && M[i][j]==0){
                    break;
                }
                
            }
            
            if(st.size()==n-1)
             {  if(!found)
                {ans=j;
                found=true;}
                else{
                    ans=-1;
                }
                
             }

            //empty stack
            while(!st.empty()){
                st.pop();
            }
            
            }
         return ans;
        
    }
};


//OPTIMAL O(N)
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> st;
        int celeb;
        for(int i=0;i<n;i++){
            st.push(i);
        }
        
        while(st.size()>1){
            int i=st.top();
            st.pop();
            int j=st.top();
            st.pop();
            //i knows j then i can't be a celebrity
            if(M[i][j]){
                //then j may be a celebrity so push it back to stack
                st.push(j);
            }
             //j knows i then j can't be a celebrity
            if(M[j][i]){
                //then i may be a celebrity so push it back to stack
                st.push(i);
            }
        }
        //when only one element is left in stack, verify it is actually a celebrity
        celeb=st.top();
        
        for(int i=0;i<n;i++){
            //to check everyone knows celeb except celeb
            if(i==celeb){contiue;}
            if (i!=celeb && M[i][celeb]){
                continue;
            }
            else{
                //if there is someone who does not know celeb then it's not a celeb
                return -1;
            }
        }

        for(int i=0;i<n;i++){
            //to check celeb knows no one 
            if(M[celeb][i]) return -1;
        } 
        
        return celeb;
        
    }
};

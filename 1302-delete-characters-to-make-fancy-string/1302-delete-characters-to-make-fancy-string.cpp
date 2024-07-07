class Solution {
public:
    string makeFancyString(string s) {
    string ans;
    for(auto ch:s){
    //add first 2 chars always 
    if(ans.length()<2) ans+=ch;

    //this is a fresh char
    else if(ans.length()>0 && ans[ans.length()-1]!=ch){
        ans+=ch;
    }
    //this is second repearation
    else if(ans.length()>=2 && ans[ans.length()-1]==ch && ans[ans.length()-2]!=ch)   {
        ans+=ch;
    }
    
    //if this is third repeatition ignore it
    }
    return ans;
    }
};
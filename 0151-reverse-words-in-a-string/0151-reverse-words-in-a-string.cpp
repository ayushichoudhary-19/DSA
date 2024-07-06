class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string word;
        for(auto ch:s){
            if(word==" ") word="";
            if(ch==' ' && word.length()>0) {
                st.push(word);
                word="";
            }
            else word+=ch;
        }
        if(word.length()>0 && word!=" ") {
                st.push(word);
        }
        string ans;
        while(st.size()>1){
            ans+=st.top()+' ';
            st.pop();
        }
        //last word
        ans+=st.top();
        return ans;
    }
};
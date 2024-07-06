class Solution {
public:
    string reverseWords(string s) {
        vector<string> sen;
        string word;
        for(int ch=0; ch<s.length(); ch++){
            if(s[ch]==' '){
                if(word.length()>0) sen.push_back(word);
                word="";}
            else word+=s[ch];
        }
        
        if(word.length()>0) sen.push_back(word);
        for(auto word:sen){
            cout<<"\""<<word<<"\""<<" ";
        }

        string ans;
        int senLen=sen.size();
        for(int word=senLen-1; word>0; word--){
            ans+=sen[word]+' ';
        }
        ans+=sen[0];
        return ans;
    }
};
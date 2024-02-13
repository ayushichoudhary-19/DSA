class Solution {
private:
    bool ispalindrome(string word){
        int i=0,j=word.length()-1;
        while(i<j){
            if(word[i]==word[j]){
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }
public:
    string firstPalindrome(vector<string>& words) {
        for(auto word:words){
            if(ispalindrome(word)) return word;
        }
        return "";
    }
};
class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1;
        vector<int> v2;

        version1+='.';
        version2+='.';

        int n1=version1.length();
        int n2=version2.length();

        string val;
        for(int i=0; i<n1; i++){
            char ch=version1[i];
            if(ch=='.'){
                if(val.length()>0){
                    int value = stoi(val);
                    v1.push_back(value);
                }
                val="";
            }
            else{
                val+=ch;
            }
        }
        val="";

        for(int i=0; i<n2; i++){
            char ch=version2[i];
            if(ch=='.'){
                if(val.length()>0){
                    int value = stoi(val);
                    v2.push_back(value);
                }
                val="";
            }
            else{
                val+=ch;
            }
        }

        while(v1.size()<v2.size()){
            v1.push_back(0);
        }
        while(v2.size()<v1.size()){
            v2.push_back(0);
        }

        for(int i=0; i<v1.size();i++){
            if(v1[i]<v2[i]) return -1;
            if(v1[i]>v2[i]) return 1;
        }


        
        return 0;
    }
};
class Solution {
public:
    int findF(string qr){
        int ans=0;
        sort(qr.begin(), qr.end());

        for(char q:qr){
            if(q!=qr[0]) break;
            ans++;
        }
        return ans;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int n=queries.size(), m=words.size();
        vector<int> vec1(n), vec2(m);

        int idx=0;
        for(string qr: queries){
            vec1[idx] = findF(qr);
            idx++;
        }
        idx=0;
        for(string word: words){
            vec2[idx] = findF(word);
            idx++;
        }
        int cnt;
        vector<int> ans;
        for(int q:vec1){
            cnt=0;
            for(int w:vec2){
                if(q<w) cnt++;
            }
            ans.push_back(cnt); 
        }
        return ans;
    }
};
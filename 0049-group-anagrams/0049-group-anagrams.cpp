class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> anagmap;

        for(auto& st: strs){
            string sortedst = st;
            sort(sortedst.begin(), sortedst.end());
            anagmap[sortedst].push_back(st);
        }

        vector<vector<string>> ans;
        for(auto& pair: anagmap){
            vector<string> anags = pair.second;

            ans.push_back(anags);
        }
        return ans;
    }
};
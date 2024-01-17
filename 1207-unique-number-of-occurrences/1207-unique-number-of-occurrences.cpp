class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m;
        for(auto num:arr) m[num]++;

        set<int> s;
        for(auto it=m.begin();it!=m.end();it++){
            s.insert(it->second);
        }
        return s.size()==m.size();
    }
};
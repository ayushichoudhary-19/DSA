class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n1=target.size(), n2=arr.size();
        if(n1!=n2) return false;

        unordered_map<int,int> map;
        for(int i=0; i<n2; i++){
            map[arr[i]]++;
        }

        for(int i=0; i<n1; i++){
            if(map.find(target[i])==map.end()) return false;
            map[target[i]]--;
            if(map[target[i]]==0) map.erase(target[i]);
        }
        return true;
    }
};
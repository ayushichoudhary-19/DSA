class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less;
        vector<int> more;
        vector<int> pivotelem;
        for(auto num:nums){
            if(num<pivot) {
                less.push_back(num);
                cout<<num;}
            else if(num>pivot) more.push_back(num);
            else pivotelem.push_back(num);
        }
        less.insert(less.end(), pivotelem.begin(), pivotelem.end());
        less.insert(less.end(),more.begin(),more.end());

        return less;
    }
};
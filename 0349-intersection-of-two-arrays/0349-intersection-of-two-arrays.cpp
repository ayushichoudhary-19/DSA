class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
       sort(nums1.begin(),nums1.end()); 
        sort(nums2.begin(),nums2.end());
        vector<int> intersection;
        int i=0,j=0;
        int n1=nums1.size(),n2=nums2.size();
        while(i<n1 && j<n2){
            if(nums1[i]==nums2[j]){
                if(intersection.size()==0){
                    intersection.push_back(nums1[i]);
                }
                else if(intersection.back()!=nums1[i]){
                    intersection.push_back(nums1[i]);
                }
                i++;j++;
            }
            else if(nums1[i]<nums2[j]) i++;
            else j++;
        }
        
        return intersection;
    }
};
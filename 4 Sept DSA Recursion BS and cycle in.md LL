# Binary Search Using Recursion
```
int binarySearch(vector<int> nums,int target,int s,int e){
    int mid=s+(e-s)/2;
    if(nums.size()==0){
        return -1;
    }
    if(s>e){
        return -1;
    }
    else if(nums[mid]==target){
        return mid;
    }
    else if(nums[mid]>target){
        return binarySearch(nums,target,s,mid-1);
    }
    else{
        return binarySearch(nums,target,mid+1,e);
    }
}
int search(vector<int> &nums, int target) {
    int s=0,e=nums.size()-1;
    return binarySearch( nums, target,  s, e);
}
```

# DETECT CYCLE IN A LL
Optimized Approach
```


# Code
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        struct ListNode* p=head,*q=head;
        if(head==NULL || head->next==NULL){
            return false;
        }
        else{
            while(q!=NULL  && q->next!=NULL){
                
                    p=p->next;
                    q=q->next->next;
                    if(p==q){return true;}
                
            }
        }
        return false;
    }

};
```

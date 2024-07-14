/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if(nums.size()==0) return head;
        set<int> s;
        for(int n:nums){
            s.insert(n);
        }

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* prev=dummy;
        ListNode* curr=head;

        while(curr!=nullptr){
            if(s.find(curr->val)!=s.end()){
                prev->next = curr->next;
                curr=curr->next;
            }
            else{
                curr=curr->next;
                prev=prev->next;
            }
        }
        
        return dummy->next;
    }
};
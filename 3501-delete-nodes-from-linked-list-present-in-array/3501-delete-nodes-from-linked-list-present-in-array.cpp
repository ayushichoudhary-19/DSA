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
        unordered_set<int> st;

        for(auto& num:nums){
            st.insert(num);
        }

        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;

        ListNode *temp=head, *prev=dummy;

        while(temp != nullptr){
            if(st.find(temp->val) != st.end()){
                //delete this node
                prev -> next = temp -> next;
            }
            else prev = temp;
            temp = temp->next;
        }
        return dummy->next;
    }
};
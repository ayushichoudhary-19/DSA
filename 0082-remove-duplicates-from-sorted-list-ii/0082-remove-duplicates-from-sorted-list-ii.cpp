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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int,int> m;
        ListNode *pointer = head;
        
        while(pointer != nullptr){
            m[pointer->val]++;
            pointer = pointer -> next;
        }

        ListNode* dummy = new ListNode(0);
        ListNode* newlist = dummy;

        for(auto &it: m){
            if(it.second == 1){
                newlist->next = new ListNode(it.first);
                newlist = newlist -> next;
            }
        }
        return dummy->next;
    }
};
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummyLess = new ListNode(-1);
        ListNode* dummyMore = new ListNode(-1);
        ListNode* temp=head, *more=dummyMore, *less=dummyLess;
    
        while(temp!=nullptr){
            if(temp->val<x){
                less->next=temp;
                less=less->next;
            }
            else{
                more->next=temp;
                more=more->next;
            }
            temp=temp->next;
        }
        less->next=dummyMore->next;
        more->next=nullptr;
        return dummyLess->next;
    }
};
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
private: 
    int findgcd(int a, int b){
        if(a==0) return b;
        if(b==0) return a;

        if(a>b) return findgcd(a-b,b);
        else return findgcd(a,b-a);
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next==NULL) return head;

        ListNode* curr = head->next, *prev = head;

        while(curr!=nullptr){
            int gcd = findgcd(curr->val, prev->val);
            ListNode* node = new ListNode(gcd);
            prev->next = node;
            node->next = curr;
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};
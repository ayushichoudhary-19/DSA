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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        dummy->next = list1;

        ListNode *aTemp=dummy, *bTemp;
        for(int i=0;i<a;i++){
            aTemp=aTemp->next;
        }
        bTemp=aTemp;
        for(int j=a;j<=b;j++){
           bTemp=bTemp->next; 
        } 

        aTemp->next=list2;
        ListNode* list2Temp=list2;
        while(list2Temp->next!=nullptr){
            list2Temp=list2Temp->next;
        }
        list2Temp->next=bTemp->next;

        return dummy->next;
        
    }
};
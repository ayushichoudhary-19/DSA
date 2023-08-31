# Convert Binary Number in a Linked List to Integer 
**Leetcode:** https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/

# BruteForce
**My Intution: ** was to calculate how many total nodes are there. Once I know the nuber of nodes, I can use the formula of converting binary to decimal/int by multiplying the node value/data with 2 ki power the number of node from left. As power starts from 0 till n-1 from right end but we can only traverse a LL from left so I use a reverse for loop and decrement value of 2 ki power from n-1 till 0 and add the values to ans and return the final answer.**
**TC:** O(N)
**SC:** O(1)

```
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
    int getDecimalValue(ListNode* head) {
        int ans=0;
        int n=0;
        struct ListNode *p=new ListNode;
        p=head;
        if(p->next==NULL){
            return p->val;
        }
        //to check number of elements in LL
        while(p!=NULL){
            n++;
            p=p->next;
        }
        p=head;
        for(int i=n-1;i>=0;i--){
            ans+= p->val*(pow(2,i));
            p=p->next;
        }
        return ans;
    }
};
```

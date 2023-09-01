# delete-node-in-a-linked-list

Leetcode:https://leetcode.com/problems/delete-node-in-a-linked-list/

I got this problem from A2Z's DSA sheet. 

# Intuition

In this problem we are simply needed to remove a node from linked list. We do not have to actually 'delete' it from memory, but only remove the node from linked list.


# Approach
Since, head is not given, we can't traverse and reach upto the given node, but that is not actually needed too. We only need to remove the node from linkedin list, which means get rid of the value it hold on the linked list. 

E.g: 
[1]->[2]->[3]->[4]->[5]
If we call void deleteNode(ListNode* node), with parameter node pointing to [3],
Output should be [1]->[2]->[4]->[5].
This can be done by moving the value after `node` to shift one step back.
E.g.: Since, everything before node remains same so we do not need head. We directly go to the location that node is pointing. In this case node is pointing to 3.
[1]->[2]->**[3]**->[4]->[5].
So, to remove 3, we shift 4 to 3's position: 
`node->val=node->next->val;`
[1]->[2]->**[4]**->[4]->[5].
Now, since now 4 is repeating, we can discard the second 4 that is repeating by making the node's next point to next 4's next.

`node->next=node->next->next;`
[1]->[2]->[4]->[5].



# Complexity
- Time complexity:
O(1)

- Space complexity:
O(1)

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
    void deleteNode(ListNode* node) {
        node->val=node->next->val;
        node->next=node->next->next;
    }
};
```

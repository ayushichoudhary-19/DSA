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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    //If there are less than three points return [-1,-1];
    if(head->next==nullptr || head->next->next==nullptr) return {-1,-1};

    vector<int> criticalPoints;

    ListNode *p=head, *q=head->next, *r=head->next->next;
    int nodeNo=1;
    while(r!=nullptr){
        nodeNo++;
        if((p->val< q->val && q->val>r->val) || (p->val > q->val && q->val<r->val))
        criticalPoints.push_back(nodeNo);

        p=p->next;
        q=q->next;
        r=r->next;
    }
    if(criticalPoints.size()<2) return {-1,-1};

    int cps=criticalPoints.size();
    int minDist=INT_MAX;
    for(int i=1; i<cps; i++){
        minDist=min(minDist,criticalPoints[i]-criticalPoints[i-1]);
    }
    return {minDist,criticalPoints[cps-1]-criticalPoints[0]};
    }
};
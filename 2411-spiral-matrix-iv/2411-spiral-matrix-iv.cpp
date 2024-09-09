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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n,-1));

        ListNode* curr = head;
        int top=0, bottom=m-1, left=0, right = n-1;

        while(top <= bottom){
            int i=top, j=left;
            while(j<=right){
                if(curr==nullptr) return matrix;
                matrix[i][j] = curr->val;
                curr=curr->next;
                j++;
            }
            j--;
            right--;
            i++;
            while(i<=bottom){
                if(curr==nullptr) return matrix;
                matrix[i][j] = curr->val;
                curr=curr->next;
                i++;
            }
            i--;
            bottom--;
            j--;

            while(j>=left){
                if(curr==nullptr) return matrix;
                matrix[i][j] = curr->val;
                curr=curr->next;
                j--;
            }
            left++;
            j++;
            i--;

            while(i>top){
                if(curr==nullptr) return matrix;
                matrix[i][j] = curr->val;
                curr=curr->next;
                i--;
            }
            top++;
        }
        return matrix;
    }
};


# Complexity
- Time complexity:
Best Case: O(h)/O(logN)
Worst Case: O(N) 
in worst case height can be: N

![image.png](https://assets.leetcode.com/users/images/7690be68-d114-47c4-92c5-8d018f422eb1_1705394327.9298909.png)

- Space complexity:
O(1)
# Code
```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* head=root;
        //create a new node with value val for insetion
        TreeNode* newNode=new TreeNode(val);
        if (root==nullptr) return newNode;
        while(true){
            if(root->val>val){
                //if root is > new root then we need to move to the left to put it in
                if(root->left)
                    root=root->left;
                else{ root->left=newNode;
                return head;}
            }
            else if(root->val<val){
                if(root->right)
                    root=root->right;
                else
                { root->right=newNode;
                return head;}
            }
        }
        return head;
    }
};
```

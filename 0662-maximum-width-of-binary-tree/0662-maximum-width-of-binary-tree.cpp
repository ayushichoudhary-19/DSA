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
    int widthOfBinaryTree(TreeNode* root) {
        // we use level order traversal to assign levels and calculating width
        int maxwidth=INT_MIN;
        queue<pair<TreeNode*,int>> q;
            //<node,index>
        q.push({root,1});
        int leftmost,rightmost;
        //level order traversal
        while(!q.empty()){
            int levels=q.size();
            int currmin=q.front().second;
            for(int i=0;i<levels;i++){
                root=q.front().first;
                //index needs to be long long because in case of single node in each level and total nodes 5*10^5 something, the index values can go out of bound of integers.
                long long index=q.front().second-currmin; //currmin is subtracted to avoid integer overflow
                q.pop();
                if(i==0) leftmost=index; //i=0 is leftmost node of current level
                if(i==levels-1) rightmost=index;
                if(root->left)q.push({root->left,(2*index)});  //lets take 1 based indexing then LC=2*i and RC=2*i+1
                if(root->right)
                q.push({root->right,(2*index+1)});
                
                maxwidth=max(maxwidth,rightmost-leftmost+1);
            }
        }
        return maxwidth;
    }
};
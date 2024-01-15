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
private:
    TreeNode* buildTrees(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int,int> &inorderLoc){
        //means if there is nothing for preorder of that node, or nothing for inorder of that node then
        //return from that node
        if(preStart>preEnd || inStart>inEnd) return nullptr;
        
        //as the start of current preorder is always the root
        TreeNode* root=new TreeNode(preorder[preStart]);
        
        //now for this root we have to find it's left nodes and right nodes which will be obtained
        //from inorder traversal 
        //eg. inorder: 1,2,{3},4,6  for root 3 left ones are 1,2 and right subtree has 4,6
        //from inorder we will find index of this root from the map
        int rootLocInInorder=inorderLoc[root->val];
        int nodesOnLeft=rootLocInInorder-inStart; 
                    //1,2 are nodes so 2 nodes (rootLocInInorder is 2 and inorderstarts at 0; 2-0=2)
        
        root->left=buildTrees(preorder,preStart+1,preStart+nodesOnLeft,inorder,inStart,rootLocInInorder-1,inorderLoc);
        root->right=buildTrees(preorder,preStart+nodesOnLeft+1,preEnd,inorder,rootLocInInorder+1,inEnd, inorderLoc);
        
        return root;
        
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> inorderLoc; //this map stores the index of rach node of inorder
        
        for(int i=0;i<inorder.size();i++) 
            {inorderLoc[inorder[i]]=i;}
        
        TreeNode* root=buildTrees(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inorderLoc);
        return root;
            
    }
};
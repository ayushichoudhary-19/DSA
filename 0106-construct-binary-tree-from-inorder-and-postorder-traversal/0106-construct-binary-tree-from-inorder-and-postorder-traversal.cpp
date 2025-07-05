class Solution {
private:
    TreeNode* getTree(vector<int>& postorder, int postStart, int postEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int,int> &inMap){
        if(postStart < postEnd || inStart > inEnd) return NULL;
        
        TreeNode* root = new TreeNode(postorder[postStart]);

        int inRoot = inMap[root->val];
        int numsRight = inEnd - inRoot;

        root->right = getTree(postorder, postStart - 1, postStart - numsRight, inorder, inRoot+1, inEnd, inMap);

        root->left = getTree(postorder, postStart - numsRight - 1, postEnd,
        inorder, inStart, inRoot - 1, inMap);
        
        return root;
        
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>&  postorder) {
        unordered_map<int,int> inMap;
        for(int idx=0; idx<inorder.size(); idx++){
            inMap[inorder[idx]] = idx;
        }
        TreeNode* root = getTree(postorder, postorder.size() - 1,0, inorder, 0, inorder.size()-1, inMap);
        return root;
    }
};
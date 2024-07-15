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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        if(descriptions.size()==0) return nullptr;


        unordered_map<int,TreeNode*> map;
        set<int> nonroot;

        for(auto desc: descriptions){
            int parent = desc[0];
            int child = desc[1];
            int isLeft = desc[2];

            nonroot.insert(child);

            if(map.find(parent)==map.end()){
                TreeNode* pNode = new TreeNode(parent);
                map[parent] = pNode;
            }

            if(map.find(child)==map.end()){
                TreeNode* chNode = new TreeNode(child);
                map[child] = chNode;
            }
            if(isLeft) map[parent] -> left = map[child];
            else  map[parent]->right = map[child];  
        }
        
        for(auto it=map.begin(); it!=map.end(); it++){
            int node = it->first;
            if(nonroot.find(node)==nonroot.end()) return map[it->first];
        }
        return nullptr;
    }
};
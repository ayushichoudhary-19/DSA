/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if(root==nullptr) return root;
        q.push(root);
        vector<vector<Node*>> levels;
        while(!q.empty()){
            vector<Node*> level;
            int size = q.size();
            for(int i=0; i<size; i++){
                Node* node = q.front();
                q.pop();
                level.push_back(node);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            levels.push_back(level);
        }
        for(auto lev: levels){
            for(int i=0; i<lev.size(); i++){
                if(i != lev.size()-1){
                    lev[i]->next = lev[i+1];
                }
                else{
                    lev[i]->next = nullptr;
                }
            }
        }
        return root;
    }
};
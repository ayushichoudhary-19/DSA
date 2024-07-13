class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "";

        string s;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node == NULL){
                s += "N,";
            } else {
                s += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length() == 0) return NULL;
        
        stringstream s(data);
        string num;
        
        getline(s, num, ',');
        TreeNode *root = new TreeNode(stoi(num));
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            
            getline(s, num, ',');
            if(num != "N"){
                TreeNode *leftNode = new TreeNode(stoi(num));
                node->left = leftNode;
                q.push(leftNode);
            }
            
            getline(s, num, ',');
            if(num != "N"){
                TreeNode *rightNode = new TreeNode(stoi(num));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

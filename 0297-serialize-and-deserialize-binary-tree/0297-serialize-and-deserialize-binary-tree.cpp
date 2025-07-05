class Codec {
private:
    void solve(TreeNode* root, string &ans){
        if(!root){
            ans += "N,";
            return;
        }

        ans += to_string(root->val) + ",";
        solve(root->left, ans);
        solve(root->right, ans);
    }

    TreeNode* build(vector<string>& nodes, int& idx){
        if(idx >= nodes.size()) return nullptr;
        if(nodes[idx] == "N"){
            idx++;
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(nodes[idx]));
        idx++;
        node->left = build(nodes, idx);
        node->right = build(nodes, idx);
        return node;
    }

public:
    string serialize(TreeNode* root) {
        string ans;
        solve(root, ans);
        return ans;
    }

    TreeNode* deserialize(string data) {
        vector<string> nodes;
        string temp;

        for(char c : data){
            if(c == ','){
                nodes.push_back(temp);
                temp.clear();
            } else {
                temp += c;
            }
        }
        int idx = 0; //to track curr node val in array
        return build(nodes, idx);
    }
};

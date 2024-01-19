//Brute:

/*************************************************************

    Following is the Binary Tree node structure:

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/
void inorder(TreeNode *root,vector<int> &in){
    if(root==NULL) return;

    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}
vector<int> mergeArrays(vector<int>bst1,vector<int>bst2){
    vector<int> ans;
    int i=0,j=0;
    while(i<bst1.size() && j<bst2.size()){
        if(bst1[i]<bst2[j]){
            ans.push_back(bst1[i]);
            i++;
        }
        else{
            ans.push_back(bst2[j]);
            j++;
        }
    }
    //if bst2 is fully inserted and bst1 is left
    while(i<bst1.size()){
        ans.push_back(bst1[i]); i++;
    }
    //if bst1 is fully added and bst2 is left
    while(j<bst2.size()){
        ans.push_back(bst2[j]); j++;
    }
    return ans;
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    vector<int> bst1,bst2;
    inorder(root1,bst1);
    inorder(root2,bst2);
    //merge both inorders bst1 and bst2
    //using merge two sorted arrays
    vector<int> mergedarray=mergeArrays(bst1,bst2);
    return mergedarray;
}

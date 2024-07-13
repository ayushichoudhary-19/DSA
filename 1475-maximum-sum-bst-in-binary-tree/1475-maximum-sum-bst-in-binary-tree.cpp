
class Solution {
    int answer=INT_MIN;
    vector<int> solve (TreeNode* node){
         //{0,1,2}->represents min,max,sum;
         if(node==NULL){
              return {INT_MAX,INT_MIN,0};
          } 
         vector< int> leftsolve=solve(node->left);
         vector< int> rightsolve=solve(node->right);

         
         if(leftsolve[1]>=node->val|| rightsolve[0]<=node->val)
         {
             return {INT_MIN,INT_MAX,0};
         }
        int res=leftsolve[2]+rightsolve[2]+node->val;
        answer=max(answer,res);

        return {min(node->val,leftsolve[0]),max(rightsolve[1],node->val),res};

    }
public:
    int maxSumBST(TreeNode* root) {
         vector<int>ans=solve(root);
        if(answer<0) return 0;
        return answer;
    }
};
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int top = 0, left = 0, right = n-1, bottom = n-1;
        vector<vector<int>> matrix(n, vector<int>(n,0));
        int cnt = 0;
        while(top<=bottom){
            int i=top, j=left;
            while(j<=right){
                if(cnt==n*n) return matrix;
                cnt++;
                matrix[i][j] = cnt;
                j++;
            }
            right--;
            j--;
            i++;

            while(i<=bottom){
                if(cnt==n*n) return matrix;
                cnt++;
                matrix[i][j] = cnt;
                i++;
            }
            bottom--;
            i--;
            j--;

            while(j>=left){
                if(cnt==n*n) return matrix;
                cnt++;
                matrix[i][j] = cnt;
                j--;
            }
            left++;
            i--;
            j++;

            while(i>top){
                if(cnt==n*n) return matrix;
                cnt++;
                matrix[i][j] = cnt;
                i--;
            }
            top++;
        }
        return matrix;
    }
};
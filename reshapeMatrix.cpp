class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(),n = mat[0].size();
        vector<vector<int>> res(r,vector<int> (c));
        int a=0,b=0;
        if(r*c == m*n){
            for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(b<c){
                    res[a][b] = mat[i][j];
                    b++;
                    if(b==c){
                        b=0;
                        a++;
                    }
                }
                else{
                    res[a][b] = mat[i][j];
                    a++;
                }
            }
        }
        return res;
        }
        else{
            return mat;
        }
        
    }
};
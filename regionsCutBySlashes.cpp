class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& mat,vector<vector<bool>>& visited){
        visited[i][j] = true;
        int n = mat.size();
        vector<pair<int,int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};

        for(auto dir:dirs){
            int row = i+dir.first;
            int col = j+dir.second;

            if(row>=0 && row<n && col>=0 && col<n && mat[row][col]==0 && !visited[row][col]){
                dfs(row,col,mat,visited);
            }
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();

        vector<vector<int>> mat(n*3,vector<int>(n*3,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '/'){
                    mat[i*3][j*3+2] = 1;
                    mat[i*3+1][j*3+1] = 1;
                    mat[i*3+2][j*3] = 1;
                }else if(grid[i][j]=='\\'){
                    mat[i*3][j*3] = 1;
                    mat[i*3+1][j*3+1] = 1;
                    mat[i*3+2][j*3+2] = 1;
                }
            }
        }

        int count = 0;
        vector<vector<bool>> visited(n*3,vector<bool>(n*3,false));
        for(int i=0;i<n*3;i++){
            for(int j=0;j<n*3;j++){
                if(mat[i][j]==0 && !visited[i][j]){
                    count++;
                    dfs(i,j,mat,visited);
                }
            }
        }

        return count;
    }
};
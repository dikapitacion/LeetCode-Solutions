class Solution {
public:
    void dfs(pair<int,int> node,vector<vector<bool>>& visited,vector<vector<char>> &grid){
        int i = node.first,j=node.second;
        int n = grid.size(),m=grid[0].size();
        visited[i][j] = true;
        if(i+1<n){
            if(!visited[i+1][j] && grid[i+1][j] == '1'){
                dfs({i+1,j},visited,grid);
            }   
        }

        if(i-1>=0 && !visited[i-1][j] && grid[i-1][j]=='1'){
            dfs({i-1,j},visited,grid);
        }

        if(j+1<m && !visited[i][j+1] && grid[i][j+1] == '1'){
            dfs({i,j+1},visited,grid);
        }
        if(j-1>=0 && !visited[i][j-1] && grid[i][j-1] == '1'){
            dfs({i,j-1},visited,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    ans++;
                    dfs({i,j},visited,grid);
                }
            }
        }

        return ans;


    }
};
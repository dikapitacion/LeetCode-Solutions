class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        vector<pair<int,int>> oranges;
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                    visited[i][j] = true;
                    
                }
                if(grid[i][j] == 1){
                    oranges.push_back({i,j});
                }
            }
        }
        int ans = 0;
        while(!q.empty()){
            int nu = q.size();
            bool apple = false;
            while(nu>0){
                pair<int,int> front = q.front(); 
                int i=front.first,j=front.second;
                q.pop();
                if(i-1>=0){
                    if(grid[i-1][j]==1 && !visited[i-1][j]){
                        q.push({i-1,j});
                        visited[i-1][j] = true;
                        apple = true;
                    }
                }
                if(i+1<n){
                    if(grid[i+1][j]==1 && !visited[i+1][j]){
                        q.push({i+1,j});
                        visited[i+1][j] = true;
                        apple = true;
                    }
                }

                if(j-1>=0){
                    if(grid[i][j-1]==1 && !visited[i][j-1]){
                        q.push({i,j-1});
                        visited[i][j-1] = true;
                        apple = true;
                    }
                }

                if(j+1<m){
                    if(grid[i][j+1]==1 && !visited[i][j+1]){
                        q.push({i,j+1});
                        visited[i][j+1] = true;
                        apple = true;
                    }
                }
                
                nu--;
            }

            if(apple){
                ans++;
            }
            
        }
        for(auto it:oranges){
            if(!visited[it.first][it.second]){
                return -1;
            }
        }
        return ans;

    }
};
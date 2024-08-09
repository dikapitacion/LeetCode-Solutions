class Solution {
public:
    int ans;
    void solve(int row,int col,vector<vector<int>>& grid){
        vector<int> rSum(3,0);
        vector<int> cSum(3,0);
        vector<int> dSum(3,0);
        bitset<10> visited;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int temp = grid[row+i][col+j];
                rSum[i] += temp;
                cSum[j] += temp;
                if(temp<=9 && temp>0){
                    visited.flip(temp);
                }
                else{
                    return;
                }
            }
        }

        if(visited.count()!=9) return;

        int diag1 = grid[row][col] + grid[row+1][col+1] + grid[row+2][col+2];
        if(diag1 != grid[row][col+2] + grid[row+1][col+1] + grid[row+2][col]) return;

        for(int i=1;i<3;i++){
            if(rSum[i]!=rSum[i-1] || rSum[i]!=cSum[i] || cSum[i]!=cSum[i-1]) return;
        }

        ans++;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if(n<3 || m<3) return 0;

        for(int i=0;i<=n-3;i++){
            for(int j=0;j<=m-3;j++){
                solve(i,j,grid);
            }
        }

        return ans;
    }
};
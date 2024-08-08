class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int inc = 0;
        vector<vector<int>> res;
        int rCur = rStart, cCur = cStart;
        vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        res.push_back({rStart,cStart});
        int d = 0;


        while(res.size()!=rows*cols){
            if(d==0 || d==2) inc++;

            for(int i=0;i<inc;i++){
                rStart += dirs[d][0];
                cStart += dirs[d][1];

                if(rStart>=0 && rStart<rows && cStart>=0 && cStart<cols){
                    res.push_back({rStart,cStart});
                }
            }

            d = (d+1)%4;
        }
        return res;
    }
};
class Solution {
    public boolean isValidSudoku(char[][] board) {
        int[][] rv = new int[9][9];
        int[][] cv = new int[9][9];
        int[] res;
        // for(int i=0;i<9;i++){
        //     for(int j=0;j<9;j++){
        //         rv[i][j] = 0;
        //         cv[i][j] = 0;

        //     }
        // }
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    int val = Character.getNumericValue(board[i][j]);
                    rv[i][val-1]++;
                    cv[j][val-1]++;
                    if(rv[i][val-1]>1 || cv[j][val-1]>1){
                        return false;
                    }
                }
            }
        }
        for(int i = 0;i < 3;i++){
            for(int j = 0;j < 3;j++){
                res = new int[9];
                for(int p = 3*i;p < 3*i+3;p++){
                    for(int q = 3*j;q < 3*j+3;q++){
                        if(board[p][q] == '.'){
                            continue;
                        }

                        res[board[p][q]-'1']++;

                        if(res[board[p][q]-'1'] > 1){
                            return false;
                        }

                    }
                }
            }
        }

        return true;
    }
}
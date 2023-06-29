class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length-1;
        int n = matrix[0].length-1;
        
        boolean ans = false;
        int rlo = 0;
        int rhi = m;
        while(rlo<=rhi){
            int mid = (rlo+rhi)/2;
            if(target==matrix[mid][0]){
                return true;
            }
            else if(target>matrix[mid][0]){
                if(target>matrix[mid][n]){
                    rlo = mid+1;
                }
                else if(target == matrix[mid][n]){
                    return true;
                }
                else{
                    for(int i = 1;i<n;i++){
                        if(target==matrix[mid][i]){
                            return true;
                        }
                    }
                    return false;
                }
            }
            else{
                rhi = mid-1;
            }
        }
        return false;
    }
}
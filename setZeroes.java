class Solution {
    public void setZeroes(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        ArrayList<Integer> mo = new ArrayList<>();
        ArrayList<Integer> no = new ArrayList<>();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    mo.add(i);
                    no.add(j);
                }
            }
        }
        for(int i=0;i<m;i++){
            if(mo.contains(i)){
                Arrays.fill(matrix[i],0);
            }
            for(int j=0;j<n;j++){
                if(no.contains(j)){
                    matrix[i][j] = 0;
                }
            }
        }
    }
}
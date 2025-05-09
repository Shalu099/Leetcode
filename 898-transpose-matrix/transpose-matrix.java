class Solution {
    public int[][] transpose(int[][] matrix) {
                int m=matrix.length;
        int n=matrix[0].length;
        int reverse[][]=new int [n][m];

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                reverse[j][i]=matrix[i][j];
            }
        }
        return reverse;
    
    }
}
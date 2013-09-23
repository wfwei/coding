public void setZeroes(int[][] matrix) {
    // Start typing your Java solution below
    // DO NOT write main() function
    if(matrix==null)
        return;
    int r=-1, c=-1;
    int rowcnt=matrix.length, colcnt=matrix[0].length;
    // found first zero
    for(int i=0; i<rowcnt && r==-1; i++){
        for(int j=0; j<colcnt; j++){
            if(matrix[i][j]==0){
                r=i;c=j;
                break;
            }
        }
    }
    // not found
    if(r==-1)
        return ;
    // collect information
    for(int i=r+1; i<rowcnt; i++){
        for(int j=0; j<colcnt; j++){
            if(matrix[i][j]==0){
                matrix[r][j]=0;
                matrix[i][c]=0;
            }
        }
    }
    // set value
    for(int i=0; i<rowcnt; i++){
        if(i==r)
            continue;
        for(int j=0; j<colcnt; j++){
            if(j==c)
                continue;
            matrix[i][j] = (matrix[r][j]==0||matrix[i][c]==0) ? 0:matrix[i][j];
        }
    }
    for(int i=0; i<rowcnt; i++)
        matrix[i][c] = 0;
    for(int j=0; j<colcnt; j++)
        matrix[r][j] = 0;
}

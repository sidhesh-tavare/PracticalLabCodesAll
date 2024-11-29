#include <stdio.h>

void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void MultiplyMat(int rows1, int cols1 , int mat1[rows1][cols1],
int rows2, int cols2 , int mat2[rows2][cols2],int res[rows1][cols2]){
    for(int i = 0 ; i< rows1 ;i++){
        for(int j = 0 ; j < cols2;j++){
            res[i][j]=0;
            for(int k =0 ; k<cols1 ; k++){
                res[i][j] = mat1[i][k]*mat2[k][j];
            }
        }
    }
}

int main(){
    
    int rows1,cols1,cols2,rows2;
    rows1=rows2=cols1=cols2=3;
    int res[rows1][cols2];
    int mat1[3][3] = {
    {5, 3, 7},
    {2, 9, 4},
    {6, 8, 2}
};

int mat2[3][3] = {
    {5, 3, 7},
    {2, 9, 4},
    {6, 8, 2}
};

if(cols1!=rows2) printf("Multiplication not possible");
MultiplyMat(rows1,cols1,mat1,rows2,cols2,mat2,res);
printMatrix(3,3,res);
}
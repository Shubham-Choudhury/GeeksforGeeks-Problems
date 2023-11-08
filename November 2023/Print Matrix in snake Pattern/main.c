// Link: https://www.geeksforgeeks.org/problems/print-matrix-in-snake-pattern-1587115621/1

#include <stdio.h>
#include <stdlib.h>

int* snakePattern(int n, int matrix[][n]);

int main(){
    int n=3;
    int matrix[3][3]={{45, 48, 54}, {21, 89, 87}, {70, 78, 15}};
    int *arr=snakePattern(n, matrix);
    for(int i=0; i<n*n; i++){
        printf("%d ", arr[i]);
    }
}

int* snakePattern(int n, int matrix[][n])
{   
    int flag = 0;
    int *arr=(int*)malloc((n*n+1)*sizeof(int));
    for(int i=0; i<n; i++){
        if(i%2==0){
            for(int j=0; j<n; j++){
                arr[flag++]=matrix[i][j];
            }
        }
        else{
            for(int j=n-1; j>=0; j--){
                arr[flag++]=matrix[i][j];
            }
        }
    }
    return arr;
}
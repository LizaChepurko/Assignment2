#include <stdio.h>
#define size 10
#define INFINITY 9999

void input_values(int mat[size][size]){
    for(int i = 0; i<size ;i++){
        for(int j = 0; j<size; j++){
            scanf("%d",&mat[i][j]);

        if(i != j && mat[i][j] == 0){
           mat[i][j] = INFINITY;
        }
    }
    }
    }

void hasPath(int i, int j, int mat[size][size]){
    if (i != j && mat[i][j] != INFINITY) {
        printf("True\n");
    } else {
        printf("False\n");
    }
}

void floydWarshall(int mat[size][size]){
    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (mat[i][k] + mat[k][j] < mat[i][j]) {
                    mat[i][j] = mat[i][k] + mat[k][j];
                }
            }
        }
    }
   

}

void findTheShortestPath(int mat[size][size], int i, int j) {
    if (i == j || mat[i][j] == INFINITY)
        printf("%d\n", -1);

    else
         printf("%d\n", mat[i][j]);
}





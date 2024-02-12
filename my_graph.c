#include <stdio.h>
#include "my_mat.h"
#define size 10

int main(){

    char c;
    int t = 0;

    int mat[size][size];
    while(t != 1)
    {
        scanf("%c",&c);

        switch(c)
        {
            case 'A':
            {
                input_values(mat);
                break;
            }
            case 'B':
            {
                int a, b;
                scanf("%d%d", &a, &b);
                floydWarshall(mat);
                hasPath(a, b, mat);
                break;
            }
            case 'C':
            {
                int a,b;
                scanf("%d%d", &a, &b);
                floydWarshall(mat);
                findTheShortestPath(mat,a,b);
                break;
            }

            case 'D':
            {
                t=1;
                break;
            }
        }
    }
    return 0;
}

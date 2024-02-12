#include <stdio.h>

#define N 5
#define W 20

int max(int a, int b) { 
	return (a > b) ? a : b;
}

int knapSack(int wt[], int val[], int selected_bool[]) {
	int i, w;
	int K[N + 1][W + 1];

	for (i = 0; i <= N; ++i)
	{
		for (w = 0; w <= W; ++w)
		{
			if (i == 0 || w == 0)
				K[i][w] = 0;

			else if (wt[i - 1] <= w)
				K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
			
			else
				K[i][w] = K[i - 1][w];
		}
	}

    w = W;
	
    for (i = N; i > 0 && w > 0; --i)
	{
        if (K[i][w] != K[i - 1][w])
		{
            selected_bool[i - 1] = 1;
            w -= wt[i - 1];
        }
    }

	return K[N][W];
}

int main(void) {
	char strings[N][5];
	int weights[N] = { 0 };
	int values[N] = { 0 };
	int selected[N] = { 0 };

	for (int i = 0; i < N; ++i)
	{
		scanf("%4s", strings[i]);
		scanf("%d", &values[i]);
		scanf("%d", &weights[i]);

		while (weights[i] > W)
		{
			printf("Max weight is %d, please retry.", W);
			scanf("%d", &weights[i]);
		}
	}

	int res = knapSack(weights, values, selected);

	printf("Maximum profit: %d\n", res);
	printf("Selected items:");

	for (int i = 0; i < N; ++i)
	{
		if (selected[i])
			printf(" %s", strings[i]);
	}

	return 0;
}
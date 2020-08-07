#include <stdio.h>
#include <stdlib.h>
int* readElements(int);
void printArray(int, int*);
float weightedMean(int, int*, int*);

int main (void)
{
	int n;
	int *x_s;
	int *w_s;
	float weighted_mean;

	scanf("%d", &n);
	getchar();

	x_s = readElements(n);
	w_s = readElements(n);

	/*printArray(n, x_s);
	printArray(n, w_s);*/

	weighted_mean = weightedMean(n, x_s, w_s);
	printf("%.1f\n", weighted_mean);
	
	return 0;
}
int* readElements(int n)
{
	int *memory = (int *)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++)
	{
		scanf("%d", memory+i);
		getchar();
	}
	return memory;
}

void printArray(int n, int *array)
{
	for (int i = 0; i < n; i++)
	{
		printf("[%d] ", array[i]);
	}
	putchar('\n');
}

float weightedMean(int n, int *x_s, int *w_s)
{
	int result = 0, sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += w_s[i];
		//printf("-%d-", x_s[i] * w_s[i]);
		result += x_s[i] * w_s[i];
	}

	//printf("\n%d, %d\n", result, sum);

	return result / (float)sum;

}
#include <stdio.h>//printf scanf getchar putchar
#include <stdlib.h>// malloc free
#include <math.h> // pow sqrt

int getSizeArray(void);
int* getArray(int);
void printArray(int, int*);
float MEAN(int, int*);
double VARIANCE(int, int*, float);
double standarDeviation(double);

int main (void)
{
	/*Get inputs*/
	int size = getSizeArray();
	int *array = getArray(size);

	/*Calculate mean*/
	float mean = MEAN(size, array);
	
	/*Calculate variance*/
	double variance = VARIANCE(size, array, mean);

	/*Calculate Standar Deviation*/
	double st_dv = standarDeviation(variance);

	/*Debugging*/
	/*printf("size = %d\n", size);
	printArray(size, array);
	printf("mean = %f\n", mean);
	printf("variance = %lf\n", variance);
	printf("standarDeviation = %lf\n", st_dv);*/

	/*Output*/
	printf("%.1lf\n", st_dv);

	free(array);
	return 0;
}

int getSizeArray(void)
{
	int size;
	scanf("%d", &size);
	getchar();

	return size;
}

int* getArray(int size)
{
	int *array = (int*)malloc(size * sizeof(int));

	for (int i = 0; i < size; i++)
	{
		scanf("%d", array+i);
		getchar();
	}

	return array;
}

void printArray(int size, int *array)
{
	for (int i = 0; i < size; i++)
	{
		printf(" [%d] ", array[i]);
	}

	putchar('\n');
}

float MEAN(int size, int *array)
{
	int acumulator = 0;

	for (int i = 0; i < size; i++)
	{
		acumulator += array[i];
	}

	return acumulator / (float)size;
}

double VARIANCE(int size, int *array, float mean)
{
	double acumulator = 0;

	for (int i = 0; i < size; i++)
	{
		acumulator += pow(array[i] - mean, 2);
	}

	return acumulator / (double)size;
}

double standarDeviation(double variance)
{
	return sqrt(variance);
}
#include <stdio.h>
#include <stdlib.h>
int compare(const void *, const void *);
void printArray(int, int *);
int* getElements(int *);
float getMean(int, int*);
float getMedian(int, int*);
int getMode(int, int*);

int main (void)
{
	int *array;
	int size;
	float mean, median;
	int mode;

	array = getElements(&size);
	/*printf("Before sorting\n");
	printArray(size, array);*/
	qsort(array, size, sizeof(int), compare);
	/*printArray(size, array);*/

	mean = getMean(size, array);
	median = getMedian(size, array);
	mode = getMode(size, array);
	printf("%.1f\n", mean);
	printf("%.1f\n", median);
	printf("%d\n", mode);
	return 0;
}

int compare(const void *a, const void *b)
{
	//return (*(int *)a + *(int *)b);
	if(*(int *)a > *(int *)b){
		return 1;
	}else if(*(int *)a < *(int *)b){
		return -1;
	}else{
		return 0;
	}
}

void printArray(int count, int *array)
{
	for (int i = 0; i < count; i++)
	{
		printf(" [%d] ", array[i]);
	}
	putchar('\n');
}

int* getElements(int *size)
{
	printf("How many elements?\n");
	scanf("%d", size);
	getchar();
	int *memory = (int *)malloc(*size * sizeof(int)); 
	for (int i = 0; i < *size; i++)
	{
		scanf("%d", memory+i);
		getchar();
	}
	return memory;
}

float getMean(int size, int *array)
{
	float result = 0;
	for (int i = 0; i < size; i++)
	{
		result += array[i];
	}
	return result / (float)size;
}
float getMedian(int size, int *array)
{
	if(size % 2 == 0){
		float sum = (array[(int)(size / 2)-1] + array[((int)(size / 2))]) / (float)2;
		return sum;
	}else{
		return array[(int)(size / 2)];
	}
}
int getMode(int size, int *array)
{
	int pos_popular = 0;
	int rep_array[size];

	for (int i = 0; i < size; i++)
	{
		rep_array[i] = 1;
		for (int j = 0; j < size; j++)
		{
			if ( i != j && (array[i] == array[j]))
			{
				rep_array[i]++;
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		if (rep_array[i] > rep_array[pos_popular])
		{
			pos_popular = i;
		}
	}

	return array[pos_popular];
}
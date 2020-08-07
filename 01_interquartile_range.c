#include <stdio.h>
#include <stdlib.h>

int getNumber(void);
int* getArray(int);
void printArray(int, int*);
int compare(const void*, const void*);
float getMedian(int, int*);
float* getQuartiles(int, int*);
void printArrayFloats(int, float*);
int* generateArray(int, int*, int*, int*);

int main (void)
{
	int size, size_input_array, *array;
	int *elements;
	int *frecuency;
	float *quartiles;

	size_input_array = getNumber();
	elements = getArray(size_input_array);
	frecuency = getArray(size_input_array);
	array = generateArray(size_input_array, elements, frecuency, &size);


	/*printArray(size, array);*/
	qsort(array, size, sizeof(int), compare);
	/*printArray(size, array);*/

	quartiles = getQuartiles(size, array);
	
	printf("%.1f\n", (quartiles[2])-(quartiles[0]));

	free(elements);
	free(frecuency);
	free(array);

	return 0;
}

int getNumber(void)
{
	int number;
	scanf("%d", &number);
	getchar();

	return number;
}

int* getArray(int size)
{
	int *array;
	array = (int*)malloc(size * (sizeof(int)));

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

int compare(const void *a, const void *b)
{
	if (*(int*)a > *(int*)b)
	{
		return 1;
	}else if (*(int*)a < *(int*)b)
	{
		return -1;
	}else{
		return 0;
	}
}

float getMedian(int size, int *array)
{
	if (size % 2 == 0)
	{
		return ((array[(size/2)-1]) + (array[size/2])) / (float)2;
	}else{
		return (float)array[size/2];
	}
}

float* getQuartiles(int size, int *array)
{
	float *quartiles = (float*)malloc(3 * sizeof(float));
	float median = getMedian(size, array);

	quartiles[1] = median;
	if (size%2 == 0)
	{
		//printArray((size/2), array);
		quartiles[0] = getMedian((size/2), array);

		int *temp_array = (int*)malloc((size/2) * sizeof(int));
		for (int i = 0; i < (size/2); i++)
		{
			temp_array[i] = array[(size/2)+i];
		}
		quartiles[2] = getMedian((size/2), temp_array);
	}else{
		quartiles[0] = getMedian((size/2), array);

		int *temp_array = (int*)malloc((size/2) * sizeof(int));
		for (int i = 0; i < (size/2); i++)
		{
			temp_array[i] = array[(size/2)+1+i];
		}
		quartiles[2] = getMedian((size/2), temp_array);

	}
	return quartiles;
}

void printArrayFloats(int size, float *array)
{
	for (int i = 0; i < size; i++)
	{
		printf(" [%f] ", array[i]);
	}

	putchar('\n');
}

int* generateArray(int size, int *elements, int *frecuency, int *real_size)
{
	/*calculate the real array's size*/
	*real_size = 0;
	for (int i = 0; i < size; i++)
	{
		*real_size += frecuency[i];
	}

	/*allocate array's memory*/
	int *real_array = (int*)malloc(*real_size * sizeof(int));

	/*generate array*/
	int pos = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < frecuency[i]; j++)
		{
			real_array[pos++] = elements[i]; 
		}
	}

	/*return array*/
	return real_array;
}
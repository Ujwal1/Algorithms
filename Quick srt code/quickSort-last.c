#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// last element as pivot
int partition(int ar[], int start, int end) {
	int i = start - 1, pivot = ar[end], j;

	for(j = start; j < end; j++) {
		if(ar[j] < pivot) {
            i++;
			swap(ar, i, j);
		}
	}
	swap(ar, end, i+1);
	return i+1;
}

// quicksort
void quicksort(int ar[], int start, int end) {
	if(start < end) {
		int pivotPostition = partition(ar, start, end);
		quicksort(ar, start, pivotPostition - 1);
		quicksort(ar, pivotPostition + 1, end);
	}
}

// function to swap elements of array
void swap(int ar[], int a, int b) {
	int temp = ar[a];
	ar[a] = ar[b];
	ar[b] = temp;
}

// function to print array
void printArray(int ar[], int n) {
	int i;
	for(i = 0; i < n; i++)
		printf("%d ", ar[i]);
	printf("\n");
}

int main() {
	int i, n;
	srand(time(NULL));
	clock_t begin, end;
	n = 10;
	int ar[n];

	for(i = 0; i < n; i++)
		ar[i] = rand();

	printArray(ar, n);
	begin = clock();
	quicksort(ar, 0, n-1);
	end = clock();
	printArray(ar, n);

	double timeTaken = (double) (end - begin) / CLOCKS_PER_SEC;
	printf("%lf\n", timeTaken);

	return 0;
}

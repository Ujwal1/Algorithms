#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// random element pivot
int randomPartition(int ar[], int start, int end) {
    // chooses position of pivot randomly by using rand() function .
    int random = start + rand() % (end - start + 1) ;

    swap (ar, random, start);        //swap pivot with 1st element.
    return partitionFirst(ar,start ,end);       //call the above partition function
}

// random
void quicksortRandom(int ar[], int start, int end) {
	if(start < end) {
		int pivotPostition = randomPartition(ar, start, end);
		quicksortRandom(ar, start, pivotPostition - 1);
		quicksortRandom(ar, pivotPostition + 1, end);
	}
}

// first element as pivot
int partitionFirst(int ar[], int start, int end) {
	int i = start + 1, pivot = ar[start], j;

	for(j = start + 1; j <= end; j++) {
		if(ar[j] < pivot) {
			swap(ar, i, j);
			i++;
		}
	}
	swap(ar, start, i-1);
	return i-1;
}

// quicksortFirst
void quicksortFirst(int ar[], int start, int end) {
	if(start < end) {
		int pivotPostition = partitionFirst(ar, start, end);
		quicksortFirst(ar, start, pivotPostition - 1);
		quicksortFirst(ar, pivotPostition + 1, end);
	}
}

// last element as pivot
int partitionLast(int ar[], int start, int end) {
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

// quicksortLast
void quicksortLast(int ar[], int start, int end) {
	if(start < end) {
		int pivotPostition = partitionLast(ar, start, end);
		quicksortLast(ar, start, pivotPostition - 1);
		quicksortLast(ar, pivotPostition + 1, end);
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
	int i;
	srand(time(NULL));
	clock_t begin, end;
	long n = 500000;
	int arFirst[n], arLast[n], arRandom[n];

	for(i = 0; i < n; i++) {
		arFirst[i] = rand();
		arLast[i] = rand();
		arRandom[i] = rand();
	}
    printArray(arFirst, n);

    // first
    printf("\nFIRST\n");
	begin = clock();
	quicksortFirst(arFirst, 0, n-1);
	end = clock();
	//printArray(arFirst, n);

	double timeTaken = (double) (end - begin) / CLOCKS_PER_SEC;
	printf("%lf\n", timeTaken);

    // last
    printf("\nLAST\n");
	begin = clock();
	quicksortLast(arLast, 0, n-1);
	end = clock();
	//printArray(arLast, n);

	timeTaken = (double) (end - begin) / CLOCKS_PER_SEC;
	printf("%lf\n", timeTaken);

	// random
    printf("\nRANDOM\n");
	begin = clock();
	quicksortLast(arRandom, 0, n-1);
	end = clock();
	//printArray(arRandom, n);

	timeTaken = (double) (end - begin) / CLOCKS_PER_SEC;
	printf("%lf\n", timeTaken);

	return 0;
}

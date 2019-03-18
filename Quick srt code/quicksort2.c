#include <stdio.h>
#include<time.h>
void quick_sort(int[],int,int);
int partition(int[],int,int);

int main()
{
    clock_t b,e;
	int a[50000],n,i;
	printf("enter the no of elements:");
	scanf("%d",&n);
	srand(time(0));


	for(i=0;i<n;i++)
    {
        a[i]=rand()%100;
    }

b=clock();
	quick_sort(a,0,n-1);
	printf("\nArray after sorting:");

	for(i=0;i<n;i++)
		printf("%d ",a[i]);
e=clock();
printf("\n the execution time %d ms",e-b);
	return 0;
}

void quick_sort(int a[],int l,int u)
{
	int j;
	if(l<u)
	{
		j=partition(a,l,u);
		quick_sort(a,l,j-1);
		quick_sort(a,j+1,u);
	}
}

int partition(int a[],int l,int u)
{
	int v,i,j,temp;
	v=a[l];
	i=l;
	j=u+1;

	do
	{
		do
			i++;

		while(a[i]<v&&i<=u);

		do
			j--;
		while(v<a[j]);

		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}while(i<j);

	a[l]=a[j];
	a[j]=v;

	return(j);
}

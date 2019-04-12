//hahhahuhu
//hy

#include <stdio.h>
#include <stdlib.h>
#include<time.h>
void Insertion(int n)
{
    (srand(time(NULL)));
    int a[n];
    int i,temp1,t=0;
    printf("Enter the elements of Array\n");
    for(i=0;i<n;i++)
    {
        a[i]=rand();
        //scanf("%d",&a[i]);
    }
    printf("\nEntered array is :");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    for(i=0;i<n;i++)
    {
        temp1=a[i];
        t=i-1;
        while(temp1<a[t] && t>=0)
        {
            a[t+1]=a[t];
            t=t-1;
        }
        a[t+1]=temp1;
    }
    printf("\nSorted array is :");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
int main()
{
    int x=1700;
    printf("Enter the number of elements of the array %d\n",x);
    //scanf("%d",&x);
    Insertion(x);
    return 0;
}

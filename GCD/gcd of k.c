#include<stdio.h>
#include<time.h>
#include<windows.h>
int main()
{srand(time(NULL));
int n=98,i,gcd;
//printf("Enter how many no.s u want to find gcd : ");

//scanf("%d",&n);

int arr[n];

for(i=0;i<n;i++)
{
/*printf("\nEnter your %d number = ",i+1);
scanf("%d",&arr[i]);*/
arr[i]=rand();
printf("num are %d\n",arr[i]);
}

clock_t start, end;
double time;
start=clock();
gcd=arr[0];
int j=1;
while(j<n)
{
    Sleep(1);
if(arr[j]%gcd==0)
{
j++;
}
else
{
gcd=arr[j]%gcd;
i++;
}
}
printf("\nGCD of k no.s = %d ",gcd);
end=clock();
time=((double)end - start)/CLOCKS_PER_SEC;
printf("time=%f",time);
return 0;
}

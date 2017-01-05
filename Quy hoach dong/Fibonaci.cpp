#include<stdio.h>
#include<conio.h>

int FB(int a[],int n)
{
	 a[0]=0;
	 a[1]=1;
	 int k=1,tg;
	while(k<n)
	{
		a[k+1]=a[k]+a[k-1];		
		k++;
	}

}

int main()
{
	int a[100],n=10;
	FB(a,n);
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	int b[100];
	b[0]=0;
	b[1]=1;
	b[2]=1;
	for(int i=3;i<n;i++)
	{
		b[i]=b[i-1]+b[i-2];
	}
	for(int i=0;i<n;i++)
	{
		printf("%d ",b[i]);
	}
	getch();
	return 1;
}

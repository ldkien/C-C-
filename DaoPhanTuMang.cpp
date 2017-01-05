#include<stdio.h>
#include<conio.h>
void Swap(int &a,int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}
void doicho(int *a, int i,int j,int m)
{
	int p;
	for(p=0;p<m;p++)
	{
		Swap(a[i+p],a[j+p]);
	}
	
}

void Transpose(int *a,int n, int m)
{
	int i=m,j=n-m;
	
	while(i!=j)
	{
		if(i>j)
		{
			doicho(a,m-i,m,j);
			i=i-j;
		}
		else
		{
			j=j-i;
			doicho(a,m-i,m+j,i);
		}
		
	}
	doicho(a,m-i,m,i);
}
int main()
{
	int a[11]={1,2,3,4,5,6,7,8,9,10,11};
	Transpose(a,11,2);
	for(int i=0;i<11;i++)
	{
		printf("%d ",a[i]);
	}
	getch();
	return 0;
}

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void Swap(int &a,int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}
void InsertSort(int *p,int n)
{
	int j;
	for(int i=1;i<n;i++)
	{
		j=i;
		while((j>=1)&&(*(p+j)<=*(p+j-1)))
		{
			Swap(*(p+j),*(p+j-1));
			j--;
		}
	}
	
}

void Input(int *(&p),int &n)
{
	printf("Nhap so phan tu cua mang: ");
	scanf("%d",&n);
	p=(int *) malloc(n*sizeof(int));
	printf("Nhap cac phan tu cua mang:\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",p+i);
	}
	
}
void Output(int *p,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d",*(p+i));
	}
}
int TimKiem(int *p,int n,int x)
{
	p=(int *) malloc(n*sizeof(int));
	int d=0,c=n-1,k;
	while(d<c)
	{
		k=(d+c)/2;
		if(*(p+k)=x)
			return k;
		else
		{
			if(*(p+k)<x)
				d=k+1;
			else
				c=k-1;				
		}
	}
	return -1;
}
int main()
{
	int *p;
	int n;
	Input(p,n);
	InsertSort(p,n);
	Output(p,n);
	printf("\n%d",TimKiem(p,n,3));
	free(p);
	getch();
	return 1;
}

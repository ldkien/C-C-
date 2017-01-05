#include<conio.h>
#include<stdio.h>

void Swap(int &a, int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}

void QuickSort(int *arr, int left, int right)
{
	int i,j,x;
	x=arr[(left+right)/2];
	i=left;
	j=right;
	
	while(i<=j)
	{
		while(arr[i]<x)
			i++;
		while(arr[j]>x)
			j--;
		if(i<=j)
		{
			if(i<j)
				Swap(arr[i],arr[j]);
			i++;
			j--;
		}
	}
	if(left<j)
		QuickSort(arr,left,j);
	if(i<right)
		QuickSort(arr,i,right);	
}
int main()
{
	int arr[20];
	int n;
	printf("Nhap so phan tu cua mang: ");
	scanf("%d",&n);
	printf("Nhap cac phan tu cua mang:\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	QuickSort(arr,0,n-1);
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	getch();
	return 0;
}

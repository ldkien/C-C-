#include<stdio.h>
#include<conio.h>

void Swap(int &a, int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}
void BubbleSort(int *arr,int n)
{
	int i,j,k=0,m=n;
	for(i=0;i<m-1;i++)
	{
	
		for(j=m-1;j>i;j--)
		{
			if(arr[j]<arr[j-1])
			{
				Swap(arr[j-1],arr[j]);
				k=j-1;
			}
		}
		
		m=n-k-1;
	}

}
int main()
{
	int arr[10]={42,23,74,11,65,58,94,36,99,87};
	BubbleSort(arr,10);
	for(int i=0;i<10;i++)
		printf("%d ",arr[i]);
	getch();
	return 1;
		
}

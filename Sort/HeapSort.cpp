#include<stdio.h>
#include<conio.h>
void Swap(int &a, int &b)
{
	int temp;
	temp=a;a=b;b=temp;
}
// hoan vi nut cha thu i phai lon hon nut con
void Heap(int *a, int n,int i)
{
	int left=2*i+1, right=2*i+2;
	int max;
	
	if(left<n && a[left]>a[i])
		max=left;
	else
		max=i;
	if(right<n && a[right]>a[max])
		max=right;
	if(i!=max)
	{
		Swap(a[i],a[max]);
		Heap(a,n,max);
	}
}
//xay dung heap sao cho moi nut cha lon hon nut con
void BuildHeap(int *a, int n)
{
	
	for(int i=n/2-1;i>=0;i--)
	{
		Heap(a,n,i);
	}
}

void HeapSort(int *a, int n)
{
	BuildHeap(a,n);
	for(int i=n-1;i>0;i--)
	{
		Swap(a[0],a[i]);
		Heap(a,i,0);
	}
}

int main()
{
	int a[11]={3, 5, 8, 9, 4, 2, 7, 5, 3,9,8};
	HeapSort(a,11);
	for(int i=0;i<11;i++)
		printf("%d ",a[i]);
	getch();
	return 1;
}

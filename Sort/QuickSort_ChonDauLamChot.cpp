#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>
#include <ctime> 
void Swap(int &a, int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}
int Partition(int *a, int left, int right)
{
	//Partition
	int i,j,x;
	x = a[left];
	i = left + 1;
	j = right;
	while (i <= j)
	{
		while(i <= j && a[i]<x)
			i++;
		while(j >= i && a[j] >= x)
			j--;
		if(i < j)
		{
			Swap(a[i], a[j]);
		}
	}
	Swap(a[left], a[j]);
	
	return j;
}
int QuickSort(int *a, int left, int right)
{
	if(left >= right)
		return -1;
	int i = Partition(a, left, right);
	QuickSort(a, left, i-1);
	QuickSort(a, i+1, right);
}
int main()
{
	int a[50], i;
	//int a[11]={3, 5, 8, 9, 4, 2, 7, 5, 3,9,8};
	//int a[11]={-7,8,10,-3,2,12,-6,-7,11,-11,7};
	srand(time(0));
	int n = 11 + rand() % (13-11+1);
	for( i = 0; i < n; i++)
		a[i]= -11 + rand() % (12+11+1);
	for(i = 0;i < n; i ++)
		printf("%d ",a[i]);
	printf("\n");
	QuickSort(a,0,n-1);
	for(int i = 0;i < n; i ++)
		printf("%d ",a[i]);
	getch();
	return 1;
}

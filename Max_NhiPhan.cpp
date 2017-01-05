#include<stdio.h>
#include<conio.h>

int Max(int *a, int left, int right)
{
	int max1,max2,max;
	int m=(left+right)/2;
	if(left==right)
		max=a[left];
	else
	{
		max1=Max(a,left,m);
		max2=Max(a,m+1,right);
		if(max1>max2)
			max=max1;
		else
			max=max2;
	}
	return max;
}

int main()
{
	int a[10]={8,-64,-67,-65,-879,78,-65,-21,6,-67};
	printf("%d",Max(a,0,9));
	getch();
	return 0;
}

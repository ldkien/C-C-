#include<stdio.h>
#include<conio.h>

int MaxSubVecto(int *a,int n)
{
	int s;
	int max=-4563221;
	for(int i=0;i<n;i++)
	{
		s=0;
		for(int j=i;j<n;j++)
		{
			s=s+a[j];
			if(s>max)
				max=s;
		}
	}
	return max;
}
int main()
{
	int a[10]={98,54,67, 65,-879,78,65,21,-6,67};
	printf("%d",MaxSubVecto(a,10));
	getch();
	return 0;
}

#include<stdio.h>
#include<conio.h>

int SubMax(int a[], int n, int &s, int &e)
{
	int maxS=a[0];
	int maxE=a[0];
	s=0;e=0;
	int s1=0;
	for(int i=1;i<n;i++)
	{
		if(maxE>0)
		{
			maxE=maxE+a[i];
		}
		else
		{
			maxE=a[i];
			s1=i;
		}
		if(maxE>maxS)
		{
			maxS=maxE;
			e=i;
			s=s1;
		}
	}
	return maxS;
}
int main()
{
	int s,e;
	//int a[9]={-13,-15,-2,-18,-4,-8,-1,-5,-8};
	int a[16] = {4, 6, -2, 8, 2, 9, -6, -15, 4, 1, 9, -3, -3, 1, 5, 6};
	printf("%d\n",SubMax(a,16,s,e));
	printf("%d %d",s,e);
	getch();
	return 1;
}

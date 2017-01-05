#include<stdio.h>
#include<conio.h>

int Bag_best(int w[], int c[], int n, int b)
{
	int MaxV[100][100];
	int i,l;
	for(i=0;i<=n;i++)
		MaxV[i][0]=0;
	for(l=0;l<=b;l++)
		MaxV[0][l]=0;
	for(i=0;i<=n;i++)
		for(l=0;l<=b;l++)
		{
			MaxV[i][l]=MaxV[i-1][l];
			if((l>=w[i]) && ((MaxV[i-1][l-w[i]]+c[i])>MaxV[i-1][l]))
				MaxV[i][l]= MaxV[i-1][l-w[i]]+c[i];
		}
	return MaxV[n][b];
}

int main()
{
	int w[7]={3,4,5,7,6,9};
	int c[7]={7,10,20,19,13,40};
	printf("%d", w[7]);
	printf("%d ",Bag_best(w,c,6,19));
	getch();
	return 1;
}

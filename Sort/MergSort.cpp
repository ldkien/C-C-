#include<stdio.h>
#include<conio.h>
/*X = {7, 2, 5, 4, 1, 3, 8, 6}
Dãy ban d?u: 7, 2, 5, 4, 1, 3, 8, 6
T? dãy ban d?u, chia làm 2 do?n con {7, 2, 5, 4} và {1, 3, 8, 6}
Chia ti?p làm các do?n con X1 = {7, 2}, X2 = {5, 4} và X3 = {1, 3}, X4 = {8, 6}
Merge t?ng do?n ta du?c X1 = {2, 7}, X2 = {4, 5} và X3 = {1, 3}, X4 = {6, 8}
Merge(X1+X2), Merge(X3+X4) ta du?c X5 = {2, 4, 5, 7} và X6 = {1, 3, 6, 8}
Merge(X5+X6) ta du?c {1, 2, 3, 4, 5, 6, 7 ,8}*/

// Tron
void Merg(int *a, int left, int t, int right )
{
	int i=left, j=t, p=left;
	int temp[50];
	while(i<t&&j<=right)
	{
		if(a[i]<a[j])
		{
			temp[p]=a[i];
			i++;
		}
		else
		{
			temp[p]=a[j];
			j++;
		}
		p++;
	}
	while(i<t)
	{
		temp[p]=a[i];
		i++;
		p++;
	}
	while(j<=right)
	{
		temp[p]=a[j];
		j++;
		p++;
	}
	/*if (i>=t)
        for(int n=j;n<=right;n++)
         temp[p+n-j]=a[n];
   else
      for(int n=i;n<=t;n++)
         temp[p+n-i]=a[n];*/
	for(int k=left;k<=right;k++)
	{
		a[k]=temp[k];
	}
}

int MergSort(int *a, int left, int right)
{
	if(left>=right)
		return 1;
	int t=(left+right)/2;
	MergSort(a,left,t);
	MergSort(a,t+1,right);
	Merg(a,left,t+1,right);
	
}

int main()
{
	int a[11]={3, 5, 8, 9, 4, 2, 7, 5, 3,9,8};
	MergSort(a,0,10);
	for(int i=0;i<11;i++)
		printf("%d ",a[i]);
	getch();
	return 1;
}

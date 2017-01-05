#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
static 	int h[50][50];

void Try(int i, int n, int x, int y)
{

	static int a[8]={-1,-2,-2,-1,1,2,2,1};
	static int b[8]={2,1,-1,-2,-2,-1,1,2};
	int u,v;
	if(i==n*n)
	{
		cout<<"-----------"<<endl;
		for (int l=0;l<5;l++)
				{
				  	for (int j=0;j<5;j++)
						printf("%4d",h[l][j]);
				  	cout << endl;
				  	cout << endl;
				}

		return;
	}
		for(int k=0;k<8;k++)
		{
			u=x+a[k];
			v=y+b[k];
			if(u>=0 && u<n && v>=0 && v<n && !h[u][v])
			{
				h[u][v]=i+1;
				Try(i+1,n,u,v);
				h[u][v]=0;
			}
			
		}

}

int main()
{
	for (int i=0;i<5;i++)
  		for (int j=0;j<5;j++)
   			h[i][j]=0;
 	h[0][0]=1;
	Try(1,5,0,0);
	getch();
	return 1;
}

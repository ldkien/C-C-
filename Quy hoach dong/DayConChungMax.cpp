
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<string>
#include <cstdlib>
using namespace std;
int LCS(char x[], char y[])
{
	int n=strlen(x);
	int m=strlen(y);
	int c[50][50],b[50][50];
	for(int i=0;i<n;i++)
	{
		c[i][0]=0;
	}
	for(int j=0;j<m;j++)
	{
		c[0][j]=0;

	}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			if(x[i]==y[j])
			{
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]=1;
			}				
			else
			{
				if(c[i-1][j]>=c[i][j-1])
				{
					c[i][j]=c[i-1][j];
					b[i][j]=2;
				}
				else
				{
					c[i][j]=c[i][j-1];
					b[i][j]=3;
				}
					
			}
		}
		int t=c[n-1][m-1];
		int i=n-1;
		int j=m-1;
		while(t>=1)
		{
				if(b[i][j]==1)
				{
					cout<<x[i];
					i=i-1;
					j=j-1;
					t--;
				}
				else
				{
					if(b[i][j]==2)
					{
						i=i-1;
					}
					else
					{
						j=j-1;
					}
				}
					
		}
		return c[n-1][m-1];
}

int main()
{
	char x[8]="hoahong",y[8]="khoahoc";
	cout<<x<<endl;
	cout<<y<<endl;
	cout<<"\n"<<LCS(x,y);
	getch();
	return 0;
}


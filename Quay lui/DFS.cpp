#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
int daxet[50];
int truoc[50];
void Xuat(int s, int t, int truoc[])
{
	cout<<t+1<<"<--";
	int j=t;
	while(truoc[j]!=s)
	{
		cout<<truoc[j]+1<<"<--";
		j=truoc[j];
	}
	cout<<s+1<<endl;
}
void DFS(int s, int t, int a[][7], int n)
{
	int u;

	daxet[s]=1;
	for(u=0;u<n;u++)
	{
		if(a[s][u] && !daxet[u])
		{
			truoc[u]=s;
			daxet[s]=1;
			if(u==t)
			{
				Xuat(1,4,truoc);
			}
			else
				DFS(u,t,a,n);
			daxet[u]=0;
		}
	}
}
int main()
{
	int a[7][7]={
		{0,0,0,1,0,1,1},{0,0,1,1,0,0,0},{0,1,0,1,0,1,0},{1,0,1,0,0,0,0},{0,0,0,0,1,1,0},{1,0,0,0,1,0,0},{1,0,0,1,0,0,0}
	};
	for(int i=0;i<7;i++)
	{
		daxet[i]=0;
		truoc[i]=1;
	}
	DFS(1,4,a,7);
	getch();
	return 1;
}

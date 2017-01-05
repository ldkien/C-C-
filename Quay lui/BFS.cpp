#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
int daxet[50];
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
void BFS(int s, int t, int a[][6], int n)
{
	int u,i,dauQ=0,cuoiQ=0;
	int queue[50],truoc[50];
	queue[cuoiQ]=s;
	daxet[s]=1;
	
	while(dauQ<=cuoiQ)
	{
		u=queue[dauQ];
		dauQ++;
		for(i=0;i<n;i++)
		{
			if(a[u][i]==1 && !daxet[i])
			{
				cuoiQ++;
				queue[cuoiQ]=i;
				daxet[i]=1;
				truoc[i]=u;
			}
		}
	}
	Xuat(s,t,truoc);
	
}
int main()
{
	int a[6][6]={{0,1,1,0,1,0},{0,0,0,0,0,1},{0,1,0,0,1,0},{1,0,1,0,1,0},{0,0,0,0,0,1},{1,1,0,1,0,0}};
	for(int i=0;i<6;i++)
	{
		daxet[i]=0;
	}
	
	//for(int i=0;i<6;i++)
	//{
	//	if(daxet[i]==0)
	//	{
			BFS(0,3,a,6);
		//}
	//}
	getch();
	return 1;
}

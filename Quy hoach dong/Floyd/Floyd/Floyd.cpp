// Floyd.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
void Floyd(int a[][6],int n, int f, int l)
{
	int i,j,k;
	int d[50][50],p[50][50];
	
	//khoi dong ma tran ddnn(d) va dinh di qua (p)
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			d[i][j]=a[i][j];
			p[i][j]=0;
		}
	}
	cout<<endl;
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			if(d[i][k]>0 && d[i][k]<456)
			{
				for(j=0;j<n;j++)
				{
					if(d[k][j]>0 && d[k][j]<456)
					{
						if(d[i][k]+d[k][j]<d[i][j])
						{
							d[i][j]=d[i][k]+d[k][j];
							p[i][j]=k;
						}
					}
				}
			}
		}
	
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				cout<<d[i][j]<<" ";
			cout<<endl;
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				cout<<p[i][j]<<" ";
			cout<<endl;
		}
		cout<<endl;	
	}
	f=f-1;
	l=l-1;
	int u=f,v=l;
	int cost=0;
	if(p[f][l]==0)
	{
		cout<<f+1<<"->"<<l+1<<endl;
		cout<<d[f][l];
	}
	else
	{
		cout<<f+1<<"->";
		while(p[u][v]!=0)
		{
			cout<<p[u][v]+1<<"->";
			cost=d[u][v];
			u=p[u][v];
		}
		cout<<l+1<<endl;
		cout<<d[f][l];
	}
}
int main()
{
	/*int a[4][4]={
		{0,5,456,456},
		{50,0,15,5},
		{30,456,0,15},
		{15,456,5,0}
	};*/
	int a[6][6]={{0,20,15,456,80,456},{40,0,456,456,10,30},{20,4,0,456,456,10},{36,18,15,0,456,456},{456,456,90,15,0,456},{456,456,45,4,10,0}};
	Floyd(a,6,6,1);
	getchar();
	return 1;
}



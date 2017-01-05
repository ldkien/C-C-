#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
void xuatdd(int s,int k,int ddnn[])
{
	int i;
	cout<<"Duong di ngan nhat tu "<<s+1<<" den "<< k+1<<" la: ";
	i=k;
	while(i!=s)
	{
		cout<<i+1<<"<--";
		i=ddnn[i];
	}
	cout<<s+1;
}
void Dijkstra(int a[][6],int n,int s)
{
	int dht,i,k,min;//dht dinh hien tai
	int ddnn[50];//chua duowng di ngan nhat tu s den dinh hien tai
	int L[50],daxet[50];//L nhan cua cac dinh
	for(i=0;i<n;i++)
	{
		daxet[i]=0;
		L[i]=456;//luc dau cac nhan bang vo cung
	}
	dht=s;
	daxet[s]=1;
	L[s]=0;
	int h=1;
	while(h<n)
	{
		min=456;
		for(i=0;i<n;i++)
		{
			if(!daxet[i])
			{
				if(L[dht]+a[dht][i]<L[i])
				{
					L[i]=L[dht]+a[dht][i];
					ddnn[i]=dht;				
				}
				if(L[i]<min)
				{
					min=L[i];
					k=i;
				}
			}
		}
		
		xuatdd(s,k,ddnn);
		cout<<" Trong so: "<<L[k]<<endl;
		dht=k;
		daxet[dht]=1;
		h++;		
	}
}
int main()
{
	int a[6][6]={{0,20,15,456,80,456},{40,0,456,456,10,30},{20,4,0,456,456,10},{36,18,15,0,456,456},{456,456,90,15,0,456},{456,456,45,4,10,0}};
	Dijkstra(a,6,0);
	getch();
	return 1;
}


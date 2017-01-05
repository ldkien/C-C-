#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;

void Prim(int a[][7],int n)
{
	int Lowcost[50];
	int Closest[50],duyet[10];
	int i,j,k,min;
	for(i=1;i<n;i++)
	{
		Lowcost[i]=a[0][i];
		Closest[i]=0;
		duyet[i]=0;
	}
	for(i=1;i<n;i++)
	{
		min=Lowcost[1];
		k=1;
		for(j=2;j<n;j++)
		{
			if(Lowcost[j]<min)
			{
				min=Lowcost[j];
				k=j;
			}					
		}
		
		cout<<k+1<<Closest[k]+1<<endl;
		Lowcost[k]=800;
		for(j=1;j<n;j++)
			{
				if((a[k][j]<Lowcost[j])&&(Lowcost[j]<500))
				{
					Lowcost[j]=a[k][j];
					Closest[j]=k;
				
				}
			}

		
	}
}
int main()
{
	int a[7][7]={{0,1,456,4,456,456,456},{1,0,2,6,10,456,456},{456,2,0,456,4,5,456},{4,6,456,0,3,456,4},{456,10,4,3,0,8,7},{456,456,5,456,0,8,3},{456,456,456,4,7,3,456}};
	Prim(a,7);
	getch();
	return 1;
}

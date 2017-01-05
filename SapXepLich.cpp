#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>
#include <ctime> 
using namespace std;

struct CongViec{
	int maCV;
	int timeStart;
	int timeEnd;
};
void Init(struct CongViec cv[], int &n)
{
	int i,j;
	srand(time(0));
	n = rand() % 10;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cv[i].maCV=i;
			cv[i].timeStart= rand() % 15;
			cv[i].timeEnd= cv[i].timeStart + 1 + rand() % 11;
		}
	}
}
void Sort (struct CongViec cv[], int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=i;j<=n-1;j++)
		{
			if(cv[i].timeEnd>cv[j].timeEnd)
			{
				struct CongViec temp;
				temp=cv[i];
				cv[i]=cv[j];
				cv[j]=temp;
			}
		}
	}
}
void ChonLich(struct CongViec cv[], int n)
{
	int i=0, j, t;
	int S[50];
	S[0]=0;
	t=0;
	for( j=1;j<n;j++)
	{
		if(cv[t].timeEnd<=cv[j].timeStart)//tgian ket thuc cua cong viec nayf sowm hown thoi gian bat dau cua cong iec kia
		{
			t=j;
			i++;
			S[i]=t;
		}
	}
	cout<<"Cong viec duoc chon: "<<endl;
	for(j=0;j<=i;j++)
	{
		cout<<cv[S[j]].maCV<<" "<<cv[S[j]].timeStart<<" "<<cv[S[j]].timeEnd<<endl;
	}
}
int main()
{
	struct CongViec cv[50];
	int n;
	Init(cv, n);
	cout<<" Danh sach cong viec: "<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<cv[i].maCV<<" "<<cv[i].timeStart<<" "<<cv[i].timeEnd<<endl;
	}
	Sort(cv, n);	
	ChonLich(cv, n);
	getch();
	return 0;
}

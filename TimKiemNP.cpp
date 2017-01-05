#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>
#include <ctime> 
using namespace std;

int TimKiemNhiPhan(int a[], int x, int dau, int cuoi)
{
	int i;
	if(dau > cuoi)
		return 0;//day rong
	else
	{
		i = (dau+cuoi)/2;
		if(x == a[i])
		{
			return 1;
		}
			
		else
		{
			if( x > a[i])
				TimKiemNhiPhan(a, x, i+1, cuoi);
			else
				TimKiemNhiPhan(a, x, dau, i-1);
		}
	}
}
int main()
{
	int a[11]={2,4,6,8,10,12,14,16,18,20,22};
	if(TimKiemNhiPhan(a,10,0,10))
		cout<<"Tim thay"<<endl;
	else
		cout<<"KHong tim thay"<<endl;
	getch();
	return 1;
}

// ConMaDiTuan.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
using namespace std;
int  dx[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int  dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int n = 8;
int h[50][50];
//===================
void khoitao(int h[][50], int n, int x, int y)
{
	int i, j;
	for (i = 1; i<=n; i++)
		for (j = 1; j<=n; j++) h[i][j] = 0;
	h[x][y] = 1;
}
//=======================
void inkq(int h[][50], int n)
{
	int i, j;
	for (i = 1; i<=n; i++)
	{
		for (j = 1; j <= n; j++)
			cout << h[i][j] << " ";
		cout << endl;
	}
	cout<<"\n--------------------------\n";
}
//thu cac kha nang co the co
void Try(int i, int x, int y, int h[][50])
{
	int j, u, v;
	for (j = 0; j<8; j++)//tu 1 vi tri co the di den 8 vi tri khac
	{
		u = x + dx[j];
		v = y + dy[j];
		if (h[u][v] == 0 && 1 <= u && u<=n && 1 <= v && v<=n)
		{
			h[u][v] = i;
			if (i > n*n )
			{
				inkq(h, n);
				exit(0);// chi can 1 nghiem thi de exit
			}
			else
				Try(i + 1, u, v, h);
			h[u][v] = 0;
			//inkq(h, n);//xem tung buoc quan ma di
		}
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	int x, y;
	cout << "Nhap toa do ban dau" << endl;
	cout << "Nhap toa do x: ";
	cin >> x;
	cout << "Nhap toa do y: ";
	cin >> y;
	khoitao(h, n, x, y);
	Try(1, x, y, h);
	getchar();
	return 0;
}


// BFS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;

int daxet[50];

void XuatDuongDi(int s, int t, int truoc[])
{
	int j = t;
	cout << t + 1<< "<--";
	while (truoc[j] != s)
	{
		cout << truoc[j]+1 << "<--";
		j = truoc[j];
	}
	cout << s+1;
}
void BFS(int a[][6], int n, int s, int t)
{
	int queue[50], truoc[50];
	int dau = 0, cuoi = 0, u,i;
	queue[cuoi] = s;
	daxet[s] = 1;

	while (dau<=cuoi)
	{
		u = queue[dau];
		dau++;
		cout << u;
		for (i = 0; i<n; i++)
		{
			if (a[u][i] == 1 && !daxet[i])
			{
				cuoi++;
				queue[cuoi] = i;
				daxet[i] = 1;
				truoc[i] = u;
			}
		}
	}
	XuatDuongDi(s, t, truoc);

}
int _tmain(int argc, _TCHAR* argv[])
{

	int a[6][6] = { { 0, 1, 1, 0, 1, 0 }, { 0, 0, 0, 0, 0, 1 }, { 0, 1, 0, 0, 1, 0 }, { 1, 0, 1, 0, 1, 0 }, { 0, 0, 0, 0, 0, 1 }, { 1, 1, 0, 1, 0, 0 } };
	for (int i = 0; i<6; i++)
	{
		daxet[i] = 0;
	}
	BFS(a, 6, 0, 3);
	getchar();
	return 0;
}


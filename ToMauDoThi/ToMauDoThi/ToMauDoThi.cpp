// ToMauDoThi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;

int n=10, d[10], color[10], v[10], number = 0;
void duyet(int a[][10],int u)
{
	color[u] = number;
	for (int j = 0; j < n; j++)
	{
		if ((a[u][j] == 0) && (color[j] == 0))
			color[j] = number;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	
	int a[10][10] = { { 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, },
	{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, },
	{ 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, },
	{ 1, 0, 0, 0, 1, 0, 1, 1, 0, 0, },
	{ 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, },
	{ 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, },
	{ 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, },
	{ 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, },
	{ 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, },
	{ 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, } };

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			d[i] += a[i][j];
		}
		v[i] = i;
		color[i] = 0;
	}
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j <= n-1; j++)
			if (d[v[i]]<d[v[j]])
			{
				int tem = v[i];
				v[i] = v[j];
				v[j] = tem;
			}
	for (int i = 0; i < n; i++)
	{
		if (color[v[i]] == 0)
		{
			number++;
			duyet(a,v[i]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << " dinh " << i + 1 << " to mau " << color[i] << "\n";
	}
	getchar();
	return 0;
}


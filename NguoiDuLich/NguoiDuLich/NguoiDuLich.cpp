// NguoiDuLich.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>
#include <ctime> 
using namespace std;

void Input(int a[][50], int &n, int &dau)
{
	int i, j;
	srand(time(0));
	n = rand() % 11;
	dau = rand() % n;
	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
				a[i][j] = a[j][i] = 1 + rand() % (21 -1 + 1);
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void Output(int tour[], int n, int cost)
{
		cout << "Do dai quang duong: " << cost << endl;
		cout << "Duong di: ";
		for (int j = 0; j<n; j++)
			cout << tour[j]+1  << "-->";
		cout << tour[0]+1 ;
}
void GTS(int a[][50], int n, int ddau)
{
	int tour[50];
	int v;//Dinh dang xet
	int k; //Duyet qua n dinh de chon
	int w; //Dinh duoc chon trong moi buoc
	int mini; //Chon min cac canh(cung) trong moi buoc int COST; //Trong so nho nhat cua chu trinh
	int daxet[50]; //Danh dau cac dinh da duoc su dung
	for (k = 0; k <n; k++)
		daxet[k] = 0; //Chua dinh nao duoc xet
	int cost = 0; //Luc dau, gia tri COST == 0
	int i; // Bien dem, dem tim du n dinh thi dung
	v = ddau; //Chon dinh xuat phat la 1
	i = 0;
	tour[i] = v; //Dua v vao chu trinh daxet[v] = 1; //Dinh v da duoc xet
	daxet[v] = 1;
	while (i <n)
	{
		mini = 21;
		for (k = 0; k < n; k++)
		{
			if (!daxet[k])
			{
				if (mini > a[v][k])
				{
					mini = a[v][k];
					w = k;
				}
			}
		}
		v = w;
		cost += mini;
		i++;
		tour[i] = v;
		daxet[v] = 1;	
	}
	cost = cost;
	
		
	Output(tour, n, cost);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[50][50], n, dau;
	Input(a, n, dau);
	GTS(a, n, 0);
	getchar();
	return 1;
}


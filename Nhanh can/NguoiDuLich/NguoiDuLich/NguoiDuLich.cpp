// NguoiDuLich.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;

int daxet[50];

void KhoiTao(int C[][5], int n, int &Cmin, int &gttu, int &S, int x[])
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		daxet[i] = 0;
	}
	Cmin = 456;//quang duong nho nhat giua hai thanh pho
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (Cmin > C[i][j])
				Cmin = C[i][j];//cap nhat cho Cmin
		}
	}
	S = 0;//tong quang duong luc dau
	gttu = 456;//gia tri toi uu f*
	x[0] = 0;//xuat phat tu dinh 1
}

void Try(int i, int C[][5], int n, int x[], int S, int Cmin, int &gttu)
{
	int j, tong, g;

	for (j = 1; j < n; j++)
	{
		if (!daxet[j])
		{
			x[i] = j;
			daxet[j] = 1;
			S = S + C[x[i - 1]][x[i]];// quang duong
			if (i == n-1)
			{
				tong = S + C[x[n-1]][x[0]];// tong chi phi ca quay ve dinh dau tien
				if (tong < gttu)
				{
					for (int i = 0; i < 5; i++)
					{
						cout << x[i] + 1;
					}
					
					gttu = tong;
					cout << "\n" << tong << endl;
				}

			}
			else
			{
				g = S + (n - i + 1) * Cmin; //danh gia lai can
				if (g < gttu)
					Try(i + 1, C, 5, x, S, Cmin, gttu);				
			}
			S = S - C[x[i - 1]][x[i]];
			daxet[j] = 0;
		}
		
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int C[5][5] = { {  456, 3, 14, 18, 5 }, {  3, 456, 4, 22, 10 }, {  17, 9, 456, 16, 4 }, {  6, 2, 7, 456, 12 }, {  9, 15, 11, 5, 456 } };
	int x[50], Cmin, gttu, S;
	KhoiTao(C, 5, Cmin, gttu, S, x);
	Try(1, C, 5, x, S, Cmin, gttu);
	
	getchar();
	return 0;
}


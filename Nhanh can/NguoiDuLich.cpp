#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;

int daxet[50];

void KhoiTao (int C[][6], int n, int Cmin, int gttu, int S, int x[])
{
	int i,j;
	for (i = 1 ; i <= n ; i ++)
	{
		daxet[i]=0;
	}
	Cmin = 456;//quang duong nho nhat giua hai thanh pho
	for (i = 1; i <= n ; i++ )
	{
		for (j = 1; j <= n; j++)
		{
			if (Cmin > C[i][j])
				Cmin = C[i][j];//cap nhat cho Cmin
		}
	}
	S = 0;//tong quang duong luc dau
	gttu = 0;//gia tri toi uu f*
	x[1] = 1;//xuat phat tu dinh 1
}

void Try(int i, int C[][6], int n, int x[], int S, int Cmin, int gttu)
{
	int j, tong, g;
	for (j = 2; j <= n; j++)
	{
		if (! daxet[j])
		{
			x[i] = j;
			daxet[j] = 1;
			S = S + C[x[i-1]][x[i]];// quang duong
			if (i == n)
			{
				tong = S + C[x[n]][x[1]];// tong chi phi ca quay ve dinh dau tien
				if (tong < gttu)
				{
					gttu = tong;
				}
			}
		}
		else
		{
			g = S + (n - i + 1) * Cmin; //danh gia lai can
			if (g < gttu)
				Try(i + 1, C, 6, x, S, Cmin, gttu);
			daxet[j] =0;
		}
	}
}

int main ()
{
	int C[6][6]={{0, 456, 3, 14, 18, 5},{0, 3, 456, 4, 22, 10},{0, 17, 9, 456, 16, 4},{0, 6, 2, 7, 456, 12},{0, 9, 15, 11, 5, 456}};
	int x[50], n, Cmin, gttu, S;
	KhoiTao(C, 6, Cmin, gttu, S, x);
	Try(1, C, 6, x, S, Cmin, gttu);
	getch();
	return 1;
}

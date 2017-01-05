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
	n = 10 + rand() % (15-10+1);
	dau = rand() % n;
	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i == j)
			{
				a[i][j] = 0;
			}
			else
			{
				a[i][j] = a[j][i] = 1 + rand() % (456 -1 + 1);
			}
		}
	}
	cout << n << endl;
	cout << dau << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}


void Output(int tour[],int dem, int n, int cost)
{
	if (dem==n)
	{
		cout << "Do dai quang duong: " << cost << endl;
		cout << "Duong di: ";
		for (int j = 0; j<n; j++)
			cout << tour[j]  << "-->";
		cout << tour[0] ;
	}
	else
	{
		cout << "KHong co duong di thoa man yeu cau" << endl;
		cout << "Do dai quang duong: " << cost << endl;
		cout << "Duong di: ";
		for (int j = 0; j<=dem; j++)
		{		
			cout << tour[j]  << "-->";
		}			
	}			
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
	w = ddau;
	i = 0;
	tour[i] = v; //Dua v vao chu trinh daxet[v] = 1; //Dinh v da duoc xet
	daxet[v] = 1;
	int dem = 0;
	while (i <n)
	{
		mini = 456;
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
		if (i < n - 1 && mini < 456)
			cost += mini;
		cout << cost << endl;
		i++;
		if (v != tour[i - 1])
		{
			tour[i] = v;
			dem++;
			daxet[v] = 1;
		}
		else
			break;		
	}
	if (dem < n - 1)
	{
		cost = cost;
	}
	else
	{
		if (a[v][ddau]<456)
		{
			cost += a[v][ddau];
			dem++;
		}
	}		
	Output(tour, dem, n, cost);
}

int main()
{
	int a[50][50], n, dau;
	Input(a, n, dau);
	GTS(a, n, dau);
	getch();
	return 1;
}

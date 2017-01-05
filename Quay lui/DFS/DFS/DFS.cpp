// DFS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>
#include<fstream>
#include<iostream>
#include <stdlib.h>
#include<stack>
using namespace std;
int daxet[50];
/*int truoc[50];
void Xuat(int s, int t, int truoc[])
{
	cout << t + 1 << "<--";
	int j = t;
	while (truoc[j] != s)
	{
		cout << truoc[j] + 1 << "<--";
		j = truoc[j];
	}
	cout << s + 1 << endl;
}
void DFS(int s, int t, int a[][7], int n)
{
	int u;

	daxet[s] = 1;
	for (u = 0; u<n; u++)
	{
		if (a[s][u] && !daxet[u])
		{
			truoc[u] = s;
			daxet[s] = 1;
			if (u == t)
			{
				Xuat(0, 3, truoc);
			}
			else
				DFS(u, t, a, n);
			daxet[u] = 0;
		}
	}
}
*/
/*void DFS(int a[][7], int n, int s, int t)
{
	int stack[50];
	int top = 0, u;
	daxet[s] = 1;
	stack[top] = s;
	while (s != t)
	{
		for (u = 0; u < n; u++)
		{
			if (a[s][u] && !daxet[u])
			{
				top++;
				stack[top] = u;
				s = u;
				daxet[u] = 1;
			}
		}
	}
	for (int j = top; j >= 0; j--)
	{
		cout << stack[j]+1 << "<--";
	}
}*/
class dt
{
public:
	int n;
	int A[100][100];
	int LoadFile(char *fn);
	int DFS(int s, int f);
	void inkq(int *, int, int);
	void Out();
};
void dt::inkq(int *sign, int s, int f)
{
	if (sign[f] == s) printf("\n%d->%d", s, f);
	else
	{
		inkq(sign, s, sign[f]);
		printf("->%d", f);
	}
}
int dt::DFS(int s, int f)
{
	stack<int>S;
	int *sign = new int[n + 2];
	int u, v, i;
	for (i = 1; i <= n; i++) sign[i] = 0;
	S.push(s);
	sign[s] = 1;
	while (!S.empty())
	{
		u = S.top();
		S.pop();
		for (v = 1; v <= n; v++)
			if (A[u][v] == 1 && sign[v] == 0)
			{
				S.push(v);
				sign[v] = u;
				if (v == f) { inkq(sign, s, f); return 1; }
			}
	}
	return 0;
}
void dt::Out()
{
	printf("\nDo thi tu file\n");
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			printf("%4d", A[i][j]);
		printf("\n");
	}
}
int dt::LoadFile(char *fn)
{
	FILE *f;
	fopen_s(&f,"graph.txt", "r");
	if (f == NULL) return 0;
	fscanf_s(f, "%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			int t;
			fscanf_s(f, "%d", &t);
			A[i][j] = t;
		}
	fclose(f);
	return 1;
}

int _tmain(int argc, _TCHAR* argv[])
{
	/*dt g;
	g.A= {{ 0, 0, 0, 1, 0, 1, 1 }, { 0, 0, 1, 1, 0, 0, 0 }, { 0, 1, 0, 1, 0, 1, 0 }, { 1, 0, 1, 0, 0, 0, 0 }, { 0, 0, 0, 0, 1, 1, 0 }, { 1, 0, 0, 0, 1, 0, 0 }, { 1, 0, 0, 1, 0, 0, 0 }};
	for (int i = 0; i<7; i++)
	{
		daxet[i] = 0;
		//truoc[i] = 1;
	}
	g.DFS(7, 1, 4);*/
	dt G;
	int f, s;
	G.LoadFile("graph.txt");
	G.Out();
	do
	{
		printf("\n\nNhap dinh xuat phat s : ");
		scanf_s("%d", &s);
		printf("Nhap dinh ket thuc f : ");
		scanf_s("%d", &f);
		if (G.DFS(s, f));//printf("Co duong di tu %d den %d",s,f);
		else printf("Khong co duong di tu %d den %d", s, f);
	} while (s);

	getchar();
	return 1;

}


#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;

int x[50], n, daxet[50];

void Try(int i)
{
	for (int j = 0; j <= 1; j++)
	{
			x[i] = j;
			daxet[j] = 1;
			if (i == n)
			{
				for (int k = 1; k <= n; k++)
				{
					cout << x[k];
				}
				cout << endl;
			}
			else
				Try(i + 1);
	}
}

int main()
{
	int i;
	n = 5;
//	for (i = 0; i <= 1; i++)
//	{
//		daxet[i] = 0;
//	}
	Try (1);
	getch();
	return 1;
}

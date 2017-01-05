// LietKeHoanVi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;

int b[50],a[50];;

void Try(int i)
{
	int j;
	for (j = 1; j <= 4; j++)
	{
		if (b[j]==1)
		{
			a[i] = j;
			b[j] = 0;
			if (i < 4)
				Try(i + 1);
			else
			{
				for (int k = 1; k <=4; k++)
					cout << a[k];
				cout << endl;
			}
			b[j] = 1;
		}
		
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	
	for (int i = 0; i<5; i++)
	{
		b[i] = 1;
	}
	
	Try(1);
	getchar();
	return 1;
}


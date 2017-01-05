#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;

int x[50], S, Gttu, TL, n, m;//c la gia tri tu, w la khoi luong tui, x la so luong moi do vat, S tong gia tri mang di,gttu la gia tri toi uu
int w[5] = {0, 5, 3, 2, 4};
int	c[5] = {0, 10, 5, 3, 6};
void Init()
{
	int i;
	for (i = 1; i <= n; i++)
	{
		x[i] = 0;
	}
	S = 0;
	TL = 0;
	Gttu = 0;
}

void Try(int i)
{
	int j, t, g;
	t = (int) ((m-TL) / w[i]);// gioi han khoi luong cua tui khi lay them vat i
	for (j = t; j >= 0; j--)
	{
		x[i] = j;
		TL = TL + w[i] * x[i]; // trong luon tui thu dc sau khi lay doo vat i voi so luong x[i]
		S = S + c[i] * x[i]; //gia tri tui thu duoc sau khi lay do vat i voi so luong x[i]
		if ( i == n) //cap nhat gia tri toi uu
		{
			if (S > Gttu)
			{
				Gttu = S;
				for (int k = 1; k <= n; k++)
				{
					cout << x[k] << " ";
				}
				cout << "\n" << TL << endl;
				cout << S;
			}
		}
		else
		{
			g = S + c[i + 1] * (m - TL) / w[i + 1];//danh gia can
			if ( g > Gttu)
			{
				Try (i + 1);
			}	
		}
		TL = TL - w[i] * x[i];
		S = S - c[i] * x[i];
	}	
}

int main()
{
	n = 4;
	m= 8;
	Try(1);
	getch();
	return 0;
}

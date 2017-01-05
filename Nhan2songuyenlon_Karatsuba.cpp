#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<math.h>
using namespace std;
int DemChuSo(int n, int &dem)
{
	if (n < 10)	return (dem+1);
	else {
		dem++;
		return(DemChuSo(n/10, dem));
	}
}
int PhanBenTrai(int &n, int dem)
{
	return n/pow(10,dem);
}
int PhanBenPhai(int &n, int dem)
{
	int i = pow(10,dem);
	return n % i;
}
int Karatsuba(int x, int y)
{
	int dem1=0,dem2=0;
	long int a, b,c,d,U,V,W;
	int dem = max(DemChuSo(x,dem1),DemChuSo(y,dem2));
	if (dem <= 1)
	{
		return x*y;
	}
		
	dem= dem/2 + dem%2;
	
		a = PhanBenTrai(x,dem);
		cout<<"a "<<a<<endl;
		b = PhanBenPhai(x,dem);
		cout<<"b "<<b<<endl;
		c= PhanBenTrai(y,dem);
		cout<<"c "<<c<<endl;
		d=PhanBenPhai(y,dem);
		cout<<"d "<<d<<endl;
		U = Karatsuba(a,c);
		V=Karatsuba(b,d);
		W=Karatsuba(a+b,c+d);
		return U*pow(10,2*dem)+(W-U-V)*pow(10,dem)+V;
	
}
int main()
{
	long int x= 13356;
	long int y = 235;
	cout<< Karatsuba(x,y);
	getch();
	return 1;
}

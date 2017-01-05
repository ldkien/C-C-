#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;
void Swap(int &a, int &b)
{
	int temp =a;
	a = b;
	b = temp;
}
/*void Sort(int *doVat, int *giaTri, int *kl, int n)
{
 	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j <= n-1; j++)
			if (giaTri[i]<giaTri[j])
			{
				Swap(doVat[i], doVat[j]);
				Swap(giaTri[i], giaTri[j]);
				Swap(kl[i], kl[j]);
			}
}
void LayDoVat(int doVat[], int giaTri[], int kl[], int n, int b)// b la trong luong toi da cua tui
{
 	int i, tongKL = 0, tongGT=0;
 	for(i = 0; i < n; i ++)
 	{
 		if(kl[i]<=(b-tongKL))
 			{
 				cout<<"Lay do vat "<<doVat[i]<<endl;
 				tongKL += kl[i];
 				tongGT += giaTri[i];
			}
 	}
 	cout<<"Tong khoi luong "<<tongKL<<endl;
 	cout<<"Tong gia tri "<<tongGT<<endl;
}
*/
void Sort(int *doVat, int *giaTri, int *kl, int n)
{
 	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j <= n-1; j++)
			if ((giaTri[i]/kl[i])<(giaTri[j]/kl[j]))
			{
				Swap(doVat[i], doVat[j]);
				Swap(giaTri[i], giaTri[j]);
				Swap(kl[i], kl[j]);
			}
}
void LayDoVat(int doVat[], int giaTri[], int kl[], int n, int b)// b la trong luong toi da cua tui
{
 	int i, tongKL = 0, tongGT=0;
 	for(i = 0; i < n; i ++)
 	{
 		if(kl[i]<=(b-tongKL))
 			{
 				cout<<"Lay do vat "<<doVat[i]<<endl;
 				tongKL += kl[i];
 				tongGT += giaTri[i];
			}
 	}
 	cout<<"Tong khoi luong "<<tongKL<<endl;
 	cout<<"Tong gia tri "<<tongGT<<endl;
}
int main()
{
	int doVat[8] = 	{1, 2, 3, 4, 5, 6, 8, 8};
	int giaTri[8] = {10, 6, 15, 9, 3, 5, 2, 14};
	int kl[8] = {5, 4, 9, 2, 3, 1, 7, 6};
	int b=10;
	Sort(doVat, giaTri, kl, 8);
	for(int i=0;i<8;i++)
	{
		cout<<doVat[i]<<" "<<giaTri[i]<<" "<<kl[i]<<endl;

	}
	LayDoVat(doVat, giaTri, kl, 8, b);
	getch();
	return 1;
}

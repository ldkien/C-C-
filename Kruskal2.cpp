#include<conio.h>
#include<stdio.h>
int min2(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}
 void Krusta(int a[][7],int n)
 {
 	int D[50],daxet[50],min,m=0,k,h;
 	//-khoi tao-
 	for(int i=0;i<n;i++)
 	{
 		daxet[i]=0;//chua dinh nao duoc xet
 		D[i]=i;//luc dau cac canh thuoc thanh phan lien thong i
	}


	do
	{
		min=456;
		//-cap thanh thanh phan liên thông-
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{				
				if((a[i][j]>0)&&(a[i][j]<min)&&D[i]!=D[j])//neu canh nho nhat va khac thanh phan lien thông
				{
					min=a[i][j];//cap nhat lai gai tri min
					k=j;
					h=i;				
				}				
			}
			
		}
		if(D[h]!=D[k])//neu khac thanh phân liên thông thi gan chúng vào cùng 1 thanh phân liên thông voi nhau
			{
				int temp = D[h];
				for( int l=0; l<n; l++)
              		if(temp==D[l])
              			D[l]=D[k];
			}
		printf("%d %d\n",h+1,k+1);//xuat ra cay khung nho nhat
		m++;
	}while(m<n-1);
	//printf("%d %d",m,k);
 }
 int main()
 {
 	int a[7][7]={{0,1,456,4,456,456,456},{1,0,2,6,10,456,456},{456,2,0,456,4,5,456},{4,6,456,0,3,456,4},{456,10,4,3,0,8,7},{456,456,5,456,0,8,3},{456,456,456,4,7,3,456}};
	Krusta(a,7);
	getch();
	return 1;
 }

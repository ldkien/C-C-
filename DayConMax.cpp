#include<stdio.h>
#include<conio.h>
#include<math.h>
int max3(int a,int b,int c)
{
	int d[3];
	d[0]=a;
	d[1]=b;
	d[2]=c;
	int max=d[1];
	for(int i=0;i<3;i++)
	{
		if(d[i]>=max)
			max=d[i];
	}
	return max;
}
int max2(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}
//tim max bên phía bên trái
int MaxLeftVecto(int *a,int i,int j)// p dùng thêm de dánh dau vi tri
{
	int k,maxsum=-452547,s=0;
	for(k=j;k>=i;k--)
	{
		s=s+a[k];
		maxsum=max2(s,maxsum);
	}
	return maxsum;		
}
int MaxRightVecto(int *a,int i,int j)// q dung de danh dau vi tri
{
	int k,maxsum=-452547,s=0;
	for(k=i;k<=j;k++)
	{
		s=s+a[k];
		maxsum=max2(s,maxsum);
	}
	return maxsum;		
}
int MaxSub(int *a,int i,int j)
{
	int m,wl,wr,wm,max,p=0,q=0;
	if (i ==j) return a[i];
	else
	{
		m= (i+j)/2;
		wl= MaxSub(a, i, m);
		wr= MaxSub(a, m+1, j);	
		wm= MaxLeftVecto(a, i, m) + MaxRightVecto(a, m+1, j);				
		max=max3(wl, wr, wm);
	}		
	return max;
}


int main()
{
//	int a[10]={-98,54,67, -65,-9,-78,-65,-21,-556,67};
	int a[16] = {4, 6, -2, 8, 2, 9, -6, -15, 4, 1, 9, -3, -3, 1, 5, 6};
	printf("%d\n",MaxSub(a,0,15));
	getch();
	return 0;
}

#include<stdio.h>
#include<conio.h>
#include <stdlib.h>

int main()
{
	int *p;
	int n,k;
	printf("Nhap so phan tu cua mang:");
	scanf("%d",&n);
	p=(int *) malloc(n*sizeof(int));
	printf("Nhap tung phan tu cua mang:\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",p+i);
	}
	for(int i=0;i<n;i++)
	{
		k=i;
		for(int j=i+1;j<=n;j++)
			{
				if(*(p+j)<=*(p+k))
					k=j;
			}
		if(k!=i)
		{
			int temp;
			temp=*(p+i);
			*(p+i)=*(p+k);
			*(p+k)=temp;
			
		}
	}	
	for(int i=0;i<n;i++)
	{
		printf("%d",*(p+i));
	}
	free(p);
	
	getch();
	return 1;
}

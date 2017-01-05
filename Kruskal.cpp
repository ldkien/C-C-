#include<stdio.h>
#include<conio.h>

typedef struct Egde{
	int x,y;
};
void Xuat(Egde*L,int n,int Sum)
{
	 printf("%d\n",Sum);
    for(int i =0; i<n-1; i++)
      printf("%d - %d\n",L[i].x+1,L[i].y+1);
}
void Kruskal(int A[][7], int n) {
    int *D = new int[n];
    Egde *L = new Egde[n-1];
    int i;
    int min = 456, Dem = 0, Sum = 0, T = 0, Temp;
    for(int i=0; i<n; i++)
        D[i] = 0;
        do{
              min = 456;
              for( i=0; i<n; i++)
                   for(int j=0; j<n; j++)
                        if(A[i][j]>0 && min>A[i][j]&& !(D[i]!=0 && D[i]==D[j])) {
                               min = A[i][j];
                               L[Dem].x = i;
                               L[Dem].y = j;
                         }
             if(D[L[Dem].x] ==0 && D[L[Dem].y] == 0){
             T++;
             D[L[Dem].x] = D[L[Dem].y] = T;
       }
       if(D[L[Dem].x] == 0 && D[L[Dem].y] != 0){
        D[L[Dem].x] = D[L[Dem].y];
    }
    if(D[L[Dem].x] != 0 && D[L[Dem].y] == 0){
    D[L[Dem].y] = D[L[Dem].x];
  }
   if(D[L[Dem].x] != D[L[Dem].y] && D[L[Dem].y]!=0) {
        Temp = D[L[Dem].x];
         for( i=0; i<n; i++)
              if(Temp==D[i])
              D[i]=D[L[Dem].y];
     }
     Sum+=min;
     Dem++;
    } while(Dem<n-1);
    Xuat(L,n,Sum);
  
   }



int main()
{
	int a[7][7]={{0,1,456,4,456,456,456},{1,0,2,6,10,456,456},{456,2,0,456,4,5,456},{4,6,456,0,3,456,4},{456,10,4,3,0,8,7},{456,456,5,456,0,8,3},{456,456,456,4,7,3,456}};
	Kruskal(a,7);
	getch();
	return 1;
}

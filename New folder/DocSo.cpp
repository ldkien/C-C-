#include<stdio.h>
#include<conio.h>
#include<string.h>
char kq[50]="";
char *Doc3So(int a,int &flag)
{
	kq[0]=0;
	char chu[10][5]={" ","mot","hai","ba","bon","nam","sau","bay","tam","chin"};
	int tram,chuc,donvi;
	tram=a/100;
	chuc=(a%100)/10;
	donvi=a%10;
	if(tram==0&&chuc==0&&donvi==0) return kq;
	if(flag>0)
	{
		if(tram==0)
			strcat(kq," khong tram");
	}
	if(tram>0)
	{
	
		strcat(kq,chu[tram]);
		strcat(kq," tram ");
	}
	if(chuc>0)
	{
		if(chuc==1)
		{
			strcat(kq," muoi ");
		}
		else
		{
		
			strcat(kq,chu[chuc]);
			strcat(kq," muoi ");
		}
	}
	if(donvi>0)
	{
		if(chuc==0&&tram!=0&&flag==0)
			strcat(kq," linh ");
		if(chuc==0&&flag>0)
			strcat(kq," linh ");
		if(donvi==1)
			strcat(kq," mot ");
		else if(donvi==5 &&(chuc!=0 && tram!=0))
			strcat(kq," lam ");
		else if(donvi==5 && (chuc==0 && tram==0))
			strcat(kq,"nam");
		else
			strcat(kq,chu[donvi]);					
	}
	flag++;
	return kq;
}
void *ChuanHoa(char s[])
{
	int i;
	while(s[0]==' ')
	{	
		strcpy(&s[0],&s[1]);		
	}
	while(s[strlen(s)-1]==' ')
		strcpy(&s[strlen(s)-1],&s[strlen(s)]);
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]==' '&&s[i+1]==' ')
		{
			strcpy(&s[i],&s[i+1]);
			i--;
		}
	}
}
int main()
{
	unsigned long int n=4294967293;
	if(n>4294967294||n<0)
	{
		printf("Loi");
		return 0;
	}
	int donvi,ngan,trieu,ty;
	int flag=0;
	char s[150]=" ";
	donvi=n%1000;
	n=n/1000;
	ngan=n%1000;
	n=n/1000;
	trieu=n%1000;
	ty=n/1000;	

		if(ty>0)
		{			
			strcat(s,Doc3So(ty,flag));
			strcat(s," ty ");		
		}
		if(trieu>0)
		{		
			strcat(s,Doc3So(trieu,flag));
			strcat(s," trieu ");
		}
					
		if(ngan>0)
		{			
			strcat(s,Doc3So(ngan,flag));
			strcat(s," ngan ");			
		}
			
		
		if(donvi>0)
		{	
			strcat(s,Doc3So(donvi,flag));			
		}
	ChuanHoa(s);
	printf("%s",s);
	getch();
	return 1;
}

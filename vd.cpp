#include <stdio.h>
#include <conio.h>
#include <string.h>
int main()
{
	int i,j,x=1,k,t,q,ls,ls1,ls2,lsn,dem,th3=0,tim=0,n=0;
	char s[200], s1[200], s2[200], sn[200];
	printf("Nhap chuoi s:\n");	gets(s);
	printf("Chuoi can tim:\n");	gets(s1);
	printf("Thay the bang chuoi:\n");	gets(s2);
	ls=strlen(s); ls1=strlen(s1); ls2=strlen(s2);
tt:
	{
	for (; x<=200; x++)
		{ dem=0; k=x-1;
	for (i=0; i<ls1; i++, k++)
			if (s1[i]==s[k])	dem++;
	if (dem==ls1)
		{
			tim++;
			if (ls2==ls1)
				{for (j=0, q=k-ls1; j<ls2; q++, j++) s[q]=s2[j];
			x=k-ls1+ls2+1;
			goto tt;
			}
			
			else if (ls2<ls1)
				{for (j=1; j<=ls1-ls2; j++)
					for (t = k-ls1+ls2; t<ls; t++)	s[t] = s[t+1];
				for (t=0, q=k-ls1; t<ls2; q++, t++) s[q]=s2[t];
				x=k-ls1+ls2+1;
				goto tt;
				}
			else
			{
				th3++; n++;
				lsn=ls+n*(ls2-ls1);
			for (i=0, j=0; i<k-ls1; i++, j++) sn[j]=s[i];
			for (i=0, j=k-ls1; i<ls2; i++, j++)  sn[j]=s2[i];
			for (i=k, j=k-ls1+ls2; i<lsn; i++, j++) sn[j]=s[i];
			for (i=0; i<lsn; i++) s[i]=sn[i];
			x=k-ls1+ls2+1;
			goto tt;
			}}}
	}
	if (tim==0)
		printf("\nKhong tim duoc chuoi yeu cau\a");
	else
		{
		if (th3==0)	{ printf("\nKet qua:\a\n"); puts(s);}
		else
		{ printf("\nKet qua:\a\n"); for (i=0; i<lsn; i++) printf("%c", s[i]);}
		}
	getch();
}

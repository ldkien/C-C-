#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<string>
#include<string.h>
#include <ctype.h>
using namespace std;
int main()
{
	char c[]="anh xin loi nhieu nhieu lam";
	for(int i=0;i<strlen(c);i++)
	{
		if(c[i]!=' ')
		{
			c[i]=toupper( c[i] );
			cout<<i+35<<". ";
			puts(c);
			c[i]=tolower(c[i]); 
			cout<<"\n";
		}
	}

	getch();
	return 1;
}

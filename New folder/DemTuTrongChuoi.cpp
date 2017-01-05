#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
#include <stdlib.h>
using namespace std;
void Replace(char *s1, char *s2, char *s3, int pos)
{
    int n1 = strlen(s1), n2 = strlen(s2), n3 = strlen(s3), i;
    if (n3>n2)
    {
        int t = n3-n2;
        for (i=n1-1; i>= pos+n2; i--) s1[i+t] = s1[i];
        s1[n1+t] = '\0';
    }
    else if (n3<n2)
    {
        int t = n2-n3;
        for (i=pos+n3; i < n1-t; i++) s1[i] = s1[i+t];
        s1[n1-t] = '\0';
    }
 
    for (i=0; i<n3; i++) s1[pos+i] = s3[i];
}
int main()
{
	string line;
	char data[50];
	//data="con meo con can con cho con";
	gets(data);
	/*ifstream fi;
	fi.open("anhviet.txt");
	if(fi.fail())
	{
		cout<<"No success!";
		exit(1);
	}
	else
	{
		while(!fi.eof())
		{
			getline(fi,line);
			data+=line;
		}
		cout<<data<<endl;
		fi.close();		
	}*/
	cout<<data<<endl;
	char t[50];
	cout<<"Nhap tu can dem:";
	fflush(stdin);
	//getline(cin,t);
	gets(t);	
	string temp;
	temp = (char *) malloc( 10 * sizeof( char ));
	int dem=0;
	int i,j,l=0;
	int p[50];//vi tri bat sau cua tu can tim;
	
	for(i=0;i<strlen(data);i++)
	{
		if(data[i]==t[0])
		{
			temp="";
			for(j=i;j<i+strlen(t);j++)
			{
				//temp+=data[j];
				
				fflush(stdin);
				temp+=data[j];
				fflush(stdin);
				
			}		
			if(temp==t)
			{
				dem++;
				p[l++]=i;//l=dem la so tu xuat hien
			}
				
			
		}
			
	}
	cout<<"so tu xuat hien: "<<dem<<endl;
	for(int k=0;k<l;k++)
	{
		cout<<k<<" "<<p[k]<<endl;
	}
	char tt[50];
	cout<<"nhap chuoi muon thay the:";
	//getline(cin,tt);
	gets(tt);
	int k;
	int d=0;
	if(strlen(t)==strlen(tt))
	{
			for(int h=0;h<strlen(data);h++)
			{
				for(k=0;k<l;k++)
				{
					if(h==p[k])
					{
						for(int m=h;m<h+strlen(tt);m++)
						{
							data[m]=tt[d++];
						}
						d=0;
					}
				}
			
			}
	}
	int v;
	if(strlen(t)<strlen(tt))
	{
		int n=strlen(data);
		for(int h=0;h<n;h++)
		{
				for(k=0;k<l;k++)
				{
					if(h==p[k])
					{
						v= strlen(tt)-strlen(t);
						for(i=strlen(data)-1;i>=h+strlen(t);i--)
							data[i+v]=data[i];
						data[n+v]='\0';
						for(int m=h;m<h+strlen(tt);m++)
						{
							data[m]=tt[d++];
						}
						n=strlen(data);
						p[k+1]=p[k+1]+v;					
						d=0;				
					}
				}
		}
	}
	cout<<data;
	getch();
	return 1;
}

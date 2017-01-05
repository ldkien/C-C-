#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<fstream>
#include<stdlib.h>
void Replace(char *s1, char *s2, char *s3, int pos)
{
    int n1 = strlen(s1), n2 = strlen(s2), n3 = strlen(s3), i;
    if (n3>n2)//neu do dai chuoi thay the lon hon do dai chuoi bi thay the thì phai dan do dai chuoi ban dau
    {
        int t = n3-n2;
        for (i=n1-1; i>= pos+n2; i--) s1[i+t] = s1[i];//dan do dai di t don vi
        s1[n1+t] = '\0';
    }
    else if (n3<n2)//neu do dai chuoi thay the nho hon do dai chuoi bi thay the thì phai co do dai chuoi ban dau
    {
        int t = n2-n3;
        for (i=pos+n3; i < n1-t; i++) s1[i] = s1[i+t];//co do dai t don vi
        s1[n1-t] = '\0';
    }
 
    for (i=0; i<n3; i++) s1[pos+i] = s3[i];//thay the chuoi
}
 
void Process(char *s1, char *s2, char *s3)//s1 la chuoi ban dau,s2 là chuoi can thay the,s3 la chuoi thay the
{
    int n1 = strlen(s1), n2 = strlen(s2), n3 = strlen(s3), i=0;
    while (i<n1)//duyet den het chuoi
    {
        if (s1[i]==s2[0])//tim vi tri trong chuoi s1 =vi tri dau cua chuoi s2
        {
            int ok = 1, j;
            for (j=1; j< n2; j++)// chay het do dai chuoi s2
                if (s1[i+j]!=s2[j])//khac nhau o 1 vi tri=>ko bang nhau=>break
                {
                    ok = 0;
                    break;
                }
            if (ok)//neu chuoi trong s1=s2 bat dau thay the
            {
                Replace(s1,s2,s3,i);
                n1 = strlen(s1);//tinh lai do dai chuoi s1
                i += n3-1;//vi tri cua i cung bi thay doi do do dai s1 thay doi
            }
        }
        i++;
    }
}

int main()
{
    char s1[90000], s2[10], s3[10];
    //s1=(char *) malloc(sizeof(char));
    //strcpy(s1,"con meo con can con cho con");
    FILE *f;
    f=fopen("test.txt","r");
    fflush(stdin);
    //fgets(s1,900,f);
	int i=0;
   	while( fscanf(f,"%c",&s1[i]) != EOF )
   	i++;
    //fclose(f);
	fclose(f);
	puts(s1);
    //Input(s1,f);
    //strcpy(s2,"con");
    //strcpy(s3,"me");
    printf("Nhap tu muon thay the: ");
    gets(s2);
    printf("Nhap tu can thay the: ");
    gets(s3);
    Process(s1,s2,s3);
    puts(s1);
    //printf("%s",s1);
    getch();
    return 1;
}

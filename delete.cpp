#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
using namespace std;
char text[2048];
char text1[2048];
void fun (char *a,int n,char *b)
{
		int i,j;
 for(i=0;i<n;i++){*(b+i)=*(a+i); }
 *(b+i)='\n';
 *(b+i+1)='\0';
}
int main()
{
    int i,j;
	FILE *fp1;
	FILE *fp2;
	 fp1 = fopen("E:\\ÕÅçù\\aa.c","r");
	 fp2 = fopen("E:\\ÕÅçù\\test.c","w");
haha: while(fgets(text,2047,fp1)!=NULL)
		{
			for(i=0;i<=sizeof(text);i++)
		{

			if(text[i]=='/'&&text[i+1]=='/')
				{
				fun(text,i,text1);
				fputs(text1,fp2);
			    break;
				}
			 if(text[i]=='/'&&text[i+1]=='*')
			{   fun(text,i,text1);
			    fputs(text1,fp2);
                 i=i+2;
			    for(;i<=sizeof(text);i++)
				{
					if(text[i]=='*'&&text[i+1]=='/') goto haha;
				
				else
				{    while(fgets(text,2047,fp1)!=NULL)
				{
					for(j=0;j<=sizeof(text);j++)
						if(text[j]=='*'&&text[j+1]=='/')
						goto haha;
				}
				}
				}
			}
			}    
		fun(text,i,text1);
		 fputs(text1,fp2);
	 }
fclose(fp1);
fclose(fp2);
}

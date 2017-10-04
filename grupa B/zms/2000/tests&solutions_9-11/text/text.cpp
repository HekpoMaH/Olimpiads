#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MAXW 1000
int hash(unsigned char* s)
{
	int i=0, sum=0;
	while(s[i]!='\0')  
		sum=(sum+s[i++])%MAXW;
	return sum;
}
int strl(unsigned char *s)
{
  int i=0;while(s[i]!='\0') i++;
  return i;
}
void strcp(unsigned char *d,unsigned char *s)
{
	int i=0;while((d[i]=s[i])!='\0') i++;d[i]='\0';
}
int strcm(unsigned char *a,unsigned char *b)
{
	int i=0;
	while(a[i]==b[i])if(a[i]=='\0') return 0;else i++;
	if(a[i]<b[i]) return -1;else return 1;
}
void main()
{

	unsigned char *dict[MAXW]; int num[MAXW];
	unsigned char *sorted[MAXW];int snum[MAXW];
	unsigned char buffer[30];
	FILE *fin; int l,j,h,novi=0;long tnum=0;

	for(int i=0;i<MAXW;i++){dict[i]=(unsigned char *)NULL;num[i]=0;}
	fin=fopen("text.inp","r");
	while((l=fscanf(fin,"%s", buffer))!= -1)
	{
		h=hash(buffer);
		if(dict[h]==NULL) //niama ia dosega
		{
			dict[h]=(unsigned  char *)malloc(strl(buffer));
			strcp(dict[h],buffer);
			num[h]=1;novi++;
		}
		else if(strcm(dict[h],buffer)==0) num[h]++;//ima ia na hash miasto
		else do
		{
			h=(h+1)%MAXW;
			if(dict[h]==NULL) //niama ia dosega v kolisia
			{
				dict[h]=(unsigned char *)malloc(strl(buffer));
				strcp(dict[h],buffer);
				num[h]=1; novi++;break;
			}
			else if(strcm(dict[h],buffer)==0) //ima ia v kolisia
			{
				num[h]++;break;
			}
		}while(0);
	}
	int k=0;for(i=0;i<MAXW;i++)
		if(dict[i]!=NULL){sorted[k]=dict[i];snum[k++]=num[i];tnum+=num[i];}
	for(i=novi-2;i>=0;i--)
		for(j=0;j<=i;j++)
			if(strcm(sorted[j],sorted[j+1])>0)
			{
				unsigned char *t=sorted[j];sorted[j]=sorted[j+1];sorted[j+1]=t;
				int ti=snum[j];snum[j]=snum[j+1];snum[j+1]=ti;
			}
	char c;int cur=0;i= -1;
	while(cur<=tnum/2) cur+=snum[++i];
	printf("%s\n",sorted[i]);
}

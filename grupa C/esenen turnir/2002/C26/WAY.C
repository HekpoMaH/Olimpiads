#include<stdio.h>

void find(int ind,int  i);
int ind,r,num,a,tmp[100],A,B,j,n,P[50][3],gm[10][10];
int main(void){
int i;

scanf("%d",&n);

if(n==1){ printf("%d\n",1);printf("%d",1);return 0;}
if (n==2) for (i=0;i<=0;i++)   scanf("%d%d%d",&P[i][0],&P[i][1],&P[i][2]);
if (n==3) for (i=0;i<=2;i++)   scanf("%d%d%d",&P[i][0],&P[i][1],&P[i][2]);
if (n==4) for (i=0;i<=5;i++)   scanf("%d%d%d",&P[i][0],&P[i][1],&P[i][2]);
if (n==5) for (i=0;i<=9;i++)   scanf("%d%d%d",&P[i][0],&P[i][1],&P[i][2]);
if (n==6) for (i=0;i<=14;i++)  scanf("%d%d%d",&P[i][0],&P[i][1],&P[i][2]);
if (n==7) for (i=0;i<=20;i++)  scanf("%d%d%d",&P[i][0],&P[i][1],&P[i][2]);
if (n==8) for (i=0;i<=27;i++)  scanf("%d%d%d",&P[i][0],&P[i][1],&P[i][2]);
if (n==9) for (i=0;i<=35;i++)  scanf("%d%d%d",&P[i][0],&P[i][1],&P[i][2]);
if (n==10) for (i=0;i<=41;i++) scanf("%d%d%d",&P[i][0],&P[i][1],&P[i][2]);

scanf("%d%d",&A,&B);


for (i=0;i<=n-1;i++)             /*ako m/u dvata grada ima prqk pat*/
    if (P[i][0]==A)
	if (P[i][1]==B)
		if (P[i][2]==1) { printf("%d\n",2);printf("%d"," ","%d",A,B);return 0;}



for (i=1;i<=n;i++) gm[i-1][0]=i;

ind=1;
for (i=0;i<=n-1;i++)
  {
  for (j=0;j<=42;j++)
	if (P[j][0]==i+1)
		if (P[j][2]==1)
		    {
		    gm[i][ind]=P[j][1];
		    ind++;
		    }
  ind=1;
  }


ind=1;
for(i=0;i<=n-1;i++)
	{
	j=1;
	while (gm[i][j]!=0)
	{
	for(ind=1;ind<=40;ind++)
		if(gm[ gm[i][j]-1 ][ind]==0)
		{
		gm[ gm[i][j]-1 ][ind]=gm[i][0];break;
		}
	j++;
	ind=1;
	}
	}



for (i=0;i<=50;i++){
	if (gm[i][0]==A) ind=i;break;}

r=2;
num=1;
find(ind,1);
if (r==2) printf("%d",0);
return 0;
}



void find(ind,i){
if (gm[ind][i]==B){r=1;printf("%d\n",num);for(a=0;a<=num-1;a++) printf("%d"," ",tmp[a]);}
else
{
i++;
num++;
tmp[num++]=ind;
find(gm[ind][i]);
}

/*for (i=1;i<=9;i++)
if (gm[ind][i]==B)
	else
	{
	num++;
	tmp[num]=ind;
	find(gm[ind][i]);
	}*/
}





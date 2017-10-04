#include<iostream.h>
void main()
{int m[55][3],n,i=0,br=0,p[55],l=1;
cin>>n;
while(m[i][3]-'0'==' ')
{cin>>m[i][0]>>m[i][1]>>m[i][2];br++;i++;};
for(i=0;i<55;i++)
p[i]=0;
for(i=0;i<br-1;i++)
if((m[i][0]==m[br][0])&&(m[i][2]==1)){p[l]=m[i][0];m[br][0]=m[i][1];l++;};
cout<<l<<endl;
for(i=0;i<l;i++)
cout<<p[i]<<" ";
}


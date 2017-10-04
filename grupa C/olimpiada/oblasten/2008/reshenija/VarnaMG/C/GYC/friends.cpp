#include<iostream>
using namespace std;
unsigned a[2][100000];
int main()
{unsigned n,m,i,j,br=1,max=1,p,q;
cin>>n>>m;
for(i=0;i<m;i++)
for(j=0;j<2;j++)
cin>>a[i][j];

for(i=0;i<m-1;i++)
{for(j=i;j<m;j++)
 {if(a[j][0]=a[j+1][0])br++;
  if(br>max)max=br;
  if(a[j][0]!=a[j+1][0])br=0;
  }
}
cout<<br;
return 0;
}   



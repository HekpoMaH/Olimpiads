#include<iostream>
using namespace std;

int m,n,r,k;
int a[101][101];

long long sum;

void RekDiff(int k,int l,int level)
{
   if(level==0)return;

   if(k%2!=l%2){sum+=a[k][l];
                //cout<<"reached "<<a[k][l]<<endl;
                a[k][l]=0;}

   if(k>1)RekDiff(k-1,l,level-1);
   if(l>1)RekDiff(k,l-1,level-1);
   if(k<m)RekDiff(k+1,l,level-1);
   if(l<m)RekDiff(k,l+1,level-1);
}

void RekSame(int k,int l,int level)
{
   if(level==0)return;

   if(k%2==l%2){sum+=a[k][l];
                //cout<<"reached "<<a[k][l]<<endl;
                a[k][l]=0;}

   if(k>1)RekSame(k-1,l,level-1);
   if(l>1)RekSame(k,l-1,level-1);
   if(k<m)RekSame(k+1,l,level-1);
   if(l<m)RekSame(k,l+1,level-1);
}

int main()
{
   int i,j,x,y;

   cin>>m>>n>>r>>k;

   for(i=1;i<=m;i++)
      for(j=1;j<=n;j++)
      {
         a[i][j]=(i-1)*n+j;

         if(a[i][j]==r)
         {x=i;y=j;}
      }

        if(x%2==y%2 && k%2==0) RekSame(x,y,k+1);
   else if(x%2==y%2 && k%2!=0) RekDiff(x,y,k+1);
   else if(x%2!=y%2 && k%2!=0) RekSame(x,y,k+1);
   else if(x%2!=y%2 && k%2==0) RekDiff(x,y,k+1);

   cout<<sum<<endl;
   return 0;
}

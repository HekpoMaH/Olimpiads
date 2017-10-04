#include<iostream>
using namespace std;
long a[100][100],b[100][100];
long n,m,r,k,i,j,g,h,c,br;

void inc()
{
  cin>>n>>m>>r>>k;
  int br=0;
  for(i=0;i<n;i++)
  for(j=0;j<m;j++)
  {
    br++;
    a[i][j]=br;
    if(br==r){g=i;h=j;}
  }
}

void counter()
{
  br=0;
  for(i=0;i<n;i++)
  for(j=0;j<m;j++)
  {
    if(b[i][j]==k){br+=a[i][j];j++;//cout<<a[i][j]<<' ';
    }
  }
}

int main()
{
  inc();

  /*for(i=0;i<n;i++)
  {for(j=0;j<m;j++)
  cout<<a[i][j]<<' ';
  cout<<endl;
  }
*/

  i=g;j=h;
  if(i+1<n)b[i+1][j]=c+1;
  if(i-1>=0)b[i-1][j]=c+1;
  if(j+1<m)b[i][j+1]=c+1;
  if(j-1>=0)b[i][j-1]=c+1;
  c++;


  while(c!=k)
  {
    for(i=0;i<n;i++)
    for(j=0;j<m;j++)
      if(b[i][j]==c){
                    if(i+1<n)b[i+1][j]=c+1;
                    if(i-1>=0)b[i-1][j]=c+1;
                    if(j+1<m)b[i][j+1]=c+1;
                    if(j-1>=0)b[i][j-1]=c+1;


                    }


    c++;
  }
  counter();
  cout<<br<<endl;
  return 0;
}






















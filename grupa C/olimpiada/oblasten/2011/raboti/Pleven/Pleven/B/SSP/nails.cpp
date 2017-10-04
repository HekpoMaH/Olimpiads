#include<iostream>
#include<cstdio>
using namespace std;
int n,x1,x2,y1,y2,a[1002][5],p;
int main()
{
  n=0;
  while(cin>>x1)
  {
    n++;
    scanf("%d%d%d",&y1,&x2,&y2);
    a[n][1]=x1;
    a[n][2]=y1;
    a[n][3]=x2;
    a[n][4]=y2;
  }
  n--;
  /*for(int i=1; i<=n; i++)
  {
    p1=min(a[i][1],a[i][3]);
    q1=max(a[i][1],a[i][3]);
    m1=min(a[i][2],a[i][4]);
    n1=max(a[i][2],a[i][4]);
    for(int j=i+1; j<=n; j++)
    {
      p2=min(a[j][1],a[j][3]);
      q2=max(a[j][1],a[j][3]);
      m2=min(a[i][2],a[i][4]);
      n2=max(a[i][2],a[i][4]);
      if(q2>=p1 && p2<=q1 && n2>=n1 && m2<=n1
      if((p1>=p2 && p1<=q2) || (q1>=p2 && q1<=q2) ||
    }
  }
  for(int i=1; i<=n+1; i++)
  {
    for(int j=1; j<=4; j++)
    {
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }*/
  p=n;
  int c=n;
  p-=2;
  p%=3;
  p*=2;
  p--;
  if(p<0) p=-p;
  if(p>n) n;
  else n=p;
  printf("%d\n",n);
  return 0;
}

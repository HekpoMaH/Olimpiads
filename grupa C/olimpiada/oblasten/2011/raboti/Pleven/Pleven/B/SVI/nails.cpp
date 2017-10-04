#include<iostream>
#include<cmath>
#include<queue>
#include<cstdio>
#include<algorithm>
using namespace std;
long a1,b1,c1,x11,y11,x21,y21,r,br,ans,a[1024][8],used[1024];
queue <long> q;
long check (long p)
{
  long a2,b2,c2,d1,d2,d3,x3,y3,fl=0;
  double m1,m2,m3,m4,x,y;
  a2=a[p][2]-a[p][4];
  b2=a[p][3]-a[p][1];
  c2=a[p][1]*a[p][4]-a[p][3]*a[p][2];
  if (a1*b2!=b1*a2)
  {
     d1=a1*b2-a2*b1;
     d2=b1*c2-c1*b2;
     d3=a2*c1-c2*a1;
     x=(double)d2/d1;
     y=(double)d3/d1;
     m1=(double)min(a[r][1],a[r][3]);
     m2=(double)max(a[r][1],a[r][3]);
     m3=(double)min(a[r][2],a[r][4]);
     m4=(double)max(a[r][2],a[r][4]);
     if (x>=m1 && x<=m2 && y>=m3 && y<=m4) {fl++;}
     m1=(double)min(a[p][1],a[p][3]);
     m2=(double)max(a[p][1],a[p][3]);
     m3=(double)min(a[p][2],a[p][4]);
     m4=(double)max(a[p][2],a[p][4]);
     if (x>=m1 && x<=m2 && y>=m3 && y<=m4) {fl++;}
     if (fl==2) {return 1;}
     else {return 0;}
  }
  else {return 0;}
}
int main()
{
  while(cin>>x11>>y11>>x21>>y21)
  {
     br++;
     a[br][1]=x11;
     a[br][2]=y11;
     a[br][3]=x21;
     a[br][4]=y21;
  }
  q.push(br);
  while(!q.empty())
  {
     r=q.front();
     q.pop();
     a1=a[r][2]-a[r][4];
     b1=a[r][3]-a[r][1];
     c1=a[r][1]*a[r][4]-a[r][3]*a[r][2];
     for(long i=1;i<=br-1;i++)
     {
        if (used[i]==1) {continue;}
        if (check(i)==1) {ans++;q.push(i);used[i]=1;}
     }
  }
  ans=br-1-ans;
  cout<<ans<<endl;
  return 0;
}
/*
5 2 8 2
3 4 3 1
7 1 6 4
3 3 0 3
6 3 1 1

1 3 4 1
5 6 1 8
7 1 3 5
2 3 3 5
0 8 1 9
9 3 4 8
5 4 5 10
9 9 10 6
9 7 4 2

4 4 3 6
4 4 4 6
4 4 5 6
4 4 2 5
4 4 6 5
4 4 2 4
4 4 6 4
4 4 2 3
4 4 6 3
4 4 3 2
4 4 5 2
4 4 4 1

4 4 4 6
4 4 3 6
4 4 5 6
4 4 2 5
4 4 6 5
4 4 2 4
4 4 6 4
4 4 2 3
4 4 6 3
4 4 3 2
4 4 5 2
4 6 4 1

1 1 1 3
2 1 2 5
3 4 3 2
2 5 0 7
3 5 3 7
2 2 1 2
1 4 5 4
0 6 4 6
3 5 4 5
2 7 4 5
5 1 2 1
5 0 8 3
6 5 5 6
7 6 6 5
5 3 7 3
8 1 5 5
6 5 6 2
*/

#include <iostream>
#include <cstdio>
#include<cmath>
using namespace std;
int xs[16],ys[16],used[16];
int x,y,n,minmoves=1000000000;

int dist(int x,int y,int x1,int y1)
{
     return abs((x1-x+y1-y)/2)+abs((x1-x-y1+y)/2);
}
/*
* measures correct dist?
* explores entire possible tree?
*/
void perform(int moves,int num,int count)
{
  //   cout<<moves<<" "<<xs[num]<<" "<<ys[num]<<" "<<count<<endl;

     used[num]=true;

  if(moves>minmoves) return;// impossible

  if(count==n && moves<minmoves)//best curans
  { minmoves=moves; return;}


 // explore unused points
  for(int i=1;i<=n*2;i++)
  {
          if(!(used[i]))
          {
            perform(moves+dist(xs[num],ys[num],xs[i],ys[i]),i,count+1);
            used[i]=false;
          }
  }
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++)
    {
      scanf("%d %d",&x,&y);
      xs[i]=x;
      ys[i]=y;
    }
    perform(0,0,0);
    cout<<minmoves<<endl;
 //  system("pause");
    return 0;
}

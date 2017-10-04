#include<iostream>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
#include<cstdio>
#include<vector>


using namespace std;
#define wait system("pause")
#define pb push_back
#define mp make_pair
#define PII pair<int,int>
#define LOW_BIT(x) (x&(-x))

int n,ans,x,y,a[2001][2001],n1,pointx[16],pointy[16];
bool b[2001][2001];
queue<int> qx,qy;
void wave(int xbeg,int ybeg)
{ int br=0;
  qx.push(xbeg); qy.push(ybeg);
  while(!qx.empty())
  {  if(br==n1)  {  break;}
    int x=qx.front(); int y=qy.front(); qx.pop(); qy.pop();
    if(x!=0 && y!=0 &&a[x-1][y-1]<=0)
    {  if(a[x-1][y-1]==-1) br++;  if(br==n1) { ans=a[x][y]+1; break;}     a[x-1][y-1]=a[x][y]+1; qx.push(x-1); qy.push(y-1);  }

     if(x!=0 && y!=1999 && a[x-1][y+1]<=0)
     {  if(a[x-1][y+1]==-1) br++; if(br==n1) { ans=a[x][y]+1; break;}       a[x-1][y+1]=a[x][y]+1; qx.push(x-1); qy.push(y+1);  }

      if(x!=1999 && y!=0 && a[x+1][y-1]<=0)
       {  if(a[x+1][y-1]==-1) br++;  if(br==n1) { ans=a[x][y]+1; break;}      a[x+1][y-1]=a[x][y]+1; qx.push(x+1); qy.push(y-1);  }

       if(x!=1999 && y!=1999 && a[x+1][y+1]<=0)
        {  if(a[x+1][y+1]==-1) br++;   if(br==n1) { ans=a[x][y]+1; break;}     a[x+1][y+1]=a[x][y]+1; qx.push(x+1); qy.push(y+1);  }

  }

}









int main()
{
  scanf("%d",&n);  n1=n; n<<=1;
  for(int i=1;i<=n;i++)
  {
    scanf("%d%d",&x,&y); x+=1000; y+=1000;   pointx[i]=x; pointy[i]=y; a[x][y]=-1; b[x][y]=true;
  }


 wave(1000,1000);
 printf("%d\n",ans);


return 0;
}
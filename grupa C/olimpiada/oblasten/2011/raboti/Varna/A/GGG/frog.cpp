#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;
int n;
int graph[2003][2003];
int x[8]={ +1 , +1 , -1 , -1 };
int y[8]={ +1 , -1 , +1 , -1 };
int pmax,qmax;
int pointsx[16];
int pointsy[16];
int dist[2003][2003];
int MAX_VALUE=1<<20;
int min3(int a,int b,int c)
{
    int s1=min(a,b);
    int s2=min(b,c);
    return min(s1,s2);
}
void bfs(int startx,int starty)
{
    dist[startx][starty]=1;
    int px,py;
    int movex;
    int movey;
    int i,j;
    queue<int>qx;
    queue<int>qy;
    qx.push(startx);
    qy.push(starty);
    
    while( !qx.empty() )
    {
           px=qx.front();
           py=qy.front();
           qx.pop();
           qy.pop();
           for(i=0;i<4;i++)
           {
                           movex=px+x[i];
                           movey=py+y[i];
                           if(movex>0 && movey>0 && movex<pmax+1 && movey<qmax+1)
                           
                           {
                                      if( graph[movex][movey]==0   )
                                      {
                                          graph[movex][movey]=-1;
                                          dist[movex][movey]=dist[px][py]+1;
                                          qx.push(movex);
                                          qy.push(movey);
                                      }
                           }
           }
    }
}

int main()
{
    int i,j;
    int p,q;
    pmax=-MAX_VALUE;
    qmax=-MAX_VALUE;
    int min_val=MAX_VALUE;
    cin>>n;
    for( i = 0 ; i < 2*n ; i++ )
    {
                      cin>>p>>q;
                      pmax=max(p+1001,pmax);
                      qmax=max(q+1001,qmax);
                      min_val=min3(pmax,qmax,min_val);
                      pointsx[i]=p+1001;
                      pointsy[i]=q+1001;
    }
    bfs( 0 , 0 );
    int arr[16];
    for(i=0;i<2*n;i++)
    {
                      //cout<<pointsx[i]-min_val+1<<" "<<pointsy[i]-min_val+1<<endl;
                      arr[i]=dist[ pointsx[i]-min_val+1 ][ pointsy[i]-min_val+1 ]-1;
                      //cout<<arr[i]<<endl;
    }
    sort(arr,arr+2*n);
    cout<<abs(arr[n-1])<<endl;
    return 0;
}
    

#include<cstdio>
#include<iostream>
#define WHITE 0
#define GREY 1
#define BLACK 2
using namespace std;
int n,e;
int capacity[100][100], flow[100][100], color[100], pred[100];

int min(int x,int y)
{
  if(x<y)
    return x;
  return y;
}

int head, tail;
int q[102];

void enque(int x)
{
  q[tail]=x;
  tail++;
  color[x]= GREY;

}
int deque()
{
  int x= q[head];
  head++;
  color[x]= BLACK;
  return x;
}

int bfs(int st, int tt)
{
  int u,v;
  for(u=0;u<n;u++)
    color[u]=WHITE;
  head=0;
  tail=0;
  enque(st);
  pred[st]= -1;
  while(head!=tail)
    {
      u=deque();
      for(v=0;v<n;v++)
	{
	  if(color[v]== WHITE && (capacity[u][v]-flow[u][v])>0)
	    {
	      enque(v);
	      pred[v]=u;
	    }
	}
    }
  if(color[tt]== BLACK)
    return 0;

  else return 1;
}

int max_flow(int so, int sk)
{
  int i,j,u;
  int maxflow=0;
  for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
	flow[i][j]=0;
    }
  while(bfs(so,sk)== 0)
  {

      int incr=10000;
      for(u=n-1;pred[u]>=0;u=pred[u])
	{
	  incr=min(incr,(capacity[pred[u]][u]-flow[pred[u]][u]));
	}

      for(u=n-1;pred[u]>=0;u=pred[u])
	{
	  flow[pred[u]][u]+=incr;
	  flow[u][pred[u]]-=incr;
	}
      maxflow+=incr;
    //system("pause");
    }
  return maxflow;
}

int main()
{
  int i,j;
  printf("\nEnter the no of nodes ");
  scanf("%d",&n);
  printf("\nEnter the adjacency matrix\n");
  for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
	scanf("%d",&capacity[i][j]);
    }
  printf("\nThe max flow allowed %d",max_flow(0,n-1));
  return 0;
}

#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
class point
{
  public:
    int x, y;
};
int min = 999999;
int distance(point a, point b)
{
  double u = a.x-b.x, v = a.y-b.y;
  return abs(u)>abs(v)?abs(u):abs(v);
}
int solve(int p[16], point orig[32], int n)
{
  bool visited[32]; memset(visited, 0, 32*sizeof(bool));
  int dist = 0;
  point pos;
  pos.x = 0; pos.y = 0;
  for(int done = 0; done < n; ++done)
  {
    int min_dist = 999999, min_i = -1;
    for(int i = 0; i < n; ++i)
    {
      if(!visited[i])
      {
	int d = distance(pos, orig[p[i]]);
	if(d<min_dist)
	{
	  min_dist = d;
	  min_i = i;
	}
      }
    }
    dist += min_dist;
    pos = orig[p[min_i]];
    visited[min_i] = true;
  }
  return dist;
}
void generate(point orig[32], int s, int n, int p[16], int g)
{
  if(g == n)
  {
    int k = solve(p, orig, n);
    if(k < min) min = k;
  }
  else
  {
    if(g == 0)
    {
      for(int i = 0; i < s-n+1; ++i)
      {
	p[0] = i;
	generate(orig, s, n, p, 1);
      }
    }
    else
    {
      int last = p[g-1];
      for(int i = last + 1; i < s - (n-g) +  1; ++i)
      {
	p[g] = i;
	generate(orig, s, n, p, g+1);
      }
    }
  }
}
int main()
{
  int n, s = 0;
  point p[32];
  scanf("%d", &n);
  for(int i = 0; i < 2*n; ++i)
  {
    scanf("%d %d", &(p[s].x), &(p[s].y));
    if((p[s].x+p[s].y)%2==0) ++s;
  }
  int h[16];
  generate(p, s, n, h, 0);
  printf("%d\n", min);
  return 0;
}

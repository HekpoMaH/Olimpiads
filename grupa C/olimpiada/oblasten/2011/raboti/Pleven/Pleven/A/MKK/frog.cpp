#include<cstdio>
#include<vector>
#define PB push_back
#define MP make_pair
#define PI pair<int,int>
using namespace std;


int N;
PI coords [16];
vector< PI > v[16];
int MIN = 999999999;
int d;
bool theused[16];
int m,n;




int CountDistBetween (int,int);
void Solve(int);




main()
{
    scanf("%d",&N);
    n = 2*N;
    coords[0] = MP (0,0);
    for ( int i = 1; i <= n; i ++ )
     {
         int x, y;
         scanf("%d%d",&x, &y);
         coords[i] = MP(x,y);
     }

    for (int i = 0; i < n; i ++)
     for (int j = i+1; j<= n; j ++)
      {
          int dist = CountDistBetween (i,j);
          v[i].PB ( MP (j,dist));
          v[j].PB ( MP (i,dist));
      }

    theused[0] = true;
    Solve(0);


    printf("%d\n", MIN);
    return 0;
}







void Solve ( int k )
{
    if ( m == N )
    {
        if ( d < MIN )
         MIN = d;
        return;
    }

    for ( int i=0; i < n; i++)
    {
        int to, howlong;
        to = v[k][i].first;
        howlong = v[k][i].second;
        if ( !theused[to] )
        {
            theused[to] = true;
            m ++;
            d+= howlong;

            Solve(to);

            theused[to] = false;
            m --;
            d -= howlong;
        }
    }
}




int CountDistBetween(int i, int j)
{
    int x, y;
    x = coords[i].first - coords[j].first;
    y = coords[i].second - coords[j].second;
    if (x < 0 ) x *= -1;
    if ( y < 0 ) y *= -1;
    if ( x == y) return x;
    else
    {
        if ( x > y) return y + (x-y);
        else return x + (y-x);
    }
}

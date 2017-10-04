#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

  int N;
  vector <pair<int, int> > points;
  vector <pair<pair<int, int>,int > > range;
  vector <int> range0;

int move(int index,int num);
int main()
{
  cin>>N;
  for(int i=1;i<=N*2;i++)
  {
    int x,y;
    cin>>x>>y;
    if   ((x+y)%2==1);
    else
    {
      points.push_back(make_pair(x,y));
    }
  }
  for(unsigned i=0;i<points.size()-1;i++)
  {
    for(unsigned j=i+1;j<points.size();j++)
    {
      int w_r=0;
      w_r=(max(  fabs(points[i].first-points[j].first),fabs(points[i].second-points[j].second) ) );
      range.push_back(make_pair(make_pair(i,j),w_r));
    }
  }
  for(unsigned i=0;i<points.size();i++)
  {
    range0.push_back(max (fabs(points[i].first),fabs(points[i].second)) );
  }
  int mm=3000,ind,result=0;
  vector <int> visited(20);
  for(int i=0;i<=16;i++)visited[i]=0;
  for(unsigned j=0;j<range0.size();j++)
  {
    if(mm>range0[j])
    {
    	mm=range0[j];
    	ind=j;
    }
  }
  result += mm;
  visited[ind]=1;
  for(int i=0;i<N-1;i++)
  {
    mm=3000;
    for(unsigned j=0;j<range.size();j++)
    {
      if(range[j].first.first==ind )
      {
        if( visited[range[j].first.second] == 0 )
        {
          if( mm > range[j].second)
          {
            mm=range[j].second;
            ind=j;
          }
        }
      }
    }

    visited[ind]=1;
    result += mm;
  }
  cout<<result<<endl;
  return 0;
}
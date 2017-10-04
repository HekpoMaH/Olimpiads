#include<iostream>
#include<vector>
#define A first
#define B second

using namespace std;
long n,br,br1,x,y,possible,trip,best_trip=9999999;
pair<long, long> dots[16];
vector<long> v[16],road[16];
long used[16];


long abs1(long x)
{
 if(x<0) return -x;
 return x;

}

long distance1(long x, long y)
{
 long a,b;
 a=abs1(dots[x].A-dots[y].A);
 b=abs1(dots[x].B-dots[y].B);
 if(a>b) return a;
 return b;

}

void dfs(long cur, long step)
{

 //cout<<step<<" "<<cur<<": ("<<dots[cur].A<<" "<<dots[cur].B<<")   "<<trip<<endl;
 //system("pause");


 long br;
 if(step==n)
 {
  best_trip=min(trip,best_trip);
  return;
 }
 for(br=0; br<v[cur].size(); br++)
 {
  if(used[v[cur][br]]==0)
  {
   used[v[cur][br]]=1;
   trip+=road[cur][br];
   dfs(v[cur][br],step+1);
   trip-=road[cur][br];
   used[v[cur][br]]=0;
  }
 }


}


int main()
{
 cin>>n;
 for(br=1; br<=2*n; br++)
 {
  cin>>x>>y;
  dots[br].A=x;
  dots[br].B=y;
}
 for(br=1; br<=2*n; br++)
  for(br1=1; br1<=2*n; br1++)
   {
    if(br1==br) continue;
    v[br].push_back(br1);
    road[br].push_back(distance1(br,br1));
   }

/*
 for(br=0; br<=2*n; br++)
 {
  cout<<"("<<dots[br].A<<" "<<dots[br].B<<"): ";
  for(br1=0; br1<v[br].size(); br1++) cout<<road[br][br1]<<" "<<v[br][br1]<<"   ";
  cout<<endl;
 }
*/

 used[0]=1;
 for(br=1; br<=2*n; br++)
 {
  used[br]=1;
  trip=max(abs1(dots[br].A),abs1(dots[br].B));
  dfs(br,1);
  used[br]=0;
 }


 cout<<best_trip<<endl;







 return 0;
}

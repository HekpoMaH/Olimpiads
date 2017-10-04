#include<iostream>
#include<cstdio>
using namespace std;
struct brickt
{
  unsigned long long a,b,c;
};
int n;
brickt brick[2048];
bool cp[2048][2048];
unsigned long long mx,mxh[2048];
unsigned long long dfs(long long k)
{
  long long i;
  if(mxh[k]!=0)return mxh[k];
  for(int i=0;i<n;i++)
  {
    if(cp[i][k])
    {
      if(mxh[k]<dfs(i))
      {
        mxh[k]=mxh[i];
      }

    }
  }
  mxh[k]+=brick[k].c;
  if(mxh[k]>mx)mx=mxh[k];
  return mxh[k];
}
int main()
{
  cin>>n;
  n*=3;
    for(int j=0;j<n;j+=3){
        scanf("%u %u %u", &brick[j].a, &brick[j].b, &brick[j].c);
        brick[j+1]=brick[j];
        swap(brick[j+1].b, brick[j+1].c);
        brick[j+2]=brick[j];
        swap(brick[j+2].a, brick[j+2].c);
        if(brick[j].a>brick[j].b) swap(brick[j].a, brick[j].b);
        if(brick[j+1].a>brick[j+1].b) swap(brick[j+1].a, brick[j+1].b);
        if(brick[j+2].a>brick[j+2].b) swap(brick[j+2].a, brick[j+2].b);
    }
  for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cp[i][j]=brick[i].a<brick[j].a&&brick[i].b<brick[j].b;
        }
    }
  for(int i=0;i<n;i++){
        dfs(i);
    }
  cout<<mx<<endl;
  return 0;
}

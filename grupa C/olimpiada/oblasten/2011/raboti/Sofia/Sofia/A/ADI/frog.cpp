#include<iostream>
#include<vector>
#include<pair.h>
using namespace std;
struct coor{
  int x1;
  int x2;
  bool vis;
  int dis;
};

vector<int> limb[20];
int mig[200][200];
int n;
int w;
bool coores[1000][10000];
coor coors[20];
void data()
{

  int v;
  cin>>n;
  for(int z=0;z<1000;++z)
    for(int z2=0;z2<1000;++z2)
      coores[z][z2]=0;
  coors[0].x1=0;coors[0].x2=0;
  for(int z=0;z<2*n;++z)
  {  int c,d;
  cin>>c>>d;coors[z+1].x1=c;coors[z+1].x2=d;

    coores[c][d]=1;
      }


}
 ;
int abs(int x)
{
 if(x<0)
  x=-x;
 return x;
}

 int mng( coor h,coor s)
 {

  int z;
  if(abs(h.x1-s.x1)>abs(h.x2-s.x2))z=abs(h.x1-s.x1);
  else z=abs(h.x2-s.x2);
  return z;
 }

int doww(int a)
{
  int s=0;
  for(int z=0;z<a;++z)
    if(s>mig[a][z])s=z;
  return s;
}

int g4x(int w,int s,int x,int hav[])
{
   if(x<n )
   {
     for(int z=1;z<2*n+1;++z)
  {
    int z2=doww(w);
    s+=doww(w);
    hav[z2]=1;
    return g4x(w,s,x,hav);

  }

   }
   else
   {
       s+=0;
       return s;
   }
}

void solve()
{
  vector<int> edge;
  coor vertex;
  vertex.x1=0;vertex.x2=0;
  edge.push_back(1);
  limb[0]=edge;
  //z3=0;z4=0;
  int s[100];
  int hav[100];
  for(int z=0;z<2*n+1;++z)
  {
    s[z]=0;
    hav[z]=0;for(int z2=z+1;z2<2*n+1;++z2 )
    {

      mig[z][z2]=mig[z2][z]=mng(coors[z],coors[z2]);
      //cout<<mig[z][z2]<<" ";
      /*z3=coors[z2].x1;z4=coors[z2].x2;
      if(coors[z].x1-z3<2 && z3-coors[z].x1<2 && z4-coors[z].x2<2 && z4-coors[z].x2 >-2 && !coors[z].vis)
      {
      d=0;
      limb[z].push_back(z2);
      alimb[z2].push_back(z);
      //limb.push_coors[z].len=coor[v].len+1;
        //coors[z].vis=1;
        v=z;


      }
      */
    }
  }
cout<<g4x(0,0,0,hav)<<"\n";
   /* for()

  }
  int c1=0;int c2=0;
  int z=0;
  int Y=0;
  while(Y!=1)
  {
    if(coores[c1-1][c2+1]  )
    {

      coores[c1-1][c2+1];
    }

  }
*/
/*
}
*/

}

void answer()
{
 cout<<w;
}
int main()

{
  int v;
  vector<int> zealot;
  zealot.push_back(3);
  data();
  solve();



  return 0;
}
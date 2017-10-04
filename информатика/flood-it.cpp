#include<iostream>
#include<fstream>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
struct pole
{
  long long col;
  long long number;
  long long xk[353],yk[353];
};
struct table
{
  long long tab[353][353];
};
table t;
long long n,c,used[353][353],cn;
int nb[500][500],s[504];
pole flood[350*350+4];
bool cmp(pole a,pole b)
{
  if(a.number>b.number)return true;
  return false;
}
void dfs(long long i,long long j,long long co,table t1)
{
  //cout<<t1.tab[i][j]<<endl;
  queue<long long>x;queue<long long>y;
  x.push(i);y.push(j);
  long long xc,yc,br=-1;
  used[i][j]=1;
  flood[cn].col=co;
  while(!x.empty())
  {
    //cout<<t1.tab[xc][yc]<<" ";
    br++;
    xc=x.front();
    x.pop();
    yc=y.front();
    y.pop();
    flood[cn].xk[br]=xc;
    flood[cn].yk[br]=yc;
    if(xc>0&&t1.tab[xc-1][yc]==co&&used[xc-1][yc]==0)
    {
      //cout<<"vlizam -1x"<<endl;
      x.push(xc-1);
      y.push(yc);
      used[xc-1][yc]=1;
    }//cout<<t1.tab[xc][yc]<<endl;
    if(yc>0&&t1.tab[xc][yc-1]==co&&used[xc][yc-1]==0)
    {
      //cout<<"vlizam -1y"<<endl;
      x.push(xc);
      y.push(yc-1);
      used[xc][yc-1]=1;
    }
    if(xc<n&&t1.tab[xc+1][yc]==co&&used[xc+1][yc]==0)
    {
      //cout<<"vlizam +1x"<<endl;
      x.push(xc+1);
      y.push(yc);
      used[xc+1][yc]=1;
    }
    if(yc<n&&t1.tab[xc][yc+1]==co&&used[xc][yc+1]==0)
    {
      //cout<<"vlizam +1y"<<endl;
      x.push(xc);
      y.push(yc+1);
      used[xc][yc+1]=1;
    }
  }
  flood[cn].number=br;
  //cout<<"stop"<<endl;
}
bool sasedni(int x1,int y1,int x2,int y2)
{
  if(x1==x2&&abs(y1-y2)==1)return true;
  if(y1==y2&&abs(x1-x2)==1)return true;
  return false;
}
void obrazuvaimatrica()
{
  int hfl;
  for(int i=0;i<=cn;i++)
  {
    for(int j=0;j<=cn;j++)
    {
      hfl=0;
      for(int k=0;k<=flood[i].number;k++)
      {
        for(int p=0;p<=flood[j].number;p++)
        {
          if(sasedni(flood[i].xk[k],flood[i].yk[k],flood[j].xk[p],flood[j].yk[p])==true)
          {
            //cout<<"i="<<i<<" j="<<j<<endl;
            nb[i][j]=1;
            nb[j][i]=1;
            hfl=1;
            break;
          }
        }
        if(hfl==1)break;
      }
    }
  }
}
long long flooded[350*350+1];
int main()
{
  ifstream fin("flood-it.in");
  ofstream fout("flood-it.out");
  fin>>n>>c;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      fin>>t.tab[i][j];
    }
  }
  for(int i=0;i<=500;i++)for(int j=0;j<=500;j++)used[i][j]=0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(used[i][j]==0)
      {
        dfs(i,j,t.tab[i][j],t);
        //cout<<"aa"<<endl;
        cn++;
      }
    }
  }
  sort(flood,flood+cn,cmp);
  long long stx,sty;
  //stx=flood[0].xk[0];sty=flood[0].yk[0];
  long long l=1,mx,pn;
  //cout<<cn<<endl;

  obrazuvaimatrica();
  long long lastcol=flood[0].col,answer[350*350+2],br=0,mxcol,mmx,firstline[350],ztr[350];
  //for(int i=0;i<cn;i++)
  //{
    //for(int j=0;j<cn;j++)
    //{
      //cout<<nb[i][j]<<" ";
      //if(nb[i][j]==1)cout<<j+1<<" ";
      //else cout<<0<<" ";
    //}
    //cout<<endl;
  //}
  for(int i=0;i<cn;i++)
  {
    firstline[i]=nb[0][i];
  }
  while(l)
  {
    for(int i=0;i<=c;i++)s[i]=0;
    for(int i=0;i<=cn;i++)ztr[i]=0;
    //cout<<lastcol<<endl;
    //system("pause");
    //for(int i=0;i<cn;i++)
    //{
      //cout<<firstline[i]<<" ";
    //}
    //cout<<endl;
    for(int j=1;j<cn;j++)
    {
      if(firstline[j]==1&&flooded[j]==0)
      {

        if(br!=0){s[flood[j].col]+=flood[j].number+1;}
        if(br==0&&flood[j].col!=flood[0].col)s[flood[j].col]+=flood[j].number+1;
      }
    }
    mmx=0;
    //for(int i=1;i<=c;i++)cout<<"s["<<i<<"]="<<s[i]<<" ";
    //cout<<endl;
    //system("pause");
    for(int i=1;i<=c;i++)
    {
      if(s[i]>mmx)
      {
        mmx=s[i];
        mxcol=i;
      }
    }
    lastcol=mxcol;
    answer[br]=lastcol;
    br++;
    //cout<<"mxcol="<<mxcol<<endl;
    //for(int i=0;i<cn;i++)ztr[i]=0;
    //for(int i=0;i<cn;i++)
    //{
      //cout<<firstline[i]<<" ";
    //}
    //cout<<endl;
    for(int i=0;i<cn;i++)
    {
      //cout<<"1 "<<firstline[i]<<" 2 "<<flood[i].col<<" 3 "<<mxcol<<endl;
      if(firstline[i]==1){ztr[i]=1;}
    }

    for(int j=1;j<cn;j++)
    {
      if(firstline[j]==1)
      {//cout<<"tcol="<<flood[j].col<<" mxcol="<<mxcol<<" ";
        if(flood[j].col==mxcol)
        {
          flooded[j]=1;
          for(int i=0;i<cn;i++)
          {

            if(nb[j][i]==1)firstline[i]=1;
          }
        }
      }
    }
    //for(int i=0;i<cn;i++)
    //{
      //cout<<firstline[i]<<" ";
    //}
    //cout<<endl;
    for(int i=0;i<cn;i++)
    {
      if(ztr[i]==1&&flood[i].col==mxcol){firstline[i]=0;ztr[i]=0;}
    }
    //cout<<endl;
    //for(int i=0;i<cn;i++)
    //{
      //cout<<firstline[i]<<" ";
    //}
    //cout<<endl;
    //for(int i=1;i<=cn;i++)
    //{
      //if(nb[0][i]==1)cout<<i<<" ";
      //else cout<<0<<" ";
    //}
    //cout<<endl;

    l=0;
    //flood[0].col=mxcol;
    for(int i=1;i<=c;i++)
    {
      //cout<<"f["<<i<<"]="<<firstline[i]<<" ";
      if(s[i]>0)
      {
        l=1;
        //break;
      }
    }
    //system("pause");
    //cout<<endl;
  }
  //ofstream fout("flood-it.out");
  fout<<br-1<<endl;
  fout<<flood[0].xk[0]<<" "<<flood[0].yk[0]<<endl;
  for(int i=0;i<br-1;i++)
  {
    fout<<answer[i]<<endl;
  }
  fin.close();fout.close();
  return 0;
}

#include<iostream>
#include<string>
using namespace std;
string n;
string m;
string g;
int cif[15];
int srav(string s1,string s2)
{
  if(s1.size()>s2.size())return 1;
  if(s1.size()<s2.size())return 2;
  if(s1.size()==s2.size())
  {
    int l;
    for(int i=0;i<s1.size();i++)
    {
      if(s1[i]>s2[i])return 1;
      if(s1[i]<s2[i])return 2;
    }
  }
  return 3;
}
string razl(string a,string b)
{
  int sa=a.size(),sb=b.size(),ca,cb,i,j,br=0;
  string c;
  i=sa-1;j=sb-1;
  while(i>=0||j>=0)
  {
    if(i>=0){ca=a[i]-'0';i--;}
    else ca=0;
    if(j>=0){cb=b[j]-'0';j--;}
    else cb=0;
    if(ca<cb)
    {
      for(int f=i;f>=0;f--)
      {
        if(a[f]==0)a[f]='9';
        else{a[f]--;ca+=10;break;}
      }
    }
    c+=ca-cb+'0';br++;//cout<<c<<endl;
  }
  //string d;
  //for(int f=0;f<br;f++){d+=c[f];}

  reverse(c.begin(),c.end());
  int kr=-1;
  for(int i=0;i<c.size();i++)if(c[i]!='0'){kr=i;break;}
  c.erase(0,kr);
  //cout<<d<<endl;
  return c;
}
string umn(string a,string b)
{
  int c[2005]={0};
  int st1,st2,st,cif1,cif2;int mst=-1,na=0,kr1=b.size(),kr2=a.size();//cout<<kr2<<" "<<a<<endl;
  for(int i=0;i<kr1;i++)
  {
    for(int j=0;j<kr2;j++)
    {
      cif1=a[j]-'0';
      cif2=b[i]-'0';
      st1=i;st2=j;
      //st=st1+st2+1;
      st=st1+st2;//cout<<"st="<<st<<endl;
      if(st>mst)mst=st;
      c[st]+=cif1*cif2;
    }
  }//mst=a.size()+1;
  na=0;//cout<<"mst="<<mst<<endl;
  for(int i=mst;i>=0;i--)
  {
    c[i]+=na;
    na=0;
    if(c[i]>=10)
    {
      na=c[i]/10;
      c[i]=c[i]-na*10;
    }
  }
  //cout<<na<<endl;
  //for(int i=0;i<=mst;i++){cout<<c[i];}
  //cout<<endl;
  string otg="";
  if(na>0)otg+=na+'0';
  for(int i=0;i<=mst;i++){otg+=c[i]+'0';}
  return otg;
}
int main()
{
  cin>>n;
  cin>>m;
  cin>>g;
  int d1=n.size(),d2=m.size();
  string raz,sum,um,um2;
  if(srav(n,m)==1||srav(n,m)==3){raz=razl(n,m);}
  if(srav(n,m)==2){raz=razl(m,n);}
  //cout<<raz<<endl;
  um=raz;um2=g;
  sum=umn(raz,g);
  //cout<<sum<<endl;
  //sum=sumi(um,um2);
  cout<<sum<<endl;
  int k=sum.size(),sumci=0,mx=0,mc=0;
  for(int i=0;i<k;i++)
  {
    cif[sum[i]-'0']++;
    sumci+=sum[i]-'0';
  }
  //cout<<sumci<<endl;
  for(int i=1;i<=9;i++)
  {
    if(sumci%i==0)
    {//cout<<"AAAAAAAAAA"<<endl;
      if(mx<cif[i]){mx=cif[i];mc=i;}
    }
  }
  cout<<mc<<endl;
  return 0;
}

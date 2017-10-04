#include<iostream>
#include<string>
using namespace std;
int br1,br2,br5,br10,br101,k1,k2,k5,k10;
long n;
int r;
string s,s101;
string sr;
int main()
{
  cin>>n;
  for(long i=0;i<n;i++)
  {
    cin>>r;
    switch(r)
    {
      case 1:br1++;break;
      case 2:br2++;break;
      case 5:br5++;break;
      case 10:br10++;break;
    }
  }
  if(br10>0&&br1==0&&br2==0&&br5==0)cout<<"No"<<endl;
  else
  {
    //if(br1>0&&br10>0)br101=abs(br10-br1);
    //br1-=br101;
    //k101=br101/2;
    if(br10%2!=0&&br1>3)
    {
      for(int i=0;i<br10;i++)sr+="10";
      sr+="1";
      br1--;
    }
    else if(br1%2!=0)sr="1";
    else if(br2%2!=0)sr="2";
    else if(br5%2!=0)sr="2";
    //else if(br101%2!=0)sr="101";
    k1=br1/2;
    k2=br2/2;
    k5=br5/2;
    k10=br10/2;
    if(k10>0&&k1>0)
    {
      for(int i=0;i<k10;i++)s101+="10";
      s101+="1";
      k1--;br10-=k10*2;
      k10=0;
      br1-=2;
      s+=s101;
    }
    for(int i=0;i<k1;i++)s+="1";
    for(int i=0;i<k2;i++)s+="2";
    for(int i=0;i<k5;i++)s+="5";
    br1-=k1*2;
    br2-=k2*2;
    br5-=k2*5;
    //cout<<br10<<" "<<br1<<endl;
    //cout<<br10<<" "<<br1<<endl;
    s101="";
    if(br10>0&&br1>0)
    {
      for(int i=0;i<br10;i++)s101+="10";
      s101+="1";//cout<<s101<<endl;
      k1-=br1/2;
      br1--;
      br10=0;
      sr=s101;
    }
    cout<<s<<sr;
    reverse(s.begin(),s.end());
    cout<<s;
    //s+=s101;
    //if(k10>0&&br1==1)
    //{
     // for(int i=0;i<k10;i++)s101+="10";
  }
  return 0;
}

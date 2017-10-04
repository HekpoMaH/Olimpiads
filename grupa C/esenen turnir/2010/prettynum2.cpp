#include<iostream>
#include<string>
using namespace std;
struct num
{
  int count;
  int number;
};
int n,a[1000005],br,bgr,k;
num gr[1000005];
string pretty,cha,prettymax;
int main()
{
  cin>>n;
  for(int i=0;i<n;i++)cin>>a[i];
  //cout<<n<<endl;
  for(int i=0;i<n;i++)
  {
    br++;
    //cout<<i<<" "<<br<<endl;
    if(a[i]!=a[i+1])
    {
      gr[bgr].number=a[i];
      gr[bgr].count=br;
      br=0;
      bgr++;
    }
  }
  //for(int i=0;i<bgr;i++)cout<<gr[i].number<<" "<<gr[i].count<<endl;
  //cout<<"gr[0].count="<<gr[0].count<<endl;
  for(int i=0;i<bgr;i++)
  {
    //cout<<i<<endl;
    //cout<<"k="<<k<<" gr["<<i<<"].count="<<gr[i].count<<"bgr="<<bgr<<endl;

    if(gr[i].count>k)
    {
      //cout<<"1.1max="<<prettymax<<" pretty="<<pretty<<" k="<<k<<endl;
      if(prettymax==""||prettymax.size()<pretty.size())prettymax=pretty;
      if(k==0)k=gr[i].count;
      for(int j=0;j<k;j++)pretty+=(char)('0'+gr[i].number);
      k=gr[i].count;
      if(prettymax==""||prettymax.size()<pretty.size())prettymax=pretty;
      //cout<<"1.2max="<<prettymax<<" pretty="<<pretty<<" k="<<k<<endl;
    }
    else if(gr[i].count==k)
    {
      for(int j=1;j<=gr[i].count;j++)pretty+=(char)('0'+gr[i].number);
      //if(prettymax==""||prettymax.size()<pretty.size())prettymax=pretty;
      //cout<<"2max="<<prettymax<<" pretty="<<pretty<<" k="<<k<<endl;
    }
    else if(gr[i].count<k)
    {
      if(prettymax==""||prettymax.size()<pretty.size())prettymax=pretty;
      cha.clear();
      for(int j=pretty.size()-1;j>=pretty.size()-gr[i].count;j--)cha+=pretty[j];
      for(int j=1;j<=gr[i].count;j++)cha+=(char)(gr[i].number+'0');
      pretty.clear();
      pretty=cha;
      k=gr[i].count;      if(prettymax==""||prettymax.size()<pretty.size())prettymax=pretty;

      //cout<<"3max="<<prettymax<<" pretty="<<pretty<<" k="<<k<<endl;
    }
    //if(prettymax==""||prettymax.size()<pretty.size())prettymax=pretty;
  }
  cout<<prettymax<<endl;
  return 0;
}

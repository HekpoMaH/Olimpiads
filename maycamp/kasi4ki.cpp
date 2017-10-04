#include<iostream>
#include<stack>
using namespace std;
stack<int> s;
int tab[111][111],used[111],n,k,l,br,f,c;
int main()
{
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>k;
    tab[i][k-1]=1;
    tab[k-1][i]=1;
    //cout<<k-1<<" "<<i<<endl;
  }
  do
  {
    f=-1;
    for(int i=0;i<n;i++)if(used[i]==0){f=i;break;}
    if(f!=-1)s.push(f);
    //s.push(f+1);
    //cout<<"f="<<f<<endl;
    used[f]=1;
    //cout<<used[1]<<endl;
    while(s.size()>0)
    {
      c=s.top();//cout<<"c="<<s.top()<<endl;
      s.pop();
      //used[c]=1;
      for(int i=0;i<n;i++)
      {
        if(tab[c][i]==1&&used[i]==0){k=i;s.push(k);used[k]=1;}//cout<<c<<" "<<i<<" "<<used[i]<<" "<<tab[c][i]<<endl;
      }
      //s.pop();
    }
    //break;

    l=1;
    for(int i=0;i<n;i++)if(used[i]==0){l=0;if(i>=n)cout<<"problem-re"<<endl;break;}
    //break;
    br++;
    //cout<<l<<endl;
  }while(l==0);
  cout<<br<<endl;
  return 0;
}

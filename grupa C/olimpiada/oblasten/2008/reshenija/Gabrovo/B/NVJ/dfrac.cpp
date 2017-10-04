#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int a,b;
    long long k;
    int p;
    cin>>a>>b>>k>>p;
    int gcd=__gcd(a,b);
    a/=gcd;
    b/=gcd;
    vector<int> res(b+10,0);
    vector<int> next(b+10,-1);
    vector<int> prev(b+10,-1);
    vector<bool> end(b+10,0);
    for(int i=0;i<b;i++)
    {
        res[i]=(i*10)/b;
        next[res[i]]=(i*10)%b;
        //cout<<(i*10)%b<<endl;
        prev[res[i]]=i;
        if((i*10)%b==0)
         end[i]=true;
    }

    /*for(int i=0;i<b+10;i++)
     cout<<i<<"   "<<res[i]<<" "<<next[res[i]]<<" "<<prev[res[i]]<<endl;*/

    vector<int> used(b+10,0);
    int curr=a;
    vector<int> seq;
    int j=0;
    bool e=0;
    while(!used[curr])
    {
        //cout<<curr<<" "<<used[next[res[curr]]]<<endl;;
        seq.push_back(res[curr]);
        used[curr]=seq.size()-1;
        curr=next[res[curr]];
        if(end[curr])
         e=1;

    }
    int st=used[curr];
    long long d=(long long) seq.size();
    k=k%d;
    int cnt=0;
    k--;
    if(k<0)
     k=seq.size()-1;
     for(int i=k;i<seq.size();i++,cnt++)
     {
      if(cnt<p)
       cout<<seq[i];
     }
    while(cnt<p)
    {
     bool q=1;
     if(seq[seq.size()-1]==0 || e)
      while(cnt<p)
      {
          //cout<<"0";
          cnt++;
      }
     for(int i=st;i<seq.size();i++,cnt++)
     {
      if(cnt<p)
       cout<<seq[i];
      else
      {
          q=false;
          break;
      }
     }


    }
    cout<<endl;
    return 0;
}

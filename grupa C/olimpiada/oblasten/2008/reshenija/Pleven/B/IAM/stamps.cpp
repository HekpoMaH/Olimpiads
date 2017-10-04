#include<iostream>
#include<vector>
using namespace std;
int s,n,j,i,brmin;
vector<int>a;

bool solve(int p,int sum,int br)
{
if(sum==s){if(br<brmin)brmin=br;return true;}
if(p>n)return true;

i=(s-sum)/a[n-p]+1;
while(i!=0)
{i--;
solve(p+1,sum+(i*a[n-p]),br+i);
}
}

int main()
{    
      cin>>s>>n;
      for(i=0;i<n;i++)
      {cin>>j; a.push_back(j);}
    
    sort(a.begin(),a.end()); brmin=s;

   for(j=1;j<=n;j++) solve(j,0,0);
      
    cout<<brmin;
    cout<<endl;
    return 0;
}

#include<iostream>
using namespace std;
main()
{ int ones[9][100]={0}, num[100], n;
  string s;
  cin>>s;
  n=s.length();
  int maxn=0;
  for (int i=0;i<n;i++)
  {
      num[i]=s[i]-48;
      if (maxn<num[i])maxn=num[i];
  }
  for (int i=0;i<n;i++)
  {    
       int m=num[i];
       for (int j=0;j<m;j++)ones[j][i]=1;
  }
  cout<<maxn<<endl;
  for (int i=0;i<maxn;i++)
  {    
       int f=0;
       for (int j=0;j<n;j++)
         if (f)cout<<ones[i][j];
         else if (ones[i][j]){f=1; cout<<'1';}
              else cout<<' ';
       cout<<endl;
  }
} 


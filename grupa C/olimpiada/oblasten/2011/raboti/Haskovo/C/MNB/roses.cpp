#include<iostream>
using namespace std;
int m,n,k;
long long int main_sum,max_sum,current_sum;
int roses[1015][1015];
int main()
{
  cin>>m>>n>>k;
  for(int o=0;o<m;o++)
  {
    for(int o2=0;o2<n;o2++)
    {
      cin>>roses[o][o2];
      main_sum+=roses[o][o2];
    }
  }
  int i=0,j=0;
  while(i!=(m-k)+1&&j!=(n-k)+1)
  {
    for(int o=i;o<i+k;o++)
    {
      for(int o2=j;o2<j+k;o2++)
      {
        current_sum+=roses[o][o2];
      }
    }
    if(current_sum>max_sum){max_sum=current_sum;}
    current_sum=0;
    j++;
    if(j==n-1){j=0;i++;}
  }
  cout<<main_sum-max_sum<<endl;
  return 0;
}
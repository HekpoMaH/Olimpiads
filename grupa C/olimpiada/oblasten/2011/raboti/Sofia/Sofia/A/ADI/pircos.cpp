#include<iostream>
#include<bitset>
#include<vector>
using namespace std;

int main()
{
  int c=0;
    int n;
  cin>>n;

int a1,a2;
  if(n<100001)
  {
    bitset <100000>arr;

  int ks;for(int co=0;co<n;co++)
  {
    int nu1=co/4;
    int nu2=co%4;
    cin>>ks;
    if(arr[ks]==1 )arr[ks]=0;
    else{arr[ks]=1;}
    //cout<<arr[ks]<<" ";
  }

  int x[2];
  int ct=0;
  for(int co=0;co<100000;++co)
  {

    if(arr[co]==1){x[ct]=co;ct++;if(ct==2)break;}

  }

  a1=x[0];a2=x[1];if(x[0]>x[1]){a1=x[1];a2=x[0];}

  }
  else if(n>100000)
  {

    vector<unsigned int> f;
    int en;
    /*for(int co=0;co<n;++co)
    {
      cin>>en;
      if(!f.pop_back(en,))
        f.push_back(en);
    }
      int x[2];
      int ct=0;
      x[0]=2;//f.pop_back(1);
      x[1]=2;//f.pop_back(0);

      a1=x[0];a2=x[1];if(x[0]>x[1]){a1=x[1];a2=x[0];}

    */
    }
  cout<<a1<<" "<<a2;
  cout<<"\n";
  return 0;
}

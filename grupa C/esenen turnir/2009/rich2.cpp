#include<iostream>
//#include<cstdio>
using namespace std;
long long a[1001],bank,mx,ans,lmx;
int main()
{
  ios::sync_with_stdio(false);
  while(cin>>bank)
  {
    if(bank<=1000)a[bank]++;
    lmx=bank;
    //if(mx<bank){lmx=mx;mx=bank;}
    //cout<<bank<<endl;
  }
  //cout<<lmx<<endl;
  if(lmx<=1000)a[lmx]--;
  //cout<<a[2]<<" "<<a[1]<<" "<<a[0]<<endl;
  for(int i=0;i<=1000;i++)
  {
    if(a[i]>0)
    {
      //cout<<"i= "<<i<<" a["<<i<<"]= "<<a[i]<<" bank="<<bank<<endl;
      if(bank<a[i]){cout<<i<<endl;return 0;}
      if(bank>=a[i])
      {
        /*if(i>790){printf("-------");
        for(int j=543;j<=i;j++)printf("%u ",a[j]);
        printf("-------");
        system("pause");}*/
        bank-=a[i];
        //cout<<"a["<<i<<"]="<<a[i]<<" bank="<<bank<<endl;
        a[i+1]+=a[i];
        //a[i]=0;

      }
    }
  }
  if(bank>0){long long p=(bank/a[1000]);p+=1000;cout<<p<<endl;}
  return 0;
}

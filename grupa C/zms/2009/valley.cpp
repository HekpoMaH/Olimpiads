#include<iostream>
using namespace std;
int B[1000],L[1000];
int main()
{
    int N,i,j,t,BB,LL,br=0;
    cin>>N;
    for(i=1;i<=N;i++)
       cin>>B[i]>>L[i];
    for(i=N-1;i>=1;i--)
       for(j=1;j<=i;j++)
          if(B[j]>B[j+1]||B[j]==B[j+1]&&L[j]<L[j+1])
          {t=B[j];B[j]=B[j+1];B[j+1]=t;
           t=L[j];L[j]=L[j+1];L[j+1]=t;
           }
           for(int i=0;i<N;i++)cout<<B[i]<<" "<<L[i]<<endl;
    BB=B[1];LL=L[1];
    for(i=2;i<=N;i++)
    {
      cout<<"BB="<<BB<<" LL="<<LL<<" "<<"B="<<B[i]<<" "<<"L="<<L[i]<<endl;
      if(B[i]==BB||B[i]+L[i]<=BB+LL) continue;
      if(B[i]<=LL+BB){cout<<"i="<<i<<endl;br++;}
      BB=B[i];LL=L[i];
    }
    cout<<br<<endl;
    return 0;
}

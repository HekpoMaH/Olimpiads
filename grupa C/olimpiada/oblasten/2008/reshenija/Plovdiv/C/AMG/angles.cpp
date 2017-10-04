#include<iostream>
using namespace std;
int a[1024][1024], n, k, red=1001, stulb=1001, maxi, sum;
int main()
{
    cin>>n>>k;
    for(int i=0; i<n; i++)
     for(int j=0; j<n; j++)
      cin>>a[i][j];
    for(int i=0; i<n; i++)
     for(int j=0; j<n; j++)
     {
        int k1=min(k, n-j-1);
        int k2=min(k, n-i-1);
        sum=a[i][j];
        if(j<n-1)
         for(int p=j+1; p<=j+k1; p++) sum+=a[i][p];
        if(i<n-1)
         for(int q=i+1; q<=i+k2; q++) sum+=a[q][j];
         
        if(maxi<sum) { maxi=sum; red=i+1; stulb=j+1; }
     }
    cout<<red<<" "<<stulb<<endl;
    return 0;
}

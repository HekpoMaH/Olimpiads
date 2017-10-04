#include<iostream>
using namespace std;
long long br[55];
long long n,k;
int main(){
    int i,j,k,l;
    cin>>n>>k;
    br[1]=1;
    for(i=2;i<=n;i++){
                      l=i-k;
                      if(l<1) l=1;
                      for(;l<i;l++) br[i]+=br[l];
                     }
    cout<<br[n]<<'\n';
    //system("pause");
    return 0;
}                  
                       

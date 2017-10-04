#include<iostream>
using namespace std;
int a[101];
int main(){
    int i,b[101],n,k,x,brd=0,brg=0;
    cin>>n>>k;
    for(i=1;i<=n;i++)cin>>b[i];
    a[k]=1;
    x=b[k];
    for(i=k+1;;i++){
                  if(a[i]==0){
                              brd++;
                              if(brd==x){brg++;
                                        a[i]=1;
                                        brd=0;
                                        x=b[i];
                                        }
                                        }
                  if(i==n)i=0;
                  if(brg==n-2)break;
                  } 
    for(i=1;i<=n;i++)if(a[i]==0)cout<<i<<endl;
   // system("pause");
    return 0;}

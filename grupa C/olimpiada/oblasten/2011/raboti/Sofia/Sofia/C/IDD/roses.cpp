#include <iostream>
#include <cstdio>
using namespace std;
int tabl[1024][1024],n,m,k,ma,tekbr,br;
int main(){
    cin>>m>>n>>k;
    for (int i=0;i<m;++i){
        for (int j=0;j<n;++j){
            scanf("%d",&tabl[j][i]);
            br+=tabl[j][i];
        }
    }
    for (int y=0;y<m-k+1;++y){
        for (int x=0;x<n-k+1;++x){
            tekbr=0;
            for (int i=y;i<y+k;++i){
                for (int j=x;j<x+k;j++){
                        tekbr+=tabl[j][i];
                }
            }
            if (tekbr>ma){ma=tekbr;}
        }
    }
    cout<<br-ma<<endl;
return 0;
}

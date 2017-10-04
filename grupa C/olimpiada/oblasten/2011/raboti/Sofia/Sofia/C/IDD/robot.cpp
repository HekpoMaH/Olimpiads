#include <iostream>
using namespace std;
int m,n,r,k,x,y,br=0,b;
int main(){
    cin>>m>>n>>r>>k;
    y=(r-1)/n;x=(r-1)%n;
    b=0;
    for (int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            ++b;
            if ((abs(j-x)+abs(i-y))<=k&&(abs(j-x)+abs(i-y))%2==k%2){br+=b;}
        }
    }
    cout<<br<<endl;
return 0;
}

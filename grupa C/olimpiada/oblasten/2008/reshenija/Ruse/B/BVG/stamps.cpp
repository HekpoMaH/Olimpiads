#include <iostream>
using namespace std;

int main(){
    int S,N;
    cin >> S >> N;
    int a[N];
    for(int i=0; i<N; i++){
            cin >> a[i];
            }
    for(int i2=1; i2<N; i2++){
    for(int i=0; i<N; i++){
            if(a[i2]>a[i]){ swap(a[i],a[i2]); }
            }
            }
            
    //for(int i=0; i<N; i++) cout << a[i] << ' ';
    
    int sum[500]={0},stn[500]={0};
    for(int ss=0; ss<N; ss++){
         do{
         for(int i=ss; i<N; i++){
                 if(a[i]+sum[ss]<=S){ sum[ss]+=a[i]; stn[ss]++; break; }
                 }
                 }while(sum[ss]<S);
                 }
    
    int maxstn=stn[0];
    for(int i=0; i<N; i++) if(stn[i]<maxstn) maxstn=stn[i];
    cout << maxstn;
    return 0;
}

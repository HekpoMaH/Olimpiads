#include <iostream>
using namespace std;
int s,n,ch[128],br,mi,ost,t;
int main(){
    cin>>s>>n;
    mi=s;
    if (n==1){cout<<"1\n";}
    else{
        for (int i=0;i<n;++i){
            cin>>ch[i];
        }
        sort(ch,ch+n);
        for (int i=s/ch[n-1];i>=0;--i){
            ost=s-i*ch[n-1];
            for (int j=ost/ch[n-2];j>=0;--j){
                br=i+j;
                ost=s-i*ch[n-1]-j*ch[n-2];
                //cout<<i<<" "<<j<<" "<<ost<<endl;
                for (int k=n-3;k>=0;k--){
                    t=ost/ch[k];
                    ost=ost-t*ch[k];
                    br+=t;
                }
                if (mi>br){mi=br;}
            }
        }
    }
    cout<<mi<<endl;
return 0;
}

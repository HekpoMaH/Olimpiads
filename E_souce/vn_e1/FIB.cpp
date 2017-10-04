#include<iostream>
using namespace std;
int main () {
    int n,a,b,c,d;
    cin>>n;
    if (n==1) cout<<1<<endl; else
    if (n==2) cout<<1<<endl; else 
    if (n>2) {
    for (int i=1;i<=n;i++) {
    if (i==1) a=1;  
    if (i==2) b=1;
    if (i>2)
     {
        c=a+b;
        d=b;
        b=c;
        a=d;
        }
                           }
    cout<<c<<endl;
                  }
    //system ("pause");
    return 0;
}

#include <iostream>
using namespace std;
int main(){
int N,a,b,c,d,e,f,g;
cin>>N;
if (N==1) {cin>>a; 
    cout<<"1"<<endl;
}
if (N==2) cin>>a>>b;
if (N==3) cin>>a>>b>>c;
if (N==4) cin>>a>>b>>c>>d;
if (N==5) cin>>a>>b>>c>>d>>e;
if (N==6) cin>>a>>b>>c>>d>>e>>f;
if (N==7) cin>>a>>b>>c>>d>>e>>f>>g;

if (N==2) {
if (a>b) cout<<a+1<<endl;
if (b>a) cout<<b+1<<endl;
if (b==a) cout<<a+1<<endl;
}
if (N==3) {
if (a>c && c>b) cout<<(a+c)+1<<endl;
if (c>b && b>a) cout<<(c+b)+1<<endl;
if (b>a && a>c) cout<<(a+b)+1<<endl;
if (b==a || a==c || b==c) cout<<(a+b)+1<<endl;
}
if (N==4) {
if (a>c && c>b && b>d) cout<<(a+c+b)+1<<endl;
if (c>b && b>a && a>d) cout<<(c+b+a)+1<<endl;
if (b>a && a>c && c>d) cout<<(a+b+c)+1<<endl;
if (d>a && a>b && b>c) cout<<(d+a+b)+1<<endl;

if (a>b && b>c && c>d) cout<<(a+c+b)+1<<endl;
if (c>a && a>b && b>d) cout<<(c+b+a)+1<<endl;
if (b>c && c>a && a>d) cout<<(a+b+c)+1<<endl;
if (d>b && b>c && c>a) cout<<(d+c+b)+1<<endl;
if (a==b || b==c || c==d || a==d || a==c ||b==d) cout<<(a+b+c)+1<<endl;
}
if (N==7){
    if (a>=b && b>=c && c>=d && d>=e && e>=f && f>=g) cout<<(a+b+c+d+e+f)+1;
    if (a<=b && b<=c && c<=d && d<=e && e<=f && f<=g) cout<<(g+f+e+d+c+b)+1;
}
//system ("pause");
    return 0;
}


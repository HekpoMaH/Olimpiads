/*
TASK:diet
LANG:C++
*/
#include<iostream>
using namespace std;
int a,b,c,t,n;    
main()
{
    cin>>a>>b>>c;
    t=(a*10+b*20+c*30)/60;
    cout<<t<<" ";
    if(c>t) {
        n+=c-t;
        a+=c-t;
        b+=c-t;
        c=t;
        if(b>=t) {
            if(!c>=t) {
                n+=b-t;
                a+=b-t;
                b+=b-t;
                b=t;
            }
        }
    }
    else {
        if(b<t) cout<<"0\n";
        else {
            if(b>=t+t-c&&a>=t+t-c) cout<<"0\n";
            else {
                if(a>=b) cout<<"0\n";
                else {
                    n=b-2*t+c-1;
                }
            }
        }
    }
    cout<<n<<endl;
    return 0;
}

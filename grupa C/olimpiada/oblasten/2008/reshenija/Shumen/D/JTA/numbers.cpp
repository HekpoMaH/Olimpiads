#include <iostream>
using namespace std;
int main()
{
    int a,b,c,d,a2,b2,c2,d2;
    cin>>a>>b>>c>>d;
    if(a==0&&b!=0&&c!=0&&d!=0)
    {
        if(2*2==c/b) cout<<2<<' '<<b<<' '<<c<<' '<<' '<<d<<endl;
        else 
        if(3*3==c/b) cout<<3<<' '<<b<<' '<<c<<' '<<' '<<d<<endl;
        else
        if(4*4==c/b) cout<<4<<' '<<b<<' '<<c<<' '<<' '<<d<<endl;
        else
        if(5*5==c/b) cout<<5<<' '<<b<<' '<<c<<' '<<' '<<d<<endl;
        else
        if(6*6==c/b) cout<<6<<' '<<b<<' '<<c<<' '<<' '<<d<<endl;
        else
        if(7*7==c/b) cout<<7<<' '<<b<<' '<<c<<' '<<' '<<d<<endl;
        else
        if(8*8==c/b) cout<<8<<' '<<b<<' '<<c<<' '<<' '<<d<<endl;
        else
        if(9*9==c/b) cout<<9<<' '<<b<<' '<<c<<' '<<' '<<d<<endl;
        else
        if(10*10==c/b) cout<<10<<' '<<b<<' '<<c<<' '<<' '<<d<<endl;
        else
        if(11*11==c/b) cout<<11<<' '<<b<<' '<<c<<' '<<' '<<d<<endl;
        else
        if(12*12==c/b) cout<<12<<' '<<b<<' '<<c<<' '<<' '<<d<<endl;
        else
        if(13*13==c/b) cout<<13<<' '<<b<<' '<<c<<' '<<' '<<d<<endl;
        else
        if(14*14==c/b) cout<<14<<' '<<b<<' '<<c<<' '<<' '<<d<<endl;
        else
        if(15*15==c/b) cout<<15<<' '<<b<<' '<<c<<' '<<' '<<d<<endl;
        else
        if(16*16==c/b) cout<<16<<' '<<b<<' '<<c<<' '<<' '<<d<<endl;
        else
        if(17*17==c/b) cout<<17<<' '<<b<<' '<<c<<' '<<' '<<d<<endl;
        else
        if(18*18==c/b) cout<<18<<' '<<b<<' '<<c<<' '<<' '<<d<<endl;
        else
        if(19*19==c/b) cout<<19<<' '<<b<<' '<<c<<' '<<' '<<d<<endl;
        else
        if(20*20==c/b) cout<<20<<' '<<b<<' '<<c<<' '<<' '<<d<<endl;
    }
    if(a!=0&&b==0&&c!=0&&d!=0)
    {
        if(2*2==d/a) cout<<a<<' '<<2<<' '<<c<<' '<<' '<<d<<endl;
        else
        if(3*3==d/a) cout<<a<<' '<<3<<' '<<c<<' '<<' '<<d<<endl;
        else  
        if(4*4==d/a) cout<<a<<' '<<4<<' '<<c<<' '<<' '<<d<<endl;
        else 
        if(5*5==d/a) cout<<a<<' '<<5<<' '<<c<<' '<<' '<<d<<endl;
        else 
        if(6*6==d/a) cout<<a<<' '<<6<<' '<<c<<' '<<' '<<d<<endl;
        else 
        if(7*7==d/a) cout<<a<<' '<<7<<' '<<c<<' '<<' '<<d<<endl;
        else 
        if(8*8==d/a) cout<<a<<' '<<8<<' '<<c<<' '<<' '<<d<<endl;
        else 
        if(9*9==d/a) cout<<a<<' '<<9<<' '<<c<<' '<<' '<<d<<endl;
        else 
        if(10*10==d/a) cout<<a<<' '<<10<<' '<<c<<' '<<' '<<d<<endl;
        else 
        if(11*11==d/a) cout<<a<<' '<<11<<' '<<c<<' '<<' '<<d<<endl;
        else 
        if(12*12==d/a) cout<<a<<' '<<12<<' '<<c<<' '<<' '<<d<<endl;
        else 
        if(13*13==d/a) cout<<a<<' '<<13<<' '<<c<<' '<<' '<<d<<endl;
        else 
        if(14*14==d/a) cout<<a<<' '<<14<<' '<<c<<' '<<' '<<d<<endl;
        else 
        if(15*15==d/a) cout<<a<<' '<<15<<' '<<c<<' '<<' '<<d<<endl;
        else 
        if(16*16==d/a) cout<<a<<' '<<16<<' '<<c<<' '<<' '<<d<<endl;
        else 
        if(17*17==d/a) cout<<a<<' '<<17<<' '<<c<<' '<<' '<<d<<endl;
        else 
        if(18*18==d/a) cout<<a<<' '<<18<<' '<<c<<' '<<' '<<d<<endl;
        else 
        if(19*19==d/a) cout<<a<<' '<<19<<' '<<c<<' '<<' '<<d<<endl;
        else 
        if(20*20==d/a) cout<<a<<' '<<20<<' '<<c<<' '<<' '<<d<<endl;
    }
    if(a!=0&&b!=0&&c==0&&d!=0) 
    cout<<a<<' '<<b<<' '<<a*a*b<<' '<<d<<endl;
    else 
    if(a!=0&&b!=0&&c!=0&&d==0)
    cout<<a<<' '<<b<<' '<<c<<' '<<a*b*b<<endl;
    else
    if(a!=0&&b!=0&&c==0&&d==0) 
    cout<<a<<' '<<b<<' '<<a*a*b<<' '<<a*b*b<<endl;
    return 0;
}



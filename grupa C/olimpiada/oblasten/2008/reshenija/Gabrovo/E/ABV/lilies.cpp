#include <iostream.h>
using namespace std;
int main ()
{
    int n,br1,br2,br3,br4,br5,br6,br7;
    cin>>n;
    if (n==1) cin>>br1;
    if (n==2) cin>>br1>>br2;
    if (n==3) cin>>br1>>br2>>br3;
    if (n==4) cin>>br1>>br2>>br3>>br4;
    if (n==5) cin>>br1>>br2>>br3>>br4>>br5;
    if (n==6) cin>>br1>>br2>>br3>>br4>>br5>>br6;
    if (n==7) cin>>br1>>br2>>br3>>br4>>br5>>br6>>br7;
    if (n==1) cout<<n<<endl;
    if (n==2) 
    {
             if (br1>br2) cout<<br1+1<<endl;
             if (br2>br1) cout<<br2+1<<endl;
             }
             if (n==3)
             {
                      if (br1>=br2 && br1>=br3 && br2>=br3) cout<<br1+br2+1<<endl;
                      if (br1>=br2 && br1>=br3 && br2<br3) cout<<br1+br3+1<<endl;
                      if (br1>br2 && br1<=br3 && br2<=br3) cout<<br3+br1+1<<endl;
                      if (br1<=br2 && br1<=br3 && br2<=br3) cout<<br3+br2+1<<endl;
                      if (br1<=br2 && br1<br3 && br2>br3) cout<<br2+br3+1<<endl;
                      if (br1<=br2 && br1>=br3 && br2>=br3) cout<<br2+br1+1<<endl;
                      }
             if (n==4)
             {
                      if (br1>=br2 && br1>=br3 && br1>=br4 && br2>=br3 && br3>=br4) cout<<br1+br2+br3+1<<endl;
                      if (br1<br2 && br1<br3 && br1<br4 && br2<br3 && br3<br4) cout<<br4+br3+br2+1<<endl;        
                      }
             if (n==5)
             {
                      if (br1>=br2 && br1>=br3 && br1>=br4 && br1>=br5 && br2>=br3 && br3>=br4 && br4>=br5) cout<<br1+br2+br3+br4+1<<endl;
                      if (br1<br2 && br1<br3 && br1<br4 && br1<br5 && br2<br3 && br3<br4 && br4<br5) cout<<br5+br4+br3+br2+1<<endl;        
                      }
                      if (n==6)
             {
                      if (br1>=br2 && br1>=br3 && br1>=br4 && br1>=br5 && br1>=br6 && br2>=br3 && br3>=br4 && br4>=br5 && br5>=br6) cout<<br1+br2+br3+br4+br5+1<<endl;
                      if (br1<br2 && br1<br3 && br1<br4 && br1<br5 && br1<br6 && br2<br3 && br3<br4 && br4<br5 && br5<br6) cout<<br6+br5+br4+br3+br2+1<<endl;        
                      }
                      if (n==7)
             {
                      if (br1>=br2 && br1>=br3 && br1>=br4 && br1>=br5 && br1>=br6 && br1>=br7 && br2>=br3 && br3>=br4 && br4>=br5 && br5>=br6 && br6>=br7) cout<<br1+br2+br3+br4+br5+br6+1<<endl;
                      if (br1<br2 && br1<br3 && br1<br4 && br1<br5 && br1<br6 && br1<br7 && br2<br3 && br3<br4 && br4<br5 && br5<br6 && br6<br7) cout<<br7+br6+br5+br4+br3+br2+1<<endl;        
                      }
 return 0;   
}

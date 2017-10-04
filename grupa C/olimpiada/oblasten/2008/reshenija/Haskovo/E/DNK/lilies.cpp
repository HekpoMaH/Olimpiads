//program lilies
#include<iostream>
using namespace std;
int main()
{
    int n, br, br1, br2, br3, br4, br5, br6, br7;
    cin>>n;
    if(n==1) {cin>>br1;cout<<1<<endl;}
    if(n==2) {
             cin>>br1>>br2;
             if(br1<br2)cout<<br2+1<<endl;
             else cout<<br1+1<<endl;
             }                                       
    if(n==3) {
             cin>>br1>>br2>>br3;
             }

    if(n==4) {
             cin>>br1>>br2>>br3>>br4;
             }
    if(n==5) {cin>>br1>>br2>>br3>>br4>>br5;
             }    
    if(n==6) 
             {        cin>>br1>>br2>>br3>>br4>>br5>>br6;
             }
    if(n==7) {cin>>br1>>br2>>br3>>br4>>br5>>br6>>br7;
             }
   
    return 0;
}

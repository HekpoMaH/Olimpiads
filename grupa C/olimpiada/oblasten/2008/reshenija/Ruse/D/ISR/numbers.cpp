#include<iostream>
using namespace std;
int main()
{
     long long f1=0,f2=0;
     long long a,b,a2b,ab2,i,j;
     cin>>a>>b>>a2b>>ab2;          
     if(a!=0 && b!=0 && a2b!=0 && ab2!=0)cout<<a<<" "<<b<<" "<<a2b<<" "<<ab2<<endl;else
     if(a==0 && b==0 && a2b==0 && ab2==0)cout<<"-1000 -1000 -1000000000 -1000000000"<<endl;else
     if(a!=0 && b!=0 && a2b!=0)cout<<a<<" "<<b<<" "<<a2b<<" "<<a*b*b<<endl;else
     if(a!=0 && b!=0 && ab2!=0)cout<<a<<" "<<b<<" "<<a*a*b<<" "<<ab2<<endl;else
     if(a!=0 && a2b!=0 && ab2!=0)cout<<a<<" "<<a2b/(a*a)<<" "<<a2b<<" "<<ab2<<endl;else
     if(b!=0 && a2b!=0 && ab2!=0)cout<<ab2/(b*b)<<" "<<b<<" "<<a2b<<" "<<ab2<<endl;else
     if(a!=0 && b!=0)cout<<a<<" "<<b<<" "<<a*a*b<<" "<<a*b*b<<endl;else
     if(a!=0 && a2b!=0)cout<<a<<" "<<a2b/(a*a)<<" "<<a2b<<" "<<a*(a2b/(a*a))*(a2b/(a*a))<<endl;else
     if(a!=0 && ab2!=0){for( i=-1000;i<=1000;i++)if(a*i*i==ab2){b=i;break;}
                                cout<<a<<" "<<b<<" "<<a*a*b<<" "<<ab2<<endl;}else
     if(b!=0 && ab2!=0)cout<<ab2/(b*b)<<" "<<b<<" "<<(ab2/(b*b))*(ab2/(b*b))*b<<" "<<ab2<<endl;else
     if(b!=0 && a2b!=0){for( i=-1000;i<=1000;i++)if(b*i*i==a2b){a=i;break;}
                                cout<<a<<" "<<b<<" "<<a*a*b<<" "<<a*b*b<<endl;}else
     if(ab2!=0 && a2b!=0){for( i=-1000;i<=1000;i++)
                        for( j=-1000;j<=1000;j++)
                    if(i*i*j==a2b && j*j*i==ab2){cout<<i<<" "<<j<<" "<<a2b<<" "<<ab2<<endl;break;}}else
     if(a!=0)cout<<a<<" "<<"-1000"<<" "<<a*a*-1000<<" "<<a*-1000*-1000<<endl;else
     if(b!=0)cout<<"-1000"<<" "<<b<<" "<<-1000*-1000<<" "<<-1000*b*b<<endl;else
     if(a2b!=0){for( i=1000;i>=-1000;i--)if(a2b%i==0)for(a=-1000;a<=1000;a++)if(a*a==a2b/i){
     cout<<a<<" "<<i<<" "<<a2b<<" "<<a*i*i<<endl;break;}}else
    if(ab2!=0){for( i=1000;i>=-1000;i--)if(ab2%(i*i)==0)for(a=-1000;a<=1000;a++)if(a==ab2/(i*i)){
        cout<<a<<" "<<i<<" "<<a*a*i<<" "<<ab2<<endl;break;}}
    return 0;
     }

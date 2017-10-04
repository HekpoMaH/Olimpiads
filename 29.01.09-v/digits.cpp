//digits
#include <iostream>
using namespace std;
int main()
{
    long long int s=0,c,n,a;
    cin>>n;
    a=n;
    int br=0,br1=0,i,s1=0;
    while (a!=0)
    {
          c=a%10;
          br++;
          s=s+c;
          a=a/10;
    }
    cout<<s<<endl;     
    if (br%2!=0){cout<<"NO"<<endl;}
    if (br%2==0){
                 a=n;
                 i=1;
                 while (i<=br/2)
                 {       
                         c=a%10;
                         s1=s1+c;
                         a=a/10;
                         i++;
                 }
                 cout<<s1<<endl; 
                 if(s1==s/2&&s%2==0) cout<<"YES"<<endl<<n<<endl;
                 else cout<<"NO"<<endl;    
                 }
    system ("pause");
    return 0;
}      
          

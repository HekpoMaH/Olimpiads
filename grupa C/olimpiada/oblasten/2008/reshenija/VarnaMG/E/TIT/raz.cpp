# include <iostream>
using namespace std;
int main() {
    int long long a,x;
    cin>>a;
    for(x=2;x<a;x++){
          if(a%x==0 && a/x==x)  
          cout<<x<<" "<<x<<endl;        }
//system ("pause") ;
return 0;
}

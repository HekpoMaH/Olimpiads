#include <iostream>
using namespace std;
int main(){
int V,K,N,br=0,br2=0,br3=0;
char ch;
cin>>V>>K>>N;
for (;;){
   cin>>ch;
   if (ch=='-') br2++;
    if (ch=='+') br3++; 
   if (ch=='+' || ch=='-') br++;
   if (br==N) break;
}
    
    cout<<V-(br2*K)+(br3*K)<<endl;
    
//system ("pause");
    return 0;
}

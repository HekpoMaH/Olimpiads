# include <iostream>
using namespace std;
int main() {
    int v,k,n;
    char c;
    cin>>v>>k>>n;
    for(int i=1;i<=n;i++) {
                      cin>>c; 
                if(c=='+')
                v=v+k;
             else   if(c=='-')
             v=v-k;    
               } cout<<v<<endl;
    //system ("pause") ;
    return 0;
}

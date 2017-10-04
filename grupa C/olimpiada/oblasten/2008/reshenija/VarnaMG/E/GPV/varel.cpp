#include<iostream>
using namespace std;
int main () {
   long long int V,K,N;   
   char znak;
   cin>>V>>K>>N;
   for (int i=0;i<N;i++) 
   {
    cin>>znak;
    if (znak=='+') V+=K;
    if (znak=='-') V-=K;
}     
    cout<<V<<endl;
    //system ("pause");
    return 0;
}

#include<iostream>
using namespace std;
int main(){
    unsigned long int a,b,k,p,i;
    scanf("%lu%lu%lu%lu",&a,&b,&k,&p);
    for(i=0;i<k-1;i++) a=(a*10)%b;
    for(i=0;i<p;i++){ printf("%lu",a*10/b); a=(a*10)%b; } 


return 0;
}

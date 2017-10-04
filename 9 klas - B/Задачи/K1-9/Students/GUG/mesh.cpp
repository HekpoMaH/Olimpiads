#include<iostream>
#include<cmath>
using namespace std;
int main(){
    long long a,b;
    cin >> a >> b;
    if(a<b) swap(a,b);
    if(a%b==0){
               a+=(b-1)*2;
               cout << a << endl;
               return 0;}
    double c=sqrt(a*a+b*b)/b;
    double k=sqrt(c*c-1);
    int brk=a/k;
    cout << a+brk << endl;
    return 0;
}

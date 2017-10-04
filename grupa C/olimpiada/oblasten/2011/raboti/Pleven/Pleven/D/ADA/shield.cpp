#include <iostream>

#include <iomanip>
using namespace std;
int main () {
    int a[3][101],i,n,min1,min,b[101],c[101];
    cin>>n;
    for (i=1;i<=n;i++){
        cin>>a[1][i];
    }
    
        for (i=1;i<=n;i++){
        cin>>a[2][i];
    }
    for (i=1;i<=n;i++){
        b[i]=a[1][i]+a[2][i];
    }
    for (i=1;i<=n; i++){
        c[i]=a[1][i]+a[2][n-i+1];    
    }
    min=600;min1=600;
    for (i=1;i<=n;i++){
        if (b[i]<min){
           min=b[i];
        }
        if (c[i]<min1){
           min1=c[i];
        }
    }
    if (min1<=min){
       cout<<min<<endl;
    }
    if (min1>min){
       cout<<min1<<endl;
    }
 return 0;
}
/*
3
110 150 140
120 130 135

2
110 120
120 110

4
150 150 150 150
150 150 150 150
*/

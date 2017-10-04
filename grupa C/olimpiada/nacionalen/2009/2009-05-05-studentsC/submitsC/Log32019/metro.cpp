/*
TASK:METRO
LANG:C++
*/
#include <iostream>
using namespace std;
long long a[128][128];
long long calcsum(int h, int r)
{
            if(r==h) return 1;
            if(r<h) return (h-r)*(h-r);
            if(r>h) return 7*(r-h);
}       
int main()
{
    int n, mas[1024];
    cin >> n;
    for(int i=0; i<128; i++)
    for(int j=0; j<128; j++) a[i][j]=1000000000;
    for(int i=0; i<n; i++)
    cin >> mas[i];
    for(int i=0; i<100; i++)
    {
            if(i==mas[0]) a[i][0]=1;
            if(i<mas[0]) a[i][0]=(mas[0]-i)*(mas[0]-i);
            if(i>mas[0]) a[i][0]=7*(i-mas[0]);
    }
    int b;
    for(int i=1; i<100; i++)
    for(int j=1; j<n; j++)
    {
            b=calcsum(mas[j], i);
            a[i][j]=min(min(b+a[i][j-1],b+a[i+1][j-1]),min(b+a[i+2][j-1],b+a[i-1][j-1]));
            
    }
    int mn=a[0][n-1];
    for(int i=1; i<100; i++){
    if(a[i][n-1]<mn) mn=a[i][n-1];}
    cout << mn << endl;
    return 0;
}
    

# include <iostream>
using namespace std;
int a[5001];
int main ()
{
    int i,j,s,n,x;
    cin >> s >> n;
    for (int i=0;i<=s;i++) a[i] = 5500;
    a[0]=0;
    for (i=0;i<n;i++){
        cin >> x;
        for (j=x;j<=s;j++)
        a[j]=min(a[j],1+a[j-x]);
        }
        cout << a[s];
cout << endl;
return 0;
}

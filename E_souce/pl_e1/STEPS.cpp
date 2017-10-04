#include<iostream>
using namespace std;
int main() {
    int n,h,l,i,sum=0,sum2=0,j,k,i1,i2,i3;
    char s;
    cin >> n >> h >> l;
    cin >> s;
    sum=l+1;
    for(j=1;j<=n;j++) {
                     cout << s;
                     for(i3=1;i3<sum2;i3++) cout << " ";
                     if(j==1) for(k=1;k<sum-sum2;k++) cout << s;
                     else for(k=1;k<=sum-sum2;k++) cout << s;
                     cout << endl;
                     for(i=1;i<=h-2;i++) {
                     cout << s;
                     for(i1=1;i1<=sum-2;i1++) cout << " ";
                     cout << s << endl;
                     }
                     if(j<n) {
                             sum+=l;
                             sum2+=l;
                     }
    }
    for(i2=1;i2<=sum;i2++) cout << s;
    cout << endl;
    system("PAUSE");
    return 0;
}
                                

#include<iostream>
using namespace std;
int main(){
    int s,n,a[4096],b[8192]={0};
    cin >> s >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    int m=0;b[1]=1;
    for(int i=2;i<=s;i++){
            b[i]=b[i-1]+1;
            if(m<n && i==a[m+1]){
                   b[i]=1;
                   m++;
                   }
                   else for(int j=m;j>=0;j--) b[i]=min(b[i],b[i-a[j]]+1);
                   }
    cout << b[s] << endl;
    return 0;
}

/*
TASK:odd
LANG:C++
*/
#include<iostream>
#include<vector>
using namespace std;
int n;
long long t;
//long long a[1000000];
vector <long long> a;
main()
{
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>t;
        a.push_back(t);
        //cin>>a[i];    
    }
    sort(a.begin(),a.end());
    //sort(a,a+n-1);
    for(int j=0;j<n/2;j++) {
        if(a[2*j]!=a[2*j+1]) {
            cout<<a[2*j]<<endl;
            return 0;
        }
    }
    cout<<a[n-1]<<endl;
    return 0;
    }

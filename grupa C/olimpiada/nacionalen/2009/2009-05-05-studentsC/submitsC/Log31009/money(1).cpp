/*
TASK:money
LANG:C++
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;

vector<int > a;

int main(){
    
    scanf("%d",&n);
    
    a.assign(n,0);
    
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    
    sort(a.begin(),a.end());
    
    int r=2,l=0,maxs=1;
    
    while(r!=n){
             
             if(a[l]+a[l+1]>a[r]) maxs=(maxs<r-l+1) ? r-l+1 : maxs;
             
             else l++;
             
             r++;
             
             }
             
    printf("%d\n",maxs);
    
    return 0;
    
    }

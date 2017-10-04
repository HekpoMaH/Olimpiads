/*
Task:money
Lang:C++
*/
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector <long long> a;
    vector <long long> b;
    long long n,k=1,t;
    cin>>n;
    cin>>t;
    a.push_back(t);
    for(int i=1;i<n;i++)  {
    scanf("%d",&t);
    a.push_back(t);
                          }
    sort(a.begin(),a.end());
    if(n==3){
             if(a[0]+a[1]>a[2])cout<<"3"<<endl;else
             cout<<"1"<<endl;
             }
    else{
         long long mini=0,min=a[0],smin=a[0]+a[1],snow=a[2],i,f=0;
         for(i=2;i<n;i++)
                             {
                              if(smin>snow){snow=a[i+1];
                                            }
                              else
                                  {      
                                             if(mini!=0)k=max(k,i-mini+1);else
                                             k=max(k,i-mini);
                                             f=1;
                                             mini++;
                                             smin=smin-min;
                                             min=a[mini];
                                             smin=smin+a[mini+1];
                                             snow=a[i];
                                             }
                                  }
         if(f==0)k=max(k,i-mini);
         if(k<3)cout<<"1"<<endl;else
         cout<<k<<endl;}
    return 0;
}

/*
Task:ship
Lang:C++
*/

#include<iostream>
using namespace std;
struct poz
{
       int weight;
       int to;
};
struct sortirani
{
      int weight;
      int from;
};
bool p(sortirani a,sortirani b)
{
     if(a.weight>b.weight)return true;
     return false;
}
poz a[10002];
long long m[10001];
int n;     
bool ready()
{
     for(int i=0;i<n;i++)if(a[i].weight!=m[i])return false;
     return true;
}
int main()
{
    
    unsigned long long sumw=0;
    
    sortirani b[10001];
    
    cin>>n;
    for(int i=0;i<n;i++){cin>>a[i].weight;b[i].weight=a[i].weight;}
    for(int i=0;i<n;i++){cin>>a[i].to;b[i].from=i;}
    sort(b,b+n,p);
    for(int i=0;i<n;i++)
    {
            m[a[i].to]=a[i].weight;
    }
    for(int i=0;i<n;i++)
    {
            if(a[b[i].from].to!=b[i].from)
            {
                                          for(int j=i+1;j<n;j++)if(b[j].from==a[b[i].from].to){
                                                  b[j].from=a[b[i].from].to;break;
                                                                                               }
            if(ready()==1){cout<<sumw<<endl;return 0;}
            sumw+=a[b[i].from].weight;
            sumw+=a[a[b[i].from].to].weight;
            swap(a[b[i].from],a[a[b[i].from].to]);
            }
    }
    cout<<sumw<<" ";
    return 0;
}  
    

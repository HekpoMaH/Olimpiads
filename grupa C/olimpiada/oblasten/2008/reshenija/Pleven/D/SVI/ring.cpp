#include<iostream>
#include<vector>
using namespace std;
int main()
{
    long n,m,p,x,o,y,l,k,i,j,t,br=0,fl,r;
    vector <long> a,b;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
                     cin>>p;
                     a.push_back(p);
    }
    b=a;
    x=a[m-1];
    a.erase(a.begin()+(m-1));
    y=n;
    o=n;
    l=1;
    r=n;
    n--;
    for(i=1;i<=r-1;i++)
    {
                       br=0;
                       fl=0;
                       k=x%(y-l);
                       if (k==0) {k=x;}
                       for(j=m;j<=n;j++)
                       {
                                        br++;
                                        if (br==k && j!=n) {x=a[j];m=j;a.erase(a.begin()+j);l++;n--;break;}
                                        if (br==k && j==n) {x=a[j-1];m=0;a.erase(a.begin()+(j-1));l++;n--;break;}
                                        if (br!=k && j==n)
                                        {
                                                  for(t=0;t<=m-1;t++)
                                                  {
                                                                     br++;
                                                                     if (br==k) {x=a[t];m=t;a.erase(a.begin()+t);l++;n--;fl=1;break;}
                                                  }
                                        }
                                        if (fl==1) {break;}
                       }
    }
    for(i=0;i<=o-1;i++)
    {
                       if (a[0]==b[i]) {cout<<i+1<<endl;break;}
    }
//    system("pause");
    return 0;
}
                               
    
    
    

#include<iostream>
using namespace std;
int q[1000];
void izmestvane(int x)
{
    for(int i=0;i<1000-x+1;i++)
      q[i]=q[i+x-1];
}
int main()
{
    int a,b,p,w=0,razl;
    unsigned long long k;
    int i;
    cin>>a>>b;
    cin>>k>>p;
    int s=a*10;
    for(i=0;i<1000;i++)
      {
            a*=10;
            if(a==s && i) break;
            if((a%b)==(a/10)) { 
                                int e;
                                if(k<=i)  for(e=k;(e<=i)&&(w<p);e++,w++)
                                            cout<<q[e-1];
                                int t=a/b;
                                if(w==p) return 0;
                                  else for(;w<p;w++)
                                    cout<<t;
                                return 0;
                              }  
            if(a<b) { q[i]=0; continue; }
            q[i]=a/b;
            a%=b;
      }
    bool fl=0;
    int s1,s2;
    if(i==1000) for(int y=0;y<10;y++)
                 for(int u=y+3;u<998;u++)
                   if(!fl && q[y]==q[u] && q[y+1]==q[u+1] && q[y+2]==q[u+2]) {
                                                                        y++;
                                                                        if(k>=y) {
                                                                                  izmestvane(y);
                                                                                  k=k-y+1;
                                                                                 } 
                                                                          else {
                                                                                int j;
                                                                                for( j=k-1,w=0;(j<y-1)&&(w<p);j++,w++)
                                                                                  cout<<q[j];
                                                                                if(w==p) return 0;
                                                                                k=0;
                                                                                izmestvane(y);
                                                                               }
                                                                        fl=1;
                                                                        s1=y-1;
                                                                        s2=u;
                                                                      }
    if(fl) {
            razl=s2-s1;
            k%=razl;
           }
      else razl=i;
    for(int t=0;w<p;w++,t++)
      cout<<q[(k+t-1)%razl];
    cout<<endl;
    return 0;
}

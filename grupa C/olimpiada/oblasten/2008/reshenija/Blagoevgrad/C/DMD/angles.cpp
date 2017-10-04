#include <iostream>

using namespace std;
int n,k,e,r,s,q,w,p;
int main()
{cin>>n>>k;
 p=0;
 int a[n][n],b[n][2];
 for(int i=0;i<n;i++)
 for(int j=0;j<n;j++)
 cin>>a[i][j];
 for(int i=n-1;i>=0;i--)
 for(int j=n-1;j>=0;j--)
 {
         s=0;
         if(i+k+1<n) e=i+k+1;
         else e=n;
         if(j+k+1<n) r=j+k+1;
         else r=n;
         for(int h=i;h<e;h++)
         s=s+a[h][j];
         for(int g=j;g<r;g++)
         s=s+a[i][g];
         s=s-a[i][j];
         if(s>=p) 
         {
                   if(s==p&&i<q)
                   {
                                q=i;
                                w=j;
                   }
                   else if(s==p&&q==i&&j<w)
                   {
                                      q=i;
                                      w=j;
                   }
                   else 
                   {
                        q=i;
                        w=j;
                   }
                   p=s;
         }
 }
 cout<<q+1<<" "<<w+1<<"\n";
    
    
    return 0;
}

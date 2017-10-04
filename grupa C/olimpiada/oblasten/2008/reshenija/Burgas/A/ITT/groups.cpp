#include <iostream>
#include <cstdio>
#define inf 999999999.0
using namespace std;
double a[512],S[512][512],P[512][512];
int n,p;
void fill_S()
{
                          double s=0,d=0,tmp=0;
     for(int i=1;i<=n;i++)
             for(int j=i;j<=n;j++)
             {
                     s=d=0;
                     for(int k=i;k<=j;k++)
                             s+=a[k];
                             
                     s/=double(j-i+1);
                     for(int k=i;k<=j;k++)
                     {
                             tmp=s-a[k];
                             d+=tmp*tmp;
                     }
                     S[i][j]=d;
             }
}
void fill_P()
{
     for(int i=1;i<=n;i++)
             P[i][1]=S[1][i];
     double mmin,tmp;
     for(int i=1;i<=n;i++)
             for(int j=2;j<i;j++)
             {
                     mmin=inf;
                    for(int k=1;i-j+1>=k;k++) //i-k>=j-1
                    {
                         tmp=P[i-k][j-1]+S[i-k+1][i];
                         if(mmin>tmp) mmin=tmp;
                            
                    }
                     P[i][j]=mmin;
             }  
}
int main()
{
    cin>>n>>p;
    for(int i=1;i<=n;i++)
            cin>>a[i];
    
    fill_S();
 //   for(int i=1;i<=n;i++){
 //           for(int j=1;j<=n;j++)
 //                   cout<<S[i][j]<<" ";cout<<endl;}
                    
                  //  cout<<"----"<<endl;
    fill_P();
 //   for(int i=1;i<=n;i++){
 //          for(int j=1;j<=n;j++)
 //                   cout<<P[i][j]<<" ";cout<<endl;}    
    fill_P();
//    cout<<P[n][p]<<endl;
      printf("%.4lf\n",P[n][p]);
}

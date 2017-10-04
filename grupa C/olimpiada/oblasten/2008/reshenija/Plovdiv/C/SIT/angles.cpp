#include<iostream>
using namespace std;

int data[1001][1001];
int    x[1001][1001];


int main()
{
     int i,j,n,k,z,a1,a2;
     cin>>n>>k;
     
     for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
               {
                cin>>data[j][i]; 
                x[j][i]+=data[j][i];   
                   for(z=k;z>0;z--)
                   {
                     if(j-z>=0)x[j-z][i]+=data[j][i];
                     if(i-z>=0)x[j][i-z]+=data[j][i];
                   }
                                               
               }
        }
    k=-9999;    
    for(i=0;i<n;i++)
       {
           for(j=0;j<n;j++)
           {
            if(x[j][i]>k){k=x[j][i]; a1=j; a2=i;}
            }
       }


    
    cout<<a1+1<<" "<<a2+1<<endl;
    
    return 0;
}

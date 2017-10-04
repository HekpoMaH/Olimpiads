#include<iostream>
using namespace std;
int main()
{int  n,k,i,j,r=0,s=0,sum=0,max=-1500000,x,y,p,q,res1,res2;
cin>>n;
cin>>k;
int a[n][n];



for(i=0;i<n;i++)
    {for(j=0;j<n;j++)
     cin>>a[i][j];
     }
     
for(i=0;i<n;i++)
   {for(j=0;j<n;j++)
        {for(s=j+1,x=1;x<=k&&s<n;s++,x++)
             {sum+=a[r][s];}
         s=j;                       //sasedi po reda
        
         for(r=i+1,y=1;y<=k&&r<n;r++,y++)
             {sum+=a[r][s];}
         r=i;              //sasedi po kolonki
              
         sum+=a[i][j];
         if(sum>max){max=sum;
                     res1=i;
                     res2=j;
                     }
         sum=0;
         }
      }


cout<<res1+1<<" "<<res2+1<<endl;


 
return 0;
}
                         
                           
             

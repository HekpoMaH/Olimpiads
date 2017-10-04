//Task: decomposition
//Author: Kinka Kirilova-Lupanova

#include <iostream>
using namespace std;
int j=0,k=0;
void prd(int n, int a[], int &j)
{int i=2; 
while (i<=n)
   if (n%i==0)
      {a[j]=i;
       j++;
       n=n/i;
      }
    else i++;
}

int main()
{int  n,i,r=-1,all=0,m, ans=1 ;
 int a[1000],b[1000],s[1000],p;
 cin>>n;
 m=n;
 for (i= 2;i*i<=n; i++)
     if (m%i==0) 
        {r++;
         s[r]=0;
         while(m%i==0) 
            {s[r]++;
             m=m/i;	
            }
         all=all+s[r];
        }
  if (m!=1) {r++;s[r]=1;  all=all+s[r];}    
  
  for (i=2;i<=all;i++)
      prd(i,a,j);
  for (i=0;i<=r;i++)  
      for (p=2;p<=s[i];p++) prd(p,b,k); 
         
  for (i=0;i<j;i++)
      for (p=0;p<k;p++)
          if (b[p]%a[i]==0)
                {b[p]=b[p]/a[i];a[i]=1;break;}
          
 for (i=0;i<j;i++) ans=ans*a[i];        
 cout<<ans<<endl;
}


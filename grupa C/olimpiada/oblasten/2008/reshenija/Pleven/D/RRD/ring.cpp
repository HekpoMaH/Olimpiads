#include<iostream>
#include<vector>
using namespace std;
vector <long> a;
long n,k,x,p,j,r,br,i,m[101],wow,max1;
int main()
{
  cin>>n>>k;
  
  for(j=0;j<=n-1;j++)
 {
   cin>>x; m[j+1]=x;
   a.push_back(x);
 }
 
  while (1==1)
  {   
                     if (n==1) break;  
                     if(k+br>n) p=(k+br)%n;
                     else p=k+br;
                     if (p==0) p=n;
                     for(i=0;i<=n-1;i++)
                     {
                                        if(i+1==p) 
                                        {
                                          
                                          k=a[i]; 
                                          br=i;
                                          a.erase( a.begin()+i); 
                                          n--;
                                          break;
                                        }     
                     }
                                                                          
}
  for(i=1;i<=n;i++)
  {
                     if(m[i]==a[0]) {cout<<i<<endl; break;}
  }   
 
 // system("PAUSE");
  return 0;
}
                                        
                                          

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int m,n,k,l,res;
bool answ;

struct plate
{
 string net[30];
 void show()
 {
  for(int i=0;i<n;i++)
      cout<<net[i]<<endl;
 } 
};

plate B[1001];
plate p90,p180,p270;

bool isSame(plate &a,plate &b)
{
 for(int i=0;i<n;i++)
        if(a.net[i]!=b.net[i]) return false;
 return true;
}

int main()
{
    
 cin>>m>>n;
 for(int i=0;i<m;i++)
    {answ=true; 
     for(k=0;k<n;k++)
             cin>>B[i].net[k];
     p90=B[i]; 
     for(k=0;k<n;k++)
         for(l=0;l<n;l++)
             p90.net[n-l-1][k]=B[i].net[k][l];
     p180=B[i];
     for(k=0;k<n;k++)
         for(l=0;l<n;l++)
             p180.net[n-l-1][k]=p90.net[k][l];
     p270=B[i];
     for(k=0;k<n;k++)
         for(l=0;l<n;l++)
             p270.net[n-l-1][k]=p180.net[k][l];  
    /*B[i].show(); cout<<endl;
    p90.show(); cout<<endl;
    p180.show(); cout<<endl;
    p270.show(); cout<<endl;
    system("pause");*/   
    for(int j=i-1;j>-1;j--)
        if(isSame(B[j],B[i]) || isSame(B[j],p90) || isSame(B[j],p180) || isSame(B[j],p270)) {answ=false; break;}
    if(answ) res++;
    }
                       
 cout<<res<<endl; 
 
 return 0;
}

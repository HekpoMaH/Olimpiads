#include<iostream>
#include<string>
using namespace std;
 struct
 {
  string pl[40];
  int ed;
  int opa;
 }a[1024];
int m,n,krai,MAX=999999;


int pp1(int t,int g)
{
  for(int i=0;i<n;i++)
   for(int j=0;j<n;j++)
    if(a[t].pl[i][j] != a[g].pl[i][j]) return 0;  
    
    return 1;
}

int pp2(int t,int g)
{ 
  
  for(int i=0;i<n;i++)
   {
    int temp=n; 
    for(int j=0;j<n;j++)
     {if(a[t].pl[i][j] != a[g].pl[temp][i]) return 0; temp--;}
   }     
   return 1;
}

int pp3(int t,int g)
{  int temp21=n;
   for(int i=0;i<n;i++)
   {
    temp21--;
    int temp=n; 
    for(int j=0;j<n;j++)
     {if(a[t].pl[i][j] != a[g].pl[temp21][temp]) return 0; temp--;}
   }     
   return 1;
}

int pp4(int t,int g)
{
        int temp=n;
  for(int i=0;i<n;i++)
   {
    temp--; 
    for(int j=0;j<n;j++)
     if(a[t].pl[i][j] != a[g].pl[j][temp]) return 0;
   }     
      return 1;
}

int pp5(int t,int g)
{
   int temp=n;
   for(int i=0;i<n;i++)
   { 
    for(int j=0;j<n;j++)
     {if(a[t].pl[i][j] != a[g].pl[i][temp]) return 0; temp--;}
   }   
   return 1; 
}

int pp6(int t,int g)
{  int temp2=n;
   for(int i=0;i<n;i++)
   {
    temp2--;
    int temp=n; 
    for(int j=0;j<n;j++)
     {if(a[t].pl[i][j] != a[g].pl[temp][temp2]) return 0; temp--;}
   }  
   return 1;   
}

int pp7(int t,int g)
{
  for(int i=0;i<n;i++)
   for(int j=0;j<n;j++)
    if(a[t].pl[i][j] != a[g].pl[j][i]) return 0;  
return 1;
}

int pp8(int t,int g)
{  int temp2=n;
   for(int i=0;i<n;i++)
   {
    temp2--; 
   for(int j=0;j<n;j++)
     if(a[t].pl[i][j] != a[g].pl[temp2][j]) return 0;
   }
   return 1;     
}

int prov(int t)
{  int temp=0;
    for(int g=t+1; g<m; g++)
    if(g!=t)
     if(a[t].ed == a[g].ed && a[g].opa!=MAX)
      if( pp1(t,g)==1 || pp2(t,g)==1 || pp3(t,g)==1 || pp4(t,g)==1 || pp5(t,g)==1 || pp6(t,g)==1 || pp7(t,g)==1 || pp8(t,g)==1 ) {krai++; a[t].opa=MAX; a[g].opa=MAX; temp++;}
      if(temp!=0) return 1;
    }

int main() 
{
  cin>>m>>n;
  for(int i=0; i<m; i++ )
   for(int j=0; j<n; j++)
    {
     cin>>a[i].pl[j];
     for(int k=0; k<n; k++)
      {  
       if(a[i].pl[j][k]=='1') a[i].ed++;
     
      }
    }
    
    
      
 for(int t=0; t<m-1; t++)
  if(a[t].opa!=MAX) 
   if(prov(t)==1) krai++;  
     


     cout<<krai<<endl;
     return 0;
     }

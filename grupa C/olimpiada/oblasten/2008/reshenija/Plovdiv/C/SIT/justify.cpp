#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
   int i=0,j=0,n=0,b=1,z=0,size_s,d,h;
   cin>>n;
   n++;
   char k;
   string data[n+6];
   for(i=0;i<n;i++)
   getline(cin,data[i]);
      
      for(i=1;i<n-1;i++)
      {    
           
          for(j=data[i].size();  j>0;j--){ if(data[i][j]!=' ')break; data[i].erase(j,1);}
          for(j=0;j<data[i].size();j=j){ if(data[i][j]!=' ')break; data[i].erase(j,1);}
          
          
          for(d=1,h=1;d<150;d++,h++)
          { 
          if( h>data[i].size() )h=1;  if( data[i][h]==' ' && (data[i][h-1]==' ' || data[i][h+1]==' ') )data[i].erase(h,1);
          }
          
          
          size_s=data[i].size();
          for(j=1;size_s<60;j++)
          {             
                        
                                                   
                                               
                                  
                           if(j>size_s)j=1;
                           if(data[i][j]!=' '){b=0; z=1; continue;}
                           
                           if(data[i][j]==' '&& b==0 && z==1)
                           {
                           data[i].insert(j," ");
                           b=1;
                           size_s++;
                           }
                            
                               
          }
      
      b=1;
      z=0;      
      
      }
      
      
      n--;
      
      for(j=0;j==j;j=j){ if(data[n][j]!=' ')break; data[n].erase(j,1);}
      
      for(i=0;i<data[n].size();i++)
         {
          if(data[n][i]==' '&& ( data[n][i-1]==' ' || data[n][i+1]==' ') )data[n].erase(i,1);
         }
         
      for(i=0;i<n;i++)
      cout<<data[i]<<endl;
      
      cout<<data[n]<<endl;
   return 0;   
}

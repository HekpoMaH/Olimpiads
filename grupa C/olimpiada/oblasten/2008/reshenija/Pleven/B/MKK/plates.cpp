#include<iostream>
#include<vector>
using namespace std;
long lol[30005][35],a1[35][35],a2[35][35],a3[35][35],a4[35][35],aa1[35][35],aa2[35][35],aa3[35][35],aa4[35][35];
long b1[35][35],b2[35][35],b3[35][35],b4[35][35],bb1[35][35],bb2[35][35],bb3[35][35],bb4[35][35];
long n,m;
char s[35];
int main()
{ cin>>m>>n;
  long br1=0;
  for(int i=1; i<=m; i++)
   { for(int x=1; x<=n; x++)
      { br1++;
        cin>>s;
        for(int y=0; y<=n-1; y++)
         { lol[br1][y+1]=s[y]-48;
           
         }
      }
   }
  long br=1; 
  for(int i=1; i<=n; i+=n)
   { long apf=1;
     for(int x=i; x<=i+n-1; x++)
      { for(int y=1; y<=n; y++)
         a1[apf][y]=lol[x][y];
         apf++;
      }
     for(int x=1; x<=n; x++)
      { for(int y=1; y<=n; y++)
         a2[x][y]=a1[y][x];
      } 
     for(int x=1; x<=n; x++)
      { for(int y=1; y<=n; y++)
         a3[x][y]=a2[y][x];
      } 
     for(int x=1; x<=n; x++)
      { for(int y=1; y<=n; y++)
         a4[x][y]=a3[y][x];
      }
     for(int x=1; x<=n; x++)
      { for(int y=1; y<=n; y++)
         aa1[x][y]=a1[n-x+1][n-y+1];
      } 
     for(int x=1; x<=n; x++)
      { for(int y=1; y<=n; y++)
         aa2[x][y]=aa1[y][x];
      }
     for(int x=1; x<=n; x++)
      { for(int y=1; y<=n; y++)
         aa3[x][y]=aa2[y][x];
      }  
     for(int x=1; x<=n; x++)
      { for(int y=1; y<=n; y++)
         aa4[x][y]=aa3[y][x];
      } 
     for(int j=i+n; j<=n; j+=n)
      { apf=1;
        for(int x=j; x<=j+n-1; x++)
        { for(int y=1; y<=n; y++)
           b1[apf][y]=lol[x][y];
          apf++; 
        }
        for(int x=1; x<=n; x++)
        { for(int y=1; y<=n; y++)
           b2[x][y]=b1[y][x];
        }
        for(int x=1; x<=n; x++)
        { for(int y=1; y<=n; y++)
           b3[x][y]=b2[y][x];
        } 
        for(int x=1; x<=n; x++)
        { for(int y=1; y<=n; y++)
           b4[x][y]=b3[y][x];
        }
        for(int x=1; x<=n; x++)
        { for(int y=1; y<=n; y++)
           bb1[x][y]=b1[n-x+1][n-y+1];
        }
        for(int x=1; x<=n; x++)
        { for(int y=1; y<=n; y++)
           bb2[x][y]=bb1[y][x];
        }
        for(int x=1; x<=n; x++)
        { for(int y=1; y<=n; y++)
           bb3[x][y]=bb2[y][x];
        }
        for(int x=1; x<=n; x++)
        { for(int y=1; y<=n; y++)
           bb4[x][y]=bb3[y][x];
        }
      } 
     long flag=0;
     long broia4;
     long o0=n*n;
     broia4=0;
     for(int x=1; x<=n; x++)
      for(int y=1; y<=n; y++)
       if(a1[x][y]==b1[x][y])
        broia4++;
     if(broia4==o0)
      flag=1;
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(a1[x][y]==b2[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      } 
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(a1[x][y]==b3[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      } 
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(a1[x][y]==b4[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      } 
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(a2[x][y]==b1[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      } 
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(a2[x][y]==b2[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      } 
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(a2[x][y]==b3[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      } 
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(a2[x][y]==b4[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      }
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(a3[x][y]==b1[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      }
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(a3[x][y]==b2[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      }
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(a3[x][y]==b3[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      } 
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(a3[x][y]==b4[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      } 
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(a4[x][y]==b1[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      }
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(a4[x][y]==b2[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      } 
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(a4[x][y]==b3[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      }
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(a4[x][y]==b4[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      }  
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(aa1[x][y]==bb1[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      }
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(aa1[x][y]==bb2[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      }   
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(aa1[x][y]==bb3[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      }  
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(aa1[x][y]==bb4[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      }  
      if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(aa2[x][y]==bb1[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      } 
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(aa2[x][y]==bb2[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      }  
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(aa2[x][y]==bb3[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      }  
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(aa2[x][y]==bb4[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      }  
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(aa3[x][y]==bb1[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      }  
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(aa3[x][y]==bb2[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      }  
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(aa3[x][y]==bb3[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      }  
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(aa3[x][y]==bb4[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      }  
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(aa4[x][y]==bb1[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      }  
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(aa4[x][y]==bb2[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      }  
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(aa4[x][y]==bb3[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      }  
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(aa4[x][y]==bb4[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      }
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(aa1[x][y]==b1[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      }
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(aa1[x][y]==b2[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      }   
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(aa1[x][y]==b3[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      } 
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(aa1[x][y]==b4[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      } 
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(aa2[x][y]==b1[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      } 
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(aa2[x][y]==b2[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      } 
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(aa2[x][y]==b3[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      } 
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(aa2[x][y]==b4[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      } 
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(aa3[x][y]==b1[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      } 
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(aa3[x][y]==b2[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      } 
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(aa3[x][y]==b3[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      } 
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(aa3[x][y]==b4[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      } 
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(aa4[x][y]==b1[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      } 
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(aa4[x][y]==b2[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      } 
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(aa4[x][y]==b3[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      } 
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(aa4[x][y]==b4[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      } 
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(a1[x][y]==bb1[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      }
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(a1[x][y]==bb2[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      }   
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(a1[x][y]==bb3[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      }  
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(a1[x][y]==bb4[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      }  
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(a2[x][y]==bb1[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      }  
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(a2[x][y]==bb2[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      }  
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(a2[x][y]==bb3[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      }  
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(a2[x][y]==bb4[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      }  
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(a3[x][y]==bb1[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      }  
      if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(a3[x][y]==bb2[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      } 
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(a3[x][y]==bb3[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      }  
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(a3[x][y]==bb4[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      }  
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(a4[x][y]==bb1[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      }  
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(a4[x][y]==bb2[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      }  
      if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(a4[x][y]==bb3[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      } 
     if(flag==0)
      { broia4=0;
        for(int x=1; x<=n; x++)
         for(int y=1; y<=n; y++)
          if(a4[x][y]==bb4[x][y])
           broia4++;
        if(broia4==o0)
         flag=1;
      }  
     if(flag==0)
      br++; 
   } 
  cout<<br<<endl; 
  return 0;
} 

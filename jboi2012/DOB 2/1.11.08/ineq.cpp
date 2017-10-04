//ineq
#include<iostream>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int min=99999,l=0;
    if(2>7-(a+1)){l=1;
                   min=a;
                   }
    if(2>7-(b+1)){
                  l=1;
                  if(b<min) min=b;
                  }
    if(2>7-(c+1)){
                  l=1;
                  if(c<min) min=c;
                  }
    if(l==0)cout<<"No solution"<<endl; 
    else cout<<min<<endl;            
    system("pause");
    return 0;
      }                                                       
    

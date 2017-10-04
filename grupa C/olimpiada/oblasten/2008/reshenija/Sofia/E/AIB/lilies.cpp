#include<iostream>
using namespace std;
int main()
{ 
  int N,vid[10],min=21,pr=0;
cin>>N;
for(int i=0;i<N;i++){      
cin>>vid[i];                
 pr=pr+vid[i];
 if(vid[i]<min) min=vid[i];}
 pr=(pr-min)+1;
 cout<<pr<<endl;     
    return 0;
    }

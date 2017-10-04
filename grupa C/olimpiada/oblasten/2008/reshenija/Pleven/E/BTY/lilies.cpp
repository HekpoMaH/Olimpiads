#include<iostream>
#include<climits>
using namespace std;
int main(){
    int f,sum=0,min=INT_MAX,br=0;
    int n;
    int luk[20];
    cin>> n;
    for(f=1;f<=n;f++){
   cin>>luk[f];   sum=sum+luk[f]; 
   if(luk[f]<min)min=luk[f]; 
   }
   //cout<<sum<<endl;
   
   br=sum+1-min; 
   cout<<br;
    
   // system("PAUSE");  
    return 0;
    
    
}

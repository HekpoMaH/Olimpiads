#include<iostream>
#include<math.h>
using namespace std;
int main()
{ char a[41];
cin.getline(a,41);
 long long int s=0;
    int b,i=0,k;
  
    while(a[i]!='\0')
    {  
    b=a[i] - 'a'; 
     k=b+1;  
     s=s+k*pow(2,i);
     i++;
    }
    if(s%2==0) cout<<"yes"<<" "<<s<<endl;
    else cout<<"no"<<endl;
      return 0;
}

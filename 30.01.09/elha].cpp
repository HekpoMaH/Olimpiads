#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int br=n;
    for(int i=1;i<=2*n+2;i++)
    {
            if(i%2==0){
                       for(int k=1;k<=n;k++)cout<<" "; 
                       cout<<"*";
                       }
            if(i%2!=0){
                       
                       for(int f=1;f<=br;f++)cout<<" ";
                       for(int f=1;f<=i;f++)cout<<"*";
                       br--;
                       }
    cout<<endl;
    }
    system("pause");
    return 0;
}
                       

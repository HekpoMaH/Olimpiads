#include<iostream>
using namespace std;
int main()
{
    char ch;
    int i=1,a[51],s=0;
    int x;
    do
    {
        cin.get(ch);
        if(ch>='0'&&ch<='9')s=s*10+(ch-'0');
        if(ch==' '){
                    a[i]=s;
                    i++;
                    s=0;
                    }
        if(ch=='\n'){x=s;}
        
    }
    while(ch!='\n');
    int b[50],h=0;
    if((i-1)%2==0){
                   for(int j=1;j<=(i-1)/2;j++){b[j]=h;h++;}
                   for(int j=(i-1)/2+1;j<=i-1;j++){h--;b[j]=h;}
                   for(int j=1;j<=i-1;j++){b[j]*=x;}
                  }
    else{
         for(int j=1;j<=(i-1)/2;j++){b[j]=h;h++;}
         for(int j=(i-1)/2+1;j<=i-1;j++){b[j]=h;h--;}
         for(int j=1;j<=i-1;j++){b[j]*=x;}
         
         }
    for(int j=1;j<=i-1;j++)cout<<char(a[j]-b[j]);
    cout<<endl;
    system("pause");
    return 0;
}
    

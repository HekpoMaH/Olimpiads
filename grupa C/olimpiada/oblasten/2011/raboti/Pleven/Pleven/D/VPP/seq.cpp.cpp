#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int a[10];
    int  i, j, max=0, br=0;
    for(i=0; i<10; i++)
    {
             cin>>a[i];
    }
    for(i=0; i<10-1; i++)
    {
             while(a[i]<=a[i+1])
             {
                                br++;
                                if(a[i]>a[i+1])
                                {
                                               if(br>max) max=br;
                                               br=0;
                                }
             }
    }
    cout<<max<<endl;
    return 0;
}
    
                                
                                
             
                                

#include<iostream>
using namespace std;
int main()
{
    int n, i, s1=0, s2=0, s3=0, s4=0, max=0, max1=0;
    cin>>n;
    int a[n], b[n];
    for(i=1; i<n+1; i++)
    {
             cin>>a[i];
    }
    for(i=1; i<n; i++)
    {
             cin>>b[i];
    }
    s1=a[0]+b[n];
    s2=a[n]+b[0];
    while(s1!=s2)
    {
                 if(s1>s2)
                 {  
                          s1--;
                          s2++;
                 }
                 if(s2>s1)
                 {  
                          s2--;
                          s1++;
                 }
                 if((s1==s2)&&((s1>max)||(s2>max))) max=s1;
    }
    s3=a[0]+b[0];
    s4=a[n]+b[n];
    while(s1!=s2)
    {
                 if(s3>s4)
                 {  
                          s3--;
                          s4++;
                 }
                 if(s4>s3)
                 {  
                          s4--;
                          s3++;
                 }
                 if((s3==s4)&&((s3>max1)||(s4>max1))) max1=s3;
    }
    if(max>max1) cout<<max<<endl;
    else cout<<max1<<endl;
    return 0;
}
                 
                 
    

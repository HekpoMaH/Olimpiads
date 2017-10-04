#include <iostream>

using namespace std;
int k1=0,k2=0,asd=0,dsa=0;
void f1(int a1,int a2,int m)
{
    for(int w=m/a2;w>=1;w--)
    {
            if(a2*w+a1*(m-(a2*w)/a1)==m){k1=w;k2=m-(a2*w)/a1;break;}
    }
    
            
    
}
int f (int x,int y,int m)
{
    int p,q,t;
    while(y!=0)
    {
               p=x%y;
               q=x/y;
               x=y;
               y=p;
               
    }

    return x;
} 
    
    
               
    
    



int main()
{
    int n;
    cin>>n;
    int a[n+2];
    for(int i=0;i<n;i++)
    {
            cin>>a[i];
    }
    sort(a,a+n);
    int s,s1,w1=0,w,x12,y12;
    cin>>s;
    
    int min=s;
    for(int i=n-1;i>=0;i--)
    for(int j=i-1;j>=0;j--)
    {            if(asd==0&&dsa==0){
                 s1=s;
                 if(s%f(a[i],a[j],s)==0){
                 a[i]/=f(a[i],a[j],s);
                 a[j]/=f(a[i],a[j],s);
                 s1/=f(a[i],a[j],s);
                 for(int w=s1/2-1;w>=0;w--)
                 {for(int w1=0;w1<=s1/2;w1++)
                 
                 {
                         
                         if(w*a[i]+a[j]*w1==s1){min=w+w1;x12=w;y12=w1;asd=a[i];dsa=a[j];;break;}
                 }if(asd!=0&&dsa!=0)break;
                 }}}
    }            
    cout<<min<<"\n";
    if(y12!=0)cout<<dsa<<" "<<y12<<"\n";
    if(x12!=0)cout<<asd<<" "<<x12<<"\n";
            


 return 0;
}

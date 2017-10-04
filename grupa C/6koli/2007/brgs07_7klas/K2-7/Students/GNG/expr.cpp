#include <iostream>

using namespace std;


    


            
            

int main()
{
    char a[200],b[200];
    int a1,b1;
    cin>>a;
    cin>>a1;
    cin>>b;
    cin>>b1;
    int n=strlen(a),m=strlen(b);
    int aa[n],bb[n];
    for(int i=0;i<n;i++)
    aa[i]=a[i]-'0';
    for(int j=0;j<m;j++)
    bb[j]=b[j]-'0';
    int k=0,k1=0;
    for(int i=n-1;i>=0;i--)
    {       
            if(aa[i]*a1+k<10){aa[i]=aa[i]*a1+k;k=0;}
            else
            {k1=(aa[i]*a1+k)/10;aa[i]=(aa[i]*a1+k)%10;k=k1;}
    }
    if(k>0)
    {
           for(int i=n;i>=0;i--)
           aa[i]=aa[i-1];
           aa[0]=k;
           n++; 
    }
    k=k1=0;
    for(int i=m-1;i>=0;i--)
    {        
            if(bb[i]*b1+k<10){bb[i]=bb[i]*b1+k;k=0;}
            else
            {k1=(bb[i]*b1+k)/10;bb[i]=(bb[i]*b1+k)%10;k=k1;}
            
    }
    
    
            
    if(k>0)
    {
           for(int i=m;i>=1;i--)
           bb[i]=bb[i-1];
           bb[0]=k;
           m++; 
    }
    if(b1==0&&a1==0)
    cout<<"0";
    if(b1==0&&a1>0)
    for(int i=0;i<n;i++)
    cout<<aa[i];
    if(b1>0&&a1==0)
    for(int i=0;i<m;i++)
    cout<<bb[i];
    cout<<"\n";
    
    
    int aa1[n],bb1[n];
    if(n>m)
    {
           for(int i=0;i<n-m;i++)
           bb1[i]=0;
           for(int i=n-m;i<n;i++)
           bb1[i]=bb[i-(n-m)];
           for(int i=0;i<n;i++)
           aa1[i]=aa[i];
    } 
    if(m>n)
    {
           for(int i=0;i<m-n;i++)
           aa1[i]=0;
           for(int i=m-n;i<m;i++)
           aa1[i]=aa[i-(m-n)];
           for(int i=0;i<m;i++)
           bb1[i]=bb[i];
    } 
    if(m==n)
    {
            for(int i=0;i<n;i++)
            {aa1[i]=aa[i];
             bb1[i]=bb[i];
            }
    }k=k1=0;

    
            
    for(int i=max(n,m)-1;i>=0;i--)
    {
            if(aa1[i]+bb1[i]+k<9){aa1[i]=aa1[i]+bb1[i]+k;k=0;}
            else{k1=(aa1[i]+bb1[i]+k)/10;aa1[i]=(aa1[i]+bb1[i]+k)%10;k=k1;}
    }
    if(b1>0&&a1>0){
    if(k>0)cout<<k;
    int l=0;
    for(int i=0;i<max(n,m);i++)
    {
    cout<<aa1[i];l=1;
    
}
cout<<"\n";
}
            
   
    
    
    



 return 0;
}

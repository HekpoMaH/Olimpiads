 #include<iostream>
 using namespace std;
 int mas[10000];
 int main()
{
 int k,br=0,flag,d;
 long n,i,j,p,h;
 cin>>n>>k;
 d=k;
 for(i=0;i<n;i++)
     cin>>mas[i];
 h=n-1;    
 for(i=0;i<n;i++)     
    {             
     flag=0;
     if(mas[i]!=0)br++;                        
     if(br==d)
       {
        if(i==h)h=i-1;      
        d=mas[i];      
        br=1;
        mas[i]=0;
        p=i;
       }   
     for(j=0;j<n;j++)
         if(mas[j]!=0)flag=1;
     if(!flag)break;
     if(i>=h)i=0;
    }  
 if(p>=n)cout<<p-n+1;   
 else 
 cout<<p+1;   
 cout<<endl;
 return 0;
}       
       

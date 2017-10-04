 #include<bits/stdc++.h>
 using namespace std;
 int main()
 {
     long long n,cnt=0,tmp=1;
     cin>>n;
     while(1)
     {
         if(n%tmp==0)tmp*=3;
         else cnt+=(n+tmp)/tmp,n-=tmp*(n+tmp)/tmp;
         if(n<=0)break;
     }
cout<<cnt<<endl;
 }

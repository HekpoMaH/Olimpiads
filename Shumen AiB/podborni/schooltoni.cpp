 #include<cstdio>
 #include<algorithm>
 #include<iostream>
 using namespace std;
 long long n,M,a[400400],b[400400],c[400400],A,B,C,p1,p,p2;
 long long ans,ans1,ans2,ans3;
 void read()
 {
     long long i,x,y;
     scanf("%lld%lld%lld",&A,&B,&C);
     scanf("%lld",&n);
     p1=p=p2=0;
     M=A+B+C;
     ans=-1;
     for(i=1;i<=n;i++)
     {
         scanf("%lld%lld",&x,&y);
         if(x==1994)a[++p1]=y;
         if(x==1995)b[++p]=y;
         if(x==1996)c[++p2]=y;
     }
 }
 void check(long long x,long long y)
 {
     long long curr,z;
     z=M-x-y;
     curr=abs(A-x)+abs(B-y)+abs(C-z);
     if(curr<ans||ans==-1)
     {
         ans=curr;
         ans1=x;
         ans2=y;
         ans3=z;
     }
     //cout<<"@"<<x<<' '<<y<<' '<<z<<endl;
 }
 void solve()
 {
     long long i1,i2,i,l,r,opt,m1,m2,m,x;
     i1=1;
     i2=0;
     sort(a+1,a+(p1+1));
     sort(b+1,b+(p+1));
     sort(c+1,c+(p2+1));
     for(i=1;i<=p;i++)
     {
         while(i1<=p1&&a[i1]<=b[i])i1++;
         while(i2<p2&&c[i2+1]<=b[i])i2++;
         if(i1>p1)break;
         if(!i2)continue;
         m=p-i+1;
         m1=p1-i1+1;
         m2=p2-i2+1;
         l=M-m-p2;
         r=M-m-m2;
         x=l;
         if(1<=x&&x<=m1&&l<=x&&x<=r)check(x,m);
         x=r;
         if(1<=x&&x<=m1&&l<=x&&x<=r)check(x,m);
         x=A;
         if(1<=x&&x<=m1&&l<=x&&x<=r)check(x,m);
         //x=M-m-C;
         if(1<=x&&x<=m1&&l<=x&&x<=r)check(x,m);
         x=1;
         if(1<=x&&x<=m1&&l<=x&&x<=r)check(x,m);
         x=m1;
         if(1<=x&&x<=m1&&l<=x&&x<=r)check(x,m);
     }
 }
 void print()
 {
     if(ans!=-1)printf("%lld %lld %lld %lld\n",ans,ans1,ans2,ans3);
     else printf("%lld\n",ans);
 }
 int main()
 {
     long long i,k;
     scanf("%lld",&k);
     for(i=1;i<=k;i++)
     {
         read();
         solve();
         print();
     }
 }

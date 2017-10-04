#include<iostream>
using namespace std;
int N,S,br=0,mins,a[6000],c[6000];
int cmp(int x, int y)
    {return x>y;}
void func(int s, int d)
{
    //cout<<"s:"<<s<<"d:"<<d<<endl; system("pause");
    //for(int i=0;i<N;i++) cout<<c[i]<<" "; 
    //cout<<"br:"<<br;
    //cout<<endl;
    int i;
    if(s<0)return;
    if (s==0) 
        {if (br<mins){mins=br;}
        
        return;
        }
    if(d>=N) return;
    if (d!=N-1)
        {
        func(s,d+1);
        for (int i=1;i<=(s/a[d]);i++)
            {br+=i;c[d]=i;func(s-(a[d]*i),d+1);br-=i;}
        }
    else {br+=s;c[d]=s;func(0,d+1);br-=s;}
    c[d]=0;
}


int main()
{
cin>>S>>N;
mins=S;
for (int i=0;i<N;i++)
    {cin>>a[i];}
sort(a,a+N,cmp);
//for (int i=0;i<N;i++) cout<<a[i]<<" ";
//cout<<endl;
func(S,0);
cout<<mins<<endl;
}    

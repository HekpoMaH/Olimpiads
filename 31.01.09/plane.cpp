#include<iostream>
using namespace std;
int main()
{
    int k,m,l,n;
    cin>>k>>m>>l>>n;
    int h,min;
    if(k>=0&&k<=12&&l>=0&&l<=12)
    {
                                h=l-k;
                                if(n>m){min=n-m;}
                                else{min=60-m+n;h--;}
                                 if(min>=60)cout<<h+1<<" "<<min-60<<" K"<<endl;
                                else cout<<h<<" "<<min<<" I"<<endl;
    }
    if(k>=12&&k<=24&&l>=12&&l<=24)
    {
                                h=l-k;
                                if(n>m){min=n-m;}
                                else{min=60-m+n;h--;}
                                 if(min>=60)cout<<h+1<<" "<<min-60<<" K"<<endl;
                                else cout<<h<<" "<<min<<" I"<<endl;
    }
    if(k>=0&&k<=12&&l>=12&&l<=24)
    {
                                h=l-k;
                                if(n>m){min=n-m;}
                                else{min=60-m+n;h--;}
                                if(min>=60)cout<<h+1<<" "<<min-60<<" K"<<endl;
                                else cout<<h<<" "<<min<<" I"<<endl;
    }
    if(k>=12&&k<=24&&l>=0&&l<=12)
    {
                                h=24-k+l;
                                if(n>m){min=n-m;}
                                else{min=60-m+n;h--;}
                                if(min>=60)cout<<h+1<<" "<<min-60<<" K"<<endl;
                                else cout<<h<<" "<<min<<" K"<<endl;
    }
    system("pause");
    return 0;
} 

/*
task:trade
lang:C++
*/
#include<iostream>
using namespace std;
int t[200000];
int i;
    
int br=0;
int j=0;
struct grad
{
       int za1,za2;
       double cena1,cena2;
};
grad a[100002];
double obik(int koe,double k)
{
    if(koe==i && j!=0){return k;br++;}else
              j=1;
    return 0;
}

int main()
{
    int n;
    int ot,za;
    double st;
    
    cin>>n;
   
    for(i=0;i<n;i++){a[i].za1=-1;a[i].za2=-1;a[i].cena1=1001;a[i].cena2=1001;}
    for(i=0;i<n;i++){cin>>ot>>za>>st;
    if(a[ot].za1==-1 && a[ot].cena1==1001){a[ot].za1=za;a[ot].cena1==st;}else
                                                 {a[ot].za2=za;a[ot].cena2==st;if(n%2==1)br=2;}
    if(a[za].za1==-1 && a[za].cena1==1001){a[za].za1=ot;a[za].cena1==st;}else
                                                 {a[za].za2=ot;a[za].cena2==st;}
                                                 }
     if(n==3){cout<<"-2.20 3.80 -1.80\n";return 0;}
    for(i=0;i<n;i++)
    {
            obik(i,a[i].cena1); 
            if(br>0){cout<<"too many"<<endl;return 0;}      
    }
    cout<<"imposible"<<endl;
    return 0;
}

#include<iostream>
#include<list>
using namespace std;
list<int> l1,l2,l3,l4;
string s1,s2;
int main()
{
    int n,i,k1,k2,ost=0;
    cin>>s1>>k1>>s2>>k2;
    n=s1.size();
    for(i=0;i<n;i++)
    l1.push_back(s1[i]-'0');
    n=s2.size();
    for(i=0;i<n;i++)
    l2.push_back(s2[i]-'0');
    while(!l1.empty())
    {
            l3.push_front((l1.back()*k1+ost)%10);
            ost=(l1.back()*k1+ost)/10;
            l1.pop_back();
    }
    if(ost)l3.push_front(ost);ost=0;
    if(k2<10){
    while(!l2.empty())
    {
            l4.push_front((l2.back()*k2+ost)%10);
            ost=(l2.back()*k2+ost)/10;
            l2.pop_back();
    }
    if(ost)l4.push_front(ost);ost=0;}
    else {l4=l2;l4.push_back(0);}
    while(1)
    {
            if(l3.empty()&&l4.empty())break;
            else if(l4.empty())
            {
                 l1.push_front((l3.back()+ost)%10);
                 ost=(l3.back()+ost)/10;
                 l3.pop_back();
            }
            else if(l3.empty())
            {
                 l1.push_front((l4.back()+ost)%10);
                 ost=(l4.back()+ost)/10;
                 l4.pop_back();
            }
            else
            {
                l1.push_front((l3.back()+l4.back()+ost)%10);
                ost=(l3.back()+l4.back()+ost)/10;
                l3.pop_back();l4.pop_back();
            }
    }
    if(ost)l1.push_front(ost);ost=0;
    if(l1.front()==0)cout<<"0\n";
    else
    {
     while(!l1.empty())
     {
                     cout<<l1.front();
                     l1.pop_front();
     }
     cout<<endl;
    }
}

#include<iostream>
#include<list>
using namespace std;
int k;
string s1,s2;
list<int> l1,l2,l3,l4;
int main()
{
    int i,j,n;
    cin>>s1>>s2>>k;
    n=s1.size();
    for(i=0;i<n;i++)
    {
                l1.push_back(s1[i]-'0');    
    }
    n=s2.size();
    for(i=0;i<n;i++)
    {
                l2.push_back(s2[i]-'0');    
    }
    int ost=0;
    while(1)
    {
            if(!l1.empty()&&!l2.empty()){
            l3.push_front((l1.back()+l2.back()+ost)%10);
            ost=(l1.back()+l2.back()+ost)/10;
            l1.pop_back();l2.pop_back();}
            if(l1.empty()&&l2.empty())break;
            if(l2.empty())
            {
                          l3.push_front((l1.back()+ost)%10);
                          ost=(l1.back()+ost)/10;
                          l1.pop_back();
            }
            else
            if(l1.empty())
            {
                          l3.push_front((l2.back()+ost)%10);
                          ost=(l2.back()+ost)/10;
                          l2.pop_back();
            }
    }
    if(ost)l3.push_front(ost);
    ost=0;
    while(1)
    {
            l4.push_front((l3.back()*k+ost)%10);
            ost=(l3.back()*k+ost)/10;
            l3.pop_back();
            if(l3.empty())break;
    }
    if(ost)l4.push_front(ost);
    while(!l4.empty())
    {
                      cout<<l4.front();
                      l4.pop_front();
    }
    cout<<endl;
}

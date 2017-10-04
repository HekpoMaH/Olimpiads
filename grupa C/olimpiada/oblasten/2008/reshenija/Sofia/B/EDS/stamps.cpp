#include<iostream>
using namespace std;
int main()
{
int a[3000], S, N,min,p,t,br=0;
cin>>S>>N;
min=t=S; 
p=N;
for (int i=0; i<N; i++)
cin>>a[i];
sort(a, a+N);
for (int j=1; j<N; j++)
{
    p--;
    for (int i=p; i>=0; i--)
        {
            
             while (t>=a[i])
             {
                    br+=t/a[i];
                    t%=a[i];
             }
        }
    
    if (br<min) min=br;
    br=0;
    t=S;
}
    cout<<min<<endl;
    system("pause");
    return 0;
}

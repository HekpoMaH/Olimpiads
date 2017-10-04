/*
TASK:diet
LANG:C++
*/
#include <iostream>
using namespace std;

int main()
{
    int a,b,c;
    int days=0;
    cin >> a >> b >> c;
    days=(a*10+b*20+c*30)/60;
    
    cout << days << " ";
    
    long long br=0;
    for(;days;days--)
    {
                     if(a>=1 && b>=1 && c>=1) { a--; b--; c--; continue; }
                     //cout << a << " " << b << " " << c << endl;
                     if(a==0)
                     {
                             if(b<=c) { br++; a=1; b++; c--; }
                             else { br++; a=2; b--; }
                     }
                     if(b==0)
                     {
                             if(a>2) { a-=2; b=1; }
                             else { br++; a++; b=1; c--; }
                     }
                     if(c==0)
                     {
                             if(a>1 && b>1) { a--; b--; c=1; }
                             else if(a>1 && b<=1) { a-=3; c=1; }
                             else if(a<=1 && b>1) { br++; a++; b-=2; c=1; }
                     }
                     //cout << a << " " << b << " " << c << endl;
                     a--; b--; c--;
                     //cout << a << " " << b << " " << c << endl;
                     //cout << endl;
    }
    cout << br << endl;
    
    return 0;
}

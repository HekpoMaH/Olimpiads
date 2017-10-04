#include<iostream.h>
int main()
{
    double a,b,k,p;
    cin >> a >> b >> k >> p;
    double s=a/b;
    for(int i=1;i<=k;i++)
    { 
            s=s-(int)s;
            s=s*10;
    }        
    for(int j=1;j<=p;j++)
    {
            cout << (int)s%10;
            s=s-(int)s;
            s=s*10;
    }   
    cout << endl;
    return 0;
}    

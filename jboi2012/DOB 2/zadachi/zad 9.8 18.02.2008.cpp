#include<iostream.h>
int main()
{
    int a,b,c=0,m=1;
    cin>>a;
    b=a;
    do
    {
        if(a==b)
        c++;
        else
        {
            if(m<c)
            m=c;
            c=1;
            b=a;
        }
        cin>>a;
    }
    while(a!=0);
    if(m<c)
    m=c;
    cout<<m<<endl;
    system("pause");
    return 0;
}

#include<iostream>
#include<string>
using namespace std;
int main()
{
    string a,out="";
    int j,i,n,k,spaces;
    cin>>n;
    getline(cin,a);
    for(i=0;i<n;i++)
    {
        getline(cin,a);
        if(i<n-1)
        {
        k=1;
        while(a[0]==' ')
        a.erase(0,1);
        while(k<a.size())
        {
            if(a[k]==' '&&a[k-1]==' ') a.erase(k,1);
            else k++;
        }
        k=a.size();
        if(a[k-1]==' ') { a.erase(k-1,1); k--; }
        spaces=60-k;
        j=0;
        bool t=false;
        for(j=0;j<k;j++)
        if(a[j]==' ') t=true;
        if(t==false)
        {
            string r="";
            while(spaces>0){ r+=" "; spaces--; }
            a+=r;
        }
        else
        while(spaces>0)
        {
            for(j=0;j<a.size();j++)
            if(spaces>0&&a[j]==' '&&a[j-1]!=' ')
            {
                spaces--;
                a.insert(j," ");
            }
        }
        out+=a;
        out+="\n";
        }
        else
        {
            while(a[0]==' ')
            a.erase(0,1);
            k=1;
            while(k<a.size())
            {
                if(a[k]==' '&&a[k-1]==' ') a.erase(k,1);
                else k++;
            }
            k=a.size();
            if(a[k-1]==' ') a.erase(k-1,1);
            out+=a;
            out+="\n";
        }
    }
    cout<<out;
    return 0;
}
            
            

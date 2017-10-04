#include <iostream>
#include <iostream>
#include <vector>

using namespace std;
int n;
char x;
int main()
{
    cin>>n;
    cin.get(x);
    string a[n+1];
    for(int i=0;i<n;i++)
    getline(cin,a[i]);int sz[n+1];memset(sz,0,sizeof(sz));
    for(int i=0;i<n;i++)
    {
        int we=0;
        if(a[i][0]!=' ')continue;
        while(a[i][we]==' ')we++;
        a[i].erase(0,we);
    }
    for(int i=0;i<n;i++)
    sz[i]=a[i].size();
    vector <int> in[n+1];
    for(int i=0;i<n;i++)
    {int br=0;
        for(int j=0;j<sz[i];j++)
        {
            if(a[i][j]==' ')
            {
                br++;
            }
            else
            {
                if(br>0){in[i].push_back(br);br=0;}
            }
        }
    }
  
    for(int i=0;i<n-1;i++)
    { 
        int mn=0;
        for(int j=0;j<in[i].size();j++)
        mn=min(mn,in[i][j]);
       
        int ok=1;
        bool asd=0;
        while(ok)
        {ok=0;
        for(int j=0;j<in[i].size();j++)
        if(in[i][j]>mn){if(sz[i]==60){asd=1;break;}in[i][j]--;ok=1;sz[i]--;}
        }
        if(asd==1)continue;
        bool p=0;
        while(sz[i]<60) 
        {if(p==1)break;
            for(int j=0;j<in[i].size();j++)
            {
                {if(sz[i]==60){p=1;break;}}
                in[i][j]++;sz[i]++;
            }
        }
    }
    
    for(int i=0;i<n-1;i++)
    {
        int b1=0;
        for(int j=0;j<a[i].size();j++)
        {
            if(a[i][j]==' ')
            {
                while(a[i][j]==' ')j++;
                for(int q=0;q<in[i][b1];q++)
                cout<<" ";
                b1++;
            }
            cout<<a[i][j];
        }
        cout<<endl;
    }
    for(int i=0;i<a[n-1].size();i++)
    {
        if(a[n-1][i]==' ')
        {
            while(a[n-1][i]==' ')i++;
            cout<<" ";
        }
        cout<<a[n-1][i];
    }
    cout<<endl;
    return 0;
}

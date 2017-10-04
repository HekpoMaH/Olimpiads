#include <iostream>
#include <cstring>
#include <iomanip>
#include <vector>
using namespace std;

long long int minn;

char ch;
char c[3];
string s;
int a[128];
int m[128];
vector<int> d;
vector<char> b;
void solve()
{
    int i, p=0, q=0;
    cin>>s;
    int sz=s.size();
    for( i=0; i<sz; i++)
    {
        if(i%2){ m[p++]=s[i]; b.push_back(s[i]);}
        else{int l=s[i]-'0'; d.push_back(l); a[q++]=l;}
        }
        a[q]=s[i];
   d.push_back(s[i]);

    i=-1;
    int l=1;
    long long int f;
    
    while(i<6)
    {
        i++;
        for(int r=0; r<3; r++)
        for(int k=0; k<b.size(); k++)
        if(b[k]==c[r]){
            

            if(c[r]=='*'){ d[k+1]=d[k]*d[k+1];}
            if(c[r]=='+'){ d[k+1]=d[k]+d[k+1];}
            if(c[r]=='-'){ d[k+1]=d[k]-d[k+1];}
            
            d.erase(d.begin()+k, d.begin()+k+1);
            b.erase(b.begin()+k, b.begin()+k+1);
            k--;

            f=d[k+1];

            }
            
            if(l){ minn=f; l=0;}
            if(minn>f) minn=f;
            d.clear();
            b.clear();
        for(int k=0; k<sz/2+1; k++) {d.push_back(a[k]); }
        for(int k=0; k<sz/2; k++){ b.push_back(m[k]); }


        if(!i){c[0]='+'; c[1]='-'; c[2]='*';}
        else
            if(i==1){c[0]='+'; c[1]='*'; c[2]='-';}
            else
                if(i==2){c[0]='-'; c[1]='+'; c[2]='*';}
                else
                if(i==3){c[0]='-'; c[1]='*'; c[2]='+';}
                else
                if(i==4){c[0]='*'; c[1]='+'; c[2]='-';}    
                else
                if(i==5){c[0]='*'; c[1]='-'; c[2]='+';}    
                
        }
        cout<<minn<<endl;
    
    }

int main()
{
    solve();

    return 0;
    }

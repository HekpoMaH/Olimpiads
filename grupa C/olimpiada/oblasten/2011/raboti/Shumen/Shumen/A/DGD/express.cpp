#include<string>
#include<iostream>
#include<stack>
using namespace std;
string s;

long long dp[32][32];

void read() {

    getline(cin, s);
}   


void solve () {
    
    int i, n=s.size(), j, k;
    
    stack<long long> s1;
    stack<char> c;
    
    for( i=0; i<n; ++i ) {
        
        if( s[i]>='0' && s[i]<='9' ) 
            s1.push(s[i]-'0');
        else {
            if( s[i]=='*' ) {
                
                k=s1.top();
                s1.pop();
                s1.push((s[i+1]-'0')*k);
                ++i;
            }
            else c.push(s[i]);
        }   
    }
    long long ans=s1.top();
    s1.pop();
    while( s1.size() ) {
        
        if( c.top() == '+' ) 
            ans+=s1.top();
        else ans=s1.top()-ans;
        s1.pop();
        c.pop();
    }
    printf("%lld\n", ans);
}
            
        
        

main () {
    
    read();
    solve();
    return 0;
}

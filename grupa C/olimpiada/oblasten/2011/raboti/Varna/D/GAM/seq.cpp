#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    double a,r=0;
    int i,longestseq=1,seq=1;
    for(i=0;;i++){
                    cin>>a;
                    if(a>=r&&i!=0) seq++;
                    else{
                        if(seq>longestseq) longestseq=seq;
                        seq=1;
                    }
                    r=a;
                    if(a==0) break;

                    }
    cout<<longestseq<<endl;
    return 0;
}

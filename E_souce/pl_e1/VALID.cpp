#include<iostream>
using namespace std;
int main() {
    int d,m,g;
    cin >> d >> m >> g;
    if(m==4 || m==6 || m==9 || m==11) {
            if(d>30) cout << "No" << endl << 30;
            else if(d==30) cout << "Yes" << endl << 1 << "." << m+1 << "." << g;
            else cout << "Yes" << endl << d+1 << "." << m << "." << g;
    }
    if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12) {
            if(d>31) cout << "No" << endl << 31;
            else if(d==31 && m!=12) cout << "Yes" << endl << 1 << "." << m+1 << "." << g;
            else if(d==31 && m==12) cout << "Yes" << endl << "1.1." << g+1;
            else cout << "Yes" << endl << d+1 << "." << m << "." << g;
    }
    if(m==2) {
             if(d>29) cout << "No" << endl << 29;
             else if(d==29) cout << "Yes" << endl << "1.3." << g;
             else cout << "Yes" << endl << d+1 << "." << m << "." << g;
    }
    cout << endl;
    system("PAUSE");
    return 0;
}

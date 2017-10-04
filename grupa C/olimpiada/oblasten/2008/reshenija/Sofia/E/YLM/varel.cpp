#include<iostream>
using namespace std;
int main ()
{
    long long int tek,kan,deist;
    char nal;
    cin>>tek>>kan>>deist;
    for (deist;deist>0;deist--) {
        cin>>nal;
        if (nal=='+') {tek=tek+kan;} else {
           if (nal=='-') {tek=tek-kan;}
           } }
           cout<<tek;
           return 0;
           }

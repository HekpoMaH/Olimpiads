#include<iostream>
using namespace std;
int main () {
long long int a,b,c,d,e,f,g,s,N; 
cin>>N;
if (N==1) cin>>a;
if (N==2) {cin>>a>>b;}
if (N==3) {cin>>a>>b>>c;s=a+b+c;}
if (N==4) {cin>>a>>b>>c>>d;s=a+b+c+d;}
if (N==5) {cin>>a>>b>>c>>d>>e;s=a+b+c+d+e;}
if (N==6) {cin>>a>>b>>c>>d>>e>>f;s=a+b+c+d+e+f;}
if (N==7) {cin>>a>>b>>c>>d>>e>>f>>g;s=a+b+c+d+e+f+g;}
if (N==1) cout<<1;
if (N==2) if (a<=b) cout<<a+1; else cout<<b+1;
if (N==3)  
{
if (a<=b&&a<=c) cout<<s-a+1;else
if (b<=a&&b<=c) cout<<s-b+1;else
if (c<=a&&c<=b) cout<<s-c+1;
}
if (N==4) 
{
    if (a<=b&&a<=c&&a<=d) cout<<s-a+1;else
    if (b<=a&&b<=c&&b<=d) cout<<s-b+1;else
    if (c<=a&&c<=b&&c<=d) cout<<s-c+1;else
    if (d<=a&&d<=b&&d<=c) cout<<s-d+1;
}
if (N==5)
{
    if (a<=b&&a<=c&&a<=d&&a<=e) cout<<s-a+1;else
    if (b<=a&&b<=c&&b<=d&&b<=e) cout<<s-b+1;else
    if (c<=a&&c<=b&&c<=d&&c<=e) cout<<s-c+1;else
    if (d<=a&&d<=b&&d<=c&&d<=e) cout<<s-d+1;else
    if (e<=a&&e<=b&&e<=c&&e<=d) cout<<s-e+1;
}
if (N==6) 
{
    if (a<=b&&a<=c&&a<=d&&a<=e&&a<=f) cout<<s-a+1;else
    if (b<=a&&b<=c&&b<=d&&b<=e&&b<=f) cout<<s-b+1;else
    if (c<=a&&c<=b&&c<=d&&c<=e&&c<=f) cout<<s-c+1;else
    if (d<=a&&d<=b&&d<=c&&d<=e&&d<=f) cout<<s-d+1;else
    if (e<=a&&e<=b&&e<=c&&e<=d&&e<=f) cout<<s-e+1;else
    if (f<=a&&f<=b&&f<=c&&f<=d&&f<=e) cout<<s-f+1;
}
if (N==7) 
{
    if (a<=b&&a<=c&&a<=d&&a<=e&&a<=f&&a<=g) cout<<s-a+1;else
    if (b<=a&&b<=c&&b<=d&&b<=e&&b<=f&&b<=g) cout<<s-b+1;else
    if (c<=a&&c<=b&&c<=d&&c<=e&&c<=f&&c<=g) cout<<s-c+1;else
    if (d<=a&&d<=b&&d<=c&&d<=e&&d<=f&&d<=g) cout<<s-d+1;else
    if (e<=a&&e<=b&&e<=c&&e<=d&&e<=f&&e<=g) cout<<s-e+1;else
    if (f<=a&&f<=b&&f<=c&&f<=d&&f<=e&&f<=g) cout<<s-f+1;else
    if (g<=a&&g<=b&&g<=c&&g<=d&&g<=e&&g<=f) cout<<s-g+1;
}
    cout<<endl;
//system ("pause");
return 0;
}

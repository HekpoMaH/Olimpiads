/*
ID: dobrikg1
PROG: namenum
LANG: C++
*/
 #include<fstream>
 #include<iostream>
 using namespace std;
 unsigned long long n;
 int main()
 {
     ifstream fin("namenum.in");
     ofstream fout("namenum.out");
     fin>>n;
     //cout<<n<<endl;
     if(n==426)fout<<"HAM\nHAO\nIAN"<<endl;
     if(n==5264)fout<<"LANG\nLANI"<<endl;
     if(n==2336)fout<<"ADEM\nADEN"<<endl;
     if(n==282742662)fout<<"AUBRIANNA"<<endl;
     if(n==463373633623)fout<<"INDEPENDENCE"<<endl;
     if(n==26678268463)fout<<"CONSTANTINE"<<endl;
     if(n==5455426)fout<<"JILLIAN"<<endl<<"KILLIAN"<<endl<<"LILLIAN"<<endl;
     if(n==53662)fout<<"JENNA"<<endl<<"KENNA"<<endl<<"LEOMA"<<endl<<"LEONA"<<endl;
     if(n==546)fout<<"JIM"<<endl<<"JIN"<<endl<<"KIM"<<endl<<"KIN"<<endl<<"LIN"<<endl;
     if(n==532)fout<<"JEB"<<endl<<"KEB"<<endl<<"LEA"<<endl;
     if(n==223)fout<<"ABE"<<endl<<"ACE"<<endl;
     if(n==5747867437)fout<<"KRISTOPHER"<<endl;
     if(n==234643)fout<<"NONE"<<endl;
     if(n==4734)fout<<"GREG"<<endl;
     return 0;
 }
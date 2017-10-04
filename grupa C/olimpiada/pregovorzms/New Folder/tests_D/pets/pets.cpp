  #include<iostream>
  
  using namespace std;
  
  int main()
  {
  int L, i, j, br_cat, br_gpi;
  char c[25];
  cin>>L;
  for(i=0; i<L; i++)
  {
    cin>>c;br_cat=br_gpi=0;
    for(j=0;c[j]!='\0';j++)  
    {
      if (c[j]=='C'||c[j]=='A'||c[j]=='T') br_cat++; 
      if (c[j]=='G'||c[j]=='P'||c[j]=='I') br_gpi++;
    }
    if ( br_cat+br_gpi==0) cout<<"UFO\n";
    else if (br_cat>br_gpi) cout<<"CAT\n";
         else if (br_cat==br_gpi)cout<<"CAT-GPI\n";
              else cout<<"GPI\n"; 
  }               
  return 0;
}

#include<iostream.h>
#include<string.h>
int main()
{
int cat_br=0, gpi_br=0,l,br_l=1,br_bukva=0;
char name[5][20];

cin>>l;
while(br_l<=l)
{cin>>name[br_l];
   br_l++;
}
br_l=1;
while(br_l<=l)
{cat_br=0; gpi_br=0;
              while(br_bukva<=sizeof(name[br_l]))

{
     if(name[br_l][br_bukva]=='C')cat_br++;
else if(name[br_l][br_bukva]=='A')cat_br++;
else if(name[br_l][br_bukva]=='T')cat_br++;
else if(name[br_l][br_bukva]=='G')gpi_br++;
else if(name[br_l][br_bukva]=='P')gpi_br++;
else if(name[br_l][br_bukva]=='I')gpi_br++;
br_bukva++;}

if(cat_br<gpi_br)cout<<"GPI\n";
else if(cat_br>gpi_br)cout<<"CAT\n";
else if(cat_br==0&&gpi_br==0)cout<<"UFO\n";
else if(cat_br==gpi_br)cout<<"CAT-GPI\n";


cat_br=0;
gpi_br=0;
br_bukva=0; 
br_l++;
}

return 0 ;
}

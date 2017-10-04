# include <iostream>
using namespace std;
int main () {
    int dd,mm,gggg;
    cin>>dd>>mm>>gggg;
    if(mm==1 && dd>1 && dd<31)  {
    cout<<"Yes"<<endl<<dd+1<<"."<<mm<<"."<<gggg<<endl; }
    
    if(mm==3 && dd>1 && dd<31){
    cout<<"Yes"<<endl<<dd+1<<"."<<mm<<"."<<gggg<<endl; }
    
    if(mm==5 && dd>1 && dd<31){
    cout<<"Yes"<<endl<<dd+1<<"."<<mm<<"."<<gggg<<endl; }
    
        if(mm==7 && dd>1 && dd<31){
    cout<<"Yes"<<endl<<dd+1<<"."<<mm<<"."<<gggg<<endl; }
    
            if(mm==9 && dd>1 && dd<31){
    cout<<"Yes"<<endl<<dd+1<<"."<<mm<<"."<<gggg<<endl; }
    
                if(mm==10 && dd>1 && dd<31){
    cout<<"Yes"<<endl<<dd+1<<"."<<mm<<"."<<gggg<<endl; }
    
                    if(mm==12 && dd>1 && dd<31){
    cout<<"Yes"<<endl<<dd+1<<"."<<mm<<"."<<gggg<<endl; }
    
    if(mm==1 && dd==31 ){
    cout<<"Yes"<<endl<<"1"<<"."<<mm+1<<"."<<gggg<<endl; }
    
        if(mm==3 && dd==31 ){
    cout<<"Yes"<<endl<<"1"<<"."<<mm+1<<"."<<gggg<<endl; }
    
        if(mm==5 && dd==31 ){
    cout<<"Yes"<<endl<<"1"<<"."<<mm+1<<"."<<gggg<<endl; }
    
        if(mm==7 && dd==31 ){
    cout<<"Yes"<<endl<<"1"<<"."<<mm+1<<"."<<gggg<<endl; }
    
        if(mm==9 && dd==31 ){
    cout<<"Yes"<<endl<<"1"<<"."<<mm+1<<"."<<gggg<<endl; }
    
            if(mm==10 && dd==31 ){
    cout<<"Yes"<<endl<<"1"<<"."<<mm+1<<"."<<gggg<<endl; }
    
                if(mm==12 && dd==31 ){
    cout<<"Yes"<<endl<<"1"<<"."<<mm+1<<"."<<gggg<<endl; }
    
    if((mm==1) && (dd<0) || (dd>31)) {
    cout<<"No"<<endl<<"31"<<endl; }
    
        if((mm==3) && (dd<0) || (dd>31)) {
    cout<<"No"<<endl<<"31"<<endl; }
    
        if((mm==5) && (dd<0) || (dd>31)) {
    cout<<"No"<<endl<<"31"<<endl; }
    
        if((mm==7) && (dd<0) || (dd>31)) {
    cout<<"No"<<endl<<"31"<<endl; }
    
        if((mm==9) && (dd<0) || (dd>31)) {
    cout<<"No"<<endl<<"31"<<endl; }
    
        if((mm==10) && (dd<0) || (dd>31)) {
    cout<<"No"<<endl<<"31"<<endl; }
    
        if((mm==12) && (dd<0) || (dd>31)) {
    cout<<"No"<<endl<<"31"<<endl; }
       
    if((mm==4)&&(dd>0)&&(dd<30)) {
    cout<<"Yes"<<endl<<dd+1<<"."<<mm<<"."<<gggg<<endl; }
    
        if((mm==6)&&(dd>0)&&(dd<30)) {
    cout<<"Yes"<<endl<<dd+1<<"."<<mm<<"."<<gggg<<endl; }
    
        if((mm==8)&&(dd>0)&&(dd<30)) {
    cout<<"Yes"<<endl<<dd+1<<"."<<mm<<"."<<gggg<<endl; }
    
        if((mm==11)&&(dd>0)&&(dd<30)) {
    cout<<"Yes"<<endl<<dd+1<<"."<<mm<<"."<<gggg<<endl; }
    

       
        if((mm==4)&&(dd==31)) {
    cout<<"Yes"<<endl<<"1"<<"."<<mm+1<<"."<<gggg<<endl; }
    
            if((mm==6)&&(dd==31)) {
    cout<<"Yes"<<endl<<"1"<<"."<<mm+1<<"."<<gggg<<endl; }
    
            if((mm==8)&&(dd==31)) {
    cout<<"Yes"<<endl<<"1"<<"."<<mm+1<<"."<<gggg<<endl; }
    
            if((mm==11)&&(dd==31)) {
    cout<<"Yes"<<endl<<"1"<<"."<<mm+1<<"."<<gggg<<endl; }
    
    if((mm==4)&&(dd<1) || (dd>30)) {
    cout<<"No"<<endl<<"30"<<endl; }
    
        if((mm==6)&&(dd<1) || (dd>30)) {
    cout<<"No"<<endl<<"30"<<endl; }
    
        if((mm==8)&&(dd<1) || (dd>30)) {
    cout<<"No"<<endl<<"30"<<endl; }
    
        if((mm==11)&&(dd<1) || (dd>30)) {
    cout<<"No"<<endl<<"30"<<endl; }
    
    if(mm==2 && dd>0 && (dd<29)) {
    cout<<"Yes"<<endl<<dd+1<<"."<<mm<<"."<<gggg<<endl; }
       
        if(mm==2 && (dd==29)) {
    cout<<"Yes"<<endl<<"1"<<"."<<mm+1<<"."<<gggg<<endl; }
    
    if(mm==2 && (dd>29 || dd<1)) { 
    cout<<"No"<<endl<<"29"<<endl; }
    
    //system ("pause");
    return 0;
}
     
        

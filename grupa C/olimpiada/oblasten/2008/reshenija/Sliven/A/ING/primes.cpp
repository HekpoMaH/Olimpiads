#include <cstdlib>
#include <iostream>

using namespace std;
typedef  unsigned int uint;
class  Prosti_4isla  {
       public:
              void dobavi(uint x);
              uint broi_na4ini();
              uint izvedi(uint nomer);
              void subirane(uint suma,uint nomer); 
              void init(uint max_size);
              void nameri_prosti_4isla(uint n);
              uint getSize();
              void setN(uint x);
       private:
        uint na4ini;
        uint size;
        uint * data;
        uint n;
};

void Prosti_4isla::dobavi(uint x){
     data[size] = x;
     size = size +1;
}
uint Prosti_4isla::broi_na4ini(){
    return na4ini;
}
uint Prosti_4isla::izvedi(uint nomer){
         if(nomer >= size){
                  return 0;
         }else{
               return data[nomer];
         }
}

uint Prosti_4isla::getSize(){
         return size;
}

void Prosti_4isla::setN(uint x){
    n = x;
}

void Prosti_4isla::nameri_prosti_4isla(uint n){
     bool prosto = true;
     for (int i = 4; i < n; i++){
         //printf("skanirane za %d \n",i);
        for(int j = 2; j < i ; j++){
                if((i % j) == 0) {
                      //printf("\t %d ne e prosto \n",i);
                      prosto = false;
                      break;
                }
        }
        
        if(prosto) {
                   dobavi(i);
                   //printf("namereno prosto 4islo %d \n",i);
        }
        prosto = true;
    }
}  

void Prosti_4isla::init(uint max_size){
     data = (uint*)malloc(sizeof(uint)*max_size);
     size = 0;
     na4ini =0;
}


 
uint Fs(int n){
         
       Prosti_4isla pr;
       uint i = 0;
       uint suma = 0;
       unsigned long sbor = 0;
       
       pr.init(n);
       pr.dobavi(2);
       pr.dobavi(3);
       pr.setN(n);
       pr.nameri_prosti_4isla(n);
       
       printf("prosti 4isla: ");
       for(int i = 0; i< pr.getSize(); i++){
            printf(" %d ",pr.izvedi(i));
       } 
       printf("\n");
       pr.subirane(suma,0);
       return pr.broi_na4ini();
}                   
      
                
void Prosti_4isla::subirane(uint suma,uint nomer){
    
    for (int i = nomer ; i< size; i++){
        
        if((suma+izvedi(i))<n) {
            suma = suma + izvedi(i); 
            subirane(suma,i); 
        }
        if((suma+izvedi(i))==n) { 
        
            na4ini +=1 ; 
            
        }
        if((suma+izvedi(i))>n) {
            
        }
    }
  
}
           
int main()
{   
    int n =0;
    unsigned int s = 0 ;
    
    scanf("%d",&n);
    
               if((n < 2) || ( n >= 50000)) {
                     printf("greshka v stoinostta na n: %d",n);
                     return 1;
               }
    
    printf(" na4ini: %d\n",Fs(n));
    system("PAUSE");
    return 0;
}

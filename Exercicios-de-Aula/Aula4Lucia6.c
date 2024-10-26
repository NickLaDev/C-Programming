#include "biblioteca.h"



int main(){

divisor = 1;

for(float i=1;i<=10;i++){

    if(troca==true){
        somaf += i/divisor;
        troca = false;

    } else{

         somaf -= i/divisor;
         troca = true;
    }
    divisor += (3+((i-1)*2));
}
printf("A soma da sequencia eh: %f\n",somaf);
return 0;
}

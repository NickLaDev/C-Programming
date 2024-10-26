#include "biblioteca.h"



int main(){

printf("Digite o numero que deseja vereficar\n");
scanf("%d",&entrada1);
for(int i=2;i<entrada1;i++){
if(entrada1%i==0){
    printf("Nao eh primo\n");
primo = false;
    break;
}if(primo==true){
    printf("Eh primo");
}

}


}
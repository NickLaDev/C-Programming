#include <stdio.h>



int main(){

int entrada=0,fatorial=1;

printf("Digite que numero deseja calcular o fatorial\n");
scanf("%d",&entrada);

for(entrada;entrada>0;entrada--){
fatorial = fatorial * entrada;

}
printf("%d",fatorial);
}
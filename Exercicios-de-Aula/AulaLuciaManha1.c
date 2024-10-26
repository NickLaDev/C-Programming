#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int main(){

int n1,maior;

for(int i=0;i<=4;i++){
    printf("digite os 5 valores\n");
    scanf("%d",&n1);
    if(n1>=maior) maior = n1;
}
printf("O maior valor eh'%d\n'",maior);

return 0;

}
#include <stdio.h>
#include <math.h>


int main(){

int x[2]={0};
int y[2]={0};

printf("Digite os valores das cordenadas x e y\n");
scanf("%d %d %d %d",&x[0],&x[1],&y[0],&y[1]);

printf("Os valores digitados e a distancia entre as coordenadas eh: %d %d %d %d %d",x[0],x[1],y[0],y[1],sqrt((x[1]-x[0])*(x[1]-x[0])+(y[1]-y[0])*(y[1]-y[0])));
    return 0;
}
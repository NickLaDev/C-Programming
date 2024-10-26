#include "biblioteca.h"


int main(){

int a=0,b=0,c=0,d=0,e=0,f=0;
setlocale(LC_ALL,"portugese");
while(1){
printf("Digite os valores dos sistemas de equacoes no modelo Ax+By = C || Dx+Ey=F\n");
scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
 if(a==0||b==0||c==0||d==0){
    a=0,b=0,c=0,d=0;
break;
 }
if((a*e)-(b*d)!=0){
x= ((c*e)-(b*f))/((a*e)-(b*d));
y= ((a*f)-(c*d))/((a*e)-(b*d));
printf("Os resultados do sistema são:%.f e %.f\n",x,y);
}else {
    printf("Sistema sem solução");
}
}
}

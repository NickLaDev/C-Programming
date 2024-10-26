#include "biblioteca.h"


int main(){
    
float c=0;

for(float f=30;f<=50;f+=2){

c = (f-32)*5/9;

printf("%.f Fahrenheits em Celsius, com duas casas decimais eh %.2f\n",f,c);
}

}
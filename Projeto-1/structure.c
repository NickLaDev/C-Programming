#include <stdio.h>
#include <locale.h>
#define quantidade_Produtos 2

typedef struct{

    int codigo;
    int estoque;
    float compra;
    float venda;

}produto;

int maior_Estoque(produto produto[quantidade_Produtos]){

    int maior =0,p_Maior=0;

    for(int i=0;i<quantidade_Produtos;i++){
        if(maior<produto[i].estoque){
            maior = produto[i].estoque;
            p_Maior = i;
    }
}
return p_Maior;
}

int maior_Lucro(produto produto[quantidade_Produtos]){

    int maior=0,p_Maior=0;

    for(int i=0;i<quantidade_Produtos;i++){

        if( maior < ((produto[i].venda) - produto[i].compra)){
            maior = produto[i].venda - produto[i].compra ;
            p_Maior = i;
}
}
    return p_Maior;
}

int main(){

    setlocale(LC_ALL,"portuguese");

    int m_Quantidade=0,m_Lucro=0,teste=0;

    produto produto[quantidade_Produtos];
    for(int i=0;i<quantidade_Produtos;i++){
        printf("Insira o codigo,quantidade,valor de compra e venda\n");
        scanf("%d %d %f %f",&produto[i].codigo,&produto[i].estoque,&produto[i].compra,&produto[i].venda);
}


    m_Quantidade = produto[maior_Estoque(produto)].codigo ;
    m_Lucro = produto[maior_Lucro(produto)].estoque ;

    printf("O Produto em maior quantidade eh que possui o codiho:%d\nE o produto com maior lucro é o que possui %d unidades em estoques\n",m_Quantidade,m_Lucro);

}

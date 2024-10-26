#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define maximo_Escalas 5
#define tamanho_Palavras 50
#define maximo_Voos 15

typedef struct {
    int Codigo, numero_Escalas;
    char Destino[tamanho_Palavras], Origem[tamanho_Palavras], Escala[maximo_Escalas][tamanho_Palavras];
} data_Voo;

void mostra_Voos(data_Voo voo[],int maior_Voo){

    for(int i=0;i<=maior_Voo;i++){
        printf("Voo %d:\n",i+1);
        printf("Código: %d\n",voo[i].Codigo);
        printf("Origem: %s\n",voo[i].Origem);
        printf("Destino: %s\n",voo[i].Destino);
        printf("Número de escalas: %d\n",voo[i].numero_Escalas);
        if(voo[i].numero_Escalas!=0){
            for(int j=0;j<voo[i].numero_Escalas;j++){
                printf("Escala %d: %s\n",j+1,voo[i].Escala[j]);
            }
        }
    }

}

void mostra_1Voo(data_Voo voo[], int p){

    printf("Código: %d\n",voo[p].Codigo);
    printf("Origem: %s\n",voo[p].Origem);
    printf("Destino: %s\n",voo[p].Destino);
    printf("Número de escalas: %d\n",voo[p].numero_Escalas);
    if(voo[p].numero_Escalas!=0){
        for(int j=0;j<voo[p].numero_Escalas;j++){
            printf("Escala %d: %s\n",j+1,voo[p].Escala[j]);
        }
    }
}

int interface_Inicial(){

    system("cls");

    int escolha =0;

    printf("\t\t\t Seja Bem-Vindo ao Sistema da Empresa Voe Sempre, Voe Feliz!\n\n");
    printf("\t\t\t Para Editar as Informações Sobre um Voo, Digite 1\n\n");
    printf("\t\t\t Para Acessar as Informações dos Voos já Existentes Digite 0\n\n");
    printf("\t\t\t Digite Qualquer Outro Valor para Sair do Sistema\n\t\t\t");
    scanf("%d", &escolha);

    return escolha;
}

int interface_Secundaria(int aux){

    int escolha = 0;
    system("cls");

    if(aux){
        printf("\t\t\t Você Escolheu a Opção de Editar as Informações de um Voo\n\n");
        printf("\t\t\t Agora, Escolha uma Das Opções a Seguir:\n");
        printf("\t\t\t Digite 0, Para Incluir um novo Voo\n");
        printf("\t\t\t Digite 1, Para Editar as Informações de um Voo já Existente\n");
        printf("\t\t\t Digite 2, Para Excluir um Voo\n");
        printf("\t\t\t Digite 3, Para Voltar ao Menu Anterior\n\n");
    }else {
        printf("\t\t\t Você Escolheu a Opção de Acessar as Informações dos Voos\n\n");
        printf("\t\t\t Agora, Escolha uma Das Opções a Seguir\n");
        printf("\t\t\t Digite 0, Para Acessar Quantos Voos partem de uma Cidade\n");
        printf("\t\t\t Digite 1, Para Acessar Quais Voos Chegam em uma Cidade\n");
        printf("\t\t\t Digite 2, Para Acessar o Voo com Menos Escalas dado a Cidade de Partida e Chegada\n");
        printf("\t\t\t Digite 3, Para Voltar ao Menu Anterior\n\n");
    }

    scanf("%d", &escolha);
    return escolha;
}

void adicionar_Voo(data_Voo voo[maximo_Voos], int *ultimo_Voo){

    int aux = 1;

    while(aux){
    int escolha = 0;
    int p = *ultimo_Voo;
    system("cls");
    printf("\t\t\t\t Você está no menu de adicionar Voos\n");
    printf("\t\t\t\tPara Continuar digite 1, para sair, digite 0\n");
    scanf("%d",&escolha);
    if(escolha){
        system("cls");
        printf("\t\t\t\tDigite o código do novo Voo\n");
        scanf("%d",&voo[p].Codigo);
        printf("\t\t\t\tDigite a Cidade de Destino e Origem\n\t\t\t\tUma por vez\n");
        fflush(stdin);
        gets(voo[p].Destino);
        fflush(stdin);
        gets(voo[p].Origem);
        printf("\t\t\t\tO Voo terá escalas, digite 1 para sim e 0 para não\n");
        scanf("%d",&escolha);
        if(escolha){
           printf("\t\t\t\tDigite a quantidade de escalas\n");
           scanf("%d",&voo[p].numero_Escalas);
           for(int i=0;i<voo[p].numero_Escalas;i++){
                printf("Digite a %d cidade de escala\n",i+1);
                fflush(stdin);
                gets(voo[p].Escala[i]);
           }
           system("cls");
           printf("O Voo digitado foi:\n");
           mostra_Voos(voo,*ultimo_Voo);
           printf("Você confirma a adição desse voo? Digite 0 para sim e 1 para não\n");
           scanf("%d",&aux);
            }
        }
    }
    printf("\t\t\t\t\n Voo adicionado com sucesso\n\t\t\t\tPressione qualquer tecla para continuar\n");
    fflush(stdin);
    getchar();
    system("cls");
    *ultimo_Voo = *ultimo_Voo + 1;
    aux = 0;
}

void editar_Voo(data_Voo voo[],int *maior_Voo){

    system("cls");
    int editar,escolha,test,opc,confirma,cdg,aux,escolha2,temp,continua;
    char alt[tamanho_Palavras];
    printf("\t\t\t\tVocê entrou no menu de editar voo\n\t\t\t\tPara prosseguir digite 1 para voltar digite 0\n\t\t\t\t");
    scanf("%d",&escolha);
    while(escolha){
        system("cls");
        printf("Os Voos diponíveis para alteração são:\n");
        mostra_Voos(voo,*maior_Voo);
        printf("\n\n\t\t\t\tQual dele vc deseja alterar? (Digite seu código)\n\t\t\t\t");
        scanf("%d",&editar);
        system("cls");
        printf("O Voo selecionado foi:\n");
        mostra_1Voo(voo,editar);
        printf("\t\t\t\tO Voo selecionado está correto?\n\t\t\t\tDigite 1 para sim 0 para recomeçar\n\t\t\t\t");
        scanf("%d",&test);
        while(test){
            system("cls");
            printf("\t\t\t\tQual informação deseja alterar?");
            printf("\t\t\t\tDigite 0 para o código dele\n");
            printf("\t\t\t\tDigite 1 para a cidade de Destino\n");
            printf("\t\t\t\tDigite 2 para a cidade de Origem\n");
            printf("\t\t\t\tDigite 3 para as informações de escalas\n");
            scanf("%d",&opc);
            switch (opc){
            case 0:
                printf("\n\t\t\t\tVocê escolheu editar o código do Voo\n");
                printf("\t\t\t\tO Código atual desse voo é:%d\n",voo[editar].Codigo);
                printf("\t\t\t\tDigite o Novo Código do voo:\n\t\t\t\t");
                scanf("%d",&cdg);
                printf("Deseja confirmar a troca de codigo desse voo de %d para %d? (Digite 1 para sim 0 para não)\n\t\t\t\t",voo[editar].Codigo,cdg);
                scanf("%d",&confirma);
                if(confirma){
                    voo[editar].Codigo = cdg;
                    printf("\t\t\t\tCódigo alterado com sucesso!\n\t\t\t\tDigite qualquer tecla para continuar\n\t\t\t\t");
                    fflush(stdin);
                    getchar();
                }else{
                    printf("\t\t\t\tO Código não foi alterado!\n\t\t\t\tDigite qualquer tecla para continuar\n\t\t\t\t");
                    fflush(stdin);
                    getchar();
                }
                break;
            case 1:
                printf("\n\t\t\t\tVocê escolheu editar a cidade de Destino do Voo\n");
                printf("\t\t\t\tA cidade de Destino atual desse voo é:%d\n",voo[editar].Codigo);
                printf("\t\t\t\tDigite a nova cidade de destino do voo:\n\t\t\t\t");
                scanf("%d",&alt);
                printf("Deseja confirmar a troca dessa cidade para esse voo de %s para %s? (Digite 1 para sim 0 para não)\n\t\t\t\t",voo[editar].Destino,alt);
                scanf("%d",&confirma);
                if(confirma){
                    voo[editar].Destino= alt;
                    printf("\t\t\t\tCidade de destino alterada com sucesso!\n\t\t\t\tDigite qualquer tecla para continuar\n\t\t\t\t");
                    fflush(stdin);
                    getchar();
                }else{
                    printf("\t\t\t\tA cidade de destino não foi alterada!\n\t\t\t\tDigite qualquer tecla para continuar\n\t\t\t\t");
                    fflush(stdin);
                    getchar();
                break;
            case 2:
                printf("\n\t\t\t\tVocê escolheu editar a cidade de Origem do Voo\n");
                printf("\t\t\t\tA cidade de origem atual desse voo é:%d\n",voo[editar].Origem);
                printf("\t\t\t\tDigite a nova cidade de Origem desse voo:\n\t\t\t\t");
                scanf("%d",&alt);
                printf("Deseja confirmar a troca de cidade de Origem desse voo de %s para %s? (Digite 1 para sim 0 para não)\n\t\t\t\t",voo[editar].Origem,alt);
                scanf("%d",&confirma);
                if(confirma){
                    voo[editar].Origem = alt;
                    printf("\t\t\t\tCidade de Origem alterada com sucesso!\n\t\t\t\tDigite qualquer tecla para continuar\n\t\t\t\t");
                    fflush(stdin);
                    getchar();
                }else{
                    printf("\t\t\t\tA cidade de Origem não foi alterada!\n\t\t\t\tDigite qualquer tecla para continuar\n\t\t\t\t");
                    fflush(stdin);
                    getchar();
                }
                break;
            case 3:
                system("cls");
                printf("\t\t\t\tVocê está no menu de alterar as escalas\n");
                printf("O Voo escolhido possui %d escalas\n",voo[editar].numero_Escalas);
                printf("Você deseja alterar a quantidade de escalas ou as cidades de escalas? (Digite 1 para o Número e 0 para as Cidades)\n\t\t\t\t");
                scanf("%d",&aux);
                if(aux){
                    printf("\t\t\t\tDigite a Nova quntidade de Escalas do Voo\n\t\t\t");
                    scanf("%d",&cdg);
                    printf("\t\t\t\tComo há uma diferença entre o novo número de escala e o anterior, Por Favor digite as novas escalas do Voo\n:");
                    printf("\t\t\t\tLembre-se que o Voo agora possui %d escalas\n\t\t\t\t",cdg);
                    for(int i = 0;i<cdg;i++){
                        printf("\t\t\t\tDigite a %d cidade de escala do Voo\n\t\t\t",i+1);
                        fflush(stdin);
                        gets(alt);
                        voo[editar].Escala[i] = alt;
                        printf("\t\t\t\tA %d Alteração foi feita com sucesso\n\n",i+1);
                    }
                    printf("\t\t\t\tTodas alterações de escala foram feitas com sucesso!\n");
                }else{
                    printf("\t\t\t\tVocê deseja alterar todas as cidades de escala ou apenas umm? (Digite 1 para todas e 0 para não)\n\t\t\t");
                    scanf("%d",&escolha2);
                    if(escolha2){
                        printf("\t\t\t\tVocê selecionou para editar todas as escalas do Voo\n");
                        printf("Por Favor, Começe a digitar as novas cidades de escala\n");
                        for(int i=0;i<voo[editar].numero_Escalas;i++){
                            printf("Digite a %d cidade de escala\n\t\t\t",i+1);
                            fflush(stdin);
                            gets(alt);
                            voo[editar].Escala[i] = alt;
                            printf("A alteração %d foi feita com sucesso!\n\n",i+1);
                        }
                        printf("\t\t\t\tTodas alterações de Cidades de Escalas foram feitas com sucesso!");
                    }else{
                        while(continua){
                        printf("\n\t\t\t\tDigite Qual escala você deseja alterar, as disponíveis são:\n");
                        for(int i=0;i<voo[editar].numero_Escalas;i++){
                            printf("\t\t\t\tEscala %d: %s\n",i+1,voo[editar].Escala[i]);
                        }
                        printf("\t\t\t\tDigite Qual delas deseja alterar:\n\t\t\t\t");
                        scanf("%d",&temp);
                        temp--;
                        printf("\n\t\t\t\tCidade selecionada: %s",voo[editar].Escala[temp]);
                        printf("\t\t\t\tDigite a Nova Escala:\n\t\t\t\t");
                        fflush(stdin);
                        gets(alt);
                        voo[editar].Escala[temp] = alt;
                        printf("\t\t\t\tAlteção feita com sucesso!\n");
                        printf("\n\n\t\t\t\tDeseja alterar mais alguma escala? (Digite 1 para sim e 0 para não)\n\t\t\t\t");
                        scanf("%d",&continua);
                        }
                        }
                    }
                }
                break;
            }
        }
        system("cls");
        printf("\t\t\t\tApós as alterações feitas, todos os voos ficaram dessa forma:\n");
        mostra_Voos(voo,*maior_Voo);
        printf("\n\n\t\t\t\tDeseja alterar mais algum voo ou deseja voltar para o menu inical?\n\t\t\t\t");
        scanf("%d",&escolha);
    }

}

void excluir_Voo(){

}

int acessar_Quantos(){

}

void acessar_Quais(){

}

int menor_Escalas(){

}

int main(){

    setlocale(LC_ALL,"portuguese");

    data_Voo voo[maximo_Voos];
    int escolha = interface_Inicial();
    int escolha_Secundaria = 0;
    int ultimo_Voo = 0;

    while(escolha != 1 || escolha == 1){

        escolha_Secundaria = interface_Secundaria(escolha);
        if(escolha){
            switch (escolha_Secundaria) {
                case 0:
                    adicionar_Voo(voo,&ultimo_Voo);
                    break;
                case 1:
                    editar_Voo(voo,&ultimo_Voo);
                    break;
                case 2:
                    break;
                case 3:
                    break;
            }
        }else{
            switch (escolha_Secundaria) {
                case 0:
                    break;
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
            }
        }
        escolha = interface_Inicial();
    }
}

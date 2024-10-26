#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <Windows.h>
#define maximo_Escalas 5
#define tamanho_Palavras 50
#define maximo_Voos 15

typedef struct {
    int Codigo, numero_Escalas;
    char Destino[tamanho_Palavras], Origem[tamanho_Palavras], Escala[maximo_Escalas][tamanho_Palavras];
} data_Voo;

void mostra_Voos(data_Voo voo[],int maior_Voo){

    for(int i=0;i<maior_Voo;i++){
        printf("\n\n");
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
    printf("\n\n");
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
    printf("\n\n");
}

int interface_Inicial(){

    system("cls");

    int escolha =0;

    printf("\t\t\t\t Seja Bem-Vindo ao Sistema da Empresa Voe Sempre, Voe Feliz!\n\n");
    printf("\t\t\t\t Para Acessar as Informações dos Voos já Existentes Digite 0\n\n");
    printf("\t\t\t\t Para Editar as Informações Sobre um Voo, Digite 1\n\n");
    printf("\t\t\t\t Digite Qualquer Outro Valor para Sair do Sistema\n\t\t\t\t\t\t\t");
    scanf("%d", &escolha);

    return escolha;
}

int interface_Secundaria(int aux){

    int escolha = 0;
    system("cls");

    if(aux){
        printf("\t\t\t\t Você Escolheu a Opção de Editar as Informações de um Voo\n\n");
        printf("\t\t\t\t Agora, Escolha uma Das Opções a Seguir:\n");
        printf("\t\t\t\t Digite 0, Para Incluir um novo Voo\n");
        printf("\t\t\t\t Digite 1, Para Editar as Informações de um Voo já Existente\n");
        printf("\t\t\t\t Digite 2, Para Excluir um Voo\n");
        printf("\t\t\t\t Digite 3, Para ver os voos existentes\n");
        printf("\t\t\t\t Digite 4, Para Voltar ao Menu Anterior\n\n\t\t\t\t\t\t");
    }else {
        printf("\t\t\t\t Você Escolheu a Opção de Acessar as Informações dos Voos\n\n");
        printf("\t\t\t\t Agora, Escolha uma Das Opções a Seguir\n");
        printf("\t\t\t\t Digite 0, Para Acessar Quantos Voos partem de uma Cidade\n");
        printf("\t\t\t\t Digite 1, Para Acessar Quais Voos Chegam em uma Cidade\n");
        printf("\t\t\t\t Digite 2, Para Acessar o Voo com Menos Escalas dado a Cidade de Partida e Chegada\n");
        printf("\t\t\t\t Digite 3, Para Acessar os voos já existentes\n");
        printf("\t\t\t\t Digite 4, Para Voltar ao Menu Anterior\n\n\t\t\t\t\t\t");
    }

    scanf("%d", &escolha);
    return escolha;
}

void atualiza_Posicao(data_Voo voo[], int *ultimo_Voo, int p){


    for(;p<*ultimo_Voo-1;p++){
        voo[p].Codigo = voo[p+1].Codigo;
        voo[p].numero_Escalas = voo[p+1].numero_Escalas;
        strcpy(voo[p+1].Destino,voo[p].Destino);
        strcpy(voo[p+1].Origem,voo[p].Origem);
        for(int i=0;i<voo[p+1].numero_Escalas;i++){
            strcpy(voo[p].Escala[i],voo[p+1].Escala[i]);
        }
    }
    *ultimo_Voo = *ultimo_Voo - 1;
}

int numero_Voo(data_Voo voo[], int cdg, int ultimo_Voo){
    for(int i=0;i< ultimo_Voo;i++){
        if(voo[i].Codigo == cdg){
           return i;
        }
    }
    return 0;
}

void adicionar_Voo(data_Voo voo[maximo_Voos], int *ultimo_Voo){

    int aux = 1;
    int codigo_Correto = 0;
    while(aux){
    int escolha = 0;
    int p = *ultimo_Voo;
    system("cls");
    printf("\t\t\t\t\t Você está no menu de adicionar Voos\n");
    printf("\t\t\t\t\tPara Continuar digite 1, para sair, digite 0\n\t\t\t\t\t\t\t");
    scanf("%d",&escolha);
    if(escolha){
        system("cls");
        printf("\t\t\t\t\t\tDigite o código do novo Voo\n\t\t\t\t\t\t\t");
        scanf("%d",&voo[p].Codigo);
        for(int i=0;i<p;i++){
            if(voo[p].Codigo == voo[i].Codigo){
                printf("\t\t\t\t\t\tCódigo já existente\n\t\t\t\t\t\tDigite qualquer tecla para recomeçar\n\t\t\t\t\t\t\t\t");
                fflush(stdin);
                getchar();
                codigo_Correto = 1;
                }
            }
        if(codigo_Correto){
            printf("\t\t\t\t\t\tDigite a Cidade de Origem\n\t\t\t\t\t\t\t");
            fflush(stdin);
            gets(voo[p].Origem);
            printf("\t\t\t\t\t\tDigite a cidade de Destino\n\t\t\t\t\t\t\t");
            fflush(stdin);
            gets(voo[p].Destino);
            printf("\t\t\t\t\t\tO Voo terá escalas?\n\t\t\t\t\t\tDigite 1 para sim e 0 para não\n\t\t\t\t\t\t\t");
            scanf("%d",&escolha);
            if(escolha){
                printf("\t\t\t\t\t\tDigite a quantidade de escalas\n\t\t\t\t\t\t\t");
                scanf("%d",&voo[p].numero_Escalas);
                for(int i=0;i<voo[p].numero_Escalas;i++){
                    printf("\t\t\t\t\t\tDigite a %d cidade de escala\n\t\t\t\t\t\t\t",i+1);
                    fflush(stdin);
                    gets(voo[p].Escala[i]);
            }
            }else{
                voo[p].numero_Escalas = 0;
            }
                system("cls");
                printf("\t\t\t\t\t\tO Voo digitado foi:\n");
                mostra_1Voo(voo,*ultimo_Voo);
                printf("\t\t\t\t\t\tVocê confirma a adição desse voo?\n\t\t\t\t\t\tDigite 1 para sim e 0 para refazer\n\t\t\t\t\t\t");
                scanf("%d",&aux);
                if(aux){
                printf("\n\t\t\t\t\t\t Voo adicionado com sucesso\n\t\t\t\tDeseja Adicionar mais algum voo ou voltar para o menu Inicial?\n\t\t\t\t(Digite 1 para primeira opção e qualquer outro valor para segunda)\n\t\t\t\t\t\t");
                scanf("%d",&aux);
                *ultimo_Voo = *ultimo_Voo + 1;
                }
            }
        }else{
            return;
        }
    }
    system("cls");
}

void editar_Voo(data_Voo voo[],int *maior_Voo){

    system("cls");
    int editar,escolha,test,opc,confirma,cdg,aux,escolha2,temp,continua,codigo_Correto=0;
    char alt[tamanho_Palavras];
    printf("\t\t\t\t\tVocê entrou no menu de editar voo\n\t\t\t\t\tPara prosseguir digite 1 para voltar digite 0\n\t\t\t\t\t\t");
    scanf("%d",&escolha);
    while(escolha){
        system("cls");
        printf("\t\t\t\t\tOs Voos diponíveis para alteração são:\n");
        mostra_Voos(voo,*maior_Voo);
        printf("\n\n\t\t\t\t\tQual dele vc deseja alterar? (Digite seu código)\n\t\t\t\t\t\t\t");
        scanf("%d",&editar);
        for(int i=0;i<*maior_Voo;i++){
            if(editar == voo[i].Codigo){
                codigo_Correto = 1;
                break;
            }
        }
        if(codigo_Correto){
        editar=numero_Voo(voo,editar,*maior_Voo);
        system("cls");
        printf("\t\t\t\t\tO Voo selecionado foi:\n");
        mostra_1Voo(voo,editar);
        printf("\t\t\t\t\tO Voo selecionado está correto?\n\t\t\t\t\tDigite 1 para sim 0 para recomeçar\n\t\t\t\t\t\t\t");
        scanf("%d",&test);
        if(test){
            system("cls");
            printf("\t\t\t\t\tQual informação deseja alterar?\n");
            printf("\t\t\t\t\tDigite 0 para o código dele\n");
            printf("\t\t\t\t\tDigite 1 para a cidade de Destino\n");
            printf("\t\t\t\t\tDigite 2 para a cidade de Origem\n");
            printf("\t\t\t\t\tDigite 3 para as informações de escalas\n\t\t\t\t\t\t\t");
            scanf("%d",&opc);
            switch (opc){
            case 0:
                printf("\n\t\t\t\t\tVocê escolheu editar o código do Voo\n");
                printf("\t\t\t\t\t\tO Código atual desse voo é:%d\n",voo[editar].Codigo);
                printf("\t\t\t\t\t\tDigite o Novo Código do voo:\n\t\t\t\t\t\t\t");
                scanf("%d",&cdg);
                printf("\t\t\t\t\tDeseja confirmar a troca de codigo desse voo de %d para %d?\n\t\t\t\t\t (Digite 1 para sim 0 para não)\n\t\t\t\t\t\t\t",voo[editar].Codigo,cdg);
                scanf("%d",&confirma);
                if(confirma){
                    voo[editar].Codigo = cdg;
                    printf("\t\t\t\t\tCódigo alterado com sucesso!\n\t\t\t\t\tDigite qualquer tecla para continuar\n\t\t\t\t\t\t\t");
                    fflush(stdin);
                    getchar();
                }else{
                    printf("\t\t\t\t\tO Código não foi alterado!\n\t\t\t\t\tDigite qualquer tecla para continuar\n\t\t\t\t\t\t\t\t");
                    fflush(stdin);
                    getchar();
                }
                break;
            case 1:
                printf("\n\t\t\t\t\tVocê escolheu editar a cidade de Destino do Voo\n");
                printf("\t\t\t\t\tA cidade de Destino atual desse voo é:%d\n",voo[editar].Codigo);
                printf("\t\t\t\t\tDigite a nova cidade de destino do voo:\n\t\t\t\t\t\t\t");
                scanf("%s",&alt);
                printf("Deseja confirmar a troca dessa cidade para esse voo de %s para %s?\n\t\t\t\t\t (Digite 1 para sim 0 para não)\n\t\t\t\t\t\t\t",voo[editar].Destino,alt);
                scanf("%d",&confirma);
                if(confirma){
                    strcpy(voo[editar].Destino, alt);
                    printf("\t\t\t\t\tCidade de destino alterada com sucesso!\n\t\t\t\t\tDigite qualquer tecla para continuar\n\t\t\t\t\t\t\t");
                    fflush(stdin);
                    getchar();
                }else{
                    printf("\t\t\t\t\tA cidade de destino não foi alterada!\n\t\t\t\t\tDigite qualquer tecla para continuar\n\t\t\t\t\t\t\t");
                    fflush(stdin);
                    getchar();
                }
                break;
            case 2:
                printf("\n\t\t\t\t\tVocê escolheu editar a cidade de Origem do Voo\n");
                printf("\t\t\t\t\tA cidade de origem atual desse voo é:%c\n",voo[editar].Origem);
                printf("\t\t\t\t\tDigite a nova cidade de Origem desse voo:\n\t\t\t\t\t\t\t");
                scanf("%s",&alt);
                printf("\t\t\t\t\tDeseja confirmar a troca de cidade de Origem desse voo de %s para %s?\n\t\t\t\t\t (Digite 1 para sim 0 para não)\n\t\t\t\t\t\t\t",voo[editar].Origem,alt);
                scanf("%d",&confirma);
                if(confirma){
                    strcpy(voo[editar].Origem, alt);
                    printf("\t\t\t\t\tCidade de Origem alterada com sucesso!\n\t\t\t\t\tDigite qualquer tecla para continuar\n\t\t\t\t\t\t\t");
                    fflush(stdin);
                    getchar();
                }else{
                    printf("\t\t\t\t\tA cidade de Origem não foi alterada!\n\t\t\t\t\tDigite qualquer tecla para continuar\n\t\t\t\t\t\t\t");
                    fflush(stdin);
                    getchar();
                }
                break;
            case 3:
                system("cls");
                printf("\t\t\t\t\tVocê está no menu de alterar as escalas\n");
                printf("\t\t\t\t\tO Voo escolhido possui %d escalas\n",voo[editar].numero_Escalas);
                printf("\t\t\t\t\tVocê deseja alterar a quantidade de escalas ou as cidades de escalas?\n\t\t\t\t\t (Digite 1 para o Número e 0 para as Cidades)\n\t\t\t\t\t\t\t");
                scanf("%d",&aux);
                if(aux){
                    printf("\t\t\t\t\tDigite a Nova quntidade de Escalas do Voo\n\t\t\t\t\t\t");
                    scanf("%d",&cdg);
                    voo[editar].numero_Escalas = cdg;
                    printf("\t\t\t\t\tComo há uma diferença entre o novo número de escala e o anterior,\n\t\t\t\t\t Por Favor digite as novas escalas do Voo\n:");
                    printf("\t\t\t\t\tLembre-se que o Voo agora possui %d escalas\n",cdg);
                    for(int i = 0;i<cdg;i++){
                        printf("\t\t\t\t\tDigite a %d cidade de escala do Voo\n\t\t\t\t\t\t",i+1);
                        fflush(stdin);
                        gets(alt);
                        strcpy(voo[editar].Escala[i], alt);
                        printf("\t\t\t\t\tA %d Alteração foi feita com sucesso\n\n",i+1);
                    }
                    printf("\t\t\t\t\tTodas alterações de escala foram feitas com sucesso!\n");
                }else{
                    printf("\t\t\t\t\tVocê deseja alterar todas as cidades de escala ou apenas umm?\n\t\t\t\t\t (Digite 1 para todas e 0 para não)\n\t\t\t\t\t\t\t");
                    scanf("%d",&escolha2);
                    if(escolha2){
                        printf("\t\t\t\t\tVocê selecionou para editar todas as escalas do Voo\n");
                        printf("\t\t\t\t\tPor Favor, Começe a digitar as novas cidades de escala\n");
                        for(int i=0;i<voo[editar].numero_Escalas;i++){
                            printf("Digite a %d cidade de escala\n\t\t\t\t\t\t\t",i+1);
                            fflush(stdin);
                            gets(alt);
                            strcpy(voo[editar].Escala[i], alt);
                            printf("\t\t\t\t\tA alteração %d foi feita com sucesso!\n\n",i+1);
                        }
                        printf("\t\t\t\t\tTodas alterações de Cidades de Escalas foram feitas com sucesso!\n");
                    }else{
                        while(continua){
                            printf("\n\t\t\t\t\tDigite Qual escala você deseja alterar, as disponíveis são:\n");
                            for(int i=0;i<voo[editar].numero_Escalas;i++){
                                printf("\t\t\t\t\tEscala %d: %s\n",i+1,voo[editar].Escala[i]);
                            }
                            printf("\t\t\t\t\tDigite Qual delas deseja alterar:\n\t\t\t\t\t\t\t");
                            scanf("%d",&temp);
                            temp--;
                            printf("\n\t\t\t\t\tCidade selecionada: %s",voo[editar].Escala[temp]);
                            printf("\t\t\t\t\tDigite a Nova Escala:\n\t\t\t\t\t\t\t");
                            fflush(stdin);
                            gets(alt);
                            strcpy(voo[editar].Escala[temp], alt);
                            printf("\t\t\t\t\tAlteção feita com sucesso!\n");
                            printf("\n\n\t\t\t\t\tDeseja alterar mais alguma escala? (Digite 1 para sim e 0 para não)\n\t\t\t\t\t\t\t");
                            scanf("%d",&continua);
                            }
                        }
                    }
                }
                break;
            }
        }
        system("cls");
        printf("\t\t\t\t\tApós as alterações feitas, todos os voos ficaram dessa forma:\n");
        mostra_Voos(voo,*maior_Voo);
        printf("\n\n\t\t\t\t\tDeseja alterar mais algum voo ou deseja voltar para o menu inical?\n\t\t\t\t\t (Digite 0 para não e 1 para sim)\n\t\t\t\t\t\t\t");
        scanf("%d",&escolha);
    }
}
void excluir_Voo(data_Voo voo[],int *ultimo_Voo){
    system("cls");
    int escolha, cdg, confirmacao, N, i;
    printf("\t\t\t\t\tVocê entrou no menu de exclusão de voo\n\t\t\t\t\tPara prosseguir digite 1, para voltar ao menu principal digite 0\n\t\t\t\t\t\t\t");
    scanf("%d", &escolha);
    while(escolha){
        system("cls");
        mostra_Voos(voo, *ultimo_Voo);
        printf("\t\t\t\t\tInsira o codigo do voo que deseja excluir:\n\t\t\t\t\t\t\t");
        scanf("%d",&cdg);
        N=numero_Voo(voo,cdg,*ultimo_Voo);
        system("cls");
        printf("\n\t\t\t\t\tO Voo selecionado foi: ");
        mostra_1Voo(voo,N);
        printf("\n\t\t\t\t\tCerteza que deseja excluir o voo %d?\n\t\t\t\t\t (digite 1 para sim e 0 para não):\n\t\t\t\t\t\t\t", cdg);
        scanf("%d",&confirmacao);
        if(confirmacao){
            if(*ultimo_Voo>N){
                atualiza_Posicao(voo,&*ultimo_Voo,N);
                i=*ultimo_Voo+1;
                voo[i].Codigo = 0;
                voo[i].numero_Escalas = 0;
                strcpy(voo[i].Origem,"\0");
                strcpy(voo[i].Destino,"\0");
                for(int k=0;k<tamanho_Palavras;k++){
                    strcpy(voo[i].Escala[k],"\0");
                }
            }
            else{
                i=*ultimo_Voo;
                voo[i].Codigo = 0;
                voo[i].numero_Escalas = 0;
                strcpy(voo[i].Origem,"\0");
                strcpy(voo[i].Destino,"\0");
                for(int k=0;k<tamanho_Palavras;k++){
                    strcpy(voo[i].Escala[k],"\0");
                }
                *ultimo_Voo = *ultimo_Voo - 1;
            }
            printf("\t\t\t\t\tO voo %d foi excluído com sucesso!\n\t\t\t\t\tDeseja excluir mais algum voo?\n\t\t\t\t\t\t(digite 1 para sim e 0 para voltar a tela inicial)\n\t\t\t\t\t\t", cdg);
            scanf("%d", &escolha);
        }
        else{
            printf("\n\t\t\t\t\tO voo %d não foi excluido.\n\t\t\t\t\t\tDeseja excluir algum outro voo?\n\t\t\t\t\t(digite 1 para sim e 0 para voltar a tela inicial)\n\t\t\t\t\t\t\t");
            scanf("%d", &escolha);
        }
    }
}

void acessar_Quantos(data_Voo voo[], int ultimo_Voo){

//Dada a cidade de origem determinar quantos voos saem dela:
    int escolha,confirma,qtd=0;
    char origem[tamanho_Palavras];
    system("cls");
    printf("\t\t\t\t\tVocê entrou no menu de acessar a quantidade de saída de voos de uma cidade:\n");
    printf("\t\t\t\t\tDeseja continuar ou voltar para o menu inicial?\n\t\t\t\t\t\t(Digite 1 para Sim e 0 para Não)\n\t\t\t\t\t\t\t");
    scanf("%d",&escolha);
    while(escolha){
        qtd=0;
        system("cls");
        printf("\t\t\t\t\tDigite a cidade de Origem que deseja vereficar a quantidade de voos que saem dela:\n\t\t\t\t\t\t\t");
        fflush(stdin);
        gets(origem);
        printf("\t\t\t\t\tVocê confirma que a cidade que deseja realizar os testes é a:%s?\n\t\t\t\t\t\t(Digite 1 para sim e 0 para não)\n\t\t\t\t\t\t",origem);
        scanf("%d",&confirma);
        if(confirma){
            for(int i=0; i<ultimo_Voo;i++){
                if(!strcmp(origem,voo[i].Origem)){
                    qtd++;
                }
            }if(qtd!=0){
                printf("\n\t\t\t\t\t A Cidade %s possui %d voos que saem dela\n",origem,qtd);
            }else{
                printf("\t\t\t\t\tNenhum Voo sai da cidade %s",origem);
            }
            printf("\t\t\t\tDeseja realizar mais alguma verificação desse tipo ou deseja voltar para o menu inicial?\n");
            printf("\t\t\t\t\t(Digite 1 para se manter nesse menu e 0 para voltar)\n\t\t\t\t\t\t\t");
            scanf("%d",&escolha);
        }else{
            printf("\t\t\t\t\tO Voo não foi vereficado.\n\t\t\t\t\t Deseja realizar uma nova tentativa ou voltar para o menu principal?\n");
            printf("\t\t\t\t\t(Digite 1 para tentar novamente e qualquer outro valor para voltar para o menu principal)\n\t\t\t\t\t\t\t");
            scanf("%d",&escolha);
        }
    }

}

void acessar_Quais(data_Voo voo[], int ultimo_Voo){
    int escolha=1, confirmacao,aux=0;
    char destino[tamanho_Palavras];
    while(escolha){
            system("cls");
            printf("\t\t\t\t\tVocê entrou no menu de informações, na qual informa todos os voos com o destino escolhido:\n");
            printf("\t\t\t\t\tDeseja continuar ou voltar para o menu inicial? (Digite 1 para Sim e 0 para Não)\n\t\t\t\t\t\t\t");
            scanf("%d",&escolha);
            if(escolha){
            system("cls");
            printf("\t\t\t\t\tInsira a cidade de destino para obtenção de informações:\n\t\t\t\t\t\t\t");
            fflush(stdin);
            gets(destino);
            printf("\t\t\t\t\tDeseja realizar a obtenção de informação de voos com destino em %s?\n\t\t\t\t\t\t(digite 1 para sim e 0 para não)\n\t\t\t\t\t\t\t", destino);
            scanf("%d", &confirmacao);
            if(confirmacao){
                for(int i=0;i<ultimo_Voo;i++){
                    if(strcmp(destino,voo[i].Destino) == 0){
                        aux++;
                        printf("\n\t\t\t\t\tO voo %d com origem em %s tem destino em %s\n", voo[i].Codigo, voo[i].Origem, voo[i].Destino);
                    }
                }
                if(aux == 0){
                    printf("\n\t\t\t\t\tNenhum voo foi encontrado com destino em %s\n", destino);
                }
                aux=0;
            }
            printf("\t\t\t\t\t\tDeseja obter informação sobre voos com outra cidade de destino?\n\t\t\t\t\t(digite 1 para sim e 0 para voltar ao menu inicial)\n\t\t\t\t\t\t\t");
            scanf("%d", &escolha);
        }
    }
}

void menor_Escalas(data_Voo voo[],int ultimo_Voo){
    int escolha, confirmacao, menor_Escala=9999, aux=0,menor_Escala_p;
    char origem[tamanho_Palavras], destino[tamanho_Palavras];
    system("cls");
    printf("\t\t\t\t\tVocê entrou no menu de informações\n\t\t\t\t\tNa qual informa qual o voo com o menor número de escalas de acordo com uma origem e um destino\n");
    printf("\t\t\t\t\tDeseja prosseguir nesse menu (digite 1 para sim e 0 para não)\n\t\t\t\t\t\t\t");
    scanf("%d", &escolha);
    while(escolha){
        system("cls");
        printf("\t\t\t\t\tInsira a cidade de origem do voo:\n\t\t\t\t\t\t\t");
        fflush(stdin);
        gets(origem);
        printf("\t\t\t\t\tInsira a cidade de destino do voo:\n\t\t\t\t\t\t\t");
        fflush(stdin);
        gets(destino);
        printf("\t\t\t\tDeseja pesquisar pelo voo com o menor número de escalas e origem em %s e destino em %s?\n\t\t\t\t\t(digite 1 para sim e 0 para não)\n\t\t\t\t\t\t\t\t", origem, destino);
        scanf("%d", &confirmacao);
        if(confirmacao){
            for(int i=0;i<ultimo_Voo;i++){
                if((strcmp(origem,voo[i].Origem) == 0) && (strcmp(destino,voo[i].Destino) == 0)){
                    aux++;
                    if(voo[i].numero_Escalas<menor_Escala){
                        menor_Escala_p=i;
                        menor_Escala=voo[i].numero_Escalas;
                    }
                }
            }
            if(aux == 0){
                printf("\t\t\t\t\tNenhum voo foi encontrado com as cidades de destino e origem digitadas\n");
            }
            else{
                printf("\t\t\tO voo com menor número de escalas e com origem em %s e destino em %s é:\n\n", origem, destino);
                mostra_1Voo(voo,menor_Escala_p);
            }
        }
        else{
            printf("\t\t\t\t\t\tBusca por voo com menor escala cancelado.\n");
        }
        printf("\t\t\t\t\tDeseja fazer mais uma busca por voo com menor número de escalas?\n\t\t\t\t\t\t(Digite 1 para sim e 0 para não)\n\t\t\t\t\t\t\t\t");
        scanf("%d", &escolha);
    }
}

int main(){

    setlocale(LC_ALL, "Portuguese_Brazil.1252");

    data_Voo voo[maximo_Voos];
    int escolha = interface_Inicial();
    int escolha_Secundaria = 0;
    int ultimo_Voo = 0;

    while(escolha ==0 || escolha == 1){

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
                    excluir_Voo(voo,&ultimo_Voo);
                    break;
                case 3:
                    mostra_Voos(voo,ultimo_Voo);
                    printf("\n\t\t\t\t\tDigite qualquer tecla para continuar\n");
                    fflush(stdin);
                    getchar();
                    break;
                case 4:
                    break;
                default:
                    return 0;
            }
        }else{
            switch (escolha_Secundaria) {
                case 0:
                    acessar_Quantos(voo,ultimo_Voo);
                    break;
                case 1:
                    acessar_Quais(voo,ultimo_Voo);
                    break;
                case 2:
                    menor_Escalas(voo,ultimo_Voo);
                    break;
                case 3:
                    mostra_Voos(voo, ultimo_Voo);
                    printf("\n\t\t\t\t\tDigite qualquer tecla para continuar\n");
                    fflush(stdin);
                    getchar();
                    break;
                case 4:
                    break;
                default:
                    return 0;
            }
        }
        escolha = interface_Inicial();
    }
}

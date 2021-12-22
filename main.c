#include <stdio.h>
#include <string.h>

int main()
{
    int opcao,quantidadePlantas,valorMenor=0,valorMaior=0,estoqueAtual=0,quantidadeEstoque=50,estoqueIdeal=30;
    int estoqueMinimo,vetNumClientes[7],i,somaClientes;
    char plantaCara[30],plantaBarata[30];
    float media,soma=0,valorPlanta;
    char nomePlanta[50];

    while (1) {
        printf("1 - Cadastrar planta\n");
        printf("2 - Media dos valores das plantas\n");
        printf("3 - Planta mais cara\n");
        printf("4 - Planta mais barata\n");
        printf("5 - Valor total das plantas\n");
        printf("6 - Verificar estoque\n");
        printf("7 - Quantidade de clientes na semana:\n");
        printf("8 - Sair\n");
        printf("Opcao: ");
        scanf("%d",&opcao);
        if (opcao == 1) {
            printf("Entre com o nome da planta: ");
            scanf("%s",nomePlanta);
            printf("Digite o valor dela: ");
            scanf("%f",&valorPlanta);
            printf("Entre com a quantidade de plantas compradas: ");
            scanf("%d",&quantidadePlantas);
            estoqueAtual = (quantidadeEstoque - quantidadePlantas);
            estoqueMinimo = estoqueIdeal*0.6;
            soma = soma + (valorPlanta*quantidadePlantas);
            media = soma/quantidadePlantas;
            if(valorPlanta>valorMaior){
                valorMaior = valorPlanta;
                strcpy(plantaCara,nomePlanta);

            }else if(valorPlanta<valorMenor){
                valorMenor = valorPlanta;
                strcpy(plantaBarata,nomePlanta);
            }


        } else if (opcao == 2) {
            printf("Media dos valores das plantas = %.2f\n",media);

        } else if (opcao == 3) {
            printf("A planta mais cara = %s\n",plantaCara);
            printf("O valor da planta mais cara = R$ %f\n",valorMaior);

        } else if (opcao == 4) {
            printf("A planta mais barata = %s\n",plantaBarata);
            printf("O valor da planta mais barata = R$ %f\n",valorMenor);

        } else if (opcao == 5) {
            printf("O valor total das plantas compradas eh de R$ %.2f\n",soma);

        } else if (opcao == 6) {
            printf("O estoque atual eh de %d unidades\n", estoqueAtual);
            if (estoqueAtual < estoqueMinimo) {
                printf("Eh necessario repor o estoque desta planta!\n");
            } else if (estoqueAtual > estoqueMinimo) {
                printf("O estoque desta planta ainda eh suficiente!\n");
            } else if (estoqueAtual > estoqueIdeal) {
                printf("O estoque desta planta esta acima do ideal!\n");
            }
        }else if (opcao == 7){
            for(i=0;i<7;i++){
                printf("Entre com a quantidade de clientes do dia %d: ",i+1);
                scanf("%d",&vetNumClientes[i]);
            }
            for(i=0;i<7;i++){
                somaClientes = somaClientes + vetNumClientes[i];
            }
            printf("A quantidade de clientes da semana foi de: %d\n",somaClientes);

        } else if(opcao == 8 ){
            break;

        }else{
            printf("Opcao invalida!");
        }

    }




    return 0;
}



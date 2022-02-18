#include <stdio.h>
#include <string.h>

int main()
{
    int opcao,quantidadePlantas,valorMenor=0,valorMaior=0,estoqueAtual=0,quantidadeEstoque=50,estoqueIdeal=30;
    int estoqueMinimo,vetNumClientes[7],i,somaClientes;
    char plantaCara[30],plantaBarata[30];
    float media,soma=0,valorPlanta;
    char nomePlanta[50];
    float tabelaGastos[12][4],tabelaGanhos[12][4],tabelaLucro[12][4];
    int j,mesAtual;
    float ganhoParcial=0.0,gastoParcial=0.0,lucroParcial=0.0;

    while (1) {
        printf("1 - Cadastrar planta\n");
        printf("2 - Media dos valores das plantas\n");
        printf("3 - Planta mais cara\n");
        printf("4 - Planta mais barata\n");
        printf("5 - Valor total das plantas\n");
        printf("6 - Verificar estoque\n");
        printf("7 - Quantidade de clientes na semana\n");
        printf("8 - Controle de faturamento parcial\n");
        printf("9 - Sair\n");
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
            printf("Entre com o mês atual: ");
            scanf("%d",&mesAtual);

            for(i=0;i<mesAtual;i++){
                for(j=0;j<4;j++){
                    printf("Entre com os ganhos do mês %d,semana %d: ",i+1,j+1);
                    scanf("%f",&tabelaGanhos[i][j]);
                    ganhoParcial = ganhoParcial+tabelaGanhos[i][j];
                }
            }
            for(i=0;i<mesAtual;i++){
                for(j=0;j<4;j++){
                    printf("Entre com os gastos do mês %d, semana %d: ",i+1,j+1);
                    scanf("%f",&tabelaGastos[i][j]);
                    gastoParcial = gastoParcial+tabelaGastos[i][j];
                }
            }
            for(i=0;i<mesAtual;i++){
                for(j=0;j<4;j++){
                    tabelaLucro[i][j] = tabelaGanhos[i][j] - tabelaGastos[i][j];
                    lucroParcial = lucroParcial+tabelaLucro[i][j];
                }
            }
            printf("Tabela de Lucros Parcias: \n");
            for(i=0;i<mesAtual;i++){
                printf("\n");
                for(j=0;j<4;j++){
                    printf("%.2f ",tabelaLucro[i][j]);
                }
            }
            printf("\n");
            printf("Lucro parcial até o mês %d = %.2f\n",i+1,lucroParcial);
            if(lucroParcial<ganhoParcial*0.6){
                printf("Lucro abaixo do esperado, tente economizar mais!\n");
            }
            else{
                printf("Lucro acima do esperado, continue assim!\n");
            }

        }else if(opcao == 9){
            break;

        }else{
            printf("Opcao invalida!\n");
        }

    }





    return 0;
}



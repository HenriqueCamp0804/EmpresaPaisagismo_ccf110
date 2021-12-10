#include <stdio.h>
#include <string.h>

int main()
{
    int opcao,quantidadePlantas,valorMenor=0,valorMaior=0;
    char plantaCara[30],plantaBarata[30];
    float media,soma=0,valorPlanta;
    char nomePlanta[50];

    while (1) {
        printf("1 - Cadastrar planta\n");
        printf("2 - Media das plantas\n");
        printf("3 - Planta mais cara\n");
        printf("4 - Planta mais barata\n");
        printf("5 - Valor total das plantas\n");
        printf("6 - Sair\n");
        printf("Opcao: ");
        scanf("%d",&opcao);
        if (opcao == 1) {
            printf("Entre com o nome da planta: ");
            scanf("%s",nomePlanta);
            printf("Digite o valor dela: ");
            scanf("%f",&valorPlanta);
            printf("Entre com a quantidade de plantas compradas: ");
            scanf("%d",&quantidadePlantas);
            soma = soma + valorPlanta;
            media = soma/quantidadePlantas;
            if(valorPlanta>valorMaior){
                valorMaior = valorPlanta;
                strcpy(plantaCara,nomePlanta);

            }else if(valorPlanta<valorMenor){
                valorMenor = valorPlanta;
                strcpy(plantaBarata,nomePlanta);
            }


        } else if (opcao == 2) {
            printf("Media dos valores das plantas = %f\n",media);

        } else if (opcao == 3) {
            printf("A planta mais cara = %s\n",plantaCara);
            printf("O valor da planta mais cara = R$ %f\n",valorPlanta);

        } else if (opcao == 4) {

        } else if (opcao == 5) {

        } else if (opcao == 6) {
            break;
        } else{
            printf("Opcao invalida!");
        }

    }




    return 0;
}



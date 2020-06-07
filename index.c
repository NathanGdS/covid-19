#include <stdio.h>
#include "covid19.h"
#define ESPACO() printf("\n")

/* Inf gerais:
Nome dos Integrantes:
    Nathan Garcia dos Santos 
    Nathan Felipe Guerlando
    Henrique Reche

ADS 2ºCiclo 2020
*/

int main()
{
    int nP, qD, n;
    int discovery, highnumber, dia_maior, numero_contagios;
    //printf("Digite o numero de paises: ");
    scanf("%d", &nP);
    
    char paises[nP][TAM_MAX_NOME + 1];
    le_paises(nP, paises);
    

    //printf("Qnt de dias analizados: ");
    scanf("%d", &n);
    int contagios[nP][n];
    le_contagios(nP, n, contagios);

    ESPACO();
	//SAIDA DOS DADOS
    printf("Numero total de Contagios por pais: \n");
    for(int i=0;i<nP;i++){
        printf("%s: %d\n", paises[i], total_contagios_pais(n, contagios, i));
    }

    ESPACO();

    printf("Dia com maior numero de contagios por pais:\n");
    for(int i=0;i<nP;i++){
       dia_maior_contagio_pais(n, contagios, i, &discovery, &highnumber);
       printf("%s: %d (%d)\n", paises[i], discovery+1, highnumber);
    }

    ESPACO();

    printf("Dia com maior numero de contagios: \n");
    dia_maior_contagio(nP, n, contagios, &dia_maior, &numero_contagios);
    printf("%d: %d\n", dia_maior, numero_contagios);
    
    ESPACO();

    printf("Maior sequencia crescente por pais\n");
    for(int i=0;i<nP;i++){
        printf("%s: %d\n", paises[i], maior_sequencia_crescente(n, contagios, i));
    }
    
    return 0;
}

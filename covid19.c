#include <stdio.h>
#include "covid19.h"

void le_paises(int p, char lc[][TAM_MAX_NOME + 1])
{
	//preenche a matriz com o nome digitado dos paises, tratativa no scanf
	for(int i=0;i<p;i++){
        //printf("(%d)Pais: ",i+1);
        scanf(" %50[^\n]", &lc[i]);
    }
}

void le_contagios(int p, int d, int c[][d])
{
	//preenchimento da matriz contagios
	for(int i=0;i<p;i++){
		for(int j=0; j<d;j++){
			scanf("%d", &c[i][j]);
		}
	}
}

int total_contagios_pais(int d, int c[][d], int o)
{
	int total =0;
	//somando-se o total de contágios
	for(int i=0;i<d;i++){
			total += c[o][i];
	}
	//retornando o total de contagios	
	return total;
}

void dia_maior_contagio_pais(int d, int c[][d], int x, int *discovery, int *hightestNumber)
{
	int aux, vetor[d],i,j;
	//passando os argumentos da matriz contagios para o vetor[]
	for(i=0;i<d;i++){
		vetor[i] = c[x][i];
	}
	//colocar o vetor[] em ordem crescente
	for(i=0;i<d;i++){
		for(j=i+1;j<d;j++){
			if(vetor[i] > vetor[j]){
				aux = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = aux;
			}
		}
	}
	//Definir o valor de 'hightestNumber' como o maior número de contágios
	*hightestNumber = vetor[d-1];
	
	//descobrir o índice na matriz contágios em que o maior número de contágios foi registrado
	for(i=0;i<d;i++){
		if(vetor[d-1] == c[x][i]){
			*discovery = i;
			i=d;
		}
	}
}

void dia_maior_contagio(int nP, int d, int c[][d], int *dia_maior, int *numero_contagios)
{
	int vetor[d], soma=0, aux[2]={0, 0}, i,j;

	//aux[2] = {x , y}, em que: x = soma dos contagios e y é o dia em que mais teve contagios

	//duplo for para armazenar a soma de dodas as linhas no índice de coluna[i] no vetor no indice[i]
	//desta forma é possivel somar as linhas com o mesmo indice e criar um vetor para armazenar as somas
	for(i=0;i<d;i++){
		for(j=0;j<nP;j++){
			soma += c[j][i];
		}
		vetor[i] = soma;
		soma =0;
	}
	//verificacao se a soma das linhas com os indices de colunas iguais da matriz contagios(que a soma virou o vetor[])
	// e maior que o aux[0] no indice [0] do auxiliar(aux[]), armazeno o maior numero de contagios
	// no indice [1], armazeno o indice em que a soma esta
	// assim, e possivel obter o valor do numero total de contagios e o dia em que eles ocorreram
	for(i=0;i<d;i++){
		if(vetor[i] > aux[0]){
			aux[0] = vetor[i];
			aux[1] = i;
		}
	}
	//atribuicao do aux[0] e aux[1]
	*numero_contagios = aux[0];
	//e somado '+1' ao aux[1] porque ele guarda o indice do vetor, ou seja, o primeiro indice que seria o dia '1' e '0'
	//entao para arrumar isso, estou somando +1
	*dia_maior = aux[1]+1;
	
}

int maior_sequencia_crescente(int d, int c[][d], int index)
{
int max, count = 1, aux =0;
	for (int i = 0; i < d; i++) {
		if(i+1==d){
			//nao coloquei nada nesta condicao porque caso contrario o ultimo valor do vetor
		}else{
			//caso o proximo valor seja maior que o valor atual, acreste 1 ao contador
			//caso contrario defina count = 1
			if(c[index][i] < c[index][i+1]){
				count++;
			}else{
				count = 1;
			}
			//se a variavel auxiliar for menor que a contadora, defina auxiliar = contadora
			if(aux < count){
				aux = count;
			}
			//se o proximo valor for menor que o atual, redefina o contador.
			if(c[index][i] > c[index][i+1]){
				count = 1;
			}
		}
	}
	 //auxiliar = (auxliar e maior que contador?) se sim, auxiliar = auxiliar(continua com o mesmo valor)
	 //caso contrario, auxiliar = contador(count)
	 aux = aux > count ? aux : count;
   
   	return aux;
}
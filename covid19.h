#ifndef _COVID19_H 
#define _COVID19_H 
#define TAM_MAX_NOME 50


void le_paises(int, char [][TAM_MAX_NOME + 1]); 

void le_contagios(int, int, int [][*]); 

int total_contagios_pais(int, int [][*], int);

void dia_maior_contagio_pais(int, int [][*], int, int *, int *);

void dia_maior_contagio(int, int, int [][*], int *, int *);

int maior_sequencia_crescente(int, int [][*], int);

#endif
 
 

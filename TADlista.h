#ifndef TADLISTA
#define TADLISTA

#include "dados.h"

#define MAXNOS 100

//lista simplesmente ligada 
typedef struct no{
	 Dados elem;
	 struct no *prox;
}No;

typedef struct grafo{
	int numNos;
	Dados nos[MAXNOS];
	int matrizAdj[MAXNOS][MAXNOS];
}Grafo;
	
//inicializar a lista
void inicializar(No **);

//escrever lista
void escrever(No *);

//inserir lista contigua
void inserirContigua(Grafo *, Dados);

//inserir novo nó em determinada posição
void inserirLigada(No **, Dados);

#endif


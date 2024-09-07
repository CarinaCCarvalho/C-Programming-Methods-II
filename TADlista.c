#include <stdio.h>
#include <stdlib.h>
#include "TADlista.h"


//inicializar lista
void inicializar(No **lst){
	
	*lst=NULL;
}

//escrever lista
void escrever(No *lst){
	
	while(lst != NULL){
		printf("%s %s  \n", lst->elem.nome, lst->elem.apelido);
		lst=lst->prox;
	}
}

//inserir lista contígua
void inserirContigua(Grafo *g, Dados elemento){
	
	g->nos[g->numNos]=elemento;
	g->numNos=g->numNos+1;
} 

//inserir novo nó em determinada posição
void inserirLigada(No **lst, Dados elemento){
	
	No *novo;
	novo = (No*)malloc(sizeof(No));
	novo->elem = elemento;
	novo->prox = *lst;
	*lst=novo;
}

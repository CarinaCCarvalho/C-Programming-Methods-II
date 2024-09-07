#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "grafoTAD.h"
#include "TADlista.h"

int main(){
	
	//variável
	Grafo g;
	
	//cria o grafo
	criarGrafo(&g);
  
	//lê o ficheiro CSV
	lerFicheiro(&g);

	//insere uma nova pessoa
	inserirPessoa(&g);
	
	//retira uma pessoa
	retirarPessoa(&g);
	
	//insere uma nova relação 
	inserirRelacao(&g);
	
	//retira uma relação
	retirarRelacao(&g);
	
	//edita os dados de uma pessoa
	editarPessoa(&g);
	
	//indica os pais de uma pessoa
	Pais(g);
	
	//indica se uma pesosa tem irmãos e se sim quais
	Irmaos(g);
	
	//indica a família de uma pessoa
	Familia(g);
	
	//indica os ancestrais de uma pessoa
	Ancestrais(g);

	//escreve no ficheiro CSV
	escreverFicheiro(g);

	return 0;
}

#ifndef GRAFOTAD
#define GRAFOTAD
#define NUMNOS 100

#include "TADlista.h"

//cria grafo
void criarGrafo(Grafo *);

//lê o ficheiro CSV
void lerFicheiro(Grafo *);

//escreve no ficheiro CSV
void escreverFicheiro(Grafo);

//função procurar pessoa
int procurarPessoa(Grafo, char *, char *);

//insere uma nova pessoa
void inserirPessoa(Grafo *);

//retira uma pessoa
void retirarPessoa(Grafo *);

//insere uma nova relação
void inserirRelacao(Grafo *);

//retira uma relação
void retirarRelacao(Grafo *);

//edita os dados de uma pessoa
void editarPessoa(Grafo *); 

//indica os pais de uma pessoa da família
void Pais(Grafo);

//indica se uma pessoa tem irmãos e se sim quais
void Irmaos(Grafo);

//indica a família de uma pessoa
void Familia(Grafo);

//indica os ancestrais de uma pessoa (pais, avós, bisavós,...)
void Ancestrais(Grafo);

#endif

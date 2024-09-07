#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafoTAD.h"
#define MAXDIMNOME 40

//cria grafo
void criarGrafo (Grafo *g){
	g->numNos=0;
	g->matrizAdj[0][0]=0;
}

//lê o ficheiro CSV
void lerFicheiro(Grafo *g){
	
	//Variáveis
	Dados d;
	FILE *f; //ponteiro para manipular o ficheiro
	
	int maxLinha=1000;

	char linha[maxLinha];
	char *aux;

	int j;
	int i=0;
	f=fopen("ficheiro dados.csv","r"); //Abrir o ficheiro para leitura, "r"=read
	
	while(fgets(linha, maxLinha, f)!=NULL) //Lê todas as linhas do ficheiro; cada linha fica guardada na varivável linha
	{
		//Separar nome e idade
		aux=strtok(linha,",");//Separa linha até encontrar ","
		strcpy(d.nome,aux);//copia string em "aux" para d.nome
		
		aux=strtok(NULL,",");//Separa linha até encontrar ","
		strcpy(d.apelido,aux);//copia string em "aux" para d.apelido

		aux=strtok(NULL,","); //Regressa a "linha" e devolve até encontrar a prox vírgula ou até ao final de aux
		d.diaN=atoi(aux); //atoi converte string em int

		aux=strtok(NULL,","); //Regressa a "linha" e devolve até encontrar a prox vírgula ou até ao final de aux
		d.mesN=atoi(aux); //atoi converte string em int

		aux=strtok(NULL,","); //Regressa a "linha" e devolve até encontrar a prox vírgula ou até ao final de aux
		d.anoN=atoi(aux); //atoi converte string em int

		aux=strtok(NULL,","); //Regressa a "linha" e devolve até encontrar a prox vírgula ou até ao final de aux
		d.diaF=atoi(aux); //atoi converte string em int

		aux=strtok(NULL,","); //Regressa a "linha" e devolve até encontrar a prox vírgula ou até ao final de aux
		d.mesF=atoi(aux); //atoi converte string em int

		aux=strtok(NULL,","); //Regressa a "linha" e devolve até encontrar a prox vírgula ou até ao final de aux
		d.anoF=atoi(aux); //atoi converte string em int
	
		inserirContigua(g,d); //inserir lista
		
		for(j=0;j<DIMMAX;j++){
			aux=strtok(NULL, ","); 
			(g->matrizAdj[i][j])=atoi(aux);
		}
		i++;
	}
	fclose(f);
}

//escreve no ficheiro CSV
void escreverFicheiro(Grafo g){
	
	//variáveis
	FILE *f;
	int i,j;
	
	//abertura do ficheiro para escrita
	f=fopen("ficheiro dados.csv","w");
	
	//escreve no ficheiro os dados das pessoas
	for(i=0; i<g.numNos; i++){
		fprintf (f, "%s,%s,%d,%d,%d,%d,%d,%d", g.nos[i].nome, g.nos[i].apelido, g.nos[i].diaN,  g.nos[i].mesN,  g.nos[i].anoN,  g.nos[i].diaF,  g.nos[i].mesF,  g.nos[i].anoF);
		for(j=0; j < g.numNos; j++){
			fprintf (f, ",%d", g.matrizAdj[i][j]);
		}
		fprintf (f, "\n");
	}
	fclose(f);
}

//função procurar pessoa
int procurarPessoa(Grafo g, char name[DIMMAX], char surname[DIMMAX]){
	
	//variáveis
	int i=0;
	int flag=0;
	
	//o programa procura a posição em que se encontra a pessoa escolhida pelo utilizador
	while(i<g.numNos && strcmp(name, g.nos[i].nome)!=0 && flag==0){
		//confere se o primeiro nome e o apelido são coincidem com os pedidos pelo utilizador
		if(strcmp (name, g.nos[i].nome)==0 && strcmp(surname, g.nos[i].apelido)==0){
			flag=1;
		}else{
			i=i+1;
		}
	}
	//o programa chega ao fim da lista e não encontra nenhum nome que coincida com o pedido pelo utilizador
	if(i==g.numNos){
		i=-1;
	}
	return i;
}

//insere uma nova pessoa
void inserirPessoa(Grafo *g){
	
	//variáveis
	int i, j, k;
	
	printf("\n");
	printf ("Quer inserir uma nova pessoa? Insira 1-sim ou 2-nao: \n");
	scanf("%d", &k);
	
	//se não quer inserir nova pessoa, o programa avança à próxima pergunta
	if(k==2){
		return;
	}
	//se quer, insere pessoa
	else{
		
		//utilizador insere os dados da nova pessoa que quer inserir
		printf("Insira o primeiro nome da nova pessoa:");
		scanf("%s", g->nos[g->numNos].nome);
		printf("Insira o apelido da nova pessoa:");
		scanf("%s", g->nos[g->numNos].apelido);
		printf("Insira o dia de nascimento da nova pessoa: ");
		scanf("%d", &g->nos[g->numNos].diaN);
		printf("Insira o mes de nascimento da nova pessoa: ");
		scanf("%d", &g->nos[g->numNos].mesN);
		printf("Insira o ano de nascimento da nova pessoa: ");
		scanf("%d", &g->nos[g->numNos].anoN);
		printf("Insira o dia de falecimento da nova pessoa:");
		scanf("%d", &g->nos[g->numNos].diaF);
		printf("Insira o mes de falecimento da nova pessoa: ");
		scanf("%d", &g->nos[g->numNos].mesF);
		printf("Insira o ano de falecimento da nova pessoa: ");
		scanf("%d", &g->nos[g->numNos].anoF);
		
		//insere uma nova coluna
		for(i=0; i<g->numNos; i++){
			g->matrizAdj[i][g->numNos]=0;
		}
		//insere nova linha
		for(j=0; j<g->numNos; j++){
			g->matrizAdj[g->numNos][j]=0;
		}
		
		//aumenta em 1 o número de pessoas da família
		g->numNos=g->numNos+1;
	}
	inserirPessoa(g);
}

//retira uma pessoa
void retirarPessoa(Grafo *g){
	
	//variáveis
	Dados P;
	int i, j, k, p;
	
	printf("\n");
	printf ("Quer apagar uma pessoa? Insira 1-sim ou 2-nao: \n");
	scanf("%d", &k);
	
	//apaga uma pessoa
	if(k==1){
		
		//o utilizador indica quem quer apagar
		printf ("Insira o primeiro nome da pessoa que deseja apagar: ");
		scanf ("%s", P.nome);
		printf ("Insira o seu apelido: ");
		scanf ("%s", P.apelido);
		
		//o programa procura a posição da pessoa escolhida
		p=procurarPessoa(*g, P.nome, P.apelido);
		
		//apaga a coluna
		for(i=0; i<g->numNos; i++){
			for (j=p;j<g->numNos-1; j++){
				g->matrizAdj[i][j] = g->matrizAdj[i][j+1];
			}
		}
		
		//apaga a linha
		for(i=p; i<g->numNos-1; i++){
			for (j=0; j<g->numNos-1; j++){
				g->matrizAdj[i][j] = g->matrizAdj[i+1][j];
			}
		}
	
		for(i=p;i<g->numNos;i++){
			g->nos[i] = g->nos[i+1];
		}
		//diminiui em 1 o número de pessoas
		g->numNos--;
	}
	
	//se não quer apagar pessoa, o programa avança à próxima pergunta
	if (k==2){
		return;
	}
	retirarPessoa(g);
}

//insere uma nova relação
void inserirRelacao(Grafo *g){
	
	//variáveis
	Dados P1, P2;
	int a, b, escolha;
	
	printf("\n");
	printf("Quer inserir uma nova relacao? Insira 1-sim ou 2-nao: \n");
	scanf("%d", &a);
	
	
	//insere a nova relação
	if(a==1){
		
		printf ("Qual a relacao que quer estabelecer? Insira 1(casal) ou 2(progenitor): \n");
		scanf("%d", &escolha);

		//a relação entre a P1 e a P2 é de casal. A matriz guarda a posição (i,j) como 1
		if(escolha==1){
			
			//o utilizador insere os dados das 2 pessoas da relação 
			printf ("Insira o primeiro nome da pessoa 1: ");
			scanf ("%s", P1.nome);
			printf ("Insira o apelido da pessoa 1: ");
			scanf ("%s", P1.apelido);
			printf ("Insira o primeiro nome da pessoa 2: ");
			scanf ("%s", P2.nome);
			printf ("Insira o apelido da pessoa 2: ");
			scanf ("%s", P2.apelido);
			
			
			//procura a posição das 2 pessoas da relação
			a=procurarPessoa(*g, P1.nome, P1.apelido);
			b=procurarPessoa(*g, P2.nome, P2.apelido);
			
			//nas posições (a,b) e (b,a) da matriz é inserido 1
			g->matrizAdj[a][b]=1;
			g->matrizAdj[b][a]=1; 
			
		}
		//a relação entre a P1 e a P2 é de pai-filho. A matriz guarda a posição (i,j) como 2 e 0 na posição(j,i)
		else{
			
			//o utilizador insere os dados das 2 pessoas da relação 
			printf ("Insira o primeiro nome do progenitor: ");
			scanf ("%s", P1.nome);
			printf ("Insira o apelido do progenitor: ");
			scanf ("%s", P1.apelido);
			printf ("Insira o primeiro nome do/a filho/a: ");
			scanf ("%s", P2.nome);
			printf ("Insira o apelido do/a filho/a: ");
			scanf ("%s", P2.apelido);
			
			//procura a posição das 2 pessoas da relação
			a=procurarPessoa(*g, P1.nome, P1.apelido);
			b=procurarPessoa(*g, P2.nome, P2.apelido);
			
			//na posição (a,b) da matriz é inserido 2
			g->matrizAdj[a][b]=2; 
		}
	}
	//se não quer inserir uma relação, o programa avança à próxima pergunta
	else{
		return;
	}
	inserirRelacao(g);
}

//retira uma relação
void retirarRelacao(Grafo *g){
	
	//variáveis
	int a, b;
	Dados P1, P2;
	
	printf("\n");
	printf("Quer apagar uma relacao? Insira 1-sim ou 2-nao: \n");
	scanf("%d", &a);
	
	//retira uma relação
	if (a==1){
		
		//o utilizador insere os dados das 2 pessoas da relação
		printf ("Insira o primeiro nome da pessoa 1: ");
		scanf ("%s", P1.nome);
		printf ("Insira o apelido da pessoa 1: ");
		scanf ("%s", P1.apelido);
		printf ("Insira o primeiro nome da pessoa 2: ");
		scanf ("%s", P2.nome);
		printf ("Insira o apelido da pessoa 2: ");
		scanf ("%s", P2.apelido);
		
		//procura a posição das 2 pessoas da relação
		a=procurarPessoa(*g, P1.nome, P1.apelido);
		b=procurarPessoa(*g, P2.nome, P2.apelido);
		
		//nas posições (a,b) e (b,a) da matriz é inserido 0
		g->matrizAdj[a][b]=0;
		g->matrizAdj[b][a]=0; 
		
	}
	//se não quer retirar uma relação, o programa avança à próxima pergunta
	else{
		return;
	}
	retirarRelacao(g);
}

//edita os dados de uma pessoa
void editarPessoa(Grafo *g){
	
	//variáveis
	int i, editar;
	Dados P;
	
	printf("\n");
	printf("Quer editar uma pessoa? Insira 1-sim ou 2-nao: \n");
	scanf("%d", &editar);
	
	//edita os dados de uma pessoa
	if(editar == 1){
		
		//o utilizador indica a pessoa que quer editar
		printf("Insira o primeiro nome da pessoa que quer editar:");
		scanf ("%s", P.nome);
		printf("Insira o seu apelido:");
		scanf ("%s", P.apelido);
		
		//procura a posição da pessoa
		i=procurarPessoa(*g, P.nome, P.apelido);
		
		//o utilizador insere os novos dados da pessoa
		printf("Insira o novo nome da pessoa: ");
		scanf("%s", g->nos[i].nome);
		printf("Insira o novo apelido da pessoa: ");
		scanf("%s", g->nos[i].apelido);
		printf("Insira o novo dia de nascimento da pessoa: ");
		scanf("%d", &g->nos[i].diaN);
		printf("Insira o novo mes de nascimento da pessoa: ");
		scanf("%d", &g->nos[i].mesN);
		printf("Insira o novo ano de nascimento da pessoa: ");
		scanf("%d", &g->nos[i].anoN);
		printf("Insira o novo dia de falecimento da pessoa:");
		scanf("%d", &g->nos[i].diaF);
		printf("Insira o novo mes de falecimento da pessoa: ");
		scanf("%d", &g->nos[i].mesF);
		printf("Insira o novo ano de falecimento da da pessoa: ");
		scanf("%d", &g->nos[i].anoF);
	}
	//se não quer editar os dados de uma pessoa, o programa passa à próxima pergunta
	else{
		return;
	}
	editarPessoa(g);
}

//indica os pais de uma pessoa da família
void Pais(Grafo g){
	
	//variáveis
	No *lst;
	Dados P;
	int i,j,k;
	int numPais=0;
	
	//inicializa a lista
	inicializar(&lst);
	
	printf("\n");
	printf("Deseja saber quem sao os pais de alguma pessoa da familia? Insira 1-sim ou 2-nao: \n");
	scanf("%d", &k);
	
	//se não quiser saber quem são os pais, o programa avança para a próxima pergunta
	if(k==2){
		return;
	}
	//indica os pais de uma pessoa da família
	else{
		
		//o utilizador indica a pessoa de que deseja conhecer os pais
		printf("Indique o primeiro nome de quem deseja conhecer os pais: ");
		scanf("%s", P.nome);
		printf("Indique o seu apelido: ");
		scanf("%s", P.apelido);
	
		//procura a posição da pessoa
		i=procurarPessoa(g, P.nome, P.apelido);

		//o programa encontra na linha da pessoa i o número 2 e indica a pessoa j a que corresponde
		for(j=0; j<g.numNos; j++){
			if(g.matrizAdj[j][i]==2){
				inserirLigada(&lst, g.nos[j]);
				numPais++;
			}
		}
			
		//se o número de pais for diferente de 0, então o programa escreve-os
		if(numPais!=0){
			printf("Os pais de %s %s sao:\n", P.nome, P.apelido);
			escrever(lst);
		}
		
		//se o número de pais for igual a 0, então não existem 
		if(numPais==0){
			printf("A pessoa nao tem pais\n");
		}
	}
	Pais(g);
}

//indica se uma pessoa tem irmãos e se sim quais
void Irmaos(Grafo g){
	
	//variáveis
	No *lst;
	Dados P;
	int i,j,k,l,m;
	int numIrmaos=0;
	int x=0;

	//iniciliza a lista
	inicializar(&lst);
	
	printf("\n");
	printf("Deseja saber se alguma pessoa da familia tem irmaos? Insira 1-sim ou 2-nao: \n");
	scanf("%d", &k);
	
	//se não quiser saber se uma pessoa tem irmãos, o programa avança para a próxima pergunta
	if(k==2){
		return;
	}
	//indica se uma pessoa tem irmãos e se sim quais
	else{
		
		//o utilizador indica a pessoa de quem deseja conhecer os irmaos
		printf("Indique o primeiro nome de quem deseja conhecer os irmaos: ");
		scanf("%s", P.nome);
		printf("Indique o seu apelido: ");
		scanf("%s", P.apelido);
	
		//procura a posição da pessoa
		i=procurarPessoa(g, P.nome, P.apelido);

		//o programa encontra na linha da pessoa j o número 2 e indica a pessoa i a que corresponde
		for(j=0; j<g.numNos; j++){
			if(g.matrizAdj[j][i]==2){
				l=j;
				x++;
			}
		}
		
		if(x==0){
		printf("A pessoa nao tem irmaos\n");}
		
		if(x>=1){
		//o programa encontra na linha da pessoa l=j o número 2 e indica a pessoa m a que corresponde
		for(m=0; m<g.numNos; m++){
			if(g.matrizAdj[l][m]==2){
				//se a pessoa m for diferente da pessoa i é porque são irmãos
				if(m!=i){
					inserirLigada(&lst, g.nos[m]);
					
					//escreve o nome de todos os irmãos
					numIrmaos++;
				} 
			}
		}

		//se o número de irmãos for diferente de 0, então o programa escreve-os
			if(numIrmaos!=0){
				printf("O/A(s) irmao/irma(s) de %s %s sao:\n", P.nome, P.apelido);
				escrever(lst);
		}
		//se o número de irmãos for igual a 0, então não existem 
			if(numIrmaos==0){
				printf("A pessoa nao tem irmaos\n");
			}
		}			
	Irmaos(g);
	}
}

//indica a família de uma pessoa
void Familia(Grafo g){
	
	//variáveis
	Dados P;
	int i, k, pos;//pos é posição

	printf("\n");
	printf("Quer conhecer a familia de alguma pessoa? Insira 1-sim ou 2-nao: \n");
	scanf("%d", &k);
	
	//se não quiser conhecer a família de uma pessoa, o programa avança para a próxima pergunta
	if(k==2){
		return;
	}
	//indica a família de uma pessoa
	else{
		
		//o utilizador indica a pessoa de quem deseja conhecer a família
		printf("Indique o primeiro nome de quem deseja conhecer a familia: ");
		scanf("%s", P.nome);
		printf("Indique o seu apelido: ");
		scanf("%s", P.apelido);
		
		//procura a posição da pessoa
		pos=procurarPessoa(g, P.nome, P.apelido);
		
		//imprime os nomes de todos os membros da família da pessoa escolhida
		for(i=0; i<g.numNos; i++){
			if(i!= pos){
				printf("%s %s\n",g.nos[i].nome,g.nos[i].apelido);
			}
		}
	}
	Familia(g);
}

//indica os ancestrais de uma pessoa (pais, avós, bisavós,...)
void Ancestrais(Grafo g){
	
	//variáveis
	No *lst;
	Dados P;
	int i, j, k, l, m;
	int numAncestrais=0;
	
	//inicializa a lista
	inicializar(&lst);
	
	printf("\n");
	printf("Quer conhecer os ancestrais de alguma pessoa? Insira 1-sim ou 2-nao: \n");
	scanf("%d", &k);
	
	//se não quiser conhecer os ancestrais de uma pessoa, o programa avança para a próxima pergunta
	if(k==2){
		return;
	}
	//indica os ancestrais de uma pessoa
	else{
		//o utilizador indica a pessoa de quem deseja conhecer os ancestrais
		printf("Indique o primeiro nome de quem deseja conhecer os ancestrais: ");
		scanf("%s", P.nome);
		printf("Indique o seu apelido: ");
		scanf("%s", P.apelido);
		
		//procura a posição da pessoa
		i=procurarPessoa(g, P.nome, P.apelido);
		
		//indica os pais da pessoa i
		for(j=0; j<g.numNos; j++){
			if(g.matrizAdj[j][i]==2){
				inserirLigada(&lst, g.nos[j]);
				
				//indica os avós da pessoa i
				for(l=0; l<g.numNos; l++){
					if(g.matrizAdj[l][j]==2){
						inserirLigada(&lst, g.nos[l]);
						
						//indica os bisavós da pessoa i
						for(m=0; m<g.numNos; m++){
							if(g.matrizAdj[m][l]==2){
								inserirLigada(&lst, g.nos[m]);
								numAncestrais++;
							}
						}
					}
				}
			}
		}
		
		//se o número de ancestrais for diferente de 0, então o programa escreve-os
		if(numAncestrais!=0){
			printf("Os ancestrais de %s %s sao:\n", P.nome, P.apelido);
			escrever(lst);
		}
		
		//se o número de ancestrais for igual a 0, então não existem 
		if(numAncestrais==0){
			printf("A pessoa nao tem ancestrais\n");
		}
	}
	Ancestrais(g);
}


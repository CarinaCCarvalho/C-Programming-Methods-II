#ifndef ELEMENTOS
#define ELEMENTOS

#define DIMMAX 100

typedef struct dados
{
	char nome[DIMMAX];//nome
	char apelido[DIMMAX];//apelido
	int diaN; //dia de nascimento
	int mesN; //mês de nascimento
	int anoN; //ano de nascimento
	int diaF; //dia de falecimento
	int mesF; //mês de falecimento
	int anoF; //ano de falecimento
}Dados;

#endif


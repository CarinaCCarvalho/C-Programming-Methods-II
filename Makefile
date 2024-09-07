
#Compilador
CC = gcc
#Opções de compilação
CFLAGS = -Wall
#Bibliotecas adicionais
LIBS = -lm

.PHONY: all clean run

all: usaGrafo

usaGrafo: TADlista.o grafoTAD.o usaGrafo.c
	$(CC) -o $@ $@.c TADlista.o grafoTAD.o ${CFLAGS} ${LIBS} 

run: 
	cls
	./usaGrafo.exe
	
clean: 
	-del usaGrafo.exe *.o



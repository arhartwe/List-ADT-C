#-----------------------------------------------------------------
# Makefile for CMPS 101 Programming Assignment 2
#
# 	make			makes Lex
# 	make ListClient		makes ListClient
#
# 	Name		: Andrew Hartwell
# 	CruzID		: arhartwe
# 	Assignment	: pa2
#-----------------------------------------------------------------

Lex: Lex.o List.o
	gcc -o Lex Lex.o List.o

Lex.o: Lex.c List.h
	gcc -c -std=c99 -Wall Lex.c

ListClient: ListClient.o List.o
	gcc -g -o ListClient ListClient.o List.o

ListClient.o: ListClient.c List.h
	gcc -g -c -std=c99 -Wall ListClient.c

ModelListTest: ModelListTest.o List.o
	gcc -g -o ModelListTest ModelListTest.o List.o

ModelListTest.o: ModelListTest.c List.h
	gcc -g -c -std=c99 -Wall ModelListTest.c

List.o: List.c List.h
	gcc -g -c -std=c99 -Wall List.c

clean:
	rm -f Lex ListClient Lex.o ListClient.o List.o

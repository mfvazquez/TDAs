#Compilador
CC = gcc
#Opciones usadas para compilar
CFLAGS = -Wall -pedantic -std=c99 -g
#Nombre del programa principal
CEXE = prueba_hash


all: $(CEXE)

.SILENT:
lista.o: lista.h lista.c
	$(CC) $(CFLAGS) -c lista.c

.SILENT:
hash.o: hash.h hash.c
	$(CC) $(CFLAGS) -c hash.c

.SILENT:
$(CEXE): lista.o hash.o $(CEXE).c
	$(CC) $(CFLAGS) lista.o hash.o $(CEXE).c -o $(CEXE)

.SILENT:
clean:
	-rm *.o
	-rm $(CEXE)

.SILENT:
cleanAll: clean
	-rm $(CEXE)
	
run: all
	./$(CEXE)	

test: $(CEXE)
	valgrind ./$(CEXE)

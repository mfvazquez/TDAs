#Compilador
CC = gcc
#Opciones usadas para compilar
CFLAGS = -Wall -pedantic -std=c99 -g
#Nombre del programa principal
CEXE = prueba_abb


all: $(CEXE)

.SILENT:
abb.o: abb.h abb.c
	$(CC) $(CFLAGS) -c abb.c

.SILENT:
pila.o: pila.h pila.c
	$(CC) $(CFLAGS) -c pila.c

.SILENT:
$(CEXE): pila.o abb.o $(CEXE).c
	$(CC) $(CFLAGS) pila.o abb.o $(CEXE).c -o $(CEXE)

.SILENT:
clean:
	-rm *.o

.SILENT:
cleanAll: clean
	-rm $(CEXE)

run: all
	./$(CEXE)	

test: $(CEXE)
	valgrind --leak-check=full ./$(CEXE)

#Compilador
CC = gcc
#Opciones usadas para compilar
CFLAGS = -Wall -pedantic -std=c99 -g
#Nombre del programa principal
CEXE = prueba_cola


all: $(CEXE)

.SILENT:
cola.o: cola.h cola.c
	$(CC) $(CFLAGS) -c cola.c

.SILENT:
$(CEXE): cola.o $(CEXE).c
	$(CC) $(CFLAGS) cola.o $(CEXE).c -o $(CEXE)

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

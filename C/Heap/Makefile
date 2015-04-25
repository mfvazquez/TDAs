#Compilador
CC = gcc
#Opciones usadas para compilar
CFLAGS = -Wall -pedantic -std=c99 -g
#Nombre del programa principal
CEXE = prueba_heap


all: $(CEXE)

.SILENT:
heap.o: heap.h heap.c
	$(CC) $(CFLAGS) -c heap.c

.SILENT:
$(CEXE): heap.o $(CEXE).c
	$(CC) $(CFLAGS) heap.o $(CEXE).c -o $(CEXE)

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

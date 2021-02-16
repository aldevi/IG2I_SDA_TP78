c=gcc
op=-Wall -Wextra

all : es.o livre.o biblio.o tpBiblio.c saveload.o menu.o
	$(c) $(op)  es.o livre.o biblio.o tpBiblio.c saveload.o menu.o -o exe

es.o : es.c es.h
	$(c) $(op) -c es.c	
livre.o : livre.c livre.h
	$(c) $(op) -c livre.c	
biblio.o : biblio.c biblio.h
	$(c) $(op) -c biblio.c	
saveload.o : saveload.c saveload.h
	$(c) $(op) -c saveload.c
menu.o : menu.c menu.h
	$(c) $(op) -c menu.c

clean :
	rm -rf exe *.o *.a *.so
gcc libreria_ari.c -c
ar -r libreria_ari.a libreria_ari.o
gcc rubrica_malloc.c libreria_ari.a -o ex


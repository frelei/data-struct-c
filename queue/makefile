#Makefile para gerar executaveis de teste do programa

# Variáveis do makefile
# colocar aplicação em home para funcionar os caminhos   
#sources=../../uthread/src/
#includes=../../uthread/include/
#bin=../../uthread/bin/

#CFLAGS=-Wall -ansi -pedantic

# comando para mover obj para  pasta bin: 'mv *.o ${bin}' 

test_queue:
	gcc -Wall -c queue.c queue-test.c
	gcc -Wall queue.o queue-test.o -o queue-test


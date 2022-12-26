all: isort.o txtfind.o 

isort.c: isort.o
         gcc -wall -c isort.c -o isort


txtfind.c: txtfind.o
		   gcc -wall -c txtfind.c -o txtfind
		   
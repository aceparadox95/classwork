default: progDFS progBFS

cirListDeque.o: cirListDeque.h cirListDeque.c
	gcc -ansi -Wall -std=c99 -c cirListDeque.c
	
dynamicArray.o: dynamicArray.h dynamicArray.c
	gcc -ansi -Wall -std=c99 -c dynamicArray.c
	
graph.o: graph.h graph.c cirListDeque.o
	gcc -ansi -Wall -std=c99 -c graph.c

progDFS: graph.o cirListDeque.o dynamicArray.o main.c
	gcc -ansi -Wall -std=c99 -DBDFS=1 -o progDFS graph.o cirListDeque.o dynamicArray.o main.c

progBFS: graph.o cirListDeque.o dynamicArray.o main.c
	gcc -DBDFS=0 -Wall -std=c99 -ansi -o progBFS graph.o cirListDeque.o dynamicArray.o main.c

clean:
	rm dynamicArray.o
	rm cirListDeque.o
	rm graph.o

cleanall: clean
	rm progDFS
	rm progBFS 

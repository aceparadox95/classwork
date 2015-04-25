#include "cirListDeque.h"
#include <stdio.h>

int main(){
	struct cirListDeque* q = createCirListDeque(); 
	addBackCirListDeque(q, (TYPE)1);
	addBackCirListDeque(q, (TYPE)2);
	addBackCirListDeque(q, (TYPE)3);
	addFrontCirListDeque(q, (TYPE)4);
	addFrontCirListDeque(q, (TYPE)5);
	addFrontCirListDeque(q, (TYPE)6);
	printf("Printing Deque: \n");
	printCirListDeque(q);
	printf("Front of Deque: %g\n", frontCirListDeque(q));
	printf("Back of Deque: %g\n", backCirListDeque(q));
	printf("Removing Front and Back Links: \n");
	removeFrontCirListDeque(q);
	removeBackCirListDeque(q);
	printf("Printing Deque: \n");
	printCirListDeque(q);
	printf("Reversing Deque: \n");
	reverseCirListDeque(q);
	printf("Printing Deque: \n");
	printCirListDeque(q);
	return 0;
}

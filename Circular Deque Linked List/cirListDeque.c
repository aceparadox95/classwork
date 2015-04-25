#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <float.h>
#include "cirListDeque.h"

/* Double Link Struture */
struct DLink {
	TYPE value;/* value of the link */
	struct DLink * next;/* pointer to the next link */
	struct DLink * prev;/* pointer to the previous link */
};

# define TYPE_SENTINEL_VALUE DBL_MAX 


/* ************************************************************************
 Deque ADT based on Circularly-Doubly-Linked List WITH Sentinel
 ************************************************************************ */

struct cirListDeque {
	int size;/* number of links in the deque */
	struct DLink *Sentinel;	/* pointer to the sentinel */
};
/* internal functions prototypes */
struct DLink* _createLink (TYPE val);
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v);
void _removeLink(struct cirListDeque *q, struct DLink *lnk);



/* ************************************************************************
	Deque Functions
************************************************************************ */

/* Initialize deque.

	param: 	q		pointer to the deque
	pre:	q is not null
	post:	q->Sentinel is allocated and q->size equals zero
*/
void _initCirListDeque (struct cirListDeque *q) 
{
	assert(q != NULL && q != 0);
	q->Sentinel = malloc(sizeof(struct DLink)); // allocate sentinel
	assert(q->Sentinel != 0);// check for proper allocation
	q->Sentinel->next = q->Sentinel; // set the prev and next pointers to itself
	q->Sentinel->prev = q->Sentinel;
	q->size = 0; // set size to zero
}

/*
 create a new circular list deque
 
 */

struct cirListDeque *createCirListDeque()
{
	struct cirListDeque *newCL = malloc(sizeof(struct cirListDeque));//allocate linked list
	_initCirListDeque(newCL);// initialize the list
	return(newCL);// return the linked list
}


/* Create a link for a value.

	param: 	val		the value to create a link for
	pre:	none
	post:	a link to store the value
*/
struct DLink * _createLink (TYPE val)
{
	struct DLink *newLink = malloc(sizeof(struct DLink));//allocate a new link
	assert(newLink != 0);//check for proper allocation
	newLink->value = val;// pass value to the link
	return (newLink);// return the link and leave prev and next at null
}

/* Adds a link after another link

	param: 	q		pointer to the deque
	param: 	lnk		pointer to the existing link in the deque
	param: 	v		value of the new link to be added after the existing link
	pre:	q is not null
	pre: 	lnk is not null
	pre:	lnk is in the deque 
	post:	the new link is added into the deque after the existing link
*/
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v)
{
	assert(lnk != 0);
	struct DLink *newLink = _createLink(v); // create a link
	newLink->next = lnk->next; //set the next link of new link to the next link of the link passed
	newLink->prev = lnk; // set the prev link of new link to the link passed
	lnk->next->prev = newLink; // set the prev pointer of the lnk after the link passed to the new link
	lnk->next = newLink;// set the next pointer of the passed link to the new link
	q->size++;//increase the size of the area
}

/* Adds a link to the back of the deque

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the back of the deque
*/
void addBackCirListDeque (struct cirListDeque *q, TYPE val) 
{
	_addLinkAfter(q, q->Sentinel->prev, val); // add link after the link previous to the sentinel
}

/* Adds a link to the front of the deque

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the front of the deque
*/
void addFrontCirListDeque(struct cirListDeque *q, TYPE val)
{
	_addLinkAfter(q, q->Sentinel, val);// add link after the current sentinel
}

/* Get the value of the front of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the front of the deque
*/
TYPE frontCirListDeque(struct cirListDeque *q) 
{
	assert(q != NULL && !isEmptyCirListDeque(q));
	return q->Sentinel->next->value; //return the top of the deque
}

/* Get the value of the back of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the back of the deque
*/
TYPE backCirListDeque(struct cirListDeque *q)
{
	assert(q != NULL && !isEmptyCirListDeque(q));
	return q->Sentinel->prev->value;//return back of the deque
}

/* Remove a link from the deque

	param: 	q		pointer to the deque
	param: 	lnk		pointer to the link to be removed
	pre:	q is not null and q is not empty
	post:	the link is removed from the deque
*/
void _removeLink(struct cirListDeque *q, struct DLink *lnk)
{
	assert(q != NULL && !isEmptyCirListDeque(q)); // check for prequisites
	lnk->prev->next = lnk->next; //set the next pointer of the link previous to the passed link to the next link 
	lnk->next->prev = lnk->prev; // set the prev pointer of the link after the passed link to the previous link
	free(lnk); // free link from memory
	q->size--; //reduce size of linked list
}

/* Remove the front of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the front is removed from the deque
*/
void removeFrontCirListDeque (struct cirListDeque *q) {
	assert(q != NULL && !isEmptyCirListDeque(q));
	_removeLink(q, q->Sentinel->next); //remove link after sentinel
}


/* Remove the back of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the back is removed from the deque
*/
void removeBackCirListDeque(struct cirListDeque *q)
{
	assert(q != NULL && !isEmptyCirListDeque(q));
	_removeLink(q, q->Sentinel->prev); // remove link before sentinel
}

/* De-allocate all links of the deque

	param: 	q		pointer to the deque
	pre:	none
	post:	All links (including Sentinel) are de-allocated
*/
void freeCirListDeque(struct cirListDeque *q)
{
	while (q->size > 0) //cycle through the deque and remove the front of link until the size is zero
		removeFrontCirListDeque(q);
	free(q->Sentinel); //free Sentinel from memory
	q->Sentinel = 0; //set sentinel to nothing
}

/* Check whether the deque is empty

	param: 	q		pointer to the deque
	pre:	q is not null
	ret: 	1 if the deque is empty. Otherwise, 0.
*/
int isEmptyCirListDeque(struct cirListDeque *q) {
	assert(q != 0); // check to see if list is empty
	return(q->size == 0); // return the boolean of whether size is zero
}

/* Print the links in the deque from front to back

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the links in the deque are printed from front to back
*/
void printCirListDeque(struct cirListDeque *q)
{
	assert(q != 0 && q->size !=0);
	struct DLink *cur = q->Sentinel->next;
	while (cur != q->Sentinel)
	{
		printf("Value: %g\n", cur->value); //print short form double
		cur = cur->next; // iterate to next link
	}
}

/* Reverse the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the deque is reversed
*/
void reverseCirListDeque(struct cirListDeque *q)
{
	assert(q != 0 && q->size != 0);
	struct DLink *cur = q->Sentinel->next;
	struct DLink *tempLink =q->Sentinel->next; // store this value again to swap the pointer
	/*The following function was far as i got before talking with group members for help*/
	/*while (cur != q->Sentinel)
	{
		tempLink = cur->prev;
		cur->prev = cur->next;
		cur->next = tempLink;
		cur = tempLink->next;*/
	q->Sentinel->next = q->Sentinel->prev; // point original next to the original previous
	q->Sentinel->prev = cur; // point original previous to original next pointer
	while (cur != q->Sentinel)
	{
	tempLink = cur->prev; //store current link in temp variable
	cur->prev = cur->next; // Swap pointer links around
	cur->next = tempLink; 
	cur = cur->prev; //iterate backwards to the previous link after each swap
	}
}

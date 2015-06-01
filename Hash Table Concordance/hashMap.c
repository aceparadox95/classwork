#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "hashMap.h"



/*the first hashing function you can use*/
int stringHash1(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += str[i];
	return r;
}

/*the second hashing function you can use*/ //chose to use this one
int stringHash2(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += (i+1) * str[i]; /*the difference between stringHash1 and stringHash2 is on this line*/
	return r;
}

/* initialize the supplied hashMap struct*/
void _initMap (struct hashMap * ht, int tableSize)
{
	int index;
	if(ht == NULL)
		return;
	ht->table = (hashLink**)malloc(sizeof(hashLink*) * tableSize);
	ht->tableSize = tableSize;
	ht->count = 0;
	for(index = 0; index < tableSize; index++)
		ht->table[index] = NULL;
}

/* allocate memory and initialize a hash map*/
hashMap *createMap(int tableSize) {
	assert(tableSize > 0);
	hashMap *ht;
	ht = malloc(sizeof(hashMap));
	assert(ht != 0);
	_initMap(ht, tableSize);
	return ht;
}

/*
 Free all memory used by the buckets.
 Note: Before freeing up a hashLink, free the memory occupied by key and value
 */
void _freeMap (struct hashMap * ht)
{  
	struct hashLink *current;
	struct hashLink *prev;
	for (int i = 0; i < ht->tableSize; i++)
	{
		current = ht->table[i]; //set temp pointer to the first bucket
		while (current != NULL) // iterate through the bucket links until it is empty
		{
			prev = current->next;
			free(current->key);
			//free(current->value); //this made the program crash
			free(current);
			current = prev;
		}
		free(ht->table);
		ht->count = 0;
		ht->table = 0;
		ht->tableSize = 0;
	}
}

/* Deallocate buckets and the hash map.*/
void deleteMap(hashMap *ht) {
	assert(ht!= 0);
	/* Free all memory used by the buckets */
	_freeMap(ht);
	/* free the hashMap struct */
	free(ht);
}

/* 
Resizes the hash table to be the size newTableSize 
*/
void _setTableSize(struct hashMap * ht, int newTableSize)
{
	int oldSize = ht->tableSize; //preseve original tableSize
	struct hashLink *current, *prev;
	struct hashLink **oldTable = ht->table; // save the old table
	_initMap(ht, newTableSize); //reinitialize the old hasMap at double the size
	for (int i = 0; i < oldSize; i++)
	{
		current = oldTable[i]; //set the current pointer to bucket index
		while (current != 0)
		{
			insertMap(ht, current->key, current->value); //assign the values from the old table to the new table
			prev = current; //set the previous pointer to the current pointer
			current = current->next; //set the current pointer to its next pointer
			free(prev); //free the previous value from memory
		}
	}
	free(oldTable); // free the old table from memory
}

/*
 insert the following values into a hashLink, you must create this hashLink but
 only after you confirm that this key does not already exist in the table. For example, you
 cannot have two hashLinks for the word "taco".
 
 if a hashLink already exists in the table for the key provided you should
 replace that hashLink--this requires freeing up the old memory pointed by hashLink->value
 and then pointing hashLink->value to value v.
 
 also, you must monitor the load factor and resize when the load factor is greater than
 or equal LOAD_FACTOR_THRESHOLD (defined in hashMap.h).
 */
void insertMap (struct hashMap * ht, KeyType k, ValueType v)
{  
	int bucket = stringHash2(k) % ht->tableSize; //hash the value into the right bucket
	struct hashLink *insLink;
	struct hashLink *tmp;
	if (ht->table[bucket] == 0) // check to see if the bucket is empty and add to front
	{
		if (tableLoad(ht) > LOAD_FACTOR_THRESHOLD) //resize if needed
			_setTableSize(ht, ht->tableSize * 2);
		insLink = (struct hashLink*) malloc(sizeof(struct hashLink)); //allocate memory for new link
		ht->table[bucket] = insLink; //set the first link in the bucket to new link
		ht->table[bucket]->key = k; //set the key of the link to the provided key
		ht->table[bucket]->value = v; //set the value of the link to the provided value
		ht->table[bucket]->next = 0; // set the next value to null
		ht->count++; //increase the count of the hashtable
		
	}
	else //otherwise add the value to end of hashlink chain in the bucket
	{
		tmp = ht->table[bucket];
		while (tmp != 0) //find an empty bucket
		{
			if (strcmp(tmp->key, k) == 0) //if the key is the same change the value
			{
				tmp->value = v;
				return;
			}
			else //otherwise set it equal to the next
			{
				tmp = tmp->next;
			}
		}
		if (tableLoad(ht) > LOAD_FACTOR_THRESHOLD) //resize if needed
			_setTableSize(ht, ht->tableSize * 2);
		insLink = (struct hashLink*) malloc(sizeof(struct hashLink));
		insLink->key = k;
		insLink->value = v;
		insLink->next = ht->table[bucket];
		ht->table[bucket] = insLink;
		ht->count++;
	}
}

/*
 this returns the value (which is void*) stored in a hashLink specified by the key k.
 
 if the user supplies the key "taco" you should find taco in the hashTable, then
 return the value member of the hashLink that represents taco.
 
 if the supplied key is not in the hashtable return NULL.
 */
ValueType* atMap (struct hashMap * ht, KeyType k)
{ 
	int bucket = stringHash2(k) % ht->tableSize; //determine the bucket location
	struct hashLink *current;
	struct hashLink *prev;
	if (ht->table[bucket] == 0)
		return 0;
	else
	{
		current = ht->table[bucket];
		prev = ht->table[bucket];
		while (current != 0) // while the bucket is not empty
		{
			if (strcmp(current->key, k) == 0) //check to see if it matches
				return &current->value; //return address of pointer to occurences value
			else
			{
				prev = current;
				current = current->next; //otherwise move the iterator forward
			}
		}
		return 0;
	}
}

/*
 a simple yes/no if the key is in the hashtable. 
 0 is no, all other values are yes.
 */
int containsKey (struct hashMap *ht, KeyType k)
{  
	int bucket = stringHash2(k) % ht->tableSize;
	if (bucket < 0) //switch the bucket to a positive number
	{
		bucket += ht->tableSize;
	}
	struct hashLink *current = ht->table[bucket]; // point a node to hashed bucket vlaue
	while (current != 0)//iterate through links of the bucket
	{
		if (strcmp(current->key,k) == 0) //if the key is there return the value of true
			return 1;
		else
			current = current->next;
	}
	return 0;
}

/*
 find the hashlink for the supplied key and remove it, also freeing the memory
 for that hashlink. it is not an error to be unable to find the hashlink, if it
 cannot be found do nothing (or print a message) but do not use an assert which
 will end your program.
 */
void removeKey (struct hashMap * ht, KeyType k)
{  
	// compute hash value to find the correct bucket
	int bucket = stringHash2(k) % ht->tableSize;

	//assert(ht->count != 0);
	struct hashLink *current, *prev;
	current = ht->table[bucket];
	prev = ht->table[bucket];

	if (ht->table[bucket] == 0)
		return;
	else
	{
		current = ht->table[bucket];
		prev = ht->table[bucket];
		while (current != 0)
		{
			//so we have our bucket, we first compare the values at current, and the testElement
			if (strcmp(current->key,k) == 0)
			{
				if (current == ht->table[bucket]) //checks for front of bucket
					ht->table[bucket] = current->next;
				else //the node is in the middle somewhere
				{
					// else adjust the neighbors to point to each other, free the node
					prev->next = current->next;
				}
				free(current);
				ht->count--;
				//return;
				current = 0; //exit the loop!!
			}
			else
			{
				//reset our prev and current, and run it all again in our while loop
				prev = current;
				current = current->next;
			}

		}
	}
}

/*
 returns the number of hashLinks in the table
 */
int size (struct hashMap *ht)
{  
	return ht->count;
}

/*
 returns the number of buckets in the table
 */
int capacity(struct hashMap *ht)
{  
	return ht->tableSize;
}

/*
 returns the number of empty buckets in the table, these are buckets which have
 no hashlinks hanging off of them.
 */
int emptyBuckets(struct hashMap *ht)
{  
	int bucketCount = 0;
	for (int i = 0; i < ht->tableSize; i++)
	{
		if (ht->table[i] == 0)
			bucketCount++;
	}
	return bucketCount;
}

/*
 returns the ratio of: (number of hashlinks) / (number of buckets)
 
 this value can range anywhere from zero (an empty table) to more then 1, which
 would mean that there are more hashlinks then buckets (but remember hashlinks
 are like linked list nodes so they can hang from each other)
 */
float tableLoad(struct hashMap *ht)
{  
	return (float)size(ht) / (float)capacity(ht);
}
void printMap (struct hashMap *ht)
{
	int i;
	struct hashLink *temp;	
	for(i = 0;i < capacity(ht); i++){
		temp = ht->table[i];
		if(temp != 0) {		
			printf("\nBucket Index %d -> ", i);		
		}
		while(temp != 0){	
			printf("Key:%s|", temp->key);
			printValue(temp->value);
			printf(" -> ");
			temp=temp->next;			
		}		
	}
}
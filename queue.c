/*
Written by Michael Sirh
Assignment 0 for CS 201
Classes for SLL, DLL, Queue and Stack

*/

//#include "sll.h"
#include <stdlib.h>
#include <stdio.h>
//#include "integer.h"
#include "queue.h"

queue *newQueue(void (*d)(FILE *,void *))
{
	queue *items = newSLL(d);

	return items;

}   //constructor
void enqueue(queue *items,void *value)
{
	insertSLL(items,sizeSLL(items),value);
}      //stores a generic value
void *dequeue(queue *items)
{
	void *value;
	value = removeSLL(items,0);
	return value;
}               //returns a generic value
void *peekQueue(queue *items)
{
	return getSLL(items,sizeSLL(items)-1);
}               //returns a generic value
int sizeQueue(queue *items)
{
	return sizeSLL(items);
}
void displayQueue(FILE *fp,queue *items)
{
	displaySLL(fp,items);
}

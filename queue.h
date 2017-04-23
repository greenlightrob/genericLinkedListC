/*
Written by Michael Sirh
Assignment 0 for CS 201
Classes for SLL, DLL, Queue and Stack

*/

#include <stdio.h>
#include "sll.h"

typedef sll queue;

queue *newQueue(void (*d)(FILE *,void *));   //constructor
void enqueue(queue *items,void *value);      //stores a generic value
void *dequeue(queue *items);                 //returns a generic value
void *peekQueue(queue *items);               //returns a generic value
int sizeQueue(queue *items);
void displayQueue(FILE *fp,queue *items);

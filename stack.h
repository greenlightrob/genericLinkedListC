/*
Written by Michael Sirh
Assignment 0 for CS 201
Classes for SLL, DLL, Queue and Stack

*/

#include <stdio.h>
#include "dll.h"

typedef dll stack;

stack *newStack(void (*d)(FILE *,void *));   //constructor
void push(stack *items,void *value);         //stores a generic value
void *pop(stack *items);                     //returns a generic value
void *peekStack(stack *items);               //returns a generic value
int sizeStack(stack *items);
void displayStack(FILE *,stack *items);
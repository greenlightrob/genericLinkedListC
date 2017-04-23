/*
Written by Michael Sirh
Assignment 0 for CS 201
Classes for SLL, DLL, Queue and Stack

*/

//#include "dll.h"
#include <stdlib.h>
#include <stdio.h>
//#include "integer.h"
#include "stack.h"

stack *newStack(void (*d)(FILE *,void *))
{
	stack *items = newDLL(d);

	return items;

}   //constructor
void push(stack *items,void *value)
{
	insertDLL(items,0,value);
}       //stores a generic value
void *pop(stack *items)
{
	void *value;
	value = removeDLL(items,0);
	return value;
}                     //returns a generic value
void *peekStack(stack *items)
{
	return getDLL(items,sizeDLL(items)-1);
}               //returns a generic value
int sizeStack(stack *items)
{
	return sizeDLL(items);
}
void displayStack(FILE *fp,stack *items)
{
	displayDLL(fp,items);
}
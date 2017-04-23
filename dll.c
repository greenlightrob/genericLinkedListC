/*
Written by Michael Sirh
Assignment 0 for CS 201
Classes for SLL, DLL, Queue and Stack

*/

#include "dll.h"
#include <stdlib.h>
#include <stdio.h>
//#include "integer.h"

dll *newDLL(void (*d)(FILE *,void *))
{
	dll *items = malloc(sizeof(dll));
    if (items == 0)
    {
        fprintf(stderr,"out of memory");
        exit(-1);
    }
    items->head = NULL;
    items->tail = NULL;
    items->size = 0;
    items->display = d;
    return items;
}            //constructor


void insertDLL(dll *items,int index,void *value)
{
	dllnode* newNode = malloc(sizeof(dllnode));
    newNode->value = value;
    newNode->next = NULL;
    newNode->previous = NULL;

    if (index == 0) //Insert at Front
    {
    	//printf("inside insert at front\n");
  		if (items->head == NULL)
  		{
  			items->head = newNode;
  			items->tail = newNode;
  		}
  		else
  		{
  			newNode->next = items->head;
  			items->head->previous = newNode;
  			items->head = newNode;
  		}


    }

    else if (items->size == index) //Insert at back
    {
    	items->tail->next = newNode;
    	newNode->previous = items->tail;
    	items->tail = newNode;
    }

    else //EVERTHING ELSE
    {
    	//printf("\n inside insert in middle\n");
    	dllnode* temp = malloc(sizeof(dllnode));
    	temp = items->head;
        
        int counter;
        for (counter = 0;counter < index-1; counter++)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        newNode->previous = temp;
        temp->next->previous = newNode;
        temp->next = newNode;
    }
    items->size = items->size + 1;
} //stores a generic value


void *removeDLL(dll *items,int index)
{
	dllnode* temp = malloc(sizeof(dllnode));
    int counter = 0;
    //void *value = 0;

    if (index == 0) // Removes from the front of the list
    {
    	if(items->head == items->tail)
    	{
    		temp->value = items->head->value;
    		items->head = NULL;
    		items->tail = NULL;
    	}
    	else
    	{
    		temp->value = items->head->value;
    		items->head = items->head->next;
    		items->head->previous = NULL;
    	}
    }
    else if (index < items->size - 1) //Removes from the middle of the list
    {
    	//printf("inside remove middle");
    	if (index <= (items->size/2))
    	{
           // printf("inside first half... ");
    		dllnode *delete = items->head;
    		for (counter = 0; counter<index-1;counter++)
    		{
    			delete = delete->next;
    		}
    		temp->value = delete->next->value;

    		delete->next = delete->next->next;
    		delete->next->previous = delete;
    	}
    	else
    	{
            //printf("inside second half...");
    		dllnode *delete = items->tail;
    		dllnode *delete1 = NULL;
    		for (counter = items->size - 1; counter > index + 1; counter--)
    		{
    			delete = delete->previous;
    		}
    		temp->value = delete->previous->value;

    		delete->previous = delete->previous->previous;
    		delete1 = delete;
    		delete1 = delete1->previous;
    		//temp->value = delete1->value;
    		delete1->next = delete;
    		//delete->previous->next = delete;
    	}
    }
    else // Remove from the back of the list
    {
    	dllnode *delete = items->head;
    	temp->value = items->tail->value;
    	while (delete->next != items->tail)
    	{
    		delete = delete->next;
    	}
    	items->tail = delete;
    	items->tail->next = NULL;
    }
    items->size--;
    return temp->value;
}         //returns a generic value


void unionDLL(dll *recipient,dll *donor)
{
    if (donor->head == NULL)
    {
        return;
    }
    else
    {
	    recipient->size = recipient->size + donor->size;
	    donor->head->previous = recipient->tail;
        recipient->tail->next = donor->head;

        recipient->tail = donor->tail;

        donor->head = NULL;
        donor->tail = NULL;
        donor->size = 0;
    } 

}         //merge two lists into one


void *getDLL(dll *items,int index)
{
	int counter = 0;
    dllnode* temp = malloc(sizeof(dllnode));
    temp = items->head;
    void *value;
    for (counter = 0 ; counter != index; counter++)
    {
    	temp = temp->next;
    }
    value = temp->value;
    return value;
}               //get the value at the index


int sizeDLL(dll *items)
{
	return items->size;
}


void displayDLL(FILE *fp,dll *items)
{
	if (items->head == NULL)
	{
		fprintf(fp,"[]");
	}
	else
	{
		dllnode *temp = malloc(sizeof(dllnode));
		temp = items->head;
		fprintf(fp,"[");
		while (items->head != NULL)
		{
			if (items->head->next != NULL)
			{
				items->display(fp,items->head->value);
				fprintf(fp,",");
				items->head = items->head->next;
			}
			else
			{
				items->display(fp,items->head->value);
				items->head = items->head->next;
				fprintf(fp,"]");
               
			}
		}
		items->head = temp;
	}
}


/*
Written by Michael Sirh
Assignment 0 for CS 201
Classes for SLL, DLL, Queue and Stack

*/

#include "sll.h"
#include <stdlib.h>
//#include "integer.h"


extern sll *newSLL(void (*d)(FILE *,void *))
{
    sll *items = malloc(sizeof(sll));
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

} //constructor


extern void insertSLL(sll *items,int index,void *value)
{
    sllnode* newNode = malloc(sizeof(sllnode));
    newNode->value = value;
    newNode->next = NULL;

    if (index == 0) //Insert at Front
    {
    	//printf("inside insert at front\n");
  		if (items->head == NULL) //If the sll is empty
  		{
  			items->head = newNode;
  			items->tail = newNode;
  		}
  		else //If the sll has elements, insert at front
  		{
  			newNode->next = items->head;
  			items->head = newNode;
  		}


    }

    else if (items->size == index) //Insert at back
    {
    	items->tail->next = newNode;
    	items->tail = newNode;
    }

    else //EVERTHING ELSE
    {
    	//printf("\n inside insert in middle\n");
    	sllnode* temp = malloc(sizeof(sllnode));
    	temp = items->head;
        
        int counter; 
        for (counter = 0;counter < index-1; counter++) //iterates through to one node before the index
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }
    items->size = items->size + 1;

}//stores a generic value


extern void *removeSLL(sll *items,int index) //NEED TO CREATE SPECIAL CASES FOR IF SIZE IS ONE, IF REMOVING LAST INDEX
{
    
    //fprintf("size of %s",items->size);

    sllnode* temp = malloc(sizeof(sllnode));
    int counter = 0;
    //void *value = 0;

    if (index == 0)
    {
        if(items->head == items->tail) //If the sll has size of one
        {
            temp->value = items->head->value;
            items->head = NULL;
            items->tail = NULL;
        }
        else //if sll is > 1 and remove from front
        {
    	   temp->value = items->head->value;
    	   items->head = items->head->next;
        }
    }
    else if (index < items->size - 1) //remove from sll in the middle
    {
    	//printf("inside remove middle");
    	sllnode *delete = items->head;
    	for (counter = 0; counter<index-1;counter++) //iterates to node before index
    	{
    		delete = delete->next;
    	}
    	temp->value = delete->next->value;
    	delete->next = delete->next->next;
    }
    else //remove from sll in the end of sll
    {
    	sllnode *delete = items->head;
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

}//returns a generic value


extern void unionSLL(sll *recipient,sll *donor)
{
  //  sslnode* temp = malloc(sizeof(sllnode));
    if(donor->head == NULL)
    {
        return;
    }
    else
    {  
	   recipient->size = recipient->size + donor->size;
        recipient->tail->next = donor->head;
        //temp->next = donor->head;
        recipient->tail = donor->tail;
        donor->head = NULL;
        donor->tail = NULL;
        donor->size = 0;
    }



}        //merge two lists into one

extern void *getSLL(sll *items,int index)
{
    int counter = 0;
    sllnode* temp = malloc(sizeof(sllnode));
    temp = items->head;
    void *value;
    for (counter = 0 ; counter != index; counter++)
    {
    	temp = temp->next;
    }
    value = temp->value;
    return value;

}               //get the value at the index

extern int sizeSLL(sll *items)
{
    return items->size;
}


extern void displaySLL(FILE *fp,sll *items)
{
	if (items->head == NULL)
	{
		fprintf(fp,"[]");
	}
	else
	{
		sllnode *temp = malloc(sizeof(sllnode));
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


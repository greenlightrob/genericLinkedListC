#include <stdio.h>
#include <stdlib.h>
#include "sll.h"
#include "dll.h"
#include "stack.h"
#include "queue.h"
#include "integer.h"

void showQueue(queue *s)
{
 printf("Queue is ");
 displayQueue(stdout,s);
 printf(".\n");
}

void showStack(stack *s)
{
 printf("Stack is ");
 displayStack(stdout,s);
 printf(".\n");
}

void sllShowItems(sll *items)
{
  int size = sizeSLL(items);
  printf("SLL of size %d is ", size);
  displaySLL(stdout,items);
  printf(".\n");
}



void dllShowItems(dll *items)
{
  int size = sizeDLL(items);
  printf("DLL of size %d is ", size);
  displayDLL(stdout,items);
  printf(".\n");
}



int main(void)
{

  printf("SLL TEST\nINSERTING\n\n");

  sll *items = newSLL(displayInteger);
  sllShowItems(items);//test empty

  insertSLL(items,0,newInteger(3));
  sllShowItems(items);//test adding to empty

  int x = getInteger((integer *) getSLL(items,0));    //get the first item
  printf("The first item is %d.\n",x);

  insertSLL(items,0,newInteger(5));
  sllShowItems(items);//test adding to front

  x = getInteger((integer *) getSLL(items,1));    //get the last item
  printf("The last item is %d.\n",x);

  insertSLL(items,2,newInteger(8));
  sllShowItems(items);//test adding to end with index

  x = getInteger((integer *) getSLL(items,1));    //get the middle item
  printf("The middle item is %d.\n",x);

  x = getInteger((integer *) getSLL(items,0)); //get first item
  printf("The first item is %d.\n",x);

  insertSLL(items,sizeSLL(items),newInteger(9));
  sllShowItems(items);//test adding to end with size call

  insertSLL(items,1,newInteger(3));
  sllShowItems(items);//test adding to middle

  

  printf("\n\nTEST REMOVING\n");
  printf("The value ");
  displayInteger(stdout,removeSLL(items,0));
  printf(" was removed.\n");
  sllShowItems(items);//test removing from front
  
  printf("The value ");
  displayInteger(stdout,removeSLL(items,1));
  printf(" was removed.\n");
  sllShowItems(items);//test removing from middle
  
  printf("The value ");
  displayInteger(stdout,removeSLL(items,2));
  printf(" was removed.\n");
  sllShowItems(items);//test removing from back
  
  printf("The value ");
  displayInteger(stdout,removeSLL(items,1));
  printf(" was removed.\n");
  sllShowItems(items);//test removing from back
  
  printf("The value ");
  displayInteger(stdout,removeSLL(items,0));
  printf(" was removed.\n");
  sllShowItems(items);//test removing last item

  printf("\n\nTEST Union\n");
  sll *first = newSLL(displayInteger);
  sll *giver = newSLL(displayInteger);//used for union
  insertSLL(first,0,newInteger(11));
  insertSLL(first,sizeSLL(first),newInteger(22));
  insertSLL(first,1,newInteger(8));
  insertSLL(giver,0,newInteger(33));
  insertSLL(giver,sizeSLL(giver),newInteger(44));
  sllShowItems(first);
  sllShowItems(giver);
  unionSLL(first,giver);//test union
  sllShowItems(first);
  sllShowItems(giver);

  printf("The value ");
  displayInteger(stdout,removeSLL(first,2));
  printf(" was removed.\n");
  sllShowItems(first);//test removing third element from union





  printf("\n\nTEST Size\n");
  sll *size = newSLL(displayInteger);
  for (int a = 0; a <= 149; a++)
  {
    insertSLL(size,sizeSLL(size),newInteger(a));
  }
  sllShowItems(size); 



  printf("\n\nDLL INT TEST\nTEST INSERTING\n");
  dll *itemsDLL = newDLL(displayInteger);
  dllShowItems(itemsDLL);//test empty
  
  insertDLL(itemsDLL,0,newInteger(5));
  
  dllShowItems(itemsDLL);//test adding to empty
  int y = getInteger((integer *) getDLL(itemsDLL,0));    //get the first item
  printf("The first item is %d.\n",y);
  
  insertDLL(itemsDLL,0,newInteger(3));
  dllShowItems(itemsDLL);//test adding to front
  
  insertDLL(itemsDLL,2,newInteger(6));
  dllShowItems(itemsDLL);//test adding to end with index
  
  insertDLL(itemsDLL,sizeDLL(itemsDLL),newInteger(8));
  dllShowItems(itemsDLL);//test adding to end with size call
  
  insertDLL(itemsDLL,1,newInteger(4));
  dllShowItems(itemsDLL);//test adding to front middle
  
  insertDLL(itemsDLL,4,newInteger(7));
  dllShowItems(itemsDLL);//test adding to back middle

  x = getInteger((integer *) getDLL(itemsDLL,0)); //test get first element
  printf("The first item is %d.\n",x); 

  x = getInteger((integer *) getDLL(itemsDLL,3)); //test get middle element
  printf("A middle item is %d.\n",x); 

  x = getInteger((integer *) getDLL(itemsDLL,sizeDLL(itemsDLL)-1)); //test get last element
  printf("The last item is %d.\n",x); 



  printf("\n\nTEST Removal\n");

  printf("The value ");
  displayInteger(stdout,removeDLL(itemsDLL,1));
  printf(" was removed. ");
  dllShowItems(itemsDLL);//test removing 4 from front middle
  
  printf("The value ");
  displayInteger(stdout,removeDLL(itemsDLL,3));
  printf(" was removed. ");
  dllShowItems(itemsDLL);//test removing 7 from back middle
  
  printf("The value ");
  displayInteger(stdout,removeDLL(itemsDLL,0));
  printf(" was removed. ");
  dllShowItems(itemsDLL);//test removing 0 from front 
  
  printf("The value ");
  displayInteger(stdout,removeDLL(itemsDLL,1));
  printf(" was removed. ");
  dllShowItems(itemsDLL);//test removing 6 from middle
  
  printf("The value ");
  displayInteger(stdout,removeDLL(itemsDLL,sizeDLL(itemsDLL)-1));
  printf(" was removed. ");
  dllShowItems(itemsDLL);//test removing 8 from back
  
  printf("The value ");
  displayInteger(stdout,removeDLL(itemsDLL,0));
  printf(" was removed. ");
  dllShowItems(itemsDLL);//test removing 5 from last value


  printf("\n\nTEST Union\n");
  dll *firstDLL = newDLL(displayInteger);//used later for union
  dll *giverDLL = newDLL(displayInteger);
  insertDLL(firstDLL,0,newInteger(11));
  insertDLL(firstDLL,sizeDLL(firstDLL),newInteger(22));
  insertDLL(firstDLL,sizeDLL(firstDLL),newInteger(34));
  insertDLL(giverDLL,0,newInteger(33));
  insertDLL(giverDLL,sizeDLL(giverDLL),newInteger(44));
  dllShowItems(firstDLL);
  dllShowItems(giverDLL);
  unionDLL(firstDLL,giverDLL);//test union
  dllShowItems(firstDLL);
  dllShowItems(giverDLL);

  printf("The value ");
  displayInteger(stdout,removeDLL(firstDLL,3));
  printf(" was removed. ");
  dllShowItems(firstDLL);//test remove third element from union

  printf("\n\nDLL FRONT BACK TEST\n");
  dll *frontback = newDLL(displayInteger);
  insertDLL(frontback,0,newInteger(11));
  insertDLL(frontback,sizeDLL(frontback),newInteger(22));
  insertDLL(frontback,sizeDLL(frontback),newInteger(34));
  insertDLL(frontback,0,newInteger(33));
  insertDLL(frontback,sizeDLL(frontback),newInteger(44));
  insertDLL(frontback,sizeDLL(frontback),newInteger(55));
  insertDLL(frontback,sizeDLL(frontback),newInteger(66));
  dllShowItems(frontback);
   printf("The value ");
  displayInteger(stdout,removeDLL(frontback,5));
  printf(" was removed. ");
  dllShowItems(frontback);

  printf("The value ");
  displayInteger(stdout,removeDLL(frontback,1));
  printf(" was removed. ");
  dllShowItems(frontback);





  printf("\n\nDLL Size test\n");
  dll *sDLL = newDLL(displayInteger);
  for (int i = 0; i <= 149; i++)
  {
    insertDLL(sDLL,sizeDLL(sDLL),newInteger(i));
  }
  dllShowItems(sDLL);


  printf("\n\nTesting union empty sll and dll\n");
  dll *firstunion = newDLL(displayInteger);
  dll *secondunion = newDLL(displayInteger);

  sll *firstsll = newSLL(displayInteger);
  sll *secondsll = newSLL(displayInteger);

  insertDLL(firstunion,0,newInteger(1));
  insertSLL(firstsll,0,newInteger(1));
  dllShowItems(firstunion);
  sllShowItems(firstsll);

  unionDLL(firstunion,secondunion);
  unionSLL(firstsll,secondsll);

  sllShowItems(firstsll);
  dllShowItems(firstunion);





  printf("\n\nQUEUE TEST\n");
  queue *oneQueue = newQueue(displayInteger);
  showQueue(oneQueue);
  enqueue(oneQueue,newInteger(24));
  enqueue(oneQueue,newInteger(44));
  enqueue(oneQueue,newInteger(81));
  showQueue(oneQueue);
  printf("The value ");
  displayInteger(stdout,dequeue(oneQueue));
  printf(" was dequeued.\n");
  showQueue(oneQueue);
  printf("The value ");
  displayInteger(stdout,dequeue(oneQueue));
  printf(" was dequeued.\n");
  showQueue(oneQueue);
  printf("The value ");
  displayInteger(stdout,dequeue(oneQueue));
  printf(" was dequeued.\n");
  showQueue(oneQueue);

  enqueue(oneQueue,newInteger(99));
  showQueue(oneQueue);

   displayInteger(stdout,dequeue(oneQueue));
  printf(" was dequeued.\n");
  showQueue(oneQueue);

  int j = 0;
  printf("Enqueuing 100 values onto a Queue\n");
  for(j = 0;j<100;j++)
  {
    enqueue(oneQueue,newInteger(j));
  }
  showQueue(oneQueue);

  printf("Dequeuing 100 values from queue\n");
  for(j = 0; j<100; j++)
  {
    displayInteger(stdout,dequeue(oneQueue));
    printf(" ");
  }


  printf("\n\nSTACK TEST\n");
  stack *oneStack = newStack(displayInteger);
  showStack(oneStack);
  push(oneStack,newInteger(24));
  push(oneStack,newInteger(44));
  showStack(oneStack);
  printf("The value ");
  displayInteger(stdout,pop(oneStack));
  printf(" was popped.\n");
  showStack(oneStack);
  printf("The value ");
  displayInteger(stdout,pop(oneStack));
  printf(" was popped.\n");

  showStack(oneStack);
  push(oneStack,newInteger(99));
  showStack(oneStack);

  printf("The value ");
  displayInteger(stdout,pop(oneStack));
  printf(" was popped.\n");
  showStack(oneStack);

  int i = 0;
  printf("Pushing 100 values onto Stack\n");
  for(i = 0;i<100;i++)
  {
    push(oneStack,newInteger(i));
  }
  showStack(oneStack);

  printf("Poping 100 values from Stack\n");
  for(i=0;i<100;i++)
  {
    displayInteger(stdout,pop(oneStack));
    printf(" ");
  }
  showStack(oneStack);
 
  return 0;
}
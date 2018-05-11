/** @file libpriqueue.c
 */

#include <stdlib.h>
#include <stdio.h>

#include "libpriqueue.h"


/**
  Initializes the priqueue_t data structure.
  
  Assumtions
    - You may assume this function will only be called once per instance of priqueue_t
    - You may assume this function will be the first function called using an instance of priqueue_t.
  @param q a pointer to an instance of the priqueue_t data structure
  @param comparer a function pointer that compares two elements.
  See also @ref comparer-page
 */
void priqueue_init(priqueue_t *q, int(*comparer)(const void *, const void *))
{
  q->priqueue = malloc(200 * sizeof q->priqueue[0]);
  q->size = 0;
  q->compare = comparer;
}


/**
  Inserts the specified element into this priority queue.

  @param q a pointer to an instance of the priqueue_t data structure
  @param ptr a pointer to the data to be inserted into the priority queue
  @return The zero-based index where ptr is stored in the priority queue, where 0 indicates that ptr was stored at the front of the priority queue.
 */
int priqueue_offer(priqueue_t *q, void *ptr)
{
	if (q->size == 0)
  {
    q->priqueue[0] = ptr;
    //q->priqueue[0] = *(int *)ptr;
    q->size++;
    return 0;
  }
  else
  {
    //int insert = *(int *)ptr;
    for (int i = 0; i <= q->size; i++)
    {
      const void * ptr2 = &(q->priqueue[i]);
      const void * ptr3 = &ptr;
      //int a = q->priqueue[i];
      //int *ptr2 = &a;
      if (q->compare(ptr2, ptr3) > 0)
      {
        for (int j = q->size-1; j >= i; j--)
        {
          q->priqueue[j+1] = q->priqueue[j];
        }
        q->priqueue[i] = ptr;
        //q->priqueue[i] = insert;
        q->size++;
        return i;
      }
    }

    q->priqueue[q->size] = ptr;
    //q->priqueue[q->size] = *(int *)ptr;
    q->size++;
    return q->size-1;

  }

}


/**
  Retrieves, but does not remove, the head of this queue, returning NULL if
  this queue is empty.
 
  @param q a pointer to an instance of the priqueue_t data structure
  @return pointer to element at the head of the queue
  @return NULL if the queue is empty
 */
void *priqueue_peek(priqueue_t *q)
{
	 if (q->size == 0) 
  {
    return NULL;
  }
  else 
  {
    void * head = (q->priqueue[0]);
    //int a = q->priqueue[0];
    //int *head = &a;
    return (head);
  }
}


/**
  Retrieves and removes the head of this queue, or NULL if this queue
  is empty.
 
  @param q a pointer to an instance of the priqueue_t data structure
  @return the head of this queue
  @return NULL if this queue is empty
 */
void *priqueue_poll(priqueue_t *q)
{
  if (q->size == 0) 
  {
    return NULL;
  }
  else 
  {
    void * head = (q->priqueue[0]);
    //int a = q->priqueue[0];
    //int *head = &a;

    for(int i = 0; i < q->size-1; i++)
    {
      q->priqueue[i] = q->priqueue[i+1];
    }
    q->priqueue[q->size-1] = NULL;
    q->size--;

    return (head);
  }
}


/**
  Returns the element at the specified position in this list, or NULL if
  the queue does not contain an index'th element.
 
  @param q a pointer to an instance of the priqueue_t data structure
  @param index position of retrieved element
  @return the index'th element in the queue
  @return NULL if the queue does not contain the index'th element
 */
void *priqueue_at(priqueue_t *q, int index)
{
	if (q->size - 1 < index)
  {
    return NULL;
  }
  else
  {
    void * element = (q->priqueue[index]);
    //int a = q->priqueue[index];
    //int *element = &a;
    return (element);
  }
}


/**
  Removes all instances of ptr from the queue. 
  
  This function should not use the comparer function, but check if the data contained in each element of the queue is equal (==) to ptr.
 
  @param q a pointer to an instance of the priqueue_t data structure
  @param ptr address of element to be removed
  @return the number of entries removed
 */
int priqueue_remove(priqueue_t *q, void *ptr)
{
	int remove = 0;

  for (int i = 0; i < q->size; i++)
    {
      if (ptr == q->priqueue[i])
      {
        for (int j = i; j < q->size; j++)
        {
          q->priqueue[j] = q->priqueue[j+1];
        }
        q->priqueue[q->size] = 0;
        q->size--;
        remove++;
        i--;
      }
    }

    return remove;

}


/**
  Removes the specified index from the queue, moving later elements up
  a spot in the queue to fill the gap.
 .p
  @param q a pointer to an instance of the priqueue_t data structure
  @param index position of element to be removed
  @return the element removed from the queue
  @return NULL if the specified index does not exist
 */
void *priqueue_remove_at(priqueue_t *q, int index)
{
  if(index > q->size-1)
  {
    return NULL;
  }
  else
  {
    void * element = (q->priqueue[index]);
    //int a = q->priqueue[index];
    //int *element = &a;

    for(int i = index; i < q->size-1; i++)
    {
      q->priqueue[i] = q->priqueue[i+1];
    }
    q->priqueue[q->size-1] = 0;
    q->size--;

    return (element);
  }

}


/**
  Returns the number of elements in the queue.
 
  @param q a pointer to an instance of the priqueue_t data structure
  @return the number of elements in the queue
 */
int priqueue_size(priqueue_t *q)
{
	return q->size;
}


/**
  Destroys and frees all the memory associated with q.
  
  @param q a pointer to an instance of the priqueue_t data structure
 */
void priqueue_destroy(priqueue_t *q)
{
  free(q->priqueue);
}

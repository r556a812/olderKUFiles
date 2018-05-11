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
  q->size = 0;
  q->compare = comparer;
  q->front = NULL;
}


/**
  Inserts the specified element into this priority queue.

  @param q a pointer to an instance of the priqueue_t data structure
  @param ptr a pointer to the data to be inserted into the priority queue
  @return The zero-based index where ptr is stored in the priority queue, where 0 indicates that ptr was stored at the q->front of the priority queue.
 */
int priqueue_offer(priqueue_t *q, void *ptr)
{
  struct node * temp;
  temp = (struct node *)malloc(sizeof(struct node));
  temp->data = ptr;
	if (q->size == 0)
  {
    q->front = temp;
    temp->next = NULL;
    q->size++;
    return 0;
  }
  else
  {
    int index = 0;
    struct node * find;
    find = q->front;
    while (find->next != NULL)
    {
      if(q->compare(find, temp) > 0)
      {
        if(find == q->front)
        {
          q->front->next = temp;
          temp->next = find;
          size++;
          return index;
        }
        else
        {
          struct node * temp2;
          temp2 = q->front;
          while (temp2->next != find)
          {
            temp2 = temp2->next;
          }
          temp2->next = temp;
          temp->next = find;
          size++
          return index;
        }
      }
      find = find->next;
      index++;
    }

    find->next = temp;
    index++;
    size++;
    return index;
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
    void * head = q->front;
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
    void * head = q->front;
    q->front = q->front->next;
    size--;
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
    struct node * temp;
    struct node * temp2
    temp = q->front;
    temp2 = q->front;
    for (int i = 0; i <= index; i++)
    {
      temp = temp->next;
    }
    while (temp2 != temp)
    {
      temp2 = temp2->next;
    }
    temp2->next = temp->next;
    void * element = temp;

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
  struct node * temp;
  temp = q->front;
  for (int i = 0; i < q->size; i++)
    {
      if (ptr == temp)
      {
        struct node * temp2;
        temp2 = q->front;
        while(temp2->next != temp)
        {
          temp2 = temp2->next;
        }
        temp2->next = temp->next;
        free(temp);
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
    void * element;
    struct node * temp;
    temp = q->front;
    struct node * temp2;
    temp2 = q->front;

    for (int i = 0; i <= index; i++)
    {
      temp = temp->next;
    }

    while (temp2->next != temp)
    {
      temp2 = temp2->next;
    }

    temp2->next = temp->next;
    element = temp;
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

}

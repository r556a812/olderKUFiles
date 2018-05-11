/**
 * Buddy Allocator
 *
 * For the list library usage, see http://www.mcs.anl.gov/~kazutomo/list/
 */

/**************************************************************************
 * Conditional Compilation Options
 **************************************************************************/
#define USE_DEBUG 0

/**************************************************************************
 * Included Files
 **************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "buddy.h"
#include "list.h"

/**************************************************************************
 * Public Definitions
 **************************************************************************/
#define MIN_ORDER 12
#define MAX_ORDER 20

#define PAGE_SIZE (1<<MIN_ORDER)
/* page index to address */
#define PAGE_TO_ADDR(page_idx) (void *)((page_idx*PAGE_SIZE) + g_memory)

/* address to page index */
#define ADDR_TO_PAGE(addr) ((unsigned long)((void *)addr - (void *)g_memory) / PAGE_SIZE)

/* find buddy address */
#define BUDDY_ADDR(addr, o) (void *)((((unsigned long)addr - (unsigned long)g_memory) ^ (1<<o)) \
									 + (unsigned long)g_memory)

#if USE_DEBUG == 1
#  define PDEBUG(fmt, ...) \
	fprintf(stderr, "%s(), %s:%d: " fmt,			\
		__func__, __FILE__, __LINE__, ##__VA_ARGS__)
#  define IFDEBUG(x) x
#else
#  define PDEBUG(fmt, ...)
#  define IFDEBUG(x)
#endif

/**************************************************************************
 * Public Types
 **************************************************************************/
typedef struct {
	struct list_head list;
	/* TODO: DECLARE NECESSARY MEMBER VARIABLES */
  int order;
  int index;
} page_t;

/**************************************************************************
 * Global Variables
 **************************************************************************/
/* free lists*/
struct list_head free_area[MAX_ORDER+1];

/* memory area */
char g_memory[1<<MAX_ORDER];

/* page structures */
page_t g_pages[(1<<MAX_ORDER)/PAGE_SIZE];

/**************************************************************************
 * Public Function Prototypes
 **************************************************************************/

/**************************************************************************
 * Local Functions
 **************************************************************************/

/**
 * Initialize the buddy system
 */
void buddy_init()
{
	int i;
	int n_pages = (1<<MAX_ORDER) / PAGE_SIZE;
	for (i = 0; i < n_pages; i++) {
		/* TODO: INITIALIZE PAGE STRUCTURES */
	  g_pages[i].order = 0;
	  g_pages[i].index = i;
	  INIT_LIST_HEAD(&g_pages[i].list);
	}

	/* initialize freelist */
	for (i = MIN_ORDER; i <= MAX_ORDER; i++) {
		INIT_LIST_HEAD(&free_area[i]);
	}

	/* add the entire memory as a freeblock */
	list_add(&g_pages[0].list, &free_area[MAX_ORDER]);
	g_pages[0].order = MAX_ORDER;
}

int find_order(int size)
{
  int ord = ceil(log2(size));
  ord = ord;
  printf("%d  %d", size, ord);

  return(ord);
}
  

/**
 * Allocate a memory block.
 *
 * On a memory request, the allocator returns the head of a free-list of the
 * matching size (i.e., smallest block that satisfies the request). If the
 * free-list of the matching block size is empty, then a larger block size will
 * be selected. The selected (large) block is then splitted into two smaller
 * blocks. Among the two blocks, left block will be used for allocation or be
 * further splitted while the right block will be added to the appropriate
 * free-list.
 *
 * @param size size in bytes
 * @return memory block address
 */
void *buddy_alloc(int size)
{
  printf("%d   ", size);
  int ordNeed = find_order(size);
  int bud;
  int g_index;
  int currentOrder;

  

  for (int i = ordNeed; i <= MAX_ORDER; i++)
    {
      //Find the smallest page available, if a big enough one exist to cover the size request.
      if (!(list_empty(&free_area[i])))
	{
	  if (ordNeed == i)
	    {
	      g_index = ADDR_TO_PAGE(&free_area[i]);
	      void *memblock = &g_pages[g_index];
	      list_del_init(free_area[i].next);
	      return (memblock);
	    }
	  else
	    {
	      currentOrder = i;

	      //Break the bigger blocks down to smaller blocks
	      while(currentOrder >= ordNeed)
		{
		  g_index = ADDR_TO_PAGE(&free_area[currentOrder]);
		  bud = ADDR_TO_PAGE(BUDDY_ADDR(PAGE_TO_ADDR(g_index), (currentOrder - 1)));
		  list_add(&g_pages[bud].list, &free_area[(currentOrder - 1)]);
		  currentOrder -= 1;
		}

	      list_del_init(free_area[i].next);

	      //Get address of the mem block and return it
	      int mem = ADDR_TO_PAGE(BUDDY_ADDR(PAGE_TO_ADDR(bud), ordNeed));
	      void *memblock = &g_pages[mem];
	      g_pages[mem].order = ordNeed;
	      return(memblock);
	    } 
	}
    }
  
  //Return Null if the size is too big for what is available
  return NULL;
}

/**
 * Free an allocated memory block.
 *
 * Whenever a block is freed, the allocator checks its buddy. If the buddy is
 * free as well, then the two buddies are combined to form a bigger block. This
 * process continues until one of the buddies is not free.
 *
 * @param addr memory block address to be freed
 */
void buddy_free(void *addr)
{
	/* TODO: IMPLEMENT THIS FUNCTION */
  int a = *(int *)addr;
  int currentOrder = g_pages[a].order;
  int bud = ADDR_TO_PAGE(BUDDY_ADDR(PAGE_TO_ADDR(*(int*)addr), currentOrder));
  
}

/**
 * Print the buddy system status---order oriented
 *
 * print free pages in each order.
 */
void buddy_dump()
{
	int o;
	for (o = MIN_ORDER; o <= MAX_ORDER; o++) {
		struct list_head *pos;
		int cnt = 0;
		list_for_each(pos, &free_area[o]) {
			cnt++;
		}
		printf("%d:%dK ", cnt, (1<<o)/1024);
	}
	printf("\n");
}

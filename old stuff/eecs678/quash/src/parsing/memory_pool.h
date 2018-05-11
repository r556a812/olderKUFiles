/**
 * @file memory_pool.h
 *
 * @brief An abstraction of malloc that allows for all allocations in the pool
 * to be free'd with a single call to destroy_memory_pool(). Allocations to the
 * memory pool should NOT be manually free'd with a call to free().
 *
 * @warning FOR THE QUASH PROJECT, DO NOT USE OR COPY ANY OF THESE FUNCTIONS
 * YOURSELF. This is a simple garbage collector to fix memory leak problems
 * resulting from the parser, generated by bison, encountering syntax errors in
 * the input that would be very difficult or impossible to fix without this
 * mechanism. Generally, hand crafted c code should be able to manage it's heap
 * allocations directly with malloc and free. We would like for you to become
 * comfortable with malloc based memory management. YOU WILL BE PENALIZED FOR
 * USING ANYTHING IN THIS FILE TO HIDE MEMORY LEAKS.
 *
 * @warning The memory pool allocations are not thread safe
 */

#ifndef SRC_PARSING_MEMORY_POOL_H
#define SRC_PARSING_MEMORY_POOL_H

#include <stdlib.h>

#include "deque.h"

/**
 * @brief Allocate the memory pool
 *
 * @param size The initial size of the memory pool. If this value is zero then a
 * default size of one is used.
 */
void initialize_memory_pool(size_t size);

/**
 * @brief Reserve some space in the memory pool and returns a unique address
 * that can be written to and read from. This can be thought of exactly like
 * malloc() without the requirement of calling free() directly on the returned
 * pointer.
 *
 * @param size Size in bytes of the requested reserved space
 *
 * @return A pointer to a unique array of size bytes
 */
void* memory_pool_alloc(size_t size);

/**
 * @brief Free all memory allocated in the memory pool
 */
void destroy_memory_pool();

/**
 * @brief A version of strdup() that allocates the duplicate to the memory pool
 * rather than with malloc directly
 *
 * @param str Pointer to the string to duplicate
 *
 * @return A copy of str allocated in the memory pool
 */
char* memory_pool_strdup(const char* str);

/**
 * @brief Generates a @a memory_pool_alloc() based set of functions for use with
 * a structure generated by @a IMPLEMENT_DEQUE_STRUCT
 *
 * @param struct_name The name of the structure
 *
 * @param type The name of the type of elements stored in the @a struct_name
 * structure
 *
 * @sa IMPLEMENT_DEQUE_STRUCT, PROTOTYPE_DEQUE, IMPLEMENT_DEQUE_MEMORY_POOL,
 * memory_pool_alloc()
 */
#define IMPLEMENT_DEQUE_MEMORY_POOL(struct_name, type)                  \
                                                                        \
  void apply_##struct_name(struct_name*, void (*)(type));               \
                                                                        \
  struct_name new_##struct_name(size_t init_cap) {                      \
    struct_name ret;                                                    \
                                                                        \
    if (init_cap > 0)                                                   \
      ret.cap = init_cap;                                               \
    else                                                                \
      ret.cap = 1;                                                      \
                                                                        \
    ret.data = (type*) memory_pool_alloc(init_cap * sizeof(type));      \
                                                                        \
    if (ret.data == NULL) {                                             \
      fprintf(stderr, "ERROR: Failed to reallocate struct_name"         \
              " contents");                                             \
      abort();                                                          \
    }                                                                   \
                                                                        \
    ret.front = ret.back = 0;                                           \
    ret.destructor = NULL;                                              \
                                                                        \
    return ret;                                                         \
  }                                                                     \
                                                                        \
  struct_name new_destructable_##struct_name(size_t init_cap,           \
                                             void (*destructor)(type)){ \
    struct_name ret = new_##struct_name(init_cap);                      \
    ret.destructor = destructor;                                        \
    return ret;                                                         \
  }                                                                     \
                                                                        \
  void destroy_##struct_name(struct_name* deq) {                        \
    assert(deq != NULL);                                                \
                                                                        \
    if (deq->data == NULL)                                              \
      return;                                                           \
                                                                        \
    if (deq->destructor != NULL)                                        \
      apply_##struct_name(deq, deq->destructor);                        \
                                                                        \
    deq->data = NULL;                                                   \
    deq->cap = 0;                                                       \
    deq->front = deq->back = 0;                                         \
  }                                                                     \
                                                                        \
  void empty_##struct_name(struct_name* deq) {                          \
    assert(deq != NULL);                                                \
    assert(deq->data != NULL); /* Make sure the structure is valid */   \
                                                                        \
    if (deq->destructor != NULL)                                        \
      apply_##struct_name(deq, deq->destructor);                        \
                                                                        \
    deq->front = deq->back = 0;                                         \
  }                                                                     \
                                                                        \
  bool is_empty_##struct_name(struct_name* deq) {                       \
    assert(deq != NULL);                                                \
    assert(deq->data != NULL); /* Make sure the structure is valid */   \
    return deq->front == deq->back;                                     \
  }                                                                     \
                                                                        \
  size_t length_##struct_name(struct_name* deq) {                       \
    assert(deq != NULL);                                                \
    assert(deq->data != NULL); /* Make sure the structure is valid */   \
    return (deq->back - deq->front + deq->cap) % deq->cap;              \
  }                                                                     \
                                                                        \
  static void __reallign_##struct_name(struct_name* deq) {              \
    assert(deq != NULL);                                                \
    assert(deq->data != NULL); /* Make sure the structure is valid */   \
                                                                        \
    if (deq->front != 0) {                                              \
      type* old_data = deq->data;                                       \
      size_t len = length_##struct_name(deq);                           \
                                                                        \
      deq->data = (type*) memory_pool_alloc(deq->cap * sizeof(type));   \
                                                                        \
      if (deq->data == NULL) {                                          \
        fprintf(stderr, "ERROR: Failed to reallocate struct_name"       \
                " contents");                                           \
        abort();                                                        \
      }                                                                 \
                                                                        \
      size_t i;                                                         \
                                                                        \
      for (i = 0; i < len; ++i)                                         \
        deq->data[i] = old_data[(deq->front + i) % deq->cap];           \
                                                                        \
      deq->front = 0;                                                   \
      deq->back = i;                                                    \
    }                                                                   \
  }                                                                     \
                                                                        \
  type* as_array_##struct_name(struct_name* deq, size_t* len) {         \
    assert(deq != NULL);                                                \
    assert(deq->data != NULL); /* Make sure the structure is valid */   \
                                                                        \
    __reallign_##struct_name(deq);                                      \
                                                                        \
    type* ret = deq->data;                                              \
                                                                        \
    if (len != NULL)                                                    \
      *len = length_##struct_name(deq);                                 \
                                                                        \
    deq->data = NULL;                                                   \
    deq->cap = deq->front = deq->back = 0;                              \
                                                                        \
    return ret;                                                         \
  }                                                                     \
                                                                        \
  void apply_##struct_name(struct_name* deq, void (*func)(type)) {      \
    assert(deq != NULL);                                                \
    assert(deq->data != NULL); /* Make sure the structure is valid */   \
                                                                        \
    size_t len = length_##struct_name(deq);                             \
                                                                        \
    for (size_t i = 0; i < len; ++i) {                                  \
      func(deq->data[(deq->front + i) % deq->cap]);                     \
    }                                                                   \
  }                                                                     \
                                                                        \
  static void __on_push_##struct_name(struct_name* deq) {               \
    if (deq->front == (deq->back + 1) % deq->cap) {                     \
      type* old_data = deq->data;                                       \
      size_t old_cap = deq->cap;                                        \
                                                                        \
      deq->cap = 2 * deq->cap;                                          \
      deq->data = (type*) memory_pool_alloc(deq->cap * sizeof(type));   \
                                                                        \
      if (deq->data == NULL) {                                          \
        fprintf(stderr, "ERROR: Failed to reallocate struct_name"       \
                " contents\n");                                         \
        abort();                                                        \
      }                                                                 \
                                                                        \
      size_t i;                                                         \
                                                                        \
      for (i = 0; i < old_cap - 1; ++i)                                 \
        deq->data[i] = old_data[(deq->front + i) % old_cap];            \
                                                                        \
      deq->front = 0;                                                   \
      deq->back = i;                                                    \
    }                                                                   \
  }                                                                     \
                                                                        \
  static void __on_pop_##struct_name(struct_name* deq) {                \
    if (is_empty_##struct_name(deq)) {                                  \
      fprintf(stderr, "ERROR: Cannot pop from of struct_name while it " \
              "is empty\n");                                            \
      abort();                                                          \
    }                                                                   \
  }                                                                     \
                                                                        \
  void push_front_##struct_name(struct_name* deq, type element) {       \
    assert(deq != NULL);                                                \
    assert(deq->data != NULL); /* Make sure the structure is valid */   \
    __on_push_##struct_name(deq);                                       \
    deq->front = (deq->front + deq->cap - 1) % deq->cap;                \
    deq->data[deq->front] = element;                                    \
  }                                                                     \
                                                                        \
  void push_back_##struct_name(struct_name* deq, type element) {        \
    assert(deq != NULL);                                                \
    assert(deq->data != NULL); /* Make sure the structure is valid */   \
    __on_push_##struct_name(deq);                                       \
    deq->data[deq->back] = element;                                     \
    deq->back = (deq->back + 1) % deq->cap;                             \
  }                                                                     \
                                                                        \
  type pop_front_##struct_name(struct_name* deq) {                      \
    assert(deq != NULL);                                                \
    assert(deq->data != NULL); /* Make sure the structure is valid */   \
    __on_pop_##struct_name(deq);                                        \
    size_t old_front = deq->front;                                      \
    deq->front = (deq->front + 1) % deq->cap;                           \
    return deq->data[old_front];                                        \
  }                                                                     \
                                                                        \
  type pop_back_##struct_name(struct_name* deq) {                       \
    assert(deq != NULL);                                                \
    assert(deq->data != NULL); /* Make sure the structure is valid */   \
    __on_pop_##struct_name(deq);                                        \
    deq->back = (deq->back + deq->cap - 1) % deq->cap;                  \
    return deq->data[deq->back];                                        \
  }                                                                     \
                                                                        \
  type peek_front_##struct_name(struct_name* deq) {                     \
    assert(deq != NULL);                                                \
    assert(deq->data != NULL); /* Make sure the structure is valid */   \
    assert(!is_empty_##struct_name(deq));                               \
    return deq->data[deq->front];                                       \
  }                                                                     \
                                                                        \
  type peek_back_##struct_name(struct_name* deq) {                      \
    assert(deq != NULL);                                                \
    assert(deq->data != NULL); /* Make sure the structure is valid */   \
    assert(!is_empty_##struct_name(deq));                               \
    return deq->data[(deq->back + deq->cap - 1) % deq->cap];            \
  }                                                                     \
                                                                        \
  void update_front_##struct_name(struct_name* deq, type element) {     \
    assert(deq != NULL);                                                \
    assert(deq->data != NULL); /* Make sure the structure is valid */   \
    assert(!is_empty_##struct_name(deq));                               \
    deq->data[deq->front] = element;                                    \
  }                                                                     \
                                                                        \
  void update_back_##struct_name(struct_name* deq, type element) {      \
    assert(deq != NULL);                                                \
    assert(deq->data != NULL); /* Make sure the structure is valid */   \
    assert(!is_empty_##struct_name(deq));                               \
    deq->data[(deq->back + deq->cap - 1) % deq->cap] = element;         \
  }

#endif

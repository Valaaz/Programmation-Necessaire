#include "lst_elm.h"

/** Abstract type for double-linked list modeled by
  2 pointers pointing to the head and the tail of the list, resp.
  the number of element the list contains
*/
struct lst_t
{
    struct lst_elm_t *head, *tail;
    int numelm;
};

/****
  Constructors & co
****/
struct lst_t *newLst();
void freeLst(struct lst_t *L, void (*ptrf)());
bool emptyLst(struct lst_t *L);

/****
  Accessors &modifiers
****/
struct lst_elm_t *get_head(struct lst_t L);
struct lst_elm_t *get_tail(struct lst_t *L);

/** Add on head */
void cons(struct lst_t *L, void *data);
/** Add on tail */
void queue(struct lst_t *L, void *data);
/** Insert data at place pointed by ptrf */
void ordered_insert(struct lst_t *L, void *data, bool (*ptrf)());
/** Display list on stdout stream */
void printLst(struct list *L, void (*ptrf)());
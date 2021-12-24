#ifndef PROJET_PROGAV_S3_LIST_H
#define PROJET_PROGAV_S3_LIST_H

#include "elmlist.h"

/**
Abstract type for double-linked list modeled by
- 2 pointers pointing to the head and the tail of the list
- the number of element the list contains
*/
struct list_t {
    struct elmlist_t *head;
    struct elmlist_t *tail;
    int numElm;
};

/****************
Constructors & co
****************/
/** Create empty list  */
struct list_t *new_list();

struct list_t *listcpy(const struct list_t *L);

/** Delete list its elements and possibly the data they hold */
void del_list(struct list_t *L, void (*ptrF)());

/** Is list L empty ? */
bool is_empty(const struct list_t *L);

/********************
Accessors & modifiers
********************/
/** Gimme the head of L*/
struct elmlist_t *get_head(const struct list_t *L);

/** Gimme the tail of L */
struct elmlist_t *get_tail(const struct list_t *L);

/** How many elements does the list contain ? */
int get_numelm(const struct list_t *L);

/***************************
 * Advanced member functions
 ***************************/
/** Add a brand new list element holding data to the head of L */
void cons(struct list_t *L, void *data);

/** Add  a brand new list element holding data to the tail of L */
void queue(struct list_t *L, void *data);

/** Insert data at place localized by cmp_ptr */
void insert_ordered(struct list_t *L, void *data, bool (*ptrF)());

/** Display list on stdout stream */
void view_list(struct list_t *L, void (*ptrF)());

#endif //PROJET_PROGAV_S3_LIST_H

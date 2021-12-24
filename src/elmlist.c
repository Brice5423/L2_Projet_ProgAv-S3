//
// Created by brice on 21/12/2021.
//

#include "../include/elmlist.h"

struct elmlist_t *new_elmlist(void *data) {
    struct elmlist_t *E;

    E = (struct elmlist_t *) calloc(1, sizeof(struct elmlist_t));
    assert(E);

    E->data = data;
    E->pred = NULL;
    E->suc = NULL;

    return E;
}

void del_elmlist(struct elmlist_t *E, void (*ptrF)()) {
    ptrF(E);
}

struct elmlist_t *get_suc(struct elmlist_t *E) {
    return E->suc;
}

struct elmlist_t *get_pred(struct elmlist_t *E) {
    return E->pred;
}

void *get_data(struct elmlist_t *E) {
    return E->data;
}

void set_suc(struct elmlist_t *E, struct elmlist_t *S) {
    E->suc = S;
}

void set_pred(struct elmlist_t *E, struct elmlist_t *P) {
    E->pred = P;
}

void set_data(struct elmlist_t *E, void *data) {
    E->data = data;
}

void view_elmlist(struct elmlist_t *E, void (*ptrF)()) {
    ptrF(E);
}
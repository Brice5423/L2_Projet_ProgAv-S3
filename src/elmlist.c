#include "../include/elmlist.h"

struct elmlist_t *new_elmlist(void *data) {
    struct elmlist_t *E;

    E = (struct elmlist_t *) calloc(1, sizeof(struct elmlist_t));
    assert(E);

    E->data = data;

    return E;
}

void del_elmlist(struct elmlist_t *E, void (*ptrF)()) {
    assert(E);
    (*ptrF)(E);
}

struct elmlist_t *get_suc(struct elmlist_t *E) {
    assert(E);
    return E->suc;
}

struct elmlist_t *get_pred(struct elmlist_t *E) {
    assert(E);
    return E->pred;
}

void *get_data(struct elmlist_t *E) {
    assert(E);
    return E->data;
}

void set_suc(struct elmlist_t *E, struct elmlist_t *S) {
    assert(E);
    E->suc = S;
}

void set_pred(struct elmlist_t *E, struct elmlist_t *P) {
    assert(E);
    E->pred = P;
}

void set_data(struct elmlist_t *E, void *data) {
    assert(E);
    E->data = data;
}

void view_elmlist(struct elmlist_t *E, void (*ptrF)()) {
    assert(E);
    ptrF(E);
}
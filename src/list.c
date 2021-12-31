#include "../include/list.h"

struct list_t *new_list() {
    struct list_t *L;

    L = (struct list_t *) calloc(1, sizeof(struct list_t));
    assert(L);

    L->head = NULL;
    L->tail = NULL;
    L->numElm = 0;

    return L;
}

struct list_t *listcpy(const struct list_t *L) {
    struct elmlist_t *unElmDeL;
    struct list_t *copieL;
    int nbElm;
    int i;

    copieL = (struct list_t *) calloc(1, sizeof(struct list_t));
    //unElmDeL = (struct elmlist_t *) calloc(1, sizeof(struct elmlist_t));

    nbElm = get_numelm(L);
    unElmDeL = get_head(L);

    for (i = 1; i <= nbElm; i++) {
        queue(copieL, unElmDeL->data);

        if (i != nbElm) { // pas besoin de prendre l'élément suivant, il n'y en a pas
            unElmDeL = unElmDeL->suc;
        }
    }

    return copieL;
}

void del_list(struct list_t *L, void (*ptrF)()) {
    struct elmlist_t *E;

    E = L->head;

    while (E != NULL) {
        struct elmlist_t *suc;

        suc = E->suc;
        del_elmlist(E, ptrF); // ptrF(E) // free(E)
        E = suc;
    }

    free(L);
    L = NULL;
}

bool is_empty(const struct list_t *L) {
    assert(L);
    return (L->numElm == 0);
}

struct elmlist_t *get_head(const struct list_t *L) {
    assert(L);
    return L->head;
}

struct elmlist_t *get_tail(const struct list_t *L) {
    assert(L);
    return L->tail;
}

int get_numelm(const struct list_t *L) {
    assert(L);
    return L->numElm;
}

void cons(struct list_t *L, void *data) {
    struct elmlist_t *E;

    E = new_elmlist(data);

    if (is_empty(L)) {
        L->tail = E;
    } else {
        L->head->pred = E;
    }

    E->suc = L->head;
    L->numElm++;
    L->head = E;
}

void queue(struct list_t *L, void *data) {
    struct elmlist_t *E;

    E = new_elmlist(data);

    if (is_empty(L)) {
        L->head = E;
    } else {
        L->tail->suc = E;
    }

    E->pred = L->tail;
    L->numElm++;
    L->tail = E;
}

void insert_ordered(struct list_t *L, void *data, bool (*ptrF)()) {
    if (is_empty(L) || (*ptrF)(L->head->data, data)) {
        cons(L, data);

    } else if ((*ptrF)(data, L->tail->data)) {
        queue(L, data);

    } else {
        struct elmlist_t *look;
        struct elmlist_t *E;

        look = L->head;
        E = new_elmlist(data);

        while ((*ptrF)(look->suc->data, data)) {
            look = look->suc;
        }

        E->suc = look->suc;
        look->suc = E;
        L->numElm++;
    }
}

void view_list(struct list_t *L, void (*ptrF)()) {
    struct elmlist_t *E;

    printf("Dans fonction : view_list - numElm : %i\n", L->numElm);

    printf("\n");
    for (E = L->head; E != NULL; E = E->suc) {
        (*ptrF)(E->data);
        printf("\n");
    }
    printf("\n");
}
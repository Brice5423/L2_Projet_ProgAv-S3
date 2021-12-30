#include "../include/bag.h"

struct retained_t *new_bag() {
    struct retained_t *bagpack;

    bagpack = (struct retained_t *) calloc(1, sizeof(struct retained_t));

    bagpack->objects_list = (struct list_t *) calloc(1, sizeof(struct list_t));
    assert(bagpack->objects_list);

    return bagpack;
}

void bagcpy(struct retained_t *newBagpack, const struct retained_t *bagpack) {
    newBagpack->objects_list = listcpy(bagpack->objects_list);
    newBagpack->utilities_sum = bagpack->utilities_sum;
}

void free_bag(struct retained_t **bagpack) {
    clean_bag(bagpack);

    free((*bagpack)->objects_list);
    (*bagpack)->objects_list = NULL;

    free(bagpack);
    bagpack = NULL;
}

void clean_bag(struct retained_t *bagpack) {
    /* ***** ***** ***** Basé sur le TP4 ***** ***** ***** */
    assert(bagpack);
    del_list(&(bagpack->objects_list), &rmInteger);
    bagpack->utilities_sum = 0;


    /* ***** ***** ***** Fait par moi même ***** ***** ***** */
    /*struct list_t *objectsList;
    struct elmlist_t *unElmBagpack;
    struct elmlist_t *unElmBagpack2;
    int nbElm;
    int i;

    //unElmBagpack = (struct elmlist_t *) calloc(1, sizeof(struct elmlist_t));
    //unElmBagpack2 = (struct elmlist_t *) calloc(1, sizeof(struct elmlist_t));

    objectsList = bagpack->objects_list;
    nbElm = objectsList->numElm;
    unElmBagpack = objectsList->head;

    for (i = 1; i <= nbElm; i++) {
        if (i != nbElm) {
            unElmBagpack2 = unElmBagpack->suc;
        }

        free(unElmBagpack);
        unElmBagpack = NULL;

        if (i != nbElm) {
            unElmBagpack = unElmBagpack2;
        }
    }

    objectsList->head = NULL;
    objectsList->tail = NULL;
    objectsList->numElm = 0;
    bagpack->utilities_sum = 0;*/
}

void push_object_in_bag(struct retained_t *bagpack, struct object_t *object) {
    queue(bagpack->objects_list, object);
    bagpack->utilities_sum += object->utility;
}

void view_bagpack(struct retained_t *bagpack, const char *title) {
    void (*ptr_view_fct)(const struct object_t *) = &view_object;

    printf("\n*****************\nVIEW BAGPACKAGING\t%s\n", title);
    view_list(bagpack->objects_list, ptr_view_fct);
    printf("\t\tWith utilities sum = %d\n\n", bagpack->utilities_sum);
}
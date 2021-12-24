//
// Created by brice on 21/12/2021.
//

#include "../include/bag.h"

struct retained_t *new_bag() {
    struct retained_t *bagpack;

    bagpack = ...; // taille de la mémoire

    bagpack->objects_list = ...;
    assert(bagpack->objects_list);

    return bagpack;
}

void bagcpy(struct retained_t *newBagpack, const struct retained_t *bagpack) {
    newBagpack->objects_list = listcpy(bagpack->objects_list);
    newBagpack->utilities_sum = bagpack->utilities_sum;
}

void free_bag(struct retained_t *bagpack) {
    /** TODO **/
}

void clean_bag(struct retained_t *bagpack) {
    /** TODO **/
}

void push_object_in_bag(struct retained_t *bagpack, struct object_t *ptr_object) {
    /** TODO **/
}

void view_bagpack(struct retained_t *bagpack, const char *title) {
    void (*ptr_view_fct)(const struct object_t *) = &view_object;

    printf("\n*****************\nVIEW BAGPACKAGING\t%s\n", title);
    view_list(bagpack->objects_list, ptr_view_fct);
    printf("\t\tWith utilities sum = %d\n\n", bagpack->utilities_sum);
}
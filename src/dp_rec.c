#include <stdio.h>

#include "../include/prec.h"


void prec(const int Vmax, struct objects_t *obj_set, struct retained_t *bag) {
    const int nb_objects = obj_set->nb_objects;

    struct retained_t *duplicata = ...;
    bagcpy(...);

    struct retained_t *best_bagpack = ...;
    bagcpy(...); // Pred: best bag is bag

    for (int obj_idx = obj_set->first_idx ...) {// Verif: Try new objects
        struct object_t *ptr_object = ...;
        int curr_volume = ...;

        if (...) {
            bagcpy(...);
            push_object_in_bag(...);
            obj_set->first_idx = ...;
            p_rec(...);

            if (...) {
                clean_bag(...);
                bagcpy(...);
            }
        }
    }

    clean_bag(bagpack);
    bagcpy(bagpack, best_bagpack);
    free_bag(best_bagpack);
}

struct retained_t *new_bag() {
    struct retained_t *bagpack = ...;
    bagpack->objects_list = ...;
    assert(bagpack->objects_list);
    return bagpack;
}

void bagcpy(struct retained_t *duplicata, const struct retained_t *bagpack) {
    duplicata->objects_list = listcpy(bagpack->objects_list);
    duplicata->utilities_sum = bagpack->utilities_sum;
}

void free_bag(struct retained_t *bagpack) {
    /** TODO */
}

void clean_bag(struct retained_t *bagpack) {
    /** TODO */
}

void push_object_in_bag(struct retained_t *bagpack, struct object_t *ptr_object) {
    /** TODO */
}

void view_bagpack(struct retained_t *bagpack, const char *title) {
    void (*ptr_view_fct)(const struct object_t *) = &view_object;
    printf("\n*****************\nVIEW BAGPACKAGING\t%s\n", title);
    view_list(bagpack->objects_list, ptr_view_fct);
    printf("\t\tWith utilities sum = %d\n\n", bagpack->utilities_sum);
}

#include "../include/dp_rec.h"

void prec(const int VMax, struct objects_t *object_set, struct retained_t *bagpack) {
    const int nb_objects;
    struct retained_t *duplicata;
    struct retained_t *best_bagpack;

    nb_objects = object_set->nb_objects;

    duplicata = ...; // taille de la mémoire
    bagcpy(...);

    best_bagpack = ...; // taille de la mémoire
    bagcpy(...);// Pred: best bag is bag

    for (int obj_idx = object_set->first_idx ...) {// Verif: Try new objects
        struct object_t *ptr_object;
        ptr_object = ...;

        int curr_volume;
        curr_volume = ...;

        if (...) {
            bagcpy(...);
            push_object_in_bag(...);
            object_set->first_idx = ...;
            prec(...); // avant "prec" c'était "p_rec"

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

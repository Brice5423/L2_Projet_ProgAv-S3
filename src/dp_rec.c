#include "../include/dp_rec.h"

void prec(const int VMax, struct objects_t *object_set, struct retained_t *bagpack) {
    const int nb_objects = object_set->nb_objects;

    struct retained_t *duplicata;
    struct retained_t *best_bagpack;

    duplicata = (struct retained_t *) calloc(1, sizeof(struct retained_t));
    bagcpy(duplicata, bagpack);

    best_bagpack = (struct retained_t *) calloc(1, sizeof(struct retained_t));
    bagcpy(...); // Pred: best bag is bag

    for (int obj_idx = object_set->first_idx ...) { // Verif: Try new objects
        struct object_t *ptr_object;
        int curr_volume;

        ptr_object = (struct object_t *) calloc(1, sizeof(struct object_t));
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

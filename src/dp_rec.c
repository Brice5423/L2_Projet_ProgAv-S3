#include "../include/dp_rec.h"

void prec(const int VMax, struct objects_t *object_set, struct retained_t *bagpack) {
    const int nb_objects = object_set->nb_objects;

    struct retained_t *duplicata;
    struct retained_t *best_bagpack;

    duplicata = (struct retained_t *) calloc(1, sizeof(struct retained_t));
    bagcpy(duplicata, bagpack); // Moi : duplicata, bagpack

    best_bagpack = (struct retained_t *) calloc(1, sizeof(struct retained_t));
    bagcpy(...); // Pred: best bag is bag // Moi : ...

    for (int obj_idx = object_set->first_idx ...) { // Verif: Try new objects // Moi : ...
        struct object_t *ptr_object;
        int curr_volume;

        ptr_object = (struct object_t *) calloc(1, sizeof(struct object_t));
        curr_volume = ...; // Moi : ...

        if (...) { // Moi : ...
            bagcpy(...); // Moi : ...
            push_object_in_bag(...); // Moi : ...
            object_set->first_idx = ...; // Moi : ...
            prec(...); // Moi : ...

            if (...) { // Moi : ...
                clean_bag(...); // Moi : ...
                bagcpy(...); // Moi : ...
            }
        }
    }

    clean_bag(bagpack);
    bagcpy(bagpack, best_bagpack);
    free_bag(best_bagpack);
}

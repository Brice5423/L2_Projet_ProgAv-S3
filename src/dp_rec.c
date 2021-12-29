#include "../include/dp_rec.h"

void prec(const int VMax, struct objects_t *object_set, struct retained_t *bagpack) {
    const int nb_objects = object_set->nb_objects;

    struct retained_t *duplicata;
    struct retained_t *best_bagpack;

    duplicata = new_bag(); // Nous : new_bag()
    bagcpy(duplicata, bagpack); // Nous : duplicata, bagpack

    best_bagpack = new_bag(); // Nous : new_bag()
    bagcpy(best_bagpack, bagpack); // Pred: best bag is bag // Nous : best_bagpack, bagpack

    for (int obj_idx = object_set->first_idx; obj_idx < nb_objects; obj_idx++) { // Verif: Try new objects // Nous : ; obj_idx < object_set->nb_objects; obj_idx++
        struct object_t *ptr_object;
        int curr_volume;

        ptr_object = object_set->objects + obj_idx; // Nous : object_set->objects + obj_idx
        curr_volume = VMax - ptr_object->volume; // Nous : VMax - ptr_object->volume

        if (curr_volume >= 0) { // Nous : curr_volume >= 0
            bagcpy(duplicata, bagpack); // Nous : duplicata, bagpack
            push_object_in_bag(bagpack, ptr_object); // Nous : bagpack, ptr_object
            object_set->first_idx = obj_idx + 1; // Nous : obj_idx + 1
            prec(curr_volume, object_set, duplicata); // Nous : curr_volume, object_set, duplicata

            if (bagpack->utilities_sum > best_bagpack->utilities_sum) { // Nous : bagpack->utilities_sum > best_bagpack->utilities_sum
                clean_bag(best_bagpack); // Nous : best_bagpack
                bagcpy(best_bagpack, bagpack); // Nous : best_bagpack, bagpack
            }
        }
    }

    clean_bag(bagpack);
    bagcpy(bagpack, best_bagpack);
    free_bag(best_bagpack);
    free_bag(duplicata);
}

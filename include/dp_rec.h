#ifndef PROJET_PROGAV_S3_DP_REC_H
#define PROJET_PROGAV_S3_DP_REC_H

#include "bag.h"

/** @brief Nom dans le sujet : p_rec.
 * (Voir sujet, diapo 19 à 23) */
void prec(const int VMax, struct objects_t *object_set, struct retained_t *bagpack) {
    const int nb_objects = object_set->nb_objects;
    struct retained_t* duplicata = new_bag();
    bagcpy(duplicata, bagpack);
    struct retained_t* best_bagpack = new_bag();
    bagcpy(best_bagpack, bagpack);// Pred: best bag is bag
    for (int obj_idx = object_set->first_idx; obj_idx < object_set->nb_objects; obj_idx++) {// Verif: Try new objects
        struct object_t* ptr_object = object_set->objects + obj_idx;
        int curr_volume = VMax - ptr_object->volume;
        if (curr_volume >= 0) {
            bagcpy(duplicata, bagpack);
            push_object_in_bag(bagpack, ptr_object);
            object_set->first_idx = obj_idx + 1;
            prec(curr_volume, object_set, duplicata);
            /** pas sur de ce if **/
            if (bagpack->utilities_sum > best_bagpack->utilities_sum) {
                clean_bag(best_bagpack);
                bagcpy(best_bagpack, bagpack);
            }
        }
    }
    clean_bag(bagpack);
    bagcpy(bagpack, best_bagpack);
    free_bag(&best_bagpack);
    free_bag(&duplicata);
}


#endif //PROJET_PROGAV_S3_DP_REC_H

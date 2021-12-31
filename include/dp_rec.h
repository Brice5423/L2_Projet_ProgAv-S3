#ifndef PROJET_PROGAV_S3_DP_REC_H
#define PROJET_PROGAV_S3_DP_REC_H

#include "bag.h"

/** @brief Nom dans le sujet : p_rec.
 * (Voir sujet, diapo 19 à 23) */
void prec(const int VMax, struct objects_t *object_set, struct retained_t *bagpack);

void rmObject(struct object_t *object);

#endif //PROJET_PROGAV_S3_DP_REC_H

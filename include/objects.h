#ifndef PROJET_PROGAV_S3_OBJECTS_H
#define PROJET_PROGAV_S3_OBJECTS_H

#include "outils.h"

/** @brief (Voir sujet, diapo 11 à 13)
 * @struct int volume : volume de l'objet
 * @struct int utility : utilité de l'objet
 */
struct object_t {
    int volume;
    int utility;
};

/** @brief (Voir sujet, diapo 11 à 13)
 * @struct struct object_t *objects : pointeur d'un tableau d'objet, chois de l'objet par adresse
 * @struct int nb_objects : nombre d'objet dans le sac
 * @struct int first_idx : indice à traiter en premier
 */
struct objects_t {
    struct object_t *objects;
    int nb_objects;
    int first_idx;
};

/** @brief Créer un nouveau objet.
 * (Voir sujet, diapo 13 à 14) */
struct objects_t *new_objects(const int argc, char **argv, bool utility);

/** @brief Affiche l'objet.
 * (Voir sujet, diapo 13 et 15) */
void view_object(const struct object_t *object);

/** @brief Affiche tous les objets.
 * (Voir sujet, diapo 13 et 15) */
void view_objet_set(const struct objects_t *set);

#endif //PROJET_PROGAV_S3_OBJECTS_H

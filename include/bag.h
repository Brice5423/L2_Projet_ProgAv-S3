#ifndef PROJET_PROGAV_S3_BAG_H
#define PROJET_PROGAV_S3_BAG_H

#include "list.h"
#include "objects.h"

/** @brief (Voir sujet, diapo 16 à 18)
 * @struct struct list_t *objects_list : liste des objets
 * @struct int utilities_sum : somme des utilités de tous les objets
 * */
struct retained_t {
    struct list_t *objects_list;
    int utilities_sum;
};

/** @brief Construit un sac-à-dos vide.
 * (Voir sujet, diapo 16 à 18) */
struct retained_t *new_bag();

/** @brief Fait un duplicata d’un sac-à-dos.
 * (Voir sujet, diapo 16 à 18) */
void bagcpy(struct retained_t *newbagpack, const struct retained_t *bagpack);

/** @brief Libère la mémoire occupée par un sac-à-dos.
 * (Voir sujet, diapo 16 à 18) */
void free_bag(struct retained_t *bagpack);

/** @brief Vide le sac-à-dos, sans détruire la variable le modélisant.
 * (Voir sujet, diapo 16 à 18) */
void clean_bag(struct retained_t *bagpack);

/** @brief Range un nouvel objet dans le sac-à-dos.
 * (Voir sujet, diapo 16 à 18) */
void push_object_in_bag(struct retained_t *bagpack, struct object_t *ptr_object);

/** @brief Visualise les objets rangés dans un sac-à-dos.
 * (Voir sujet, diapo 16 à 18) */
void view_bagpack(struct retained_t *bagpack, const char *title);

#endif //PROJET_PROGAV_S3_BAG_H

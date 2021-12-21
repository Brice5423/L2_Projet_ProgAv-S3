#ifndef PROJET_PROGAV_S3_SPACE_ARRAY_H
#define PROJET_PROGAV_S3_SPACE_ARRAY_H

#include "objects.h"

typedef int state_t;
struct states_array_t {
    state_t *OPT; // Matrice d'états proprement dite
    state_t *CHM; // Matrice des chemins dans la matrice d'états
    int num_obj; // Dimensions de la matrice d'états
    int Vmax;
};

/** @brief Libérer la mémoire occupée par lamatrice d'états */
void free_states_array(struct states_array_t *states);

/** @brief Créer une matrice d'états ET l'initialiser à "vide" */
struct states_array_t *new_states_array(const int num_objects, const int Vmax);

/** @brief Ajouter un objet dans les états "valides" de la matrice */
void push_object_in_array(struct states_array_t *states, const struct objects_t *objects, int i);

/** @brief Visualiser la solution optimale */
void view_path_array(const struct states_array_t *states, const struct objects_t *set);

/** @brief Visualiser la matrice d'états */
void view_opt(const struct states_array_t *states);

/** @brief Visualiser les chemins associés aux états de la matrice d'états */
void view_chm(const struct states_array_t *states);

#endif //PROJET_PROGAV_S3_SPACE_ARRAY_H

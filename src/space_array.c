#include <stdio.h>

#include "../include/space_array.h"


void free_states_array(struct states_array_t * states) {
    assert(states);
    /** TODO **/
}

struct states_array_t * new_states_array(const int num_objects, const int Vmax) {
    struct states_array_t * NS = ...;
    assert(NS != NULL);

    /** TODO **/

    init_opt_chm(NS);
    return NS;
}

void push_object_in_array(struct states_array_t *S, struct objects_t *LO, int i) {
    /* Faites attention que les objets dans LO sont rangés à partir de 0
     * tandis qu'ils sont rangés à partue de 1 dans OPT (et CHM) */
    for (int bag = 0; bag < (S->Vmax + 1); bag += 1) {
        // Parcourir chaque état du sac-à-dos
        int pred = ...; // Calculer l'index de l'état pour l'objet (i-1)
        int curr = ...; // Calculer l'index de l'état pour l'objet (i)
        int OPT1 = S->OPT[pred];
        S->CHM[curr] = INFTY; //hyp.: l'objet i n'est pas dans le sac
        if (...) { // S'il y a de la place dans le sac
            int pred_without_i = ...; // L'index du bag SANS l'objet (i)
            int OPT2 = ...;
            if (...) { // Sélectionne la meilleur configuration
                S->OPT[curr] = ...;
                S->CHM[curr] = ...; // Noter que l'objet i est dans le sac
            } else states->OPT[curr] = ...;
        } else states->OPT[curr] = ...; // S'il n'y a pas de place
    }
}

/**
 * Private Function
 **/
void init_opt_chm(struct states_array_t *states) {
    states->OPT = ...;
    states->CHM = ...;

    for (int obj = 1; obj <= states->num_obj; obj += 1) {
        for (int bag = 0; bag <= states->Vmax; bag += 1) {
            int idx = ...;
            states->OPT[idx] = UNDTR;
            states->CHM[idx] = UNDTR;
        }
    }

    for (int bag = 0; bag <= states->Vmax; bag += 1) {
        states->CHM[bag] = UNDTR;
    }
}

void view_path_array(struct states_array_t *states, struct objects_t *set) {
    int obj = states->num_obj;
    int vol = states->Vmax;
    int idx = obj * (states->Vmax + 1) + vol;

    bool nonstop = (obj == 0);
    printf("******\nTotal packaging utility : %d\n******\n", states->OPT[idx]);

    while (!stop) {
        if (states->CHM[idx] != INFTY) { // object actually put in bag
            printf("\tobjet #%d(%d, %d)\n", obj, set->objects[obj - 1].volume, set->objects[obj - 1].utility);
            stop = (states->CHM[idx] == 0);
            vol = states->CHM[idx];
        }
        obj -= 1;
        stop = stop || (obj == 0);
        idx = obj * (states->Vmax + 1) + vol;
    }

    printf("\n");
}

void view_opt(const struct states_array_t *states) {
    printf("OPT |\t");

    for (int bag = 0; bag < (states->Vmax + 1); bag += 1) {
        printf("%2d\t", bag);
    }
    printf("\n----|");

    for (int bag = 0; bag < (states->Vmax + 1); bag += 1) {
        printf("--------");
    }
    printf("\n");

    for (int obj = 0; obj < (states->num_obj + 1); obj += 1) {
        printf("%3d |\t", obj);

        for (int bag = 0; bag < (states->Vmax + 1); bag += 1) {
            int idx = obj * (states->Vmax + 1) + bag;

            if (states->OPT[idx] == INFTY) {
                printf("INF\t");
            } else if (states->OPT[idx] == UNDTR) {
                printf("UND\t");
            } else {
                printf("%2d\t", states->OPT[idx]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void view_chm(const struct states_array_t *states) {
    printf("CHM |\t");

    for (int bag = 0; bag < (states->Vmax + 1); bag += 1) {
        printf("%2d\t", bag);
    }
    printf("\n----|");

    for (int bag = 0; bag < (states->Vmax + 1); bag += 1) {
        printf("--------");
    }
    printf("\n");

    for (int obj = 0; obj < (states->num_obj + 1); obj += 1) {
        printf("%3d |\t", obj);

        for (int bag = 0; bag < (states->Vmax + 1); bag += 1) {
            int idx = obj * (states->Vmax + 1) + bag;

            if (states->CHM[idx] == INFTY) {
                printf("PRE\t");
            } else if (states->CHM[idx] == UNDTR) {
                printf("UND\t");
            } else {
                printf("%2d\t", states->CHM[idx]);
            }
        }
        printf("\n");
    }
    printf("\n");
}
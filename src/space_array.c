#include "../include/space_array.h"

void free_states_array(struct states_array_t *states) {
    assert(states);
    /** TODO */
}

struct states_array_t *new_states_array(const int num_objects, const int Vmax) {
    struct states_array_t *NS;

    NS = (struct states_array_t *) calloc(1, sizeof(struct states_array_t));
    assert(NS != NULL);

    /** TODO */
    init_opt_chm(NS);

    return NS;
}

void push_object_in_array(struct states_array_t *states, const struct objects_t *objects, int i) {
    int bag;

    /* Faites attention que les objets dans LO sont rangés à partir de 0
     * tandis qu'ils sont rangés à parte de 1 dans OPT (et CHM) */
    for (bag = 0; bag < (states->VMax + 1); bag++) {
        // Parcourir chaque état du sac-à-dos
        int pred;
        int curr;
        int OPT1;

        pred = ...; // Calculer l'index de l'état pour l'objet (i-1)
        curr = ...; // Calculer l'index de l'état pour l'objet (i)
        OPT1 = states->OPT[pred];

        states->CHM[curr] = INFTY; //hyp.: l'objet i n'est pas dans le sac

        if (...) { // S'il y a de la place dans le sac
            int pred_without_i;
            int OPT2;

            pred_without_i = ...; // L'index du bag SANS l'objet (i)
            OPT2 = ...;

            if (...) { // Sélectionne la meilleur configuration
                states->OPT[curr] = ...;
                states->CHM[curr] = ...; // Noter que l'objet i est dans le sac
            } else {
                states->OPT[curr] = ...;
            }
        } else {
            states->OPT[curr] = ...; // S'il n'y a pas de place
        }
    }
}

/**
 * Private Function
 * Connais pas le but de cette fonction
 */
void init_opt_chm(struct states_array_t *states) {
    int obj;
    int bag;
    int idx;

    states->OPT = ...;
    states->CHM = ...;

    for (obj = 1; obj <= states->num_obj; obj++) {
        for (bag = 0; bag <= states->VMax; bag++) {
            idx = ...;

            states->OPT[idx] = UNDTR;
            states->CHM[idx] = UNDTR;
        }
    }

    for (bag = 0; bag <= states->VMax; bag += 1) {
        states->CHM[bag] = UNDTR;
    }
}

void view_path_array(const struct states_array_t *states, const struct objects_t *set) {
    bool nonStop;
    int obj;
    int vol;
    int idx;

    obj = states->num_obj;
    vol = states->VMax;
    idx = obj * (vol + 1) + vol;

    nonStop = (obj == 0);
    printf("******\nTotal packaging utility : %d\n******\n", states->OPT[idx]);

    while (!nonStop) {
        if (states->CHM[idx] != INFTY) { // object actually put in bag
            printf("\tobjet #%d(%d, %d)\n", obj, set->objects[obj - 1].volume, set->objects[obj - 1].utility);
            nonStop = (states->CHM[idx] == 0);
            vol = states->CHM[idx];
        }

        obj -= 1;
        nonStop = nonStop || (obj == 0);
        idx = obj * (states->VMax + 1) + vol;
    }
    printf("\n");
}

void view_opt(const struct states_array_t *states) {
    int bag;
    int obj;
    int idx;

    printf("OPT |\t");
    for (bag = 0; bag < (states->VMax + 1); bag++) {
        printf("%2d\t", bag);
    }

    printf("\n----|");
    for (bag = 0; bag < (states->VMax + 1); bag++) {
        printf("--------");
    }

    printf("\n");
    for (obj = 0; obj < (states->num_obj + 1); obj++) {
        printf("%3d |\t", obj);

        for (bag = 0; bag < (states->VMax + 1); bag++) {
            idx = obj * (states->VMax + 1) + bag;

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
    int bag;
    int obj;
    int idx;

    printf("CHM |\t");
    for (bag = 0; bag < (states->VMax + 1); bag++) {
        printf("%2d\t", bag);
    }

    printf("\n----|");
    for (bag = 0; bag < (states->VMax + 1); bag++) {
        printf("--------");
    }

    printf("\n");
    for (obj = 0; obj < (states->num_obj + 1); obj++) {
        printf("%3d |\t", obj);

        for (bag = 0; bag < (states->VMax + 1); bag++) {
            idx = obj * (states->VMax + 1) + bag;

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
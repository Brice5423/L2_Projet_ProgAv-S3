#include "../include/space_array.h"

void free_states_array(struct states_array_t *states) {
    assert(states);

    /* Nous */
    free(states);
    states = NULL;
}

struct states_array_t *new_states_array(const int num_objects, const int Vmax) {
    struct states_array_t *NS;

    NS = (struct states_array_t *) calloc(1, sizeof(struct states_array_t));
    assert(NS != NULL);

    /* Nous (à verifier) */
    NS->num_obj = num_objects;
    NS->VMax = Vmax;

    init_opt_chm(NS);

    return NS;
}

void push_object_in_array(struct states_array_t *states, const struct objects_t *objects, int i) {
    int bag;

    /* Faites attention que les objets dans LO sont rangés à partir de 0
     * tandis qu'ils sont rangés à partir de 1 dans OPT (et CHM) */
    for (bag = 0; bag < (states->VMax + 1); bag++) {
        // Parcourir chaque état du sac-à-dos
        int pred;
        int curr;
        int OPT1;

        pred = objects->first_idx +
               (i - 1); // Calculer l'index de l'état pour l'objet (i-1) // Nous : objects->first_idx + (i - 1)
        curr = objects->first_idx + i; // Calculer l'index de l'état pour l'objet (i) // Nous : objects->first_idx + i
        OPT1 = states->OPT[pred];

        states->CHM[curr] = INFTY; //hyp.: l'objet i n'est pas dans le sac

        if (objects->objects[curr].volume <= bag) { // S'il y a de la place dans le sac // Nous : objects->objects[curr].volume <= bag
            int pred_without_i;
            int OPT2;

            pred_without_i = (states->VMax + 1 - objects->objects[curr].volume) + bag; // L'index du bag SANS l'objet (i) // Nous : (states->VMax + 1 - objects->objects[curr].volume) + bag;
            OPT2 = states->OPT[pred_without_i]; // Nous : states->OPT[pred_without_i];

            if (OPT1 <= OPT2) { // Sélectionne la meilleur configuration // Nous : OPT1 <= OPT2
                states->OPT[curr] = OPT2; // Nous : OPT2;
                states->CHM[curr] = states->OPT[pred_without_i]; // Noter que l'objet i est dans le sac // Nous : states->OPT[pred_without_i];
            } else {
                states->OPT[curr] = OPT1; // Nous : OPT1;
            }

        } else {
            states->OPT[curr] = OPT1; // S'il n'y a pas de place // Nous : OPT1;
        }
    }
}

/**
 * Private Function
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